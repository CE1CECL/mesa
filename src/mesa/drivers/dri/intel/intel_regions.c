/**************************************************************************
 * 
 * Copyright 2006 Tungsten Graphics, Inc., Cedar Park, Texas.
 * All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 **************************************************************************/

/* Provide additional functionality on top of bufmgr buffers:
 *   - 2d semantics and blit operations
 *   - refcounting of buffers for multiple images in a buffer.
 *   - refcounting of buffer mappings.
 *   - some logic for moving the buffers to the best memory pools for
 *     given operations.
 *
 * Most of this is to make it easier to implement the fixed-layout
 * mipmap tree required by intel hardware in the face of GL's
 * programming interface where each image can be specifed in random
 * order and it isn't clear what layout the tree should have until the
 * last moment.
 */

#include <sys/ioctl.h>
#include <errno.h>

#include "main/hash.h"
#include "intel_context.h"
#include "intel_regions.h"
#include "intel_blit.h"
#include "intel_buffer_objects.h"
#include "intel_bufmgr.h"
#include "intel_batchbuffer.h"

#define FILE_DEBUG_FLAG DEBUG_REGION

/* This should be set to the maximum backtrace size desired.
 * Set it to 0 to disable backtrace debugging.
 */
#define DEBUG_BACKTRACE_SIZE 0

#if DEBUG_BACKTRACE_SIZE == 0
/* Use the standard debug output */
#define _DBG(...) DBG(__VA_ARGS__)
#else
/* Use backtracing debug output */
#define _DBG(...) {debug_backtrace(); DBG(__VA_ARGS__);}

/* Backtracing debug support */
#include <execinfo.h>

static void
debug_backtrace(void)
{
   void *trace[DEBUG_BACKTRACE_SIZE];
   char **strings = NULL;
   int traceSize;
   register int i;

   traceSize = backtrace(trace, DEBUG_BACKTRACE_SIZE);
   strings = backtrace_symbols(trace, traceSize);
   if (strings == NULL) {
      DBG("no backtrace:");
      return;
   }

   /* Spit out all the strings with a colon separator.  Ignore
    * the first, since we don't really care about the call
    * to debug_backtrace() itself.  Skip until the final "/" in
    * the trace to avoid really long lines.
    */
   for (i = 1; i < traceSize; i++) {
      char *p = strings[i], *slash = strings[i];
      while (*p) {
         if (*p++ == '/') {
            slash = p;
         }
      }

      DBG("%s:", slash);
   }

   /* Free up the memory, and we're done */
   free(strings);
}

#endif



/* XXX: Thread safety?
 */
GLubyte *
intel_region_map(struct intel_context *intel, struct intel_region *region)
{
   intel_flush(&intel->ctx);

   _DBG("%s %p\n", __FUNCTION__, region);
   if (!region->map_refcount++) {
      if (region->tiling != I915_TILING_NONE)
	 drm_intel_gem_bo_map_gtt(region->bo);
      else
	 drm_intel_bo_map(region->bo, GL_TRUE);
      region->map = region->bo->virtual;
   }

   return region->map;
}

void
intel_region_unmap(struct intel_context *intel, struct intel_region *region)
{
   _DBG("%s %p\n", __FUNCTION__, region);
   if (!--region->map_refcount) {
      if (region->tiling != I915_TILING_NONE)
	 drm_intel_gem_bo_unmap_gtt(region->bo);
      else
	 drm_intel_bo_unmap(region->bo);
      region->map = NULL;
   }
}

static struct intel_region *
intel_region_alloc_internal(struct intel_screen *screen,
			    GLuint cpp,
			    GLuint width, GLuint height, GLuint pitch,
			    uint32_t tiling, drm_intel_bo *buffer)
{
   struct intel_region *region;

   region = calloc(sizeof(*region), 1);
   if (region == NULL)
      return region;

   region->cpp = cpp;
   region->width = width;
   region->height = height;
   region->pitch = pitch;
   region->refcount = 1;
   region->bo = buffer;
   region->tiling = tiling;
   region->screen = screen;

   _DBG("%s <-- %p\n", __FUNCTION__, region);
   return region;
}

struct intel_region *
intel_region_alloc(struct intel_screen *screen,
		   uint32_t tiling,
                   GLuint cpp, GLuint width, GLuint height,
		   GLboolean expect_accelerated_upload)
{
   drm_intel_bo *buffer;
   unsigned long flags = 0;
   unsigned long aligned_pitch;
   struct intel_region *region;

   if (expect_accelerated_upload)
      flags |= BO_ALLOC_FOR_RENDER;

   buffer = drm_intel_bo_alloc_tiled(screen->bufmgr, "region",
				     width, height, cpp,
				     &tiling, &aligned_pitch, flags);
   if (buffer == NULL)
      return NULL;

   region = intel_region_alloc_internal(screen, cpp, width, height,
                                        aligned_pitch / cpp, tiling, buffer);
   if (region == NULL) {
      drm_intel_bo_unreference(buffer);
      return NULL;
   }

   return region;
}

GLboolean
intel_region_flink(struct intel_region *region, uint32_t *name)
{
   if (region->name == 0) {
      if (drm_intel_bo_flink(region->bo, &region->name))
	 return GL_FALSE;
      
      _mesa_HashInsert(region->screen->named_regions,
		       region->name, region);
   }

   *name = region->name;

   return GL_TRUE;
}

struct intel_region *
intel_region_alloc_for_handle(struct intel_screen *screen,
			      GLuint cpp,
			      GLuint width, GLuint height, GLuint pitch,
			      GLuint handle, const char *name)
{
   struct intel_region *region, *dummy;
   drm_intel_bo *buffer;
   int ret;
   uint32_t bit_6_swizzle, tiling;

   region = _mesa_HashLookup(screen->named_regions, handle);
   if (region != NULL) {
      dummy = NULL;
      if (region->width != width || region->height != height ||
	  region->cpp != cpp || region->pitch != pitch) {
	 fprintf(stderr,
		 "Region for name %d already exists but is not compatible\n",
		 handle);
	 return NULL;
      }
      intel_region_reference(&dummy, region);
      return dummy;
   }

   buffer = intel_bo_gem_create_from_name(screen->bufmgr, name, handle);
   if (buffer == NULL)
      return NULL;
   ret = drm_intel_bo_get_tiling(buffer, &tiling, &bit_6_swizzle);
   if (ret != 0) {
      fprintf(stderr, "Couldn't get tiling of buffer %d (%s): %s\n",
	      handle, name, strerror(-ret));
      drm_intel_bo_unreference(buffer);
      return NULL;
   }

   region = intel_region_alloc_internal(screen, cpp,
					width, height, pitch, tiling, buffer);
   if (region == NULL) {
      drm_intel_bo_unreference(buffer);
      return NULL;
   }

   region->name = handle;
   _mesa_HashInsert(screen->named_regions, handle, region);

   return region;
}

void
intel_region_reference(struct intel_region **dst, struct intel_region *src)
{
   _DBG("%s: %p(%d) -> %p(%d)\n", __FUNCTION__,
	*dst, *dst ? (*dst)->refcount : 0, src, src ? src->refcount : 0);

   if (src != *dst) {
      if (*dst)
	 intel_region_release(dst);

      if (src)
         src->refcount++;
      *dst = src;
   }
}

void
intel_region_release(struct intel_region **region_handle)
{
   struct intel_region *region = *region_handle;

   if (region == NULL) {
      _DBG("%s NULL\n", __FUNCTION__);
      return;
   }

   _DBG("%s %p %d\n", __FUNCTION__, region, region->refcount - 1);

   ASSERT(region->refcount > 0);
   region->refcount--;

   if (region->refcount == 0) {
      assert(region->map_refcount == 0);

      drm_intel_bo_unreference(region->bo);

      if (region->name > 0)
	 _mesa_HashRemove(region->screen->named_regions, region->name);

      free(region);
   }
   *region_handle = NULL;
}

/*
 * XXX Move this into core Mesa?
 */
void
_mesa_copy_rect(GLubyte * dst,
                GLuint cpp,
                GLuint dst_pitch,
                GLuint dst_x,
                GLuint dst_y,
                GLuint width,
                GLuint height,
                const GLubyte * src,
                GLuint src_pitch, GLuint src_x, GLuint src_y)
{
   GLuint i;

   dst_pitch *= cpp;
   src_pitch *= cpp;
   dst += dst_x * cpp;
   src += src_x * cpp;
   dst += dst_y * dst_pitch;
   src += src_y * src_pitch;
   width *= cpp;

   if (width == dst_pitch && width == src_pitch)
      memcpy(dst, src, height * width);
   else {
      for (i = 0; i < height; i++) {
         memcpy(dst, src, width);
         dst += dst_pitch;
         src += src_pitch;
      }
   }
}


/* Upload data to a rectangular sub-region.  Lots of choices how to do this:
 *
 * - memcpy by span to current destination
 * - upload data as new buffer and blit
 *
 * Currently always memcpy.
 */
void
intel_region_data(struct intel_context *intel,
                  struct intel_region *dst,
                  GLuint dst_offset,
                  GLuint dstx, GLuint dsty,
                  const void *src, GLuint src_pitch,
                  GLuint srcx, GLuint srcy, GLuint width, GLuint height)
{
   _DBG("%s\n", __FUNCTION__);

   if (intel == NULL)
      return;

   intel_prepare_render(intel);

   _mesa_copy_rect(intel_region_map(intel, dst) + dst_offset,
                   dst->cpp,
                   dst->pitch,
                   dstx, dsty, width, height, src, src_pitch, srcx, srcy);

   intel_region_unmap(intel, dst);
}

/* Copy rectangular sub-regions. Need better logic about when to
 * push buffers into AGP - will currently do so whenever possible.
 */
GLboolean
intel_region_copy(struct intel_context *intel,
                  struct intel_region *dst,
                  GLuint dst_offset,
                  GLuint dstx, GLuint dsty,
                  struct intel_region *src,
                  GLuint src_offset,
                  GLuint srcx, GLuint srcy, GLuint width, GLuint height,
		  GLboolean flip,
		  GLenum logicop)
{
   uint32_t src_pitch = src->pitch;

   _DBG("%s\n", __FUNCTION__);

   if (intel == NULL)
      return GL_FALSE;

   assert(src->cpp == dst->cpp);

   if (flip)
      src_pitch = -src_pitch;

   return intelEmitCopyBlit(intel,
			    dst->cpp,
			    src_pitch, src->bo, src_offset, src->tiling,
			    dst->pitch, dst->bo, dst_offset, dst->tiling,
			    srcx, srcy, dstx, dsty, width, height,
			    logicop);
}
