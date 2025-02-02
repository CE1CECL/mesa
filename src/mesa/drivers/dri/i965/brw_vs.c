/*
 Copyright (C) Intel Corp.  2006.  All Rights Reserved.
 Intel funded Tungsten Graphics (http://www.tungstengraphics.com) to
 develop this 3D driver.
 
 Permission is hereby granted, free of charge, to any person obtaining
 a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including
 without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to
 the following conditions:
 
 The above copyright notice and this permission notice (including the
 next paragraph) shall be included in all copies or substantial
 portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
 LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 **********************************************************************/
 /*
  * Authors:
  *   Keith Whitwell <keith@tungstengraphics.com>
  */
           

#include "main/compiler.h"
#include "brw_context.h"
#include "brw_vs.h"
#include "brw_util.h"
#include "brw_state.h"
#include "program/prog_print.h"
#include "program/prog_parameter.h"

#include "glsl/ralloc.h"

static inline void assign_vue_slot(struct brw_vue_map *vue_map,
                                   int vert_result)
{
   /* Make sure this vert_result hasn't been assigned a slot already */
   assert (vue_map->vert_result_to_slot[vert_result] == -1);

   vue_map->vert_result_to_slot[vert_result] = vue_map->num_slots;
   vue_map->slot_to_vert_result[vue_map->num_slots++] = vert_result;
}

/**
 * Compute the VUE map for vertex shader program.
 */
void
brw_compute_vue_map(struct brw_vue_map *vue_map,
                    const struct intel_context *intel, int nr_userclip,
                    GLbitfield64 outputs_written)
{
   int i;

   vue_map->num_slots = 0;
   for (i = 0; i < BRW_VERT_RESULT_MAX; ++i) {
      vue_map->vert_result_to_slot[i] = -1;
      vue_map->slot_to_vert_result[i] = BRW_VERT_RESULT_MAX;
   }

   /* VUE header: format depends on chip generation and whether clipping is
    * enabled.
    */
   switch (intel->gen) {
   case 4:
      /* There are 8 dwords in VUE header pre-Ironlake:
       * dword 0-3 is indices, point width, clip flags.
       * dword 4-7 is ndc position
       * dword 8-11 is the first vertex data.
       */
      assign_vue_slot(vue_map, VERT_RESULT_PSIZ);
      assign_vue_slot(vue_map, BRW_VERT_RESULT_NDC);
      assign_vue_slot(vue_map, VERT_RESULT_HPOS);
      break;
   case 5:
      /* There are 20 DWs (D0-D19) in VUE header on Ironlake:
       * dword 0-3 of the header is indices, point width, clip flags.
       * dword 4-7 is the ndc position
       * dword 8-11 of the vertex header is the 4D space position
       * dword 12-19 of the vertex header is the user clip distance.
       * dword 20-23 is a pad so that the vertex element data is aligned
       * dword 24-27 is the first vertex data we fill.
       *
       * Note: future pipeline stages expect 4D space position to be
       * contiguous with the other vert_results, so we make dword 24-27 a
       * duplicate copy of the 4D space position.
       */
      assign_vue_slot(vue_map, VERT_RESULT_PSIZ);
      assign_vue_slot(vue_map, BRW_VERT_RESULT_NDC);
      assign_vue_slot(vue_map, BRW_VERT_RESULT_HPOS_DUPLICATE);
      assign_vue_slot(vue_map, VERT_RESULT_CLIP_DIST0);
      assign_vue_slot(vue_map, VERT_RESULT_CLIP_DIST1);
      assign_vue_slot(vue_map, BRW_VERT_RESULT_PAD);
      assign_vue_slot(vue_map, VERT_RESULT_HPOS);
      break;
   case 6:
   case 7:
      /* There are 8 or 16 DWs (D0-D15) in VUE header on Sandybridge:
       * dword 0-3 of the header is indices, point width, clip flags.
       * dword 4-7 is the 4D space position
       * dword 8-15 of the vertex header is the user clip distance if
       * enabled.
       * dword 8-11 or 16-19 is the first vertex element data we fill.
       */
      assign_vue_slot(vue_map, VERT_RESULT_PSIZ);
      assign_vue_slot(vue_map, VERT_RESULT_HPOS);
      if (nr_userclip) {
         assign_vue_slot(vue_map, VERT_RESULT_CLIP_DIST0);
         assign_vue_slot(vue_map, VERT_RESULT_CLIP_DIST1);
      }
      /* front and back colors need to be consecutive so that we can use
       * ATTRIBUTE_SWIZZLE_INPUTATTR_FACING to swizzle them when doing
       * two-sided color.
       */
      if (outputs_written & BITFIELD64_BIT(VERT_RESULT_COL0))
         assign_vue_slot(vue_map, VERT_RESULT_COL0);
      if (outputs_written & BITFIELD64_BIT(VERT_RESULT_BFC0))
         assign_vue_slot(vue_map, VERT_RESULT_BFC0);
      if (outputs_written & BITFIELD64_BIT(VERT_RESULT_COL1))
         assign_vue_slot(vue_map, VERT_RESULT_COL1);
      if (outputs_written & BITFIELD64_BIT(VERT_RESULT_BFC1))
         assign_vue_slot(vue_map, VERT_RESULT_BFC1);
      break;
   default:
      assert (!"VUE map not known for this chip generation");
      break;
   }

   /* The hardware doesn't care about the rest of the vertex outputs, so just
    * assign them contiguously.  Don't reassign outputs that already have a
    * slot.
    */
   for (int i = 0; i < VERT_RESULT_MAX; ++i) {
      if ((outputs_written & BITFIELD64_BIT(i)) &&
          vue_map->vert_result_to_slot[i] == -1) {
         assign_vue_slot(vue_map, i);
      }
   }
}

static bool
do_vs_prog(struct brw_context *brw,
	   struct gl_shader_program *prog,
	   struct brw_vertex_program *vp,
	   struct brw_vs_prog_key *key)
{
   struct gl_context *ctx = &brw->intel.ctx;
   struct intel_context *intel = &brw->intel;
   GLuint program_size;
   const GLuint *program;
   struct brw_vs_compile c;
   void *mem_ctx;
   int aux_size;
   int i;

   memset(&c, 0, sizeof(c));
   memcpy(&c.key, key, sizeof(*key));

   mem_ctx = ralloc_context(NULL);

   brw_init_compile(brw, &c.func, mem_ctx);
   c.vp = vp;

   c.prog_data.outputs_written = vp->program.Base.OutputsWritten;
   c.prog_data.inputs_read = vp->program.Base.InputsRead;

   if (c.key.copy_edgeflag) {
      c.prog_data.outputs_written |= BITFIELD64_BIT(VERT_RESULT_EDGE);
      c.prog_data.inputs_read |= 1<<VERT_ATTRIB_EDGEFLAG;
   }

   /* Put dummy slots into the VUE for the SF to put the replaced
    * point sprite coords in.  We shouldn't need these dummy slots,
    * which take up precious URB space, but it would mean that the SF
    * doesn't get nice aligned pairs of input coords into output
    * coords, which would be a pain to handle.
    */
   for (i = 0; i < 8; i++) {
      if (c.key.point_coord_replace & (1 << i))
	 c.prog_data.outputs_written |= BITFIELD64_BIT(VERT_RESULT_TEX0 + i);
   }

   if (0) {
      _mesa_fprint_program_opt(stdout, &c.vp->program.Base, PROG_PRINT_DEBUG,
			       GL_TRUE);
   }

   /* Emit GEN4 code.
    */
   if (brw->new_vs_backend && prog) {
      if (!brw_vs_emit(prog, &c)) {
	 ralloc_free(mem_ctx);
	 return false;
      }
   } else {
      brw_old_vs_emit(&c);
   }

   /* Scratch space is used for register spilling */
   if (c.last_scratch) {
      c.prog_data.total_scratch = brw_get_scratch_size(c.last_scratch);

      brw_get_scratch_bo(intel, &brw->vs.scratch_bo,
			 c.prog_data.total_scratch * brw->vs_max_threads);
   }

   /* get the program
    */
   program = brw_get_program(&c.func, &program_size);

   /* We upload from &c.prog_data including the constant_map assuming
    * they're packed together.  It would be nice to have a
    * compile-time assert macro here.
    */
   assert(c.constant_map == (int8_t *)&c.prog_data +
	  sizeof(c.prog_data));
   assert(ctx->Const.VertexProgram.MaxNativeParameters ==
	  ARRAY_SIZE(c.constant_map));
   (void) ctx;

   aux_size = sizeof(c.prog_data);
   /* constant_map */
   aux_size += c.vp->program.Base.Parameters->NumParameters;

   brw_upload_cache(&brw->cache, BRW_VS_PROG,
		    &c.key, sizeof(c.key),
		    program, program_size,
		    &c.prog_data, aux_size,
		    &brw->vs.prog_offset, &brw->vs.prog_data);
   ralloc_free(mem_ctx);

   return true;
}


static void brw_upload_vs_prog(struct brw_context *brw)
{
   struct gl_context *ctx = &brw->intel.ctx;
   struct brw_vs_prog_key key;
   struct brw_vertex_program *vp = 
      (struct brw_vertex_program *)brw->vertex_program;
   int i;

   memset(&key, 0, sizeof(key));

   /* Just upload the program verbatim for now.  Always send it all
    * the inputs it asks for, whether they are varying or not.
    */
   key.program_string_id = vp->id;
   key.nr_userclip = brw_count_bits(ctx->Transform.ClipPlanesEnabled);
   key.uses_clip_distance = vp->program.UsesClipDistance;
   key.copy_edgeflag = (ctx->Polygon.FrontMode != GL_FILL ||
			ctx->Polygon.BackMode != GL_FILL);

   /* _NEW_LIGHT | _NEW_BUFFERS */
   key.clamp_vertex_color = ctx->Light._ClampVertexColor;

   /* _NEW_POINT */
   if (ctx->Point.PointSprite) {
      for (i = 0; i < 8; i++) {
	 if (ctx->Point.CoordReplace[i])
	    key.point_coord_replace |= (1 << i);
      }
   }

   /* BRW_NEW_VERTICES */
   for (i = 0; i < VERT_ATTRIB_MAX; i++) {
      if (vp->program.Base.InputsRead & (1 << i) &&
	  brw->vb.inputs[i].glarray->Type == GL_FIXED) {
	 key.gl_fixed_input_size[i] = brw->vb.inputs[i].glarray->Size;
      }
   }

   if (!brw_search_cache(&brw->cache, BRW_VS_PROG,
			 &key, sizeof(key),
			 &brw->vs.prog_offset, &brw->vs.prog_data)) {
      bool success = do_vs_prog(brw, ctx->Shader.CurrentVertexProgram,
				vp, &key);

      assert(success);
   }
   brw->vs.constant_map = ((int8_t *)brw->vs.prog_data +
			   sizeof(*brw->vs.prog_data));
}

/* See brw_vs.c:
 */
const struct brw_tracked_state brw_vs_prog = {
   .dirty = {
      .mesa  = (_NEW_TRANSFORM | _NEW_POLYGON | _NEW_POINT | _NEW_LIGHT |
		_NEW_BUFFERS),
      .brw   = (BRW_NEW_VERTEX_PROGRAM |
		BRW_NEW_VERTICES),
      .cache = 0
   },
   .prepare = brw_upload_vs_prog
};

bool
brw_vs_precompile(struct gl_context *ctx, struct gl_shader_program *prog)
{
   struct brw_context *brw = brw_context(ctx);
   struct brw_vs_prog_key key;
   struct gl_vertex_program *vp = prog->VertexProgram;
   struct brw_vertex_program *bvp = brw_vertex_program(vp);
   uint32_t old_prog_offset = brw->vs.prog_offset;
   struct brw_vs_prog_data *old_prog_data = brw->vs.prog_data;
   bool success;

   if (!vp)
      return true;

   memset(&key, 0, sizeof(key));

   key.program_string_id = bvp->id;
   key.clamp_vertex_color = true;

   success = do_vs_prog(brw, prog, bvp, &key);

   brw->vs.prog_offset = old_prog_offset;
   brw->vs.prog_data = old_prog_data;

   return success;
}
