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
            

#ifndef BRW_VS_H
#define BRW_VS_H


#include "brw_context.h"
#include "brw_eu.h"
#include "program/program.h"


struct brw_vs_prog_key {
   GLuint program_string_id;
   /**
    * Number of channels of the vertex attribute that need GL_FIXED rescaling
    */
   uint8_t gl_fixed_input_size[VERT_ATTRIB_MAX];
   GLuint nr_userclip:4;
   GLuint copy_edgeflag:1;
   GLuint point_coord_replace:8;
   GLuint clamp_vertex_color:1;
   GLuint uses_clip_distance:1;
};


struct brw_vs_compile {
   struct brw_compile func;
   struct brw_vs_prog_key key;
   struct brw_vs_prog_data prog_data;
   int8_t constant_map[1024];

   struct brw_vertex_program *vp;

   GLuint nr_inputs;

   struct brw_vue_map vue_map;
   GLuint first_output;
   GLuint last_scratch;

   GLuint first_tmp;
   GLuint last_tmp;

   struct brw_reg r0;
   struct brw_reg r1;
   struct brw_reg regs[PROGRAM_ADDRESS+1][128];
   struct brw_reg tmp;
   struct brw_reg stack;

   struct {	
       GLboolean used_in_src;
       struct brw_reg reg;
   } output_regs[128];

   struct brw_reg userplane[MAX_CLIP_PLANES];

   /** we may need up to 3 constants per instruction (if use_const_buffer) */
   struct {
      GLint index;
      struct brw_reg reg;
   } current_const[3];

   GLboolean needs_stack;
};

bool brw_vs_emit(struct gl_shader_program *prog, struct brw_vs_compile *c);
void brw_old_vs_emit(struct brw_vs_compile *c);
bool brw_vs_precompile(struct gl_context *ctx, struct gl_shader_program *prog);

#endif
