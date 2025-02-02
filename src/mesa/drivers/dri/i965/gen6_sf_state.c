/*
 * Copyright © 2009 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Authors:
 *    Eric Anholt <eric@anholt.net>
 *
 */

#include "brw_context.h"
#include "brw_state.h"
#include "brw_defines.h"
#include "brw_util.h"
#include "main/macros.h"
#include "intel_batchbuffer.h"

/**
 * Determine the appropriate attribute override value to store into the
 * 3DSTATE_SF structure for a given fragment shader attribute.  The attribute
 * override value contains two pieces of information: the location of the
 * attribute in the VUE (relative to urb_entry_read_offset, see below), and a
 * flag indicating whether to "swizzle" the attribute based on the direction
 * the triangle is facing.
 *
 * If an attribute is "swizzled", then the given VUE location is used for
 * front-facing triangles, and the VUE location that immediately follows is
 * used for back-facing triangles.  We use this to implement the mapping from
 * gl_FrontColor/gl_BackColor to gl_Color.
 *
 * urb_entry_read_offset is the offset into the VUE at which the SF unit is
 * being instructed to begin reading attribute data.  It can be set to a
 * nonzero value to prevent the SF unit from wasting time reading elements of
 * the VUE that are not needed by the fragment shader.  It is measured in
 * 256-bit increments.
 */
uint32_t
get_attr_override(struct brw_vue_map *vue_map, int urb_entry_read_offset,
                  int fs_attr, bool two_side_color)
{
   int attr_override, slot;
   int vs_attr = _mesa_frag_attrib_to_vert_result(fs_attr);
   if (vs_attr < 0 || vs_attr == VERT_RESULT_HPOS) {
      /* These attributes will be overwritten by the fragment shader's
       * interpolation code (see emit_interp() in brw_wm_fp.c), so just let
       * them reference the first available attribute.
       */
      return 0;
   }

   /* Find the VUE slot for this attribute. */
   slot = vue_map->vert_result_to_slot[vs_attr];

   /* If there was only a back color written but not front, use back
    * as the color instead of undefined
    */
   if (slot == -1 && vs_attr == VERT_RESULT_COL0)
      slot = vue_map->vert_result_to_slot[VERT_RESULT_BFC0];
   if (slot == -1 && vs_attr == VERT_RESULT_COL1)
      slot = vue_map->vert_result_to_slot[VERT_RESULT_BFC1];

   if (slot == -1) {
      /* This attribute does not exist in the VUE--that means that the vertex
       * shader did not write to it.  Behavior is undefined in this case, so
       * just reference the first available attribute.
       */
      return 0;
   }

   /* Compute the location of the attribute relative to urb_entry_read_offset.
    * Each increment of urb_entry_read_offset represents a 256-bit value, so
    * it counts for two 128-bit VUE slots.
    */
   attr_override = slot - 2 * urb_entry_read_offset;
   assert (attr_override >= 0 && attr_override < 32);

   /* If we are doing two-sided color, and the VUE slot following this one
    * represents a back-facing color, then we need to instruct the SF unit to
    * do back-facing swizzling.
    */
   if (two_side_color) {
      if (vue_map->slot_to_vert_result[slot] == VERT_RESULT_COL0 &&
          vue_map->slot_to_vert_result[slot+1] == VERT_RESULT_BFC0)
         attr_override |= (ATTRIBUTE_SWIZZLE_INPUTATTR_FACING << ATTRIBUTE_SWIZZLE_SHIFT);
      else if (vue_map->slot_to_vert_result[slot] == VERT_RESULT_COL1 &&
               vue_map->slot_to_vert_result[slot+1] == VERT_RESULT_BFC1)
         attr_override |= (ATTRIBUTE_SWIZZLE_INPUTATTR_FACING << ATTRIBUTE_SWIZZLE_SHIFT);
   }

   return attr_override;
}

static void
upload_sf_state(struct brw_context *brw)
{
   struct intel_context *intel = &brw->intel;
   struct gl_context *ctx = &intel->ctx;
   struct brw_vue_map vue_map;
   uint32_t urb_entry_read_length;
   /* CACHE_NEW_VS_PROG */
   GLbitfield64 vs_outputs_written = brw->vs.prog_data->outputs_written;
   /* BRW_NEW_FRAGMENT_PROGRAM */
   uint32_t num_outputs = brw_count_bits(brw->fragment_program->Base.InputsRead);
   uint32_t dw1, dw2, dw3, dw4, dw16, dw17;
   int i;
   /* _NEW_BUFFER */
   GLboolean render_to_fbo = brw->intel.ctx.DrawBuffer->Name != 0;
   int attr = 0, input_index = 0;
   int urb_entry_read_offset = 1;
   float point_size;
   uint16_t attr_overrides[FRAG_ATTRIB_MAX];
   int nr_userclip;

   /* _NEW_TRANSFORM */
   nr_userclip = brw_count_bits(ctx->Transform.ClipPlanesEnabled);

   brw_compute_vue_map(&vue_map, intel, nr_userclip, vs_outputs_written);
   urb_entry_read_length = (vue_map.num_slots + 1)/2 - urb_entry_read_offset;
   if (urb_entry_read_length == 0) {
      /* Setting the URB entry read length to 0 causes undefined behavior, so
       * if we have no URB data to read, set it to 1.
       */
      urb_entry_read_length = 1;
   }

   dw1 =
      GEN6_SF_SWIZZLE_ENABLE |
      num_outputs << GEN6_SF_NUM_OUTPUTS_SHIFT |
      urb_entry_read_length << GEN6_SF_URB_ENTRY_READ_LENGTH_SHIFT |
      urb_entry_read_offset << GEN6_SF_URB_ENTRY_READ_OFFSET_SHIFT;
   dw2 = GEN6_SF_VIEWPORT_TRANSFORM_ENABLE |
      GEN6_SF_STATISTICS_ENABLE;
   dw3 = 0;
   dw4 = 0;
   dw16 = 0;
   dw17 = 0;

   /* _NEW_POLYGON */
   if ((ctx->Polygon.FrontFace == GL_CCW) ^ render_to_fbo)
      dw2 |= GEN6_SF_WINDING_CCW;

   if (ctx->Polygon.OffsetFill)
       dw2 |= GEN6_SF_GLOBAL_DEPTH_OFFSET_SOLID;

   if (ctx->Polygon.OffsetLine)
       dw2 |= GEN6_SF_GLOBAL_DEPTH_OFFSET_WIREFRAME;

   if (ctx->Polygon.OffsetPoint)
       dw2 |= GEN6_SF_GLOBAL_DEPTH_OFFSET_POINT;

   switch (ctx->Polygon.FrontMode) {
   case GL_FILL:
       dw2 |= GEN6_SF_FRONT_SOLID;
       break;

   case GL_LINE:
       dw2 |= GEN6_SF_FRONT_WIREFRAME;
       break;

   case GL_POINT:
       dw2 |= GEN6_SF_FRONT_POINT;
       break;

   default:
       assert(0);
       break;
   }

   switch (ctx->Polygon.BackMode) {
   case GL_FILL:
       dw2 |= GEN6_SF_BACK_SOLID;
       break;

   case GL_LINE:
       dw2 |= GEN6_SF_BACK_WIREFRAME;
       break;

   case GL_POINT:
       dw2 |= GEN6_SF_BACK_POINT;
       break;

   default:
       assert(0);
       break;
   }

   /* _NEW_SCISSOR */
   if (ctx->Scissor.Enabled)
      dw3 |= GEN6_SF_SCISSOR_ENABLE;

   /* _NEW_POLYGON */
   if (ctx->Polygon.CullFlag) {
      switch (ctx->Polygon.CullFaceMode) {
      case GL_FRONT:
	 dw3 |= GEN6_SF_CULL_FRONT;
	 break;
      case GL_BACK:
	 dw3 |= GEN6_SF_CULL_BACK;
	 break;
      case GL_FRONT_AND_BACK:
	 dw3 |= GEN6_SF_CULL_BOTH;
	 break;
      default:
	 assert(0);
	 break;
      }
   } else {
      dw3 |= GEN6_SF_CULL_NONE;
   }

   /* _NEW_LINE */
   dw3 |= U_FIXED(CLAMP(ctx->Line.Width, 0.0, 7.99), 7) <<
      GEN6_SF_LINE_WIDTH_SHIFT;
   if (ctx->Line.SmoothFlag) {
      dw3 |= GEN6_SF_LINE_AA_ENABLE;
      dw3 |= GEN6_SF_LINE_AA_MODE_TRUE;
      dw3 |= GEN6_SF_LINE_END_CAP_WIDTH_1_0;
   }

   /* _NEW_POINT */
   if (!(ctx->VertexProgram.PointSizeEnabled ||
	 ctx->Point._Attenuated))
      dw4 |= GEN6_SF_USE_STATE_POINT_WIDTH;

   /* Clamp to ARB_point_parameters user limits */
   point_size = CLAMP(ctx->Point.Size, ctx->Point.MinSize, ctx->Point.MaxSize);

   /* Clamp to the hardware limits and convert to fixed point */
   dw4 |= U_FIXED(CLAMP(point_size, 0.125, 255.875), 3);

   if (ctx->Point.SpriteOrigin == GL_LOWER_LEFT)
      dw1 |= GEN6_SF_POINT_SPRITE_LOWERLEFT;

   /* _NEW_LIGHT */
   if (ctx->Light.ProvokingVertex != GL_FIRST_VERTEX_CONVENTION) {
      dw4 |=
	 (2 << GEN6_SF_TRI_PROVOKE_SHIFT) |
	 (2 << GEN6_SF_TRIFAN_PROVOKE_SHIFT) |
	 (1 << GEN6_SF_LINE_PROVOKE_SHIFT);
   } else {
      dw4 |=
	 (1 << GEN6_SF_TRIFAN_PROVOKE_SHIFT);
   }

   /* Create the mapping from the FS inputs we produce to the VS outputs
    * they source from.
    */
   for (; attr < FRAG_ATTRIB_MAX; attr++) {
      if (!(brw->fragment_program->Base.InputsRead & BITFIELD64_BIT(attr)))
	 continue;

      /* _NEW_POINT */
      if (ctx->Point.PointSprite &&
	  (attr >= FRAG_ATTRIB_TEX0 && attr <= FRAG_ATTRIB_TEX7) &&
	  ctx->Point.CoordReplace[attr - FRAG_ATTRIB_TEX0]) {
	 dw16 |= (1 << input_index);
      }

      if (attr == FRAG_ATTRIB_PNTC)
	 dw16 |= (1 << input_index);

      /* flat shading */
      if (ctx->Light.ShadeModel == GL_FLAT) {
         /*
          * Setup the Constant Interpolation Enable bit mask for each
          * corresponding attribute(currently, we only care two attrs:
          * FRAG_BIT_COL0 and FRAG_BIT_COL1).
          *
          * FIXME: should we care other attributes?
          */
	  if (attr == FRAG_ATTRIB_COL0 || attr == FRAG_ATTRIB_COL1)
             dw17 |= (1 << input_index);
      }

      /* The hardware can only do the overrides on 16 overrides at a
       * time, and the other up to 16 have to be lined up so that the
       * input index = the output index.  We'll need to do some
       * tweaking to make sure that's the case.
       */
      assert(input_index < 16 || attr == input_index);

      /* _NEW_LIGHT | _NEW_PROGRAM */
      attr_overrides[input_index++] =
         get_attr_override(&vue_map, urb_entry_read_offset, attr,
                           ctx->VertexProgram._TwoSideEnabled);
   }

   for (; input_index < FRAG_ATTRIB_MAX; input_index++)
      attr_overrides[input_index] = 0;

   BEGIN_BATCH(20);
   OUT_BATCH(_3DSTATE_SF << 16 | (20 - 2));
   OUT_BATCH(dw1);
   OUT_BATCH(dw2);
   OUT_BATCH(dw3);
   OUT_BATCH(dw4);
   OUT_BATCH_F(ctx->Polygon.OffsetUnits * 2); /* constant.  copied from gen4 */
   OUT_BATCH_F(ctx->Polygon.OffsetFactor); /* scale */
   OUT_BATCH_F(0.0); /* XXX: global depth offset clamp */
   for (i = 0; i < 8; i++) {
      OUT_BATCH(attr_overrides[i * 2] | attr_overrides[i * 2 + 1] << 16);
   }
   OUT_BATCH(dw16); /* point sprite texcoord bitmask */
   OUT_BATCH(dw17); /* constant interp bitmask */
   OUT_BATCH(0); /* wrapshortest enables 0-7 */
   OUT_BATCH(0); /* wrapshortest enables 8-15 */
   ADVANCE_BATCH();
}

const struct brw_tracked_state gen6_sf_state = {
   .dirty = {
      .mesa  = (_NEW_LIGHT |
		_NEW_PROGRAM |
		_NEW_POLYGON |
		_NEW_LINE |
		_NEW_SCISSOR |
		_NEW_BUFFERS |
		_NEW_POINT |
		_NEW_TRANSFORM),
      .brw   = (BRW_NEW_CONTEXT |
		BRW_NEW_FRAGMENT_PROGRAM),
      .cache = CACHE_NEW_VS_PROG
   },
   .emit = upload_sf_state,
};
