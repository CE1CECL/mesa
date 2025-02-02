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
 

#ifndef BRW_GS_H
#define BRW_GS_H


#include "brw_context.h"
#include "brw_eu.h"

#define MAX_GS_VERTS (4)	     

struct brw_gs_prog_key {
   GLbitfield64 attrs;
   GLuint primitive:4;
   GLuint pv_first:1;
   GLuint need_gs_prog:1;
   GLuint nr_userclip:4;
   GLuint pad:22;
};

struct brw_gs_compile {
   struct brw_compile func;
   struct brw_gs_prog_key key;
   struct brw_gs_prog_data prog_data;
   
   struct {
      struct brw_reg R0;
      struct brw_reg vertex[MAX_GS_VERTS];
      struct brw_reg temp;
   } reg;

   /* Number of registers used to store vertex data */
   GLuint nr_regs;
};

#define ATTR_SIZE  (4*4)

void brw_gs_quads( struct brw_gs_compile *c, struct brw_gs_prog_key *key );
void brw_gs_quad_strip( struct brw_gs_compile *c, struct brw_gs_prog_key *key );
void brw_gs_lines( struct brw_gs_compile *c );

#endif
