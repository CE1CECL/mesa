/*
 * Copyright 2010 Jerome Glisse <glisse@freedesktop.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * on the rights to use, copy, modify, merge, publish, distribute, sub
 * license, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHOR(S) AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <stdio.h>
#include <errno.h>
#include "pipe/p_defines.h"
#include "pipe/p_state.h"
#include "pipe/p_context.h"
#include "tgsi/tgsi_scan.h"
#include "tgsi/tgsi_parse.h"
#include "tgsi/tgsi_util.h"
#include "util/u_blitter.h"
#include "util/u_double_list.h"
#include "util/u_format.h"
#include "util/u_format_s3tc.h"
#include "util/u_transfer.h"
#include "util/u_surface.h"
#include "util/u_pack_color.h"
#include "util/u_memory.h"
#include "util/u_inlines.h"
#include "util/u_upload_mgr.h"
#include "vl/vl_decoder.h"
#include "vl/vl_video_buffer.h"
#include "os/os_time.h"
#include "pipebuffer/pb_buffer.h"
#include "r600.h"
#include "r600d.h"
#include "r600_resource.h"
#include "r600_shader.h"
#include "r600_pipe.h"

/*
 * pipe_context
 */
static struct r600_fence *r600_create_fence(struct r600_pipe_context *ctx)
{
	struct r600_pipe_context *rctx = (struct r600_pipe_context *)ctx;
	struct r600_fence *fence = NULL;

	if (!ctx->fences.bo) {
		/* Create the shared buffer object */
		ctx->fences.bo = r600_bo(ctx->radeon, 4096, 0, 0, 0);
		if (!ctx->fences.bo) {
			R600_ERR("r600: failed to create bo for fence objects\n");
			return NULL;
		}
		ctx->fences.data = r600_bo_map(ctx->radeon, ctx->fences.bo, rctx->ctx.cs,
					       PIPE_TRANSFER_UNSYNCHRONIZED | PIPE_TRANSFER_WRITE);
	}

	if (!LIST_IS_EMPTY(&ctx->fences.pool)) {
		struct r600_fence *entry;

		/* Try to find a freed fence that has been signalled */
		LIST_FOR_EACH_ENTRY(entry, &ctx->fences.pool, head) {
			if (ctx->fences.data[entry->index] != 0) {
				LIST_DELINIT(&entry->head);
				fence = entry;
				break;
			}
		}
	}

	if (!fence) {
		/* Allocate a new fence */
		struct r600_fence_block *block;
		unsigned index;

		if ((ctx->fences.next_index + 1) >= 1024) {
			R600_ERR("r600: too many concurrent fences\n");
			return NULL;
		}

		index = ctx->fences.next_index++;

		if (!(index % FENCE_BLOCK_SIZE)) {
			/* Allocate a new block */
			block = CALLOC_STRUCT(r600_fence_block);
			if (block == NULL)
				return NULL;

			LIST_ADD(&block->head, &ctx->fences.blocks);
		} else {
			block = LIST_ENTRY(struct r600_fence_block, ctx->fences.blocks.next, head);
		}

		fence = &block->fences[index % FENCE_BLOCK_SIZE];
		fence->ctx = ctx;
		fence->index = index;
	}

	pipe_reference_init(&fence->reference, 1);

	ctx->fences.data[fence->index] = 0;
	r600_context_emit_fence(&ctx->ctx, ctx->fences.bo, fence->index, 1);
	return fence;
}


void r600_flush(struct pipe_context *ctx, struct pipe_fence_handle **fence,
		unsigned flags)
{
	struct r600_pipe_context *rctx = (struct r600_pipe_context *)ctx;
	struct r600_fence **rfence = (struct r600_fence**)fence;

	if (rfence)
		*rfence = r600_create_fence(rctx);

	r600_context_flush(&rctx->ctx, flags);
}

static void r600_flush_from_st(struct pipe_context *ctx,
			       struct pipe_fence_handle **fence)
{
	r600_flush(ctx, fence, 0);
}

static void r600_flush_from_winsys(void *ctx, unsigned flags)
{
	r600_flush((struct pipe_context*)ctx, NULL, flags);
}

static void r600_update_num_contexts(struct r600_screen *rscreen, int diff)
{
	pipe_mutex_lock(rscreen->mutex_num_contexts);
	if (diff > 0) {
		rscreen->num_contexts++;

		if (rscreen->num_contexts > 1)
			util_slab_set_thread_safety(&rscreen->pool_buffers,
						    UTIL_SLAB_MULTITHREADED);
	} else {
		rscreen->num_contexts--;

		if (rscreen->num_contexts <= 1)
			util_slab_set_thread_safety(&rscreen->pool_buffers,
						    UTIL_SLAB_SINGLETHREADED);
	}
	pipe_mutex_unlock(rscreen->mutex_num_contexts);
}

static void r600_destroy_context(struct pipe_context *context)
{
	struct r600_pipe_context *rctx = (struct r600_pipe_context *)context;

	rctx->context.delete_depth_stencil_alpha_state(&rctx->context, rctx->custom_dsa_flush);
	util_unreference_framebuffer_state(&rctx->framebuffer);

	r600_context_fini(&rctx->ctx);

	util_blitter_destroy(rctx->blitter);

	for (int i = 0; i < R600_PIPE_NSTATES; i++) {
		free(rctx->states[i]);
	}

	u_vbuf_destroy(rctx->vbuf_mgr);
	util_slab_destroy(&rctx->pool_transfers);

	if (rctx->fences.bo) {
		struct r600_fence_block *entry, *tmp;

		LIST_FOR_EACH_ENTRY_SAFE(entry, tmp, &rctx->fences.blocks, head) {
			LIST_DEL(&entry->head);
			FREE(entry);
		}

		r600_bo_unmap(rctx->radeon, rctx->fences.bo);
		r600_bo_reference(&rctx->fences.bo, NULL);
	}

	r600_update_num_contexts(rctx->screen, -1);

	FREE(rctx);
}

static struct pipe_context *r600_create_context(struct pipe_screen *screen, void *priv)
{
	struct r600_pipe_context *rctx = CALLOC_STRUCT(r600_pipe_context);
	struct r600_screen* rscreen = (struct r600_screen *)screen;

	if (rctx == NULL)
		return NULL;

	r600_update_num_contexts(rscreen, 1);

	rctx->context.winsys = rscreen->screen.winsys;
	rctx->context.screen = screen;
	rctx->context.priv = priv;
	rctx->context.destroy = r600_destroy_context;
	rctx->context.flush = r600_flush_from_st;

	/* Easy accessing of screen/winsys. */
	rctx->screen = rscreen;
	rctx->radeon = rscreen->radeon;
	rctx->family = r600_get_family(rctx->radeon);
	rctx->chip_class = r600_get_family_class(rctx->radeon);

	rctx->fences.bo = NULL;
	rctx->fences.data = NULL;
	rctx->fences.next_index = 0;
	LIST_INITHEAD(&rctx->fences.pool);
	LIST_INITHEAD(&rctx->fences.blocks);

	r600_init_blit_functions(rctx);
	r600_init_query_functions(rctx);
	r600_init_context_resource_functions(rctx);
	r600_init_surface_functions(rctx);
	rctx->context.draw_vbo = r600_draw_vbo;

	rctx->context.create_video_decoder = vl_create_decoder;
	rctx->context.create_video_buffer = vl_video_buffer_create;

	switch (rctx->chip_class) {
	case R600:
	case R700:
		r600_init_state_functions(rctx);
		if (r600_context_init(&rctx->ctx, rctx->radeon)) {
			r600_destroy_context(&rctx->context);
			return NULL;
		}
		r600_init_config(rctx);
		rctx->custom_dsa_flush = r600_create_db_flush_dsa(rctx);
		break;
	case EVERGREEN:
	case CAYMAN:
		evergreen_init_state_functions(rctx);
		if (evergreen_context_init(&rctx->ctx, rctx->radeon)) {
			r600_destroy_context(&rctx->context);
			return NULL;
		}
		evergreen_init_config(rctx);
		rctx->custom_dsa_flush = evergreen_create_db_flush_dsa(rctx);
		break;
	default:
		R600_ERR("Unsupported chip class %d.\n", rctx->chip_class);
		r600_destroy_context(&rctx->context);
		return NULL;
	}

	rctx->screen->ws->cs_set_flush_callback(rctx->ctx.cs, r600_flush_from_winsys, rctx);

	util_slab_create(&rctx->pool_transfers,
			 sizeof(struct pipe_transfer), 64,
			 UTIL_SLAB_SINGLETHREADED);

	rctx->vbuf_mgr = u_vbuf_create(&rctx->context, 1024 * 1024, 256,
					   PIPE_BIND_VERTEX_BUFFER |
					   PIPE_BIND_INDEX_BUFFER |
					   PIPE_BIND_CONSTANT_BUFFER,
					   U_VERTEX_FETCH_DWORD_ALIGNED);
	if (!rctx->vbuf_mgr) {
		r600_destroy_context(&rctx->context);
		return NULL;
	}
	rctx->vbuf_mgr->caps.format_fixed32 = 0;

	rctx->blitter = util_blitter_create(&rctx->context);
	if (rctx->blitter == NULL) {
		r600_destroy_context(&rctx->context);
		return NULL;
	}

	return &rctx->context;
}

/*
 * pipe_screen
 */
static const char* r600_get_vendor(struct pipe_screen* pscreen)
{
	return "X.Org";
}

static const char *r600_get_family_name(enum radeon_family family)
{
	switch(family) {
	case CHIP_R600: return "AMD R600";
	case CHIP_RV610: return "AMD RV610";
	case CHIP_RV630: return "AMD RV630";
	case CHIP_RV670: return "AMD RV670";
	case CHIP_RV620: return "AMD RV620";
	case CHIP_RV635: return "AMD RV635";
	case CHIP_RS780: return "AMD RS780";
	case CHIP_RS880: return "AMD RS880";
	case CHIP_RV770: return "AMD RV770";
	case CHIP_RV730: return "AMD RV730";
	case CHIP_RV710: return "AMD RV710";
	case CHIP_RV740: return "AMD RV740";
	case CHIP_CEDAR: return "AMD CEDAR";
	case CHIP_REDWOOD: return "AMD REDWOOD";
	case CHIP_JUNIPER: return "AMD JUNIPER";
	case CHIP_CYPRESS: return "AMD CYPRESS";
	case CHIP_HEMLOCK: return "AMD HEMLOCK";
	case CHIP_PALM: return "AMD PALM";
	case CHIP_SUMO: return "AMD SUMO";
	case CHIP_SUMO2: return "AMD SUMO2";
	case CHIP_BARTS: return "AMD BARTS";
	case CHIP_TURKS: return "AMD TURKS";
	case CHIP_CAICOS: return "AMD CAICOS";
	case CHIP_CAYMAN: return "AMD CAYMAN";
	default: return "AMD unknown";
	}
}

static const char* r600_get_name(struct pipe_screen* pscreen)
{
	struct r600_screen *rscreen = (struct r600_screen *)pscreen;
	enum radeon_family family = r600_get_family(rscreen->radeon);

	return r600_get_family_name(family);
}

static int r600_get_param(struct pipe_screen* pscreen, enum pipe_cap param)
{
	struct r600_screen *rscreen = (struct r600_screen *)pscreen;
	enum radeon_family family = r600_get_family(rscreen->radeon);

	switch (param) {
	/* Supported features (boolean caps). */
	case PIPE_CAP_NPOT_TEXTURES:
	case PIPE_CAP_TWO_SIDED_STENCIL:
	case PIPE_CAP_GLSL:
	case PIPE_CAP_DUAL_SOURCE_BLEND:
	case PIPE_CAP_ANISOTROPIC_FILTER:
	case PIPE_CAP_POINT_SPRITE:
	case PIPE_CAP_OCCLUSION_QUERY:
	case PIPE_CAP_TEXTURE_SHADOW_MAP:
	case PIPE_CAP_TEXTURE_MIRROR_CLAMP:
	case PIPE_CAP_TEXTURE_MIRROR_REPEAT:
	case PIPE_CAP_BLEND_EQUATION_SEPARATE:
	case PIPE_CAP_TEXTURE_SWIZZLE:
	case PIPE_CAP_DEPTHSTENCIL_CLEAR_SEPARATE:
	case PIPE_CAP_DEPTH_CLAMP:
	case PIPE_CAP_SHADER_STENCIL_EXPORT:
	case PIPE_CAP_VERTEX_ELEMENT_INSTANCE_DIVISOR:
	case PIPE_CAP_MIXED_COLORBUFFER_FORMATS:
	case PIPE_CAP_TGSI_FS_COORD_ORIGIN_UPPER_LEFT:
	case PIPE_CAP_TGSI_FS_COORD_PIXEL_CENTER_HALF_INTEGER:
	case PIPE_CAP_SM3:
	case PIPE_CAP_SEAMLESS_CUBE_MAP:
	case PIPE_CAP_FRAGMENT_COLOR_CLAMP_CONTROL:
	case PIPE_CAP_PRIMITIVE_RESTART:
		return 1;

	/* Supported except the original R600. */
	case PIPE_CAP_INDEP_BLEND_ENABLE:
	case PIPE_CAP_INDEP_BLEND_FUNC:
		/* R600 doesn't support per-MRT blends */
		return family == CHIP_R600 ? 0 : 1;

	/* Supported on Evergreen. */
	case PIPE_CAP_SEAMLESS_CUBE_MAP_PER_TEXTURE:
		return family >= CHIP_CEDAR ? 1 : 0;

	/* Unsupported features. */
	case PIPE_CAP_STREAM_OUTPUT:
	case PIPE_CAP_TGSI_INSTANCEID:
	case PIPE_CAP_TGSI_FS_COORD_ORIGIN_LOWER_LEFT:
	case PIPE_CAP_TGSI_FS_COORD_PIXEL_CENTER_INTEGER:
		return 0;

	/* Texturing. */
	case PIPE_CAP_MAX_TEXTURE_2D_LEVELS:
	case PIPE_CAP_MAX_TEXTURE_3D_LEVELS:
	case PIPE_CAP_MAX_TEXTURE_CUBE_LEVELS:
		if (family >= CHIP_CEDAR)
			return 15;
		else
			return 14;
	case PIPE_CAP_MAX_TEXTURE_ARRAY_LAYERS:
		return rscreen->info.drm_minor >= 9 ?
			(family >= CHIP_CEDAR ? 16384 : 8192) : 0;
	case PIPE_CAP_MAX_VERTEX_TEXTURE_UNITS:
	case PIPE_CAP_MAX_TEXTURE_IMAGE_UNITS:
		return 16;
	case PIPE_CAP_MAX_COMBINED_SAMPLERS:
		return 32;

	/* Render targets. */
	case PIPE_CAP_MAX_RENDER_TARGETS:
		/* FIXME some r6xx are buggy and can only do 4 */
		return 8;

	/* Timer queries, present when the clock frequency is non zero. */
	case PIPE_CAP_TIMER_QUERY:
		return rscreen->info.r600_clock_crystal_freq != 0;

	case PIPE_CAP_MIN_TEXEL_OFFSET:
		return -8;

	case PIPE_CAP_MAX_TEXEL_OFFSET:
		return 7;

	default:
		R600_ERR("r600: unknown param %d\n", param);
		return 0;
	}
}

static float r600_get_paramf(struct pipe_screen* pscreen, enum pipe_cap param)
{
	struct r600_screen *rscreen = (struct r600_screen *)pscreen;
	enum radeon_family family = r600_get_family(rscreen->radeon);

	switch (param) {
	case PIPE_CAP_MAX_LINE_WIDTH:
	case PIPE_CAP_MAX_LINE_WIDTH_AA:
	case PIPE_CAP_MAX_POINT_WIDTH:
	case PIPE_CAP_MAX_POINT_WIDTH_AA:
		if (family >= CHIP_CEDAR)
			return 16384.0f;
		else
			return 8192.0f;
	case PIPE_CAP_MAX_TEXTURE_ANISOTROPY:
		return 16.0f;
	case PIPE_CAP_MAX_TEXTURE_LOD_BIAS:
		return 16.0f;
	default:
		R600_ERR("r600: unsupported paramf %d\n", param);
		return 0.0f;
	}
}

static int r600_get_shader_param(struct pipe_screen* pscreen, unsigned shader, enum pipe_shader_cap param)
{
	switch(shader)
	{
	case PIPE_SHADER_FRAGMENT:
	case PIPE_SHADER_VERTEX:
		break;
	case PIPE_SHADER_GEOMETRY:
		/* TODO: support and enable geometry programs */
		return 0;
	default:
		/* TODO: support tessellation on Evergreen */
		return 0;
	}

	/* TODO: all these should be fixed, since r600 surely supports much more! */
	switch (param) {
	case PIPE_SHADER_CAP_MAX_INSTRUCTIONS:
	case PIPE_SHADER_CAP_MAX_ALU_INSTRUCTIONS:
	case PIPE_SHADER_CAP_MAX_TEX_INSTRUCTIONS:
	case PIPE_SHADER_CAP_MAX_TEX_INDIRECTIONS:
		return 16384;
	case PIPE_SHADER_CAP_MAX_CONTROL_FLOW_DEPTH:
		return 8; /* FIXME */
	case PIPE_SHADER_CAP_MAX_INPUTS:
		if(shader == PIPE_SHADER_FRAGMENT)
			return 34;
		else
			return 32;
	case PIPE_SHADER_CAP_MAX_TEMPS:
		return 256; /* Max native temporaries. */
	case PIPE_SHADER_CAP_MAX_ADDRS:
		/* FIXME Isn't this equal to TEMPS? */
		return 1; /* Max native address registers */
	case PIPE_SHADER_CAP_MAX_CONSTS:
		return R600_MAX_CONST_BUFFER_SIZE;
	case PIPE_SHADER_CAP_MAX_CONST_BUFFERS:
		return R600_MAX_CONST_BUFFERS;
	case PIPE_SHADER_CAP_MAX_PREDS:
		return 0; /* FIXME */
	case PIPE_SHADER_CAP_TGSI_CONT_SUPPORTED:
		return 1;
	case PIPE_SHADER_CAP_INDIRECT_INPUT_ADDR:
	case PIPE_SHADER_CAP_INDIRECT_OUTPUT_ADDR:
	case PIPE_SHADER_CAP_INDIRECT_TEMP_ADDR:
	case PIPE_SHADER_CAP_INDIRECT_CONST_ADDR:
		return 1;
	case PIPE_SHADER_CAP_SUBROUTINES:
		return 0;
	case PIPE_SHADER_CAP_INTEGERS:
		return 0;
	default:
		return 0;
	}
}

static int r600_get_video_param(struct pipe_screen *screen,
				enum pipe_video_profile profile,
				enum pipe_video_cap param)
{
	switch (param) {
	case PIPE_VIDEO_CAP_SUPPORTED:
		return vl_profile_supported(screen, profile);
	case PIPE_VIDEO_CAP_NPOT_TEXTURES:
		return 1;
	case PIPE_VIDEO_CAP_MAX_WIDTH:
	case PIPE_VIDEO_CAP_MAX_HEIGHT:
		return vl_video_buffer_max_size(screen);
	case PIPE_VIDEO_CAP_NUM_BUFFERS_DESIRED:
		return vl_num_buffers_desired(screen, profile);
	default:
		return 0;
	}
}

static void r600_destroy_screen(struct pipe_screen* pscreen)
{
	struct r600_screen *rscreen = (struct r600_screen *)pscreen;

	if (rscreen == NULL)
		return;

	radeon_destroy(rscreen->radeon);
	rscreen->ws->destroy(rscreen->ws);

	util_slab_destroy(&rscreen->pool_buffers);
	pipe_mutex_destroy(rscreen->mutex_num_contexts);
	FREE(rscreen);
}

static void r600_fence_reference(struct pipe_screen *pscreen,
                                 struct pipe_fence_handle **ptr,
                                 struct pipe_fence_handle *fence)
{
	struct r600_fence **oldf = (struct r600_fence**)ptr;
	struct r600_fence *newf = (struct r600_fence*)fence;

	if (pipe_reference(&(*oldf)->reference, &newf->reference)) {
		struct r600_pipe_context *ctx = (*oldf)->ctx;
		LIST_ADDTAIL(&(*oldf)->head, &ctx->fences.pool);
	}

	*ptr = fence;
}

static boolean r600_fence_signalled(struct pipe_screen *pscreen,
                                    struct pipe_fence_handle *fence)
{
	struct r600_fence *rfence = (struct r600_fence*)fence;
	struct r600_pipe_context *ctx = rfence->ctx;

	return ctx->fences.data[rfence->index];
}

static boolean r600_fence_finish(struct pipe_screen *pscreen,
                                 struct pipe_fence_handle *fence,
                                 uint64_t timeout)
{
	struct r600_fence *rfence = (struct r600_fence*)fence;
	struct r600_pipe_context *ctx = rfence->ctx;
	int64_t start_time = 0;
	unsigned spins = 0;

	if (timeout != PIPE_TIMEOUT_INFINITE) {
		start_time = os_time_get();

		/* Convert to microseconds. */
		timeout /= 1000;
	}

	while (ctx->fences.data[rfence->index] == 0) {
		if (++spins % 256)
			continue;
#ifdef PIPE_OS_UNIX
		sched_yield();
#else
		os_time_sleep(10);
#endif
		if (timeout != PIPE_TIMEOUT_INFINITE &&
		    os_time_get() - start_time >= timeout) {
			return FALSE;
		}
	}

	return TRUE;
}

static int r600_interpret_tiling(struct r600_screen *rscreen, uint32_t tiling_config)
{
	switch ((tiling_config & 0xe) >> 1) {
	case 0:
		rscreen->tiling_info.num_channels = 1;
		break;
	case 1:
		rscreen->tiling_info.num_channels = 2;
		break;
	case 2:
		rscreen->tiling_info.num_channels = 4;
		break;
	case 3:
		rscreen->tiling_info.num_channels = 8;
		break;
	default:
		return -EINVAL;
	}

	switch ((tiling_config & 0x30) >> 4) {
	case 0:
		rscreen->tiling_info.num_banks = 4;
		break;
	case 1:
		rscreen->tiling_info.num_banks = 8;
		break;
	default:
		return -EINVAL;

	}
	switch ((tiling_config & 0xc0) >> 6) {
	case 0:
		rscreen->tiling_info.group_bytes = 256;
		break;
	case 1:
		rscreen->tiling_info.group_bytes = 512;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

static int evergreen_interpret_tiling(struct r600_screen *rscreen, uint32_t tiling_config)
{
	switch (tiling_config & 0xf) {
	case 0:
		rscreen->tiling_info.num_channels = 1;
		break;
	case 1:
		rscreen->tiling_info.num_channels = 2;
		break;
	case 2:
		rscreen->tiling_info.num_channels = 4;
		break;
	case 3:
		rscreen->tiling_info.num_channels = 8;
		break;
	default:
		return -EINVAL;
	}

	switch ((tiling_config & 0xf0) >> 4) {
	case 0:
		rscreen->tiling_info.num_banks = 4;
		break;
	case 1:
		rscreen->tiling_info.num_banks = 8;
		break;
	case 2:
		rscreen->tiling_info.num_banks = 16;
		break;
	default:
		return -EINVAL;
	}

	switch ((tiling_config & 0xf00) >> 8) {
	case 0:
		rscreen->tiling_info.group_bytes = 256;
		break;
	case 1:
		rscreen->tiling_info.group_bytes = 512;
		break;
	default:
		return -EINVAL;
	}
	return 0;
}

static int r600_init_tiling(struct r600_screen *rscreen)
{
	uint32_t tiling_config = rscreen->info.r600_tiling_config;

	/* set default group bytes, overridden by tiling info ioctl */
	if (r600_get_family_class(rscreen->radeon) <= R700) {
		rscreen->tiling_info.group_bytes = 256;
	} else {
		rscreen->tiling_info.group_bytes = 512;
	}

	if (!tiling_config)
		return 0;

	if (r600_get_family_class(rscreen->radeon) <= R700) {
		return r600_interpret_tiling(rscreen, tiling_config);
	} else {
		return evergreen_interpret_tiling(rscreen, tiling_config);
	}
}

struct pipe_screen *r600_screen_create(struct radeon_winsys *ws)
{
	struct r600_screen *rscreen;
	struct radeon *radeon = radeon_create(ws);
	if (!radeon) {
		return NULL;
	}

	rscreen = CALLOC_STRUCT(r600_screen);
	if (rscreen == NULL) {
		radeon_destroy(radeon);
		return NULL;
	}

	rscreen->ws = ws;
	rscreen->radeon = radeon;
	ws->query_info(ws, &rscreen->info);

	if (r600_init_tiling(rscreen)) {
		radeon_destroy(radeon);
		FREE(rscreen);
		return NULL;
	}

	rscreen->screen.winsys = (struct pipe_winsys*)ws;
	rscreen->screen.destroy = r600_destroy_screen;
	rscreen->screen.get_name = r600_get_name;
	rscreen->screen.get_vendor = r600_get_vendor;
	rscreen->screen.get_param = r600_get_param;
	rscreen->screen.get_shader_param = r600_get_shader_param;
	rscreen->screen.get_paramf = r600_get_paramf;
	rscreen->screen.get_video_param = r600_get_video_param;
	if (r600_get_family_class(radeon) >= EVERGREEN) {
		rscreen->screen.is_format_supported = evergreen_is_format_supported;
	} else {
		rscreen->screen.is_format_supported = r600_is_format_supported;
	}
	rscreen->screen.is_video_format_supported = vl_video_buffer_is_format_supported;
	rscreen->screen.context_create = r600_create_context;
	rscreen->screen.fence_reference = r600_fence_reference;
	rscreen->screen.fence_signalled = r600_fence_signalled;
	rscreen->screen.fence_finish = r600_fence_finish;
	r600_init_screen_resource_functions(&rscreen->screen);

	util_format_s3tc_init();

	util_slab_create(&rscreen->pool_buffers,
			 sizeof(struct r600_resource), 64,
			 UTIL_SLAB_SINGLETHREADED);

	pipe_mutex_init(rscreen->mutex_num_contexts);

	return &rscreen->screen;
}
