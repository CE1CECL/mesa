/* DO NOT EDIT - This file generated automatically by gl_procs.py (from Mesa) script */

/*
 * Copyright (C) 1999-2001  Brian Paul   All Rights Reserved.
 * (C) Copyright IBM Corporation 2004, 2006
 * All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.  IN NO EVENT SHALL
 * BRIAN PAUL, IBM,
 * AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


/* This file is only included by glapi.c and is used for
 * the GetProcAddress() function
 */

typedef struct {
    GLint Name_offset;
#if defined(NEED_FUNCTION_POINTER) || defined(GLX_INDIRECT_RENDERING)
    _glapi_proc Address;
#endif
    GLuint Offset;
} glprocs_table_t;

#if   !defined(NEED_FUNCTION_POINTER) && !defined(GLX_INDIRECT_RENDERING)
#  define NAME_FUNC_OFFSET(n,f1,f2,f3,o) { n , o }
#elif  defined(NEED_FUNCTION_POINTER) && !defined(GLX_INDIRECT_RENDERING)
#  define NAME_FUNC_OFFSET(n,f1,f2,f3,o) { n , (_glapi_proc) f1 , o }
#elif  defined(NEED_FUNCTION_POINTER) &&  defined(GLX_INDIRECT_RENDERING)
#  define NAME_FUNC_OFFSET(n,f1,f2,f3,o) { n , (_glapi_proc) f2 , o }
#elif !defined(NEED_FUNCTION_POINTER) &&  defined(GLX_INDIRECT_RENDERING)
#  define NAME_FUNC_OFFSET(n,f1,f2,f3,o) { n , (_glapi_proc) f3 , o }
#endif



static const char gl_string_table[] =
    "glNewList\0"
    "glEndList\0"
    "glCallList\0"
    "glCallLists\0"
    "glDeleteLists\0"
    "glGenLists\0"
    "glListBase\0"
    "glBegin\0"
    "glBitmap\0"
    "glColor3b\0"
    "glColor3bv\0"
    "glColor3d\0"
    "glColor3dv\0"
    "glColor3f\0"
    "glColor3fv\0"
    "glColor3i\0"
    "glColor3iv\0"
    "glColor3s\0"
    "glColor3sv\0"
    "glColor3ub\0"
    "glColor3ubv\0"
    "glColor3ui\0"
    "glColor3uiv\0"
    "glColor3us\0"
    "glColor3usv\0"
    "glColor4b\0"
    "glColor4bv\0"
    "glColor4d\0"
    "glColor4dv\0"
    "glColor4f\0"
    "glColor4fv\0"
    "glColor4i\0"
    "glColor4iv\0"
    "glColor4s\0"
    "glColor4sv\0"
    "glColor4ub\0"
    "glColor4ubv\0"
    "glColor4ui\0"
    "glColor4uiv\0"
    "glColor4us\0"
    "glColor4usv\0"
    "glEdgeFlag\0"
    "glEdgeFlagv\0"
    "glEnd\0"
    "glIndexd\0"
    "glIndexdv\0"
    "glIndexf\0"
    "glIndexfv\0"
    "glIndexi\0"
    "glIndexiv\0"
    "glIndexs\0"
    "glIndexsv\0"
    "glNormal3b\0"
    "glNormal3bv\0"
    "glNormal3d\0"
    "glNormal3dv\0"
    "glNormal3f\0"
    "glNormal3fv\0"
    "glNormal3i\0"
    "glNormal3iv\0"
    "glNormal3s\0"
    "glNormal3sv\0"
    "glRasterPos2d\0"
    "glRasterPos2dv\0"
    "glRasterPos2f\0"
    "glRasterPos2fv\0"
    "glRasterPos2i\0"
    "glRasterPos2iv\0"
    "glRasterPos2s\0"
    "glRasterPos2sv\0"
    "glRasterPos3d\0"
    "glRasterPos3dv\0"
    "glRasterPos3f\0"
    "glRasterPos3fv\0"
    "glRasterPos3i\0"
    "glRasterPos3iv\0"
    "glRasterPos3s\0"
    "glRasterPos3sv\0"
    "glRasterPos4d\0"
    "glRasterPos4dv\0"
    "glRasterPos4f\0"
    "glRasterPos4fv\0"
    "glRasterPos4i\0"
    "glRasterPos4iv\0"
    "glRasterPos4s\0"
    "glRasterPos4sv\0"
    "glRectd\0"
    "glRectdv\0"
    "glRectf\0"
    "glRectfv\0"
    "glRecti\0"
    "glRectiv\0"
    "glRects\0"
    "glRectsv\0"
    "glTexCoord1d\0"
    "glTexCoord1dv\0"
    "glTexCoord1f\0"
    "glTexCoord1fv\0"
    "glTexCoord1i\0"
    "glTexCoord1iv\0"
    "glTexCoord1s\0"
    "glTexCoord1sv\0"
    "glTexCoord2d\0"
    "glTexCoord2dv\0"
    "glTexCoord2f\0"
    "glTexCoord2fv\0"
    "glTexCoord2i\0"
    "glTexCoord2iv\0"
    "glTexCoord2s\0"
    "glTexCoord2sv\0"
    "glTexCoord3d\0"
    "glTexCoord3dv\0"
    "glTexCoord3f\0"
    "glTexCoord3fv\0"
    "glTexCoord3i\0"
    "glTexCoord3iv\0"
    "glTexCoord3s\0"
    "glTexCoord3sv\0"
    "glTexCoord4d\0"
    "glTexCoord4dv\0"
    "glTexCoord4f\0"
    "glTexCoord4fv\0"
    "glTexCoord4i\0"
    "glTexCoord4iv\0"
    "glTexCoord4s\0"
    "glTexCoord4sv\0"
    "glVertex2d\0"
    "glVertex2dv\0"
    "glVertex2f\0"
    "glVertex2fv\0"
    "glVertex2i\0"
    "glVertex2iv\0"
    "glVertex2s\0"
    "glVertex2sv\0"
    "glVertex3d\0"
    "glVertex3dv\0"
    "glVertex3f\0"
    "glVertex3fv\0"
    "glVertex3i\0"
    "glVertex3iv\0"
    "glVertex3s\0"
    "glVertex3sv\0"
    "glVertex4d\0"
    "glVertex4dv\0"
    "glVertex4f\0"
    "glVertex4fv\0"
    "glVertex4i\0"
    "glVertex4iv\0"
    "glVertex4s\0"
    "glVertex4sv\0"
    "glClipPlane\0"
    "glColorMaterial\0"
    "glCullFace\0"
    "glFogf\0"
    "glFogfv\0"
    "glFogi\0"
    "glFogiv\0"
    "glFrontFace\0"
    "glHint\0"
    "glLightf\0"
    "glLightfv\0"
    "glLighti\0"
    "glLightiv\0"
    "glLightModelf\0"
    "glLightModelfv\0"
    "glLightModeli\0"
    "glLightModeliv\0"
    "glLineStipple\0"
    "glLineWidth\0"
    "glMaterialf\0"
    "glMaterialfv\0"
    "glMateriali\0"
    "glMaterialiv\0"
    "glPointSize\0"
    "glPolygonMode\0"
    "glPolygonStipple\0"
    "glScissor\0"
    "glShadeModel\0"
    "glTexParameterf\0"
    "glTexParameterfv\0"
    "glTexParameteri\0"
    "glTexParameteriv\0"
    "glTexImage1D\0"
    "glTexImage2D\0"
    "glTexEnvf\0"
    "glTexEnvfv\0"
    "glTexEnvi\0"
    "glTexEnviv\0"
    "glTexGend\0"
    "glTexGendv\0"
    "glTexGenf\0"
    "glTexGenfv\0"
    "glTexGeni\0"
    "glTexGeniv\0"
    "glFeedbackBuffer\0"
    "glSelectBuffer\0"
    "glRenderMode\0"
    "glInitNames\0"
    "glLoadName\0"
    "glPassThrough\0"
    "glPopName\0"
    "glPushName\0"
    "glDrawBuffer\0"
    "glClear\0"
    "glClearAccum\0"
    "glClearIndex\0"
    "glClearColor\0"
    "glClearStencil\0"
    "glClearDepth\0"
    "glStencilMask\0"
    "glColorMask\0"
    "glDepthMask\0"
    "glIndexMask\0"
    "glAccum\0"
    "glDisable\0"
    "glEnable\0"
    "glFinish\0"
    "glFlush\0"
    "glPopAttrib\0"
    "glPushAttrib\0"
    "glMap1d\0"
    "glMap1f\0"
    "glMap2d\0"
    "glMap2f\0"
    "glMapGrid1d\0"
    "glMapGrid1f\0"
    "glMapGrid2d\0"
    "glMapGrid2f\0"
    "glEvalCoord1d\0"
    "glEvalCoord1dv\0"
    "glEvalCoord1f\0"
    "glEvalCoord1fv\0"
    "glEvalCoord2d\0"
    "glEvalCoord2dv\0"
    "glEvalCoord2f\0"
    "glEvalCoord2fv\0"
    "glEvalMesh1\0"
    "glEvalPoint1\0"
    "glEvalMesh2\0"
    "glEvalPoint2\0"
    "glAlphaFunc\0"
    "glBlendFunc\0"
    "glLogicOp\0"
    "glStencilFunc\0"
    "glStencilOp\0"
    "glDepthFunc\0"
    "glPixelZoom\0"
    "glPixelTransferf\0"
    "glPixelTransferi\0"
    "glPixelStoref\0"
    "glPixelStorei\0"
    "glPixelMapfv\0"
    "glPixelMapuiv\0"
    "glPixelMapusv\0"
    "glReadBuffer\0"
    "glCopyPixels\0"
    "glReadPixels\0"
    "glDrawPixels\0"
    "glGetBooleanv\0"
    "glGetClipPlane\0"
    "glGetDoublev\0"
    "glGetError\0"
    "glGetFloatv\0"
    "glGetIntegerv\0"
    "glGetLightfv\0"
    "glGetLightiv\0"
    "glGetMapdv\0"
    "glGetMapfv\0"
    "glGetMapiv\0"
    "glGetMaterialfv\0"
    "glGetMaterialiv\0"
    "glGetPixelMapfv\0"
    "glGetPixelMapuiv\0"
    "glGetPixelMapusv\0"
    "glGetPolygonStipple\0"
    "glGetString\0"
    "glGetTexEnvfv\0"
    "glGetTexEnviv\0"
    "glGetTexGendv\0"
    "glGetTexGenfv\0"
    "glGetTexGeniv\0"
    "glGetTexImage\0"
    "glGetTexParameterfv\0"
    "glGetTexParameteriv\0"
    "glGetTexLevelParameterfv\0"
    "glGetTexLevelParameteriv\0"
    "glIsEnabled\0"
    "glIsList\0"
    "glDepthRange\0"
    "glFrustum\0"
    "glLoadIdentity\0"
    "glLoadMatrixf\0"
    "glLoadMatrixd\0"
    "glMatrixMode\0"
    "glMultMatrixf\0"
    "glMultMatrixd\0"
    "glOrtho\0"
    "glPopMatrix\0"
    "glPushMatrix\0"
    "glRotated\0"
    "glRotatef\0"
    "glScaled\0"
    "glScalef\0"
    "glTranslated\0"
    "glTranslatef\0"
    "glViewport\0"
    "glArrayElement\0"
    "glBindTexture\0"
    "glColorPointer\0"
    "glDisableClientState\0"
    "glDrawArrays\0"
    "glDrawElements\0"
    "glEdgeFlagPointer\0"
    "glEnableClientState\0"
    "glIndexPointer\0"
    "glIndexub\0"
    "glIndexubv\0"
    "glInterleavedArrays\0"
    "glNormalPointer\0"
    "glPolygonOffset\0"
    "glTexCoordPointer\0"
    "glVertexPointer\0"
    "glAreTexturesResident\0"
    "glCopyTexImage1D\0"
    "glCopyTexImage2D\0"
    "glCopyTexSubImage1D\0"
    "glCopyTexSubImage2D\0"
    "glDeleteTextures\0"
    "glGenTextures\0"
    "glGetPointerv\0"
    "glIsTexture\0"
    "glPrioritizeTextures\0"
    "glTexSubImage1D\0"
    "glTexSubImage2D\0"
    "glPopClientAttrib\0"
    "glPushClientAttrib\0"
    "glBlendColor\0"
    "glBlendEquation\0"
    "glDrawRangeElements\0"
    "glColorTable\0"
    "glColorTableParameterfv\0"
    "glColorTableParameteriv\0"
    "glCopyColorTable\0"
    "glGetColorTable\0"
    "glGetColorTableParameterfv\0"
    "glGetColorTableParameteriv\0"
    "glColorSubTable\0"
    "glCopyColorSubTable\0"
    "glConvolutionFilter1D\0"
    "glConvolutionFilter2D\0"
    "glConvolutionParameterf\0"
    "glConvolutionParameterfv\0"
    "glConvolutionParameteri\0"
    "glConvolutionParameteriv\0"
    "glCopyConvolutionFilter1D\0"
    "glCopyConvolutionFilter2D\0"
    "glGetConvolutionFilter\0"
    "glGetConvolutionParameterfv\0"
    "glGetConvolutionParameteriv\0"
    "glGetSeparableFilter\0"
    "glSeparableFilter2D\0"
    "glGetHistogram\0"
    "glGetHistogramParameterfv\0"
    "glGetHistogramParameteriv\0"
    "glGetMinmax\0"
    "glGetMinmaxParameterfv\0"
    "glGetMinmaxParameteriv\0"
    "glHistogram\0"
    "glMinmax\0"
    "glResetHistogram\0"
    "glResetMinmax\0"
    "glTexImage3D\0"
    "glTexSubImage3D\0"
    "glCopyTexSubImage3D\0"
    "glActiveTextureARB\0"
    "glClientActiveTextureARB\0"
    "glMultiTexCoord1dARB\0"
    "glMultiTexCoord1dvARB\0"
    "glMultiTexCoord1fARB\0"
    "glMultiTexCoord1fvARB\0"
    "glMultiTexCoord1iARB\0"
    "glMultiTexCoord1ivARB\0"
    "glMultiTexCoord1sARB\0"
    "glMultiTexCoord1svARB\0"
    "glMultiTexCoord2dARB\0"
    "glMultiTexCoord2dvARB\0"
    "glMultiTexCoord2fARB\0"
    "glMultiTexCoord2fvARB\0"
    "glMultiTexCoord2iARB\0"
    "glMultiTexCoord2ivARB\0"
    "glMultiTexCoord2sARB\0"
    "glMultiTexCoord2svARB\0"
    "glMultiTexCoord3dARB\0"
    "glMultiTexCoord3dvARB\0"
    "glMultiTexCoord3fARB\0"
    "glMultiTexCoord3fvARB\0"
    "glMultiTexCoord3iARB\0"
    "glMultiTexCoord3ivARB\0"
    "glMultiTexCoord3sARB\0"
    "glMultiTexCoord3svARB\0"
    "glMultiTexCoord4dARB\0"
    "glMultiTexCoord4dvARB\0"
    "glMultiTexCoord4fARB\0"
    "glMultiTexCoord4fvARB\0"
    "glMultiTexCoord4iARB\0"
    "glMultiTexCoord4ivARB\0"
    "glMultiTexCoord4sARB\0"
    "glMultiTexCoord4svARB\0"
    "glAttachShader\0"
    "glCreateProgram\0"
    "glCreateShader\0"
    "glDeleteProgram\0"
    "glDeleteShader\0"
    "glDetachShader\0"
    "glGetAttachedShaders\0"
    "glGetProgramInfoLog\0"
    "glGetProgramiv\0"
    "glGetShaderInfoLog\0"
    "glGetShaderiv\0"
    "glIsProgram\0"
    "glIsShader\0"
    "glStencilFuncSeparate\0"
    "glStencilMaskSeparate\0"
    "glStencilOpSeparate\0"
    "glUniformMatrix2x3fv\0"
    "glUniformMatrix2x4fv\0"
    "glUniformMatrix3x2fv\0"
    "glUniformMatrix3x4fv\0"
    "glUniformMatrix4x2fv\0"
    "glUniformMatrix4x3fv\0"
    "glClampColor\0"
    "glClearBufferfi\0"
    "glClearBufferfv\0"
    "glClearBufferiv\0"
    "glClearBufferuiv\0"
    "glGetStringi\0"
    "glTexBuffer\0"
    "glFramebufferTexture\0"
    "glGetBufferParameteri64v\0"
    "glGetInteger64i_v\0"
    "glVertexAttribDivisor\0"
    "glLoadTransposeMatrixdARB\0"
    "glLoadTransposeMatrixfARB\0"
    "glMultTransposeMatrixdARB\0"
    "glMultTransposeMatrixfARB\0"
    "glSampleCoverageARB\0"
    "glCompressedTexImage1DARB\0"
    "glCompressedTexImage2DARB\0"
    "glCompressedTexImage3DARB\0"
    "glCompressedTexSubImage1DARB\0"
    "glCompressedTexSubImage2DARB\0"
    "glCompressedTexSubImage3DARB\0"
    "glGetCompressedTexImageARB\0"
    "glDisableVertexAttribArrayARB\0"
    "glEnableVertexAttribArrayARB\0"
    "glGetProgramEnvParameterdvARB\0"
    "glGetProgramEnvParameterfvARB\0"
    "glGetProgramLocalParameterdvARB\0"
    "glGetProgramLocalParameterfvARB\0"
    "glGetProgramStringARB\0"
    "glGetProgramivARB\0"
    "glGetVertexAttribdvARB\0"
    "glGetVertexAttribfvARB\0"
    "glGetVertexAttribivARB\0"
    "glProgramEnvParameter4dARB\0"
    "glProgramEnvParameter4dvARB\0"
    "glProgramEnvParameter4fARB\0"
    "glProgramEnvParameter4fvARB\0"
    "glProgramLocalParameter4dARB\0"
    "glProgramLocalParameter4dvARB\0"
    "glProgramLocalParameter4fARB\0"
    "glProgramLocalParameter4fvARB\0"
    "glProgramStringARB\0"
    "glVertexAttrib1dARB\0"
    "glVertexAttrib1dvARB\0"
    "glVertexAttrib1fARB\0"
    "glVertexAttrib1fvARB\0"
    "glVertexAttrib1sARB\0"
    "glVertexAttrib1svARB\0"
    "glVertexAttrib2dARB\0"
    "glVertexAttrib2dvARB\0"
    "glVertexAttrib2fARB\0"
    "glVertexAttrib2fvARB\0"
    "glVertexAttrib2sARB\0"
    "glVertexAttrib2svARB\0"
    "glVertexAttrib3dARB\0"
    "glVertexAttrib3dvARB\0"
    "glVertexAttrib3fARB\0"
    "glVertexAttrib3fvARB\0"
    "glVertexAttrib3sARB\0"
    "glVertexAttrib3svARB\0"
    "glVertexAttrib4NbvARB\0"
    "glVertexAttrib4NivARB\0"
    "glVertexAttrib4NsvARB\0"
    "glVertexAttrib4NubARB\0"
    "glVertexAttrib4NubvARB\0"
    "glVertexAttrib4NuivARB\0"
    "glVertexAttrib4NusvARB\0"
    "glVertexAttrib4bvARB\0"
    "glVertexAttrib4dARB\0"
    "glVertexAttrib4dvARB\0"
    "glVertexAttrib4fARB\0"
    "glVertexAttrib4fvARB\0"
    "glVertexAttrib4ivARB\0"
    "glVertexAttrib4sARB\0"
    "glVertexAttrib4svARB\0"
    "glVertexAttrib4ubvARB\0"
    "glVertexAttrib4uivARB\0"
    "glVertexAttrib4usvARB\0"
    "glVertexAttribPointerARB\0"
    "glBindBufferARB\0"
    "glBufferDataARB\0"
    "glBufferSubDataARB\0"
    "glDeleteBuffersARB\0"
    "glGenBuffersARB\0"
    "glGetBufferParameterivARB\0"
    "glGetBufferPointervARB\0"
    "glGetBufferSubDataARB\0"
    "glIsBufferARB\0"
    "glMapBufferARB\0"
    "glUnmapBufferARB\0"
    "glBeginQueryARB\0"
    "glDeleteQueriesARB\0"
    "glEndQueryARB\0"
    "glGenQueriesARB\0"
    "glGetQueryObjectivARB\0"
    "glGetQueryObjectuivARB\0"
    "glGetQueryivARB\0"
    "glIsQueryARB\0"
    "glAttachObjectARB\0"
    "glCompileShaderARB\0"
    "glCreateProgramObjectARB\0"
    "glCreateShaderObjectARB\0"
    "glDeleteObjectARB\0"
    "glDetachObjectARB\0"
    "glGetActiveUniformARB\0"
    "glGetAttachedObjectsARB\0"
    "glGetHandleARB\0"
    "glGetInfoLogARB\0"
    "glGetObjectParameterfvARB\0"
    "glGetObjectParameterivARB\0"
    "glGetShaderSourceARB\0"
    "glGetUniformLocationARB\0"
    "glGetUniformfvARB\0"
    "glGetUniformivARB\0"
    "glLinkProgramARB\0"
    "glShaderSourceARB\0"
    "glUniform1fARB\0"
    "glUniform1fvARB\0"
    "glUniform1iARB\0"
    "glUniform1ivARB\0"
    "glUniform2fARB\0"
    "glUniform2fvARB\0"
    "glUniform2iARB\0"
    "glUniform2ivARB\0"
    "glUniform3fARB\0"
    "glUniform3fvARB\0"
    "glUniform3iARB\0"
    "glUniform3ivARB\0"
    "glUniform4fARB\0"
    "glUniform4fvARB\0"
    "glUniform4iARB\0"
    "glUniform4ivARB\0"
    "glUniformMatrix2fvARB\0"
    "glUniformMatrix3fvARB\0"
    "glUniformMatrix4fvARB\0"
    "glUseProgramObjectARB\0"
    "glValidateProgramARB\0"
    "glBindAttribLocationARB\0"
    "glGetActiveAttribARB\0"
    "glGetAttribLocationARB\0"
    "glDrawBuffersARB\0"
    "glClampColorARB\0"
    "glDrawArraysInstancedARB\0"
    "glDrawElementsInstancedARB\0"
    "glRenderbufferStorageMultisample\0"
    "glFramebufferTextureARB\0"
    "glFramebufferTextureFaceARB\0"
    "glProgramParameteriARB\0"
    "glVertexAttribDivisorARB\0"
    "glFlushMappedBufferRange\0"
    "glMapBufferRange\0"
    "glTexBufferARB\0"
    "glBindVertexArray\0"
    "glGenVertexArrays\0"
    "glCopyBufferSubData\0"
    "glClientWaitSync\0"
    "glDeleteSync\0"
    "glFenceSync\0"
    "glGetInteger64v\0"
    "glGetSynciv\0"
    "glIsSync\0"
    "glWaitSync\0"
    "glDrawElementsBaseVertex\0"
    "glDrawElementsInstancedBaseVertex\0"
    "glDrawRangeElementsBaseVertex\0"
    "glMultiDrawElementsBaseVertex\0"
    "glBlendEquationSeparateiARB\0"
    "glBlendEquationiARB\0"
    "glBlendFuncSeparateiARB\0"
    "glBlendFunciARB\0"
    "glBindSampler\0"
    "glDeleteSamplers\0"
    "glGenSamplers\0"
    "glGetSamplerParameterIiv\0"
    "glGetSamplerParameterIuiv\0"
    "glGetSamplerParameterfv\0"
    "glGetSamplerParameteriv\0"
    "glIsSampler\0"
    "glSamplerParameterIiv\0"
    "glSamplerParameterIuiv\0"
    "glSamplerParameterf\0"
    "glSamplerParameterfv\0"
    "glSamplerParameteri\0"
    "glSamplerParameteriv\0"
    "glColorP3ui\0"
    "glColorP3uiv\0"
    "glColorP4ui\0"
    "glColorP4uiv\0"
    "glMultiTexCoordP1ui\0"
    "glMultiTexCoordP1uiv\0"
    "glMultiTexCoordP2ui\0"
    "glMultiTexCoordP2uiv\0"
    "glMultiTexCoordP3ui\0"
    "glMultiTexCoordP3uiv\0"
    "glMultiTexCoordP4ui\0"
    "glMultiTexCoordP4uiv\0"
    "glNormalP3ui\0"
    "glNormalP3uiv\0"
    "glSecondaryColorP3ui\0"
    "glSecondaryColorP3uiv\0"
    "glTexCoordP1ui\0"
    "glTexCoordP1uiv\0"
    "glTexCoordP2ui\0"
    "glTexCoordP2uiv\0"
    "glTexCoordP3ui\0"
    "glTexCoordP3uiv\0"
    "glTexCoordP4ui\0"
    "glTexCoordP4uiv\0"
    "glVertexAttribP1ui\0"
    "glVertexAttribP1uiv\0"
    "glVertexAttribP2ui\0"
    "glVertexAttribP2uiv\0"
    "glVertexAttribP3ui\0"
    "glVertexAttribP3uiv\0"
    "glVertexAttribP4ui\0"
    "glVertexAttribP4uiv\0"
    "glVertexP2ui\0"
    "glVertexP2uiv\0"
    "glVertexP3ui\0"
    "glVertexP3uiv\0"
    "glVertexP4ui\0"
    "glVertexP4uiv\0"
    "glBindTransformFeedback\0"
    "glDeleteTransformFeedbacks\0"
    "glDrawTransformFeedback\0"
    "glGenTransformFeedbacks\0"
    "glIsTransformFeedback\0"
    "glPauseTransformFeedback\0"
    "glResumeTransformFeedback\0"
    "glClearDepthf\0"
    "glDepthRangef\0"
    "glGetShaderPrecisionFormat\0"
    "glReleaseShaderCompiler\0"
    "glShaderBinary\0"
    "glGetGraphicsResetStatusARB\0"
    "glGetnColorTableARB\0"
    "glGetnCompressedTexImageARB\0"
    "glGetnConvolutionFilterARB\0"
    "glGetnHistogramARB\0"
    "glGetnMapdvARB\0"
    "glGetnMapfvARB\0"
    "glGetnMapivARB\0"
    "glGetnMinmaxARB\0"
    "glGetnPixelMapfvARB\0"
    "glGetnPixelMapuivARB\0"
    "glGetnPixelMapusvARB\0"
    "glGetnPolygonStippleARB\0"
    "glGetnSeparableFilterARB\0"
    "glGetnTexImageARB\0"
    "glGetnUniformdvARB\0"
    "glGetnUniformfvARB\0"
    "glGetnUniformivARB\0"
    "glGetnUniformuivARB\0"
    "glReadnPixelsARB\0"
    "glPolygonOffsetEXT\0"
    "glGetPixelTexGenParameterfvSGIS\0"
    "glGetPixelTexGenParameterivSGIS\0"
    "glPixelTexGenParameterfSGIS\0"
    "glPixelTexGenParameterfvSGIS\0"
    "glPixelTexGenParameteriSGIS\0"
    "glPixelTexGenParameterivSGIS\0"
    "glSampleMaskSGIS\0"
    "glSamplePatternSGIS\0"
    "glColorPointerEXT\0"
    "glEdgeFlagPointerEXT\0"
    "glIndexPointerEXT\0"
    "glNormalPointerEXT\0"
    "glTexCoordPointerEXT\0"
    "glVertexPointerEXT\0"
    "glPointParameterfEXT\0"
    "glPointParameterfvEXT\0"
    "glLockArraysEXT\0"
    "glUnlockArraysEXT\0"
    "glSecondaryColor3bEXT\0"
    "glSecondaryColor3bvEXT\0"
    "glSecondaryColor3dEXT\0"
    "glSecondaryColor3dvEXT\0"
    "glSecondaryColor3fEXT\0"
    "glSecondaryColor3fvEXT\0"
    "glSecondaryColor3iEXT\0"
    "glSecondaryColor3ivEXT\0"
    "glSecondaryColor3sEXT\0"
    "glSecondaryColor3svEXT\0"
    "glSecondaryColor3ubEXT\0"
    "glSecondaryColor3ubvEXT\0"
    "glSecondaryColor3uiEXT\0"
    "glSecondaryColor3uivEXT\0"
    "glSecondaryColor3usEXT\0"
    "glSecondaryColor3usvEXT\0"
    "glSecondaryColorPointerEXT\0"
    "glMultiDrawArraysEXT\0"
    "glMultiDrawElementsEXT\0"
    "glFogCoordPointerEXT\0"
    "glFogCoorddEXT\0"
    "glFogCoorddvEXT\0"
    "glFogCoordfEXT\0"
    "glFogCoordfvEXT\0"
    "glPixelTexGenSGIX\0"
    "glBlendFuncSeparateEXT\0"
    "glFlushVertexArrayRangeNV\0"
    "glVertexArrayRangeNV\0"
    "glCombinerInputNV\0"
    "glCombinerOutputNV\0"
    "glCombinerParameterfNV\0"
    "glCombinerParameterfvNV\0"
    "glCombinerParameteriNV\0"
    "glCombinerParameterivNV\0"
    "glFinalCombinerInputNV\0"
    "glGetCombinerInputParameterfvNV\0"
    "glGetCombinerInputParameterivNV\0"
    "glGetCombinerOutputParameterfvNV\0"
    "glGetCombinerOutputParameterivNV\0"
    "glGetFinalCombinerInputParameterfvNV\0"
    "glGetFinalCombinerInputParameterivNV\0"
    "glResizeBuffersMESA\0"
    "glWindowPos2dMESA\0"
    "glWindowPos2dvMESA\0"
    "glWindowPos2fMESA\0"
    "glWindowPos2fvMESA\0"
    "glWindowPos2iMESA\0"
    "glWindowPos2ivMESA\0"
    "glWindowPos2sMESA\0"
    "glWindowPos2svMESA\0"
    "glWindowPos3dMESA\0"
    "glWindowPos3dvMESA\0"
    "glWindowPos3fMESA\0"
    "glWindowPos3fvMESA\0"
    "glWindowPos3iMESA\0"
    "glWindowPos3ivMESA\0"
    "glWindowPos3sMESA\0"
    "glWindowPos3svMESA\0"
    "glWindowPos4dMESA\0"
    "glWindowPos4dvMESA\0"
    "glWindowPos4fMESA\0"
    "glWindowPos4fvMESA\0"
    "glWindowPos4iMESA\0"
    "glWindowPos4ivMESA\0"
    "glWindowPos4sMESA\0"
    "glWindowPos4svMESA\0"
    "glMultiModeDrawArraysIBM\0"
    "glMultiModeDrawElementsIBM\0"
    "glDeleteFencesNV\0"
    "glFinishFenceNV\0"
    "glGenFencesNV\0"
    "glGetFenceivNV\0"
    "glIsFenceNV\0"
    "glSetFenceNV\0"
    "glTestFenceNV\0"
    "glAreProgramsResidentNV\0"
    "glBindProgramNV\0"
    "glDeleteProgramsNV\0"
    "glExecuteProgramNV\0"
    "glGenProgramsNV\0"
    "glGetProgramParameterdvNV\0"
    "glGetProgramParameterfvNV\0"
    "glGetProgramStringNV\0"
    "glGetProgramivNV\0"
    "glGetTrackMatrixivNV\0"
    "glGetVertexAttribPointervNV\0"
    "glGetVertexAttribdvNV\0"
    "glGetVertexAttribfvNV\0"
    "glGetVertexAttribivNV\0"
    "glIsProgramNV\0"
    "glLoadProgramNV\0"
    "glProgramParameters4dvNV\0"
    "glProgramParameters4fvNV\0"
    "glRequestResidentProgramsNV\0"
    "glTrackMatrixNV\0"
    "glVertexAttrib1dNV\0"
    "glVertexAttrib1dvNV\0"
    "glVertexAttrib1fNV\0"
    "glVertexAttrib1fvNV\0"
    "glVertexAttrib1sNV\0"
    "glVertexAttrib1svNV\0"
    "glVertexAttrib2dNV\0"
    "glVertexAttrib2dvNV\0"
    "glVertexAttrib2fNV\0"
    "glVertexAttrib2fvNV\0"
    "glVertexAttrib2sNV\0"
    "glVertexAttrib2svNV\0"
    "glVertexAttrib3dNV\0"
    "glVertexAttrib3dvNV\0"
    "glVertexAttrib3fNV\0"
    "glVertexAttrib3fvNV\0"
    "glVertexAttrib3sNV\0"
    "glVertexAttrib3svNV\0"
    "glVertexAttrib4dNV\0"
    "glVertexAttrib4dvNV\0"
    "glVertexAttrib4fNV\0"
    "glVertexAttrib4fvNV\0"
    "glVertexAttrib4sNV\0"
    "glVertexAttrib4svNV\0"
    "glVertexAttrib4ubNV\0"
    "glVertexAttrib4ubvNV\0"
    "glVertexAttribPointerNV\0"
    "glVertexAttribs1dvNV\0"
    "glVertexAttribs1fvNV\0"
    "glVertexAttribs1svNV\0"
    "glVertexAttribs2dvNV\0"
    "glVertexAttribs2fvNV\0"
    "glVertexAttribs2svNV\0"
    "glVertexAttribs3dvNV\0"
    "glVertexAttribs3fvNV\0"
    "glVertexAttribs3svNV\0"
    "glVertexAttribs4dvNV\0"
    "glVertexAttribs4fvNV\0"
    "glVertexAttribs4svNV\0"
    "glVertexAttribs4ubvNV\0"
    "glGetTexBumpParameterfvATI\0"
    "glGetTexBumpParameterivATI\0"
    "glTexBumpParameterfvATI\0"
    "glTexBumpParameterivATI\0"
    "glAlphaFragmentOp1ATI\0"
    "glAlphaFragmentOp2ATI\0"
    "glAlphaFragmentOp3ATI\0"
    "glBeginFragmentShaderATI\0"
    "glBindFragmentShaderATI\0"
    "glColorFragmentOp1ATI\0"
    "glColorFragmentOp2ATI\0"
    "glColorFragmentOp3ATI\0"
    "glDeleteFragmentShaderATI\0"
    "glEndFragmentShaderATI\0"
    "glGenFragmentShadersATI\0"
    "glPassTexCoordATI\0"
    "glSampleMapATI\0"
    "glSetFragmentShaderConstantATI\0"
    "glPointParameteriNV\0"
    "glPointParameterivNV\0"
    "glActiveStencilFaceEXT\0"
    "glBindVertexArrayAPPLE\0"
    "glDeleteVertexArraysAPPLE\0"
    "glGenVertexArraysAPPLE\0"
    "glIsVertexArrayAPPLE\0"
    "glGetProgramNamedParameterdvNV\0"
    "glGetProgramNamedParameterfvNV\0"
    "glProgramNamedParameter4dNV\0"
    "glProgramNamedParameter4dvNV\0"
    "glProgramNamedParameter4fNV\0"
    "glProgramNamedParameter4fvNV\0"
    "glPrimitiveRestartIndexNV\0"
    "glPrimitiveRestartNV\0"
    "glDepthBoundsEXT\0"
    "glBlendEquationSeparateEXT\0"
    "glBindFramebufferEXT\0"
    "glBindRenderbufferEXT\0"
    "glCheckFramebufferStatusEXT\0"
    "glDeleteFramebuffersEXT\0"
    "glDeleteRenderbuffersEXT\0"
    "glFramebufferRenderbufferEXT\0"
    "glFramebufferTexture1DEXT\0"
    "glFramebufferTexture2DEXT\0"
    "glFramebufferTexture3DEXT\0"
    "glGenFramebuffersEXT\0"
    "glGenRenderbuffersEXT\0"
    "glGenerateMipmapEXT\0"
    "glGetFramebufferAttachmentParameterivEXT\0"
    "glGetRenderbufferParameterivEXT\0"
    "glIsFramebufferEXT\0"
    "glIsRenderbufferEXT\0"
    "glRenderbufferStorageEXT\0"
    "glBlitFramebufferEXT\0"
    "glBufferParameteriAPPLE\0"
    "glFlushMappedBufferRangeAPPLE\0"
    "glBindFragDataLocationEXT\0"
    "glGetFragDataLocationEXT\0"
    "glGetUniformuivEXT\0"
    "glGetVertexAttribIivEXT\0"
    "glGetVertexAttribIuivEXT\0"
    "glUniform1uiEXT\0"
    "glUniform1uivEXT\0"
    "glUniform2uiEXT\0"
    "glUniform2uivEXT\0"
    "glUniform3uiEXT\0"
    "glUniform3uivEXT\0"
    "glUniform4uiEXT\0"
    "glUniform4uivEXT\0"
    "glVertexAttribI1iEXT\0"
    "glVertexAttribI1ivEXT\0"
    "glVertexAttribI1uiEXT\0"
    "glVertexAttribI1uivEXT\0"
    "glVertexAttribI2iEXT\0"
    "glVertexAttribI2ivEXT\0"
    "glVertexAttribI2uiEXT\0"
    "glVertexAttribI2uivEXT\0"
    "glVertexAttribI3iEXT\0"
    "glVertexAttribI3ivEXT\0"
    "glVertexAttribI3uiEXT\0"
    "glVertexAttribI3uivEXT\0"
    "glVertexAttribI4bvEXT\0"
    "glVertexAttribI4iEXT\0"
    "glVertexAttribI4ivEXT\0"
    "glVertexAttribI4svEXT\0"
    "glVertexAttribI4ubvEXT\0"
    "glVertexAttribI4uiEXT\0"
    "glVertexAttribI4uivEXT\0"
    "glVertexAttribI4usvEXT\0"
    "glVertexAttribIPointerEXT\0"
    "glFramebufferTextureLayerEXT\0"
    "glColorMaskIndexedEXT\0"
    "glDisableIndexedEXT\0"
    "glEnableIndexedEXT\0"
    "glGetBooleanIndexedvEXT\0"
    "glGetIntegerIndexedvEXT\0"
    "glIsEnabledIndexedEXT\0"
    "glClearColorIiEXT\0"
    "glClearColorIuiEXT\0"
    "glGetTexParameterIivEXT\0"
    "glGetTexParameterIuivEXT\0"
    "glTexParameterIivEXT\0"
    "glTexParameterIuivEXT\0"
    "glBeginConditionalRenderNV\0"
    "glEndConditionalRenderNV\0"
    "glBeginTransformFeedbackEXT\0"
    "glBindBufferBaseEXT\0"
    "glBindBufferOffsetEXT\0"
    "glBindBufferRangeEXT\0"
    "glEndTransformFeedbackEXT\0"
    "glGetTransformFeedbackVaryingEXT\0"
    "glTransformFeedbackVaryingsEXT\0"
    "glProvokingVertexEXT\0"
    "glGetTexParameterPointervAPPLE\0"
    "glTextureRangeAPPLE\0"
    "glGetObjectParameterivAPPLE\0"
    "glObjectPurgeableAPPLE\0"
    "glObjectUnpurgeableAPPLE\0"
    "glActiveProgramEXT\0"
    "glCreateShaderProgramEXT\0"
    "glUseShaderProgramEXT\0"
    "glTextureBarrierNV\0"
    "glStencilFuncSeparateATI\0"
    "glProgramEnvParameters4fvEXT\0"
    "glProgramLocalParameters4fvEXT\0"
    "glGetQueryObjecti64vEXT\0"
    "glGetQueryObjectui64vEXT\0"
    "glEGLImageTargetRenderbufferStorageOES\0"
    "glEGLImageTargetTexture2DOES\0"
    "glArrayElementEXT\0"
    "glBindTextureEXT\0"
    "glDrawArraysEXT\0"
    "glAreTexturesResidentEXT\0"
    "glCopyTexImage1DEXT\0"
    "glCopyTexImage2DEXT\0"
    "glCopyTexSubImage1DEXT\0"
    "glCopyTexSubImage2DEXT\0"
    "glDeleteTexturesEXT\0"
    "glGenTexturesEXT\0"
    "glGetPointervEXT\0"
    "glIsTextureEXT\0"
    "glPrioritizeTexturesEXT\0"
    "glTexSubImage1DEXT\0"
    "glTexSubImage2DEXT\0"
    "glBlendColorEXT\0"
    "glBlendEquationEXT\0"
    "glDrawRangeElementsEXT\0"
    "glColorTableSGI\0"
    "glColorTableEXT\0"
    "glColorTableParameterfvSGI\0"
    "glColorTableParameterivSGI\0"
    "glCopyColorTableSGI\0"
    "glGetColorTableSGI\0"
    "glGetColorTableEXT\0"
    "glGetColorTableParameterfvSGI\0"
    "glGetColorTableParameterfvEXT\0"
    "glGetColorTableParameterivSGI\0"
    "glGetColorTableParameterivEXT\0"
    "glColorSubTableEXT\0"
    "glCopyColorSubTableEXT\0"
    "glConvolutionFilter1DEXT\0"
    "glConvolutionFilter2DEXT\0"
    "glConvolutionParameterfEXT\0"
    "glConvolutionParameterfvEXT\0"
    "glConvolutionParameteriEXT\0"
    "glConvolutionParameterivEXT\0"
    "glCopyConvolutionFilter1DEXT\0"
    "glCopyConvolutionFilter2DEXT\0"
    "glGetConvolutionFilterEXT\0"
    "glGetConvolutionParameterfvEXT\0"
    "glGetConvolutionParameterivEXT\0"
    "glGetSeparableFilterEXT\0"
    "glSeparableFilter2DEXT\0"
    "glGetHistogramEXT\0"
    "glGetHistogramParameterfvEXT\0"
    "glGetHistogramParameterivEXT\0"
    "glGetMinmaxEXT\0"
    "glGetMinmaxParameterfvEXT\0"
    "glGetMinmaxParameterivEXT\0"
    "glHistogramEXT\0"
    "glMinmaxEXT\0"
    "glResetHistogramEXT\0"
    "glResetMinmaxEXT\0"
    "glTexImage3DEXT\0"
    "glTexSubImage3DEXT\0"
    "glCopyTexSubImage3DEXT\0"
    "glActiveTexture\0"
    "glClientActiveTexture\0"
    "glMultiTexCoord1d\0"
    "glMultiTexCoord1dv\0"
    "glMultiTexCoord1f\0"
    "glMultiTexCoord1fv\0"
    "glMultiTexCoord1i\0"
    "glMultiTexCoord1iv\0"
    "glMultiTexCoord1s\0"
    "glMultiTexCoord1sv\0"
    "glMultiTexCoord2d\0"
    "glMultiTexCoord2dv\0"
    "glMultiTexCoord2f\0"
    "glMultiTexCoord2fv\0"
    "glMultiTexCoord2i\0"
    "glMultiTexCoord2iv\0"
    "glMultiTexCoord2s\0"
    "glMultiTexCoord2sv\0"
    "glMultiTexCoord3d\0"
    "glMultiTexCoord3dv\0"
    "glMultiTexCoord3f\0"
    "glMultiTexCoord3fv\0"
    "glMultiTexCoord3i\0"
    "glMultiTexCoord3iv\0"
    "glMultiTexCoord3s\0"
    "glMultiTexCoord3sv\0"
    "glMultiTexCoord4d\0"
    "glMultiTexCoord4dv\0"
    "glMultiTexCoord4f\0"
    "glMultiTexCoord4fv\0"
    "glMultiTexCoord4i\0"
    "glMultiTexCoord4iv\0"
    "glMultiTexCoord4s\0"
    "glMultiTexCoord4sv\0"
    "glStencilOpSeparateATI\0"
    "glLoadTransposeMatrixd\0"
    "glLoadTransposeMatrixf\0"
    "glMultTransposeMatrixd\0"
    "glMultTransposeMatrixf\0"
    "glSampleCoverage\0"
    "glCompressedTexImage1D\0"
    "glCompressedTexImage2D\0"
    "glCompressedTexImage3D\0"
    "glCompressedTexSubImage1D\0"
    "glCompressedTexSubImage2D\0"
    "glCompressedTexSubImage3D\0"
    "glGetCompressedTexImage\0"
    "glDisableVertexAttribArray\0"
    "glEnableVertexAttribArray\0"
    "glGetVertexAttribdv\0"
    "glGetVertexAttribfv\0"
    "glGetVertexAttribiv\0"
    "glProgramParameter4dNV\0"
    "glProgramParameter4dvNV\0"
    "glProgramParameter4fNV\0"
    "glProgramParameter4fvNV\0"
    "glVertexAttrib1d\0"
    "glVertexAttrib1dv\0"
    "glVertexAttrib1f\0"
    "glVertexAttrib1fv\0"
    "glVertexAttrib1s\0"
    "glVertexAttrib1sv\0"
    "glVertexAttrib2d\0"
    "glVertexAttrib2dv\0"
    "glVertexAttrib2f\0"
    "glVertexAttrib2fv\0"
    "glVertexAttrib2s\0"
    "glVertexAttrib2sv\0"
    "glVertexAttrib3d\0"
    "glVertexAttrib3dv\0"
    "glVertexAttrib3f\0"
    "glVertexAttrib3fv\0"
    "glVertexAttrib3s\0"
    "glVertexAttrib3sv\0"
    "glVertexAttrib4Nbv\0"
    "glVertexAttrib4Niv\0"
    "glVertexAttrib4Nsv\0"
    "glVertexAttrib4Nub\0"
    "glVertexAttrib4Nubv\0"
    "glVertexAttrib4Nuiv\0"
    "glVertexAttrib4Nusv\0"
    "glVertexAttrib4bv\0"
    "glVertexAttrib4d\0"
    "glVertexAttrib4dv\0"
    "glVertexAttrib4f\0"
    "glVertexAttrib4fv\0"
    "glVertexAttrib4iv\0"
    "glVertexAttrib4s\0"
    "glVertexAttrib4sv\0"
    "glVertexAttrib4ubv\0"
    "glVertexAttrib4uiv\0"
    "glVertexAttrib4usv\0"
    "glVertexAttribPointer\0"
    "glBindBuffer\0"
    "glBufferData\0"
    "glBufferSubData\0"
    "glDeleteBuffers\0"
    "glGenBuffers\0"
    "glGetBufferParameteriv\0"
    "glGetBufferPointerv\0"
    "glGetBufferSubData\0"
    "glIsBuffer\0"
    "glMapBuffer\0"
    "glUnmapBuffer\0"
    "glBeginQuery\0"
    "glDeleteQueries\0"
    "glEndQuery\0"
    "glGenQueries\0"
    "glGetQueryObjectiv\0"
    "glGetQueryObjectuiv\0"
    "glGetQueryiv\0"
    "glIsQuery\0"
    "glCompileShader\0"
    "glGetActiveUniform\0"
    "glGetShaderSource\0"
    "glGetUniformLocation\0"
    "glGetUniformfv\0"
    "glGetUniformiv\0"
    "glLinkProgram\0"
    "glShaderSource\0"
    "glUniform1f\0"
    "glUniform1fv\0"
    "glUniform1i\0"
    "glUniform1iv\0"
    "glUniform2f\0"
    "glUniform2fv\0"
    "glUniform2i\0"
    "glUniform2iv\0"
    "glUniform3f\0"
    "glUniform3fv\0"
    "glUniform3i\0"
    "glUniform3iv\0"
    "glUniform4f\0"
    "glUniform4fv\0"
    "glUniform4i\0"
    "glUniform4iv\0"
    "glUniformMatrix2fv\0"
    "glUniformMatrix3fv\0"
    "glUniformMatrix4fv\0"
    "glUseProgram\0"
    "glValidateProgram\0"
    "glBindAttribLocation\0"
    "glGetActiveAttrib\0"
    "glGetAttribLocation\0"
    "glDrawBuffers\0"
    "glDrawBuffersATI\0"
    "glDrawArraysInstancedEXT\0"
    "glDrawArraysInstanced\0"
    "glDrawElementsInstancedEXT\0"
    "glDrawElementsInstanced\0"
    "glRenderbufferStorageMultisampleEXT\0"
    "glBlendEquationSeparateIndexedAMD\0"
    "glBlendEquationIndexedAMD\0"
    "glBlendFuncSeparateIndexedAMD\0"
    "glBlendFuncIndexedAMD\0"
    "glSampleMaskEXT\0"
    "glSamplePatternEXT\0"
    "glPointParameterf\0"
    "glPointParameterfARB\0"
    "glPointParameterfSGIS\0"
    "glPointParameterfv\0"
    "glPointParameterfvARB\0"
    "glPointParameterfvSGIS\0"
    "glSecondaryColor3b\0"
    "glSecondaryColor3bv\0"
    "glSecondaryColor3d\0"
    "glSecondaryColor3dv\0"
    "glSecondaryColor3f\0"
    "glSecondaryColor3fv\0"
    "glSecondaryColor3i\0"
    "glSecondaryColor3iv\0"
    "glSecondaryColor3s\0"
    "glSecondaryColor3sv\0"
    "glSecondaryColor3ub\0"
    "glSecondaryColor3ubv\0"
    "glSecondaryColor3ui\0"
    "glSecondaryColor3uiv\0"
    "glSecondaryColor3us\0"
    "glSecondaryColor3usv\0"
    "glSecondaryColorPointer\0"
    "glMultiDrawArrays\0"
    "glMultiDrawElements\0"
    "glFogCoordPointer\0"
    "glFogCoordd\0"
    "glFogCoorddv\0"
    "glFogCoordf\0"
    "glFogCoordfv\0"
    "glBlendFuncSeparate\0"
    "glBlendFuncSeparateINGR\0"
    "glWindowPos2d\0"
    "glWindowPos2dARB\0"
    "glWindowPos2dv\0"
    "glWindowPos2dvARB\0"
    "glWindowPos2f\0"
    "glWindowPos2fARB\0"
    "glWindowPos2fv\0"
    "glWindowPos2fvARB\0"
    "glWindowPos2i\0"
    "glWindowPos2iARB\0"
    "glWindowPos2iv\0"
    "glWindowPos2ivARB\0"
    "glWindowPos2s\0"
    "glWindowPos2sARB\0"
    "glWindowPos2sv\0"
    "glWindowPos2svARB\0"
    "glWindowPos3d\0"
    "glWindowPos3dARB\0"
    "glWindowPos3dv\0"
    "glWindowPos3dvARB\0"
    "glWindowPos3f\0"
    "glWindowPos3fARB\0"
    "glWindowPos3fv\0"
    "glWindowPos3fvARB\0"
    "glWindowPos3i\0"
    "glWindowPos3iARB\0"
    "glWindowPos3iv\0"
    "glWindowPos3ivARB\0"
    "glWindowPos3s\0"
    "glWindowPos3sARB\0"
    "glWindowPos3sv\0"
    "glWindowPos3svARB\0"
    "glBindProgramARB\0"
    "glDeleteProgramsARB\0"
    "glGenProgramsARB\0"
    "glGetVertexAttribPointerv\0"
    "glGetVertexAttribPointervARB\0"
    "glIsProgramARB\0"
    "glPointParameteri\0"
    "glPointParameteriv\0"
    "glDeleteVertexArrays\0"
    "glIsVertexArray\0"
    "glPrimitiveRestartIndex\0"
    "glBlendEquationSeparate\0"
    "glBlendEquationSeparateATI\0"
    "glBindFramebuffer\0"
    "glBindRenderbuffer\0"
    "glCheckFramebufferStatus\0"
    "glDeleteFramebuffers\0"
    "glDeleteRenderbuffers\0"
    "glFramebufferRenderbuffer\0"
    "glFramebufferTexture1D\0"
    "glFramebufferTexture2D\0"
    "glFramebufferTexture3D\0"
    "glGenFramebuffers\0"
    "glGenRenderbuffers\0"
    "glGenerateMipmap\0"
    "glGetFramebufferAttachmentParameteriv\0"
    "glGetRenderbufferParameteriv\0"
    "glIsFramebuffer\0"
    "glIsRenderbuffer\0"
    "glRenderbufferStorage\0"
    "glBlitFramebuffer\0"
    "glBindFragDataLocation\0"
    "glGetFragDataLocation\0"
    "glGetUniformuiv\0"
    "glGetVertexAttribIiv\0"
    "glGetVertexAttribIuiv\0"
    "glUniform1ui\0"
    "glUniform1uiv\0"
    "glUniform2ui\0"
    "glUniform2uiv\0"
    "glUniform3ui\0"
    "glUniform3uiv\0"
    "glUniform4ui\0"
    "glUniform4uiv\0"
    "glVertexAttribI1i\0"
    "glVertexAttribI1iv\0"
    "glVertexAttribI1ui\0"
    "glVertexAttribI1uiv\0"
    "glVertexAttribI2i\0"
    "glVertexAttribI2iv\0"
    "glVertexAttribI2ui\0"
    "glVertexAttribI2uiv\0"
    "glVertexAttribI3i\0"
    "glVertexAttribI3iv\0"
    "glVertexAttribI3ui\0"
    "glVertexAttribI3uiv\0"
    "glVertexAttribI4bv\0"
    "glVertexAttribI4i\0"
    "glVertexAttribI4iv\0"
    "glVertexAttribI4sv\0"
    "glVertexAttribI4ubv\0"
    "glVertexAttribI4ui\0"
    "glVertexAttribI4uiv\0"
    "glVertexAttribI4usv\0"
    "glVertexAttribIPointer\0"
    "glFramebufferTextureLayer\0"
    "glFramebufferTextureLayerARB\0"
    "glColorMaski\0"
    "glDisablei\0"
    "glEnablei\0"
    "glGetBooleani_v\0"
    "glGetIntegeri_v\0"
    "glIsEnabledi\0"
    "glGetTexParameterIiv\0"
    "glGetTexParameterIuiv\0"
    "glTexParameterIiv\0"
    "glTexParameterIuiv\0"
    "glBeginConditionalRender\0"
    "glEndConditionalRender\0"
    "glBeginTransformFeedback\0"
    "glBindBufferBase\0"
    "glBindBufferRange\0"
    "glEndTransformFeedback\0"
    "glGetTransformFeedbackVarying\0"
    "glTransformFeedbackVaryings\0"
    "glProvokingVertex\0"
    ;


#ifdef USE_MGL_NAMESPACE
#define gl_dispatch_stub_343 mgl_dispatch_stub_343
#define gl_dispatch_stub_344 mgl_dispatch_stub_344
#define gl_dispatch_stub_345 mgl_dispatch_stub_345
#define gl_dispatch_stub_356 mgl_dispatch_stub_356
#define gl_dispatch_stub_357 mgl_dispatch_stub_357
#define gl_dispatch_stub_358 mgl_dispatch_stub_358
#define gl_dispatch_stub_359 mgl_dispatch_stub_359
#define gl_dispatch_stub_361 mgl_dispatch_stub_361
#define gl_dispatch_stub_362 mgl_dispatch_stub_362
#define gl_dispatch_stub_363 mgl_dispatch_stub_363
#define gl_dispatch_stub_364 mgl_dispatch_stub_364
#define gl_dispatch_stub_365 mgl_dispatch_stub_365
#define gl_dispatch_stub_366 mgl_dispatch_stub_366
#define gl_dispatch_stub_686 mgl_dispatch_stub_686
#define gl_dispatch_stub_687 mgl_dispatch_stub_687
#define gl_dispatch_stub_688 mgl_dispatch_stub_688
#define gl_dispatch_stub_689 mgl_dispatch_stub_689
#define gl_dispatch_stub_690 mgl_dispatch_stub_690
#define gl_dispatch_stub_691 mgl_dispatch_stub_691
#define gl_dispatch_stub_692 mgl_dispatch_stub_692
#define gl_dispatch_stub_693 mgl_dispatch_stub_693
#define gl_dispatch_stub_728 mgl_dispatch_stub_728
#define gl_dispatch_stub_770 mgl_dispatch_stub_770
#define gl_dispatch_stub_771 mgl_dispatch_stub_771
#define gl_dispatch_stub_772 mgl_dispatch_stub_772
#define gl_dispatch_stub_773 mgl_dispatch_stub_773
#define gl_dispatch_stub_774 mgl_dispatch_stub_774
#define gl_dispatch_stub_775 mgl_dispatch_stub_775
#define gl_dispatch_stub_776 mgl_dispatch_stub_776
#define gl_dispatch_stub_777 mgl_dispatch_stub_777
#define gl_dispatch_stub_778 mgl_dispatch_stub_778
#define gl_dispatch_stub_859 mgl_dispatch_stub_859
#define gl_dispatch_stub_860 mgl_dispatch_stub_860
#define gl_dispatch_stub_861 mgl_dispatch_stub_861
#define gl_dispatch_stub_862 mgl_dispatch_stub_862
#define gl_dispatch_stub_863 mgl_dispatch_stub_863
#define gl_dispatch_stub_872 mgl_dispatch_stub_872
#define gl_dispatch_stub_873 mgl_dispatch_stub_873
#define gl_dispatch_stub_891 mgl_dispatch_stub_891
#define gl_dispatch_stub_892 mgl_dispatch_stub_892
#define gl_dispatch_stub_893 mgl_dispatch_stub_893
#define gl_dispatch_stub_951 mgl_dispatch_stub_951
#define gl_dispatch_stub_952 mgl_dispatch_stub_952
#define gl_dispatch_stub_960 mgl_dispatch_stub_960
#define gl_dispatch_stub_961 mgl_dispatch_stub_961
#define gl_dispatch_stub_962 mgl_dispatch_stub_962
#define gl_dispatch_stub_963 mgl_dispatch_stub_963
#define gl_dispatch_stub_964 mgl_dispatch_stub_964
#endif /* USE_MGL_NAMESPACE */


#if defined(NEED_FUNCTION_POINTER) || defined(GLX_INDIRECT_RENDERING)
void GLAPIENTRY gl_dispatch_stub_343(GLenum target, GLenum format, GLenum type, GLvoid * table);
void GLAPIENTRY gl_dispatch_stub_344(GLenum target, GLenum pname, GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_345(GLenum target, GLenum pname, GLint * params);
void GLAPIENTRY gl_dispatch_stub_356(GLenum target, GLenum format, GLenum type, GLvoid * image);
void GLAPIENTRY gl_dispatch_stub_357(GLenum target, GLenum pname, GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_358(GLenum target, GLenum pname, GLint * params);
void GLAPIENTRY gl_dispatch_stub_359(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span);
void GLAPIENTRY gl_dispatch_stub_361(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
void GLAPIENTRY gl_dispatch_stub_362(GLenum target, GLenum pname, GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_363(GLenum target, GLenum pname, GLint * params);
void GLAPIENTRY gl_dispatch_stub_364(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
void GLAPIENTRY gl_dispatch_stub_365(GLenum target, GLenum pname, GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_366(GLenum target, GLenum pname, GLint * params);
void GLAPIENTRY gl_dispatch_stub_686(GLenum pname, GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_687(GLenum pname, GLint * params);
void GLAPIENTRY gl_dispatch_stub_688(GLenum pname, GLfloat param);
void GLAPIENTRY gl_dispatch_stub_689(GLenum pname, const GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_690(GLenum pname, GLint param);
void GLAPIENTRY gl_dispatch_stub_691(GLenum pname, const GLint * params);
void GLAPIENTRY gl_dispatch_stub_692(GLclampf value, GLboolean invert);
void GLAPIENTRY gl_dispatch_stub_693(GLenum pattern);
void GLAPIENTRY gl_dispatch_stub_728(GLenum mode);
void GLAPIENTRY gl_dispatch_stub_770(const GLenum * mode, const GLint * first, const GLsizei * count, GLsizei primcount, GLint modestride);
void GLAPIENTRY gl_dispatch_stub_771(const GLenum * mode, const GLsizei * count, GLenum type, const GLvoid * const * indices, GLsizei primcount, GLint modestride);
void GLAPIENTRY gl_dispatch_stub_772(GLsizei n, const GLuint * fences);
void GLAPIENTRY gl_dispatch_stub_773(GLuint fence);
void GLAPIENTRY gl_dispatch_stub_774(GLsizei n, GLuint * fences);
void GLAPIENTRY gl_dispatch_stub_775(GLuint fence, GLenum pname, GLint * params);
GLboolean GLAPIENTRY gl_dispatch_stub_776(GLuint fence);
void GLAPIENTRY gl_dispatch_stub_777(GLuint fence, GLenum condition);
GLboolean GLAPIENTRY gl_dispatch_stub_778(GLuint fence);
void GLAPIENTRY gl_dispatch_stub_859(GLenum face);
void GLAPIENTRY gl_dispatch_stub_860(GLuint array);
void GLAPIENTRY gl_dispatch_stub_861(GLsizei n, const GLuint * arrays);
void GLAPIENTRY gl_dispatch_stub_862(GLsizei n, GLuint * arrays);
GLboolean GLAPIENTRY gl_dispatch_stub_863(GLuint array);
void GLAPIENTRY gl_dispatch_stub_872(GLclampd zmin, GLclampd zmax);
void GLAPIENTRY gl_dispatch_stub_873(GLenum modeRGB, GLenum modeA);
void GLAPIENTRY gl_dispatch_stub_891(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void GLAPIENTRY gl_dispatch_stub_892(GLenum target, GLenum pname, GLint param);
void GLAPIENTRY gl_dispatch_stub_893(GLenum target, GLintptr offset, GLsizeiptr size);
void GLAPIENTRY gl_dispatch_stub_951(GLenum target, GLenum pname, GLvoid ** params);
void GLAPIENTRY gl_dispatch_stub_952(GLenum target, GLsizei length, GLvoid * pointer);
void GLAPIENTRY gl_dispatch_stub_960(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
void GLAPIENTRY gl_dispatch_stub_961(GLenum target, GLuint index, GLsizei count, const GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_962(GLenum target, GLuint index, GLsizei count, const GLfloat * params);
void GLAPIENTRY gl_dispatch_stub_963(GLuint id, GLenum pname, GLint64EXT * params);
void GLAPIENTRY gl_dispatch_stub_964(GLuint id, GLenum pname, GLuint64EXT * params);
#endif /* defined(NEED_FUNCTION_POINTER) || defined(GLX_INDIRECT_RENDERING) */

static const glprocs_table_t static_functions[] = {
    NAME_FUNC_OFFSET(    0, glNewList, glNewList, NULL, 0),
    NAME_FUNC_OFFSET(   10, glEndList, glEndList, NULL, 1),
    NAME_FUNC_OFFSET(   20, glCallList, glCallList, NULL, 2),
    NAME_FUNC_OFFSET(   31, glCallLists, glCallLists, NULL, 3),
    NAME_FUNC_OFFSET(   43, glDeleteLists, glDeleteLists, NULL, 4),
    NAME_FUNC_OFFSET(   57, glGenLists, glGenLists, NULL, 5),
    NAME_FUNC_OFFSET(   68, glListBase, glListBase, NULL, 6),
    NAME_FUNC_OFFSET(   79, glBegin, glBegin, NULL, 7),
    NAME_FUNC_OFFSET(   87, glBitmap, glBitmap, NULL, 8),
    NAME_FUNC_OFFSET(   96, glColor3b, glColor3b, NULL, 9),
    NAME_FUNC_OFFSET(  106, glColor3bv, glColor3bv, NULL, 10),
    NAME_FUNC_OFFSET(  117, glColor3d, glColor3d, NULL, 11),
    NAME_FUNC_OFFSET(  127, glColor3dv, glColor3dv, NULL, 12),
    NAME_FUNC_OFFSET(  138, glColor3f, glColor3f, NULL, 13),
    NAME_FUNC_OFFSET(  148, glColor3fv, glColor3fv, NULL, 14),
    NAME_FUNC_OFFSET(  159, glColor3i, glColor3i, NULL, 15),
    NAME_FUNC_OFFSET(  169, glColor3iv, glColor3iv, NULL, 16),
    NAME_FUNC_OFFSET(  180, glColor3s, glColor3s, NULL, 17),
    NAME_FUNC_OFFSET(  190, glColor3sv, glColor3sv, NULL, 18),
    NAME_FUNC_OFFSET(  201, glColor3ub, glColor3ub, NULL, 19),
    NAME_FUNC_OFFSET(  212, glColor3ubv, glColor3ubv, NULL, 20),
    NAME_FUNC_OFFSET(  224, glColor3ui, glColor3ui, NULL, 21),
    NAME_FUNC_OFFSET(  235, glColor3uiv, glColor3uiv, NULL, 22),
    NAME_FUNC_OFFSET(  247, glColor3us, glColor3us, NULL, 23),
    NAME_FUNC_OFFSET(  258, glColor3usv, glColor3usv, NULL, 24),
    NAME_FUNC_OFFSET(  270, glColor4b, glColor4b, NULL, 25),
    NAME_FUNC_OFFSET(  280, glColor4bv, glColor4bv, NULL, 26),
    NAME_FUNC_OFFSET(  291, glColor4d, glColor4d, NULL, 27),
    NAME_FUNC_OFFSET(  301, glColor4dv, glColor4dv, NULL, 28),
    NAME_FUNC_OFFSET(  312, glColor4f, glColor4f, NULL, 29),
    NAME_FUNC_OFFSET(  322, glColor4fv, glColor4fv, NULL, 30),
    NAME_FUNC_OFFSET(  333, glColor4i, glColor4i, NULL, 31),
    NAME_FUNC_OFFSET(  343, glColor4iv, glColor4iv, NULL, 32),
    NAME_FUNC_OFFSET(  354, glColor4s, glColor4s, NULL, 33),
    NAME_FUNC_OFFSET(  364, glColor4sv, glColor4sv, NULL, 34),
    NAME_FUNC_OFFSET(  375, glColor4ub, glColor4ub, NULL, 35),
    NAME_FUNC_OFFSET(  386, glColor4ubv, glColor4ubv, NULL, 36),
    NAME_FUNC_OFFSET(  398, glColor4ui, glColor4ui, NULL, 37),
    NAME_FUNC_OFFSET(  409, glColor4uiv, glColor4uiv, NULL, 38),
    NAME_FUNC_OFFSET(  421, glColor4us, glColor4us, NULL, 39),
    NAME_FUNC_OFFSET(  432, glColor4usv, glColor4usv, NULL, 40),
    NAME_FUNC_OFFSET(  444, glEdgeFlag, glEdgeFlag, NULL, 41),
    NAME_FUNC_OFFSET(  455, glEdgeFlagv, glEdgeFlagv, NULL, 42),
    NAME_FUNC_OFFSET(  467, glEnd, glEnd, NULL, 43),
    NAME_FUNC_OFFSET(  473, glIndexd, glIndexd, NULL, 44),
    NAME_FUNC_OFFSET(  482, glIndexdv, glIndexdv, NULL, 45),
    NAME_FUNC_OFFSET(  492, glIndexf, glIndexf, NULL, 46),
    NAME_FUNC_OFFSET(  501, glIndexfv, glIndexfv, NULL, 47),
    NAME_FUNC_OFFSET(  511, glIndexi, glIndexi, NULL, 48),
    NAME_FUNC_OFFSET(  520, glIndexiv, glIndexiv, NULL, 49),
    NAME_FUNC_OFFSET(  530, glIndexs, glIndexs, NULL, 50),
    NAME_FUNC_OFFSET(  539, glIndexsv, glIndexsv, NULL, 51),
    NAME_FUNC_OFFSET(  549, glNormal3b, glNormal3b, NULL, 52),
    NAME_FUNC_OFFSET(  560, glNormal3bv, glNormal3bv, NULL, 53),
    NAME_FUNC_OFFSET(  572, glNormal3d, glNormal3d, NULL, 54),
    NAME_FUNC_OFFSET(  583, glNormal3dv, glNormal3dv, NULL, 55),
    NAME_FUNC_OFFSET(  595, glNormal3f, glNormal3f, NULL, 56),
    NAME_FUNC_OFFSET(  606, glNormal3fv, glNormal3fv, NULL, 57),
    NAME_FUNC_OFFSET(  618, glNormal3i, glNormal3i, NULL, 58),
    NAME_FUNC_OFFSET(  629, glNormal3iv, glNormal3iv, NULL, 59),
    NAME_FUNC_OFFSET(  641, glNormal3s, glNormal3s, NULL, 60),
    NAME_FUNC_OFFSET(  652, glNormal3sv, glNormal3sv, NULL, 61),
    NAME_FUNC_OFFSET(  664, glRasterPos2d, glRasterPos2d, NULL, 62),
    NAME_FUNC_OFFSET(  678, glRasterPos2dv, glRasterPos2dv, NULL, 63),
    NAME_FUNC_OFFSET(  693, glRasterPos2f, glRasterPos2f, NULL, 64),
    NAME_FUNC_OFFSET(  707, glRasterPos2fv, glRasterPos2fv, NULL, 65),
    NAME_FUNC_OFFSET(  722, glRasterPos2i, glRasterPos2i, NULL, 66),
    NAME_FUNC_OFFSET(  736, glRasterPos2iv, glRasterPos2iv, NULL, 67),
    NAME_FUNC_OFFSET(  751, glRasterPos2s, glRasterPos2s, NULL, 68),
    NAME_FUNC_OFFSET(  765, glRasterPos2sv, glRasterPos2sv, NULL, 69),
    NAME_FUNC_OFFSET(  780, glRasterPos3d, glRasterPos3d, NULL, 70),
    NAME_FUNC_OFFSET(  794, glRasterPos3dv, glRasterPos3dv, NULL, 71),
    NAME_FUNC_OFFSET(  809, glRasterPos3f, glRasterPos3f, NULL, 72),
    NAME_FUNC_OFFSET(  823, glRasterPos3fv, glRasterPos3fv, NULL, 73),
    NAME_FUNC_OFFSET(  838, glRasterPos3i, glRasterPos3i, NULL, 74),
    NAME_FUNC_OFFSET(  852, glRasterPos3iv, glRasterPos3iv, NULL, 75),
    NAME_FUNC_OFFSET(  867, glRasterPos3s, glRasterPos3s, NULL, 76),
    NAME_FUNC_OFFSET(  881, glRasterPos3sv, glRasterPos3sv, NULL, 77),
    NAME_FUNC_OFFSET(  896, glRasterPos4d, glRasterPos4d, NULL, 78),
    NAME_FUNC_OFFSET(  910, glRasterPos4dv, glRasterPos4dv, NULL, 79),
    NAME_FUNC_OFFSET(  925, glRasterPos4f, glRasterPos4f, NULL, 80),
    NAME_FUNC_OFFSET(  939, glRasterPos4fv, glRasterPos4fv, NULL, 81),
    NAME_FUNC_OFFSET(  954, glRasterPos4i, glRasterPos4i, NULL, 82),
    NAME_FUNC_OFFSET(  968, glRasterPos4iv, glRasterPos4iv, NULL, 83),
    NAME_FUNC_OFFSET(  983, glRasterPos4s, glRasterPos4s, NULL, 84),
    NAME_FUNC_OFFSET(  997, glRasterPos4sv, glRasterPos4sv, NULL, 85),
    NAME_FUNC_OFFSET( 1012, glRectd, glRectd, NULL, 86),
    NAME_FUNC_OFFSET( 1020, glRectdv, glRectdv, NULL, 87),
    NAME_FUNC_OFFSET( 1029, glRectf, glRectf, NULL, 88),
    NAME_FUNC_OFFSET( 1037, glRectfv, glRectfv, NULL, 89),
    NAME_FUNC_OFFSET( 1046, glRecti, glRecti, NULL, 90),
    NAME_FUNC_OFFSET( 1054, glRectiv, glRectiv, NULL, 91),
    NAME_FUNC_OFFSET( 1063, glRects, glRects, NULL, 92),
    NAME_FUNC_OFFSET( 1071, glRectsv, glRectsv, NULL, 93),
    NAME_FUNC_OFFSET( 1080, glTexCoord1d, glTexCoord1d, NULL, 94),
    NAME_FUNC_OFFSET( 1093, glTexCoord1dv, glTexCoord1dv, NULL, 95),
    NAME_FUNC_OFFSET( 1107, glTexCoord1f, glTexCoord1f, NULL, 96),
    NAME_FUNC_OFFSET( 1120, glTexCoord1fv, glTexCoord1fv, NULL, 97),
    NAME_FUNC_OFFSET( 1134, glTexCoord1i, glTexCoord1i, NULL, 98),
    NAME_FUNC_OFFSET( 1147, glTexCoord1iv, glTexCoord1iv, NULL, 99),
    NAME_FUNC_OFFSET( 1161, glTexCoord1s, glTexCoord1s, NULL, 100),
    NAME_FUNC_OFFSET( 1174, glTexCoord1sv, glTexCoord1sv, NULL, 101),
    NAME_FUNC_OFFSET( 1188, glTexCoord2d, glTexCoord2d, NULL, 102),
    NAME_FUNC_OFFSET( 1201, glTexCoord2dv, glTexCoord2dv, NULL, 103),
    NAME_FUNC_OFFSET( 1215, glTexCoord2f, glTexCoord2f, NULL, 104),
    NAME_FUNC_OFFSET( 1228, glTexCoord2fv, glTexCoord2fv, NULL, 105),
    NAME_FUNC_OFFSET( 1242, glTexCoord2i, glTexCoord2i, NULL, 106),
    NAME_FUNC_OFFSET( 1255, glTexCoord2iv, glTexCoord2iv, NULL, 107),
    NAME_FUNC_OFFSET( 1269, glTexCoord2s, glTexCoord2s, NULL, 108),
    NAME_FUNC_OFFSET( 1282, glTexCoord2sv, glTexCoord2sv, NULL, 109),
    NAME_FUNC_OFFSET( 1296, glTexCoord3d, glTexCoord3d, NULL, 110),
    NAME_FUNC_OFFSET( 1309, glTexCoord3dv, glTexCoord3dv, NULL, 111),
    NAME_FUNC_OFFSET( 1323, glTexCoord3f, glTexCoord3f, NULL, 112),
    NAME_FUNC_OFFSET( 1336, glTexCoord3fv, glTexCoord3fv, NULL, 113),
    NAME_FUNC_OFFSET( 1350, glTexCoord3i, glTexCoord3i, NULL, 114),
    NAME_FUNC_OFFSET( 1363, glTexCoord3iv, glTexCoord3iv, NULL, 115),
    NAME_FUNC_OFFSET( 1377, glTexCoord3s, glTexCoord3s, NULL, 116),
    NAME_FUNC_OFFSET( 1390, glTexCoord3sv, glTexCoord3sv, NULL, 117),
    NAME_FUNC_OFFSET( 1404, glTexCoord4d, glTexCoord4d, NULL, 118),
    NAME_FUNC_OFFSET( 1417, glTexCoord4dv, glTexCoord4dv, NULL, 119),
    NAME_FUNC_OFFSET( 1431, glTexCoord4f, glTexCoord4f, NULL, 120),
    NAME_FUNC_OFFSET( 1444, glTexCoord4fv, glTexCoord4fv, NULL, 121),
    NAME_FUNC_OFFSET( 1458, glTexCoord4i, glTexCoord4i, NULL, 122),
    NAME_FUNC_OFFSET( 1471, glTexCoord4iv, glTexCoord4iv, NULL, 123),
    NAME_FUNC_OFFSET( 1485, glTexCoord4s, glTexCoord4s, NULL, 124),
    NAME_FUNC_OFFSET( 1498, glTexCoord4sv, glTexCoord4sv, NULL, 125),
    NAME_FUNC_OFFSET( 1512, glVertex2d, glVertex2d, NULL, 126),
    NAME_FUNC_OFFSET( 1523, glVertex2dv, glVertex2dv, NULL, 127),
    NAME_FUNC_OFFSET( 1535, glVertex2f, glVertex2f, NULL, 128),
    NAME_FUNC_OFFSET( 1546, glVertex2fv, glVertex2fv, NULL, 129),
    NAME_FUNC_OFFSET( 1558, glVertex2i, glVertex2i, NULL, 130),
    NAME_FUNC_OFFSET( 1569, glVertex2iv, glVertex2iv, NULL, 131),
    NAME_FUNC_OFFSET( 1581, glVertex2s, glVertex2s, NULL, 132),
    NAME_FUNC_OFFSET( 1592, glVertex2sv, glVertex2sv, NULL, 133),
    NAME_FUNC_OFFSET( 1604, glVertex3d, glVertex3d, NULL, 134),
    NAME_FUNC_OFFSET( 1615, glVertex3dv, glVertex3dv, NULL, 135),
    NAME_FUNC_OFFSET( 1627, glVertex3f, glVertex3f, NULL, 136),
    NAME_FUNC_OFFSET( 1638, glVertex3fv, glVertex3fv, NULL, 137),
    NAME_FUNC_OFFSET( 1650, glVertex3i, glVertex3i, NULL, 138),
    NAME_FUNC_OFFSET( 1661, glVertex3iv, glVertex3iv, NULL, 139),
    NAME_FUNC_OFFSET( 1673, glVertex3s, glVertex3s, NULL, 140),
    NAME_FUNC_OFFSET( 1684, glVertex3sv, glVertex3sv, NULL, 141),
    NAME_FUNC_OFFSET( 1696, glVertex4d, glVertex4d, NULL, 142),
    NAME_FUNC_OFFSET( 1707, glVertex4dv, glVertex4dv, NULL, 143),
    NAME_FUNC_OFFSET( 1719, glVertex4f, glVertex4f, NULL, 144),
    NAME_FUNC_OFFSET( 1730, glVertex4fv, glVertex4fv, NULL, 145),
    NAME_FUNC_OFFSET( 1742, glVertex4i, glVertex4i, NULL, 146),
    NAME_FUNC_OFFSET( 1753, glVertex4iv, glVertex4iv, NULL, 147),
    NAME_FUNC_OFFSET( 1765, glVertex4s, glVertex4s, NULL, 148),
    NAME_FUNC_OFFSET( 1776, glVertex4sv, glVertex4sv, NULL, 149),
    NAME_FUNC_OFFSET( 1788, glClipPlane, glClipPlane, NULL, 150),
    NAME_FUNC_OFFSET( 1800, glColorMaterial, glColorMaterial, NULL, 151),
    NAME_FUNC_OFFSET( 1816, glCullFace, glCullFace, NULL, 152),
    NAME_FUNC_OFFSET( 1827, glFogf, glFogf, NULL, 153),
    NAME_FUNC_OFFSET( 1834, glFogfv, glFogfv, NULL, 154),
    NAME_FUNC_OFFSET( 1842, glFogi, glFogi, NULL, 155),
    NAME_FUNC_OFFSET( 1849, glFogiv, glFogiv, NULL, 156),
    NAME_FUNC_OFFSET( 1857, glFrontFace, glFrontFace, NULL, 157),
    NAME_FUNC_OFFSET( 1869, glHint, glHint, NULL, 158),
    NAME_FUNC_OFFSET( 1876, glLightf, glLightf, NULL, 159),
    NAME_FUNC_OFFSET( 1885, glLightfv, glLightfv, NULL, 160),
    NAME_FUNC_OFFSET( 1895, glLighti, glLighti, NULL, 161),
    NAME_FUNC_OFFSET( 1904, glLightiv, glLightiv, NULL, 162),
    NAME_FUNC_OFFSET( 1914, glLightModelf, glLightModelf, NULL, 163),
    NAME_FUNC_OFFSET( 1928, glLightModelfv, glLightModelfv, NULL, 164),
    NAME_FUNC_OFFSET( 1943, glLightModeli, glLightModeli, NULL, 165),
    NAME_FUNC_OFFSET( 1957, glLightModeliv, glLightModeliv, NULL, 166),
    NAME_FUNC_OFFSET( 1972, glLineStipple, glLineStipple, NULL, 167),
    NAME_FUNC_OFFSET( 1986, glLineWidth, glLineWidth, NULL, 168),
    NAME_FUNC_OFFSET( 1998, glMaterialf, glMaterialf, NULL, 169),
    NAME_FUNC_OFFSET( 2010, glMaterialfv, glMaterialfv, NULL, 170),
    NAME_FUNC_OFFSET( 2023, glMateriali, glMateriali, NULL, 171),
    NAME_FUNC_OFFSET( 2035, glMaterialiv, glMaterialiv, NULL, 172),
    NAME_FUNC_OFFSET( 2048, glPointSize, glPointSize, NULL, 173),
    NAME_FUNC_OFFSET( 2060, glPolygonMode, glPolygonMode, NULL, 174),
    NAME_FUNC_OFFSET( 2074, glPolygonStipple, glPolygonStipple, NULL, 175),
    NAME_FUNC_OFFSET( 2091, glScissor, glScissor, NULL, 176),
    NAME_FUNC_OFFSET( 2101, glShadeModel, glShadeModel, NULL, 177),
    NAME_FUNC_OFFSET( 2114, glTexParameterf, glTexParameterf, NULL, 178),
    NAME_FUNC_OFFSET( 2130, glTexParameterfv, glTexParameterfv, NULL, 179),
    NAME_FUNC_OFFSET( 2147, glTexParameteri, glTexParameteri, NULL, 180),
    NAME_FUNC_OFFSET( 2163, glTexParameteriv, glTexParameteriv, NULL, 181),
    NAME_FUNC_OFFSET( 2180, glTexImage1D, glTexImage1D, NULL, 182),
    NAME_FUNC_OFFSET( 2193, glTexImage2D, glTexImage2D, NULL, 183),
    NAME_FUNC_OFFSET( 2206, glTexEnvf, glTexEnvf, NULL, 184),
    NAME_FUNC_OFFSET( 2216, glTexEnvfv, glTexEnvfv, NULL, 185),
    NAME_FUNC_OFFSET( 2227, glTexEnvi, glTexEnvi, NULL, 186),
    NAME_FUNC_OFFSET( 2237, glTexEnviv, glTexEnviv, NULL, 187),
    NAME_FUNC_OFFSET( 2248, glTexGend, glTexGend, NULL, 188),
    NAME_FUNC_OFFSET( 2258, glTexGendv, glTexGendv, NULL, 189),
    NAME_FUNC_OFFSET( 2269, glTexGenf, glTexGenf, NULL, 190),
    NAME_FUNC_OFFSET( 2279, glTexGenfv, glTexGenfv, NULL, 191),
    NAME_FUNC_OFFSET( 2290, glTexGeni, glTexGeni, NULL, 192),
    NAME_FUNC_OFFSET( 2300, glTexGeniv, glTexGeniv, NULL, 193),
    NAME_FUNC_OFFSET( 2311, glFeedbackBuffer, glFeedbackBuffer, NULL, 194),
    NAME_FUNC_OFFSET( 2328, glSelectBuffer, glSelectBuffer, NULL, 195),
    NAME_FUNC_OFFSET( 2343, glRenderMode, glRenderMode, NULL, 196),
    NAME_FUNC_OFFSET( 2356, glInitNames, glInitNames, NULL, 197),
    NAME_FUNC_OFFSET( 2368, glLoadName, glLoadName, NULL, 198),
    NAME_FUNC_OFFSET( 2379, glPassThrough, glPassThrough, NULL, 199),
    NAME_FUNC_OFFSET( 2393, glPopName, glPopName, NULL, 200),
    NAME_FUNC_OFFSET( 2403, glPushName, glPushName, NULL, 201),
    NAME_FUNC_OFFSET( 2414, glDrawBuffer, glDrawBuffer, NULL, 202),
    NAME_FUNC_OFFSET( 2427, glClear, glClear, NULL, 203),
    NAME_FUNC_OFFSET( 2435, glClearAccum, glClearAccum, NULL, 204),
    NAME_FUNC_OFFSET( 2448, glClearIndex, glClearIndex, NULL, 205),
    NAME_FUNC_OFFSET( 2461, glClearColor, glClearColor, NULL, 206),
    NAME_FUNC_OFFSET( 2474, glClearStencil, glClearStencil, NULL, 207),
    NAME_FUNC_OFFSET( 2489, glClearDepth, glClearDepth, NULL, 208),
    NAME_FUNC_OFFSET( 2502, glStencilMask, glStencilMask, NULL, 209),
    NAME_FUNC_OFFSET( 2516, glColorMask, glColorMask, NULL, 210),
    NAME_FUNC_OFFSET( 2528, glDepthMask, glDepthMask, NULL, 211),
    NAME_FUNC_OFFSET( 2540, glIndexMask, glIndexMask, NULL, 212),
    NAME_FUNC_OFFSET( 2552, glAccum, glAccum, NULL, 213),
    NAME_FUNC_OFFSET( 2560, glDisable, glDisable, NULL, 214),
    NAME_FUNC_OFFSET( 2570, glEnable, glEnable, NULL, 215),
    NAME_FUNC_OFFSET( 2579, glFinish, glFinish, NULL, 216),
    NAME_FUNC_OFFSET( 2588, glFlush, glFlush, NULL, 217),
    NAME_FUNC_OFFSET( 2596, glPopAttrib, glPopAttrib, NULL, 218),
    NAME_FUNC_OFFSET( 2608, glPushAttrib, glPushAttrib, NULL, 219),
    NAME_FUNC_OFFSET( 2621, glMap1d, glMap1d, NULL, 220),
    NAME_FUNC_OFFSET( 2629, glMap1f, glMap1f, NULL, 221),
    NAME_FUNC_OFFSET( 2637, glMap2d, glMap2d, NULL, 222),
    NAME_FUNC_OFFSET( 2645, glMap2f, glMap2f, NULL, 223),
    NAME_FUNC_OFFSET( 2653, glMapGrid1d, glMapGrid1d, NULL, 224),
    NAME_FUNC_OFFSET( 2665, glMapGrid1f, glMapGrid1f, NULL, 225),
    NAME_FUNC_OFFSET( 2677, glMapGrid2d, glMapGrid2d, NULL, 226),
    NAME_FUNC_OFFSET( 2689, glMapGrid2f, glMapGrid2f, NULL, 227),
    NAME_FUNC_OFFSET( 2701, glEvalCoord1d, glEvalCoord1d, NULL, 228),
    NAME_FUNC_OFFSET( 2715, glEvalCoord1dv, glEvalCoord1dv, NULL, 229),
    NAME_FUNC_OFFSET( 2730, glEvalCoord1f, glEvalCoord1f, NULL, 230),
    NAME_FUNC_OFFSET( 2744, glEvalCoord1fv, glEvalCoord1fv, NULL, 231),
    NAME_FUNC_OFFSET( 2759, glEvalCoord2d, glEvalCoord2d, NULL, 232),
    NAME_FUNC_OFFSET( 2773, glEvalCoord2dv, glEvalCoord2dv, NULL, 233),
    NAME_FUNC_OFFSET( 2788, glEvalCoord2f, glEvalCoord2f, NULL, 234),
    NAME_FUNC_OFFSET( 2802, glEvalCoord2fv, glEvalCoord2fv, NULL, 235),
    NAME_FUNC_OFFSET( 2817, glEvalMesh1, glEvalMesh1, NULL, 236),
    NAME_FUNC_OFFSET( 2829, glEvalPoint1, glEvalPoint1, NULL, 237),
    NAME_FUNC_OFFSET( 2842, glEvalMesh2, glEvalMesh2, NULL, 238),
    NAME_FUNC_OFFSET( 2854, glEvalPoint2, glEvalPoint2, NULL, 239),
    NAME_FUNC_OFFSET( 2867, glAlphaFunc, glAlphaFunc, NULL, 240),
    NAME_FUNC_OFFSET( 2879, glBlendFunc, glBlendFunc, NULL, 241),
    NAME_FUNC_OFFSET( 2891, glLogicOp, glLogicOp, NULL, 242),
    NAME_FUNC_OFFSET( 2901, glStencilFunc, glStencilFunc, NULL, 243),
    NAME_FUNC_OFFSET( 2915, glStencilOp, glStencilOp, NULL, 244),
    NAME_FUNC_OFFSET( 2927, glDepthFunc, glDepthFunc, NULL, 245),
    NAME_FUNC_OFFSET( 2939, glPixelZoom, glPixelZoom, NULL, 246),
    NAME_FUNC_OFFSET( 2951, glPixelTransferf, glPixelTransferf, NULL, 247),
    NAME_FUNC_OFFSET( 2968, glPixelTransferi, glPixelTransferi, NULL, 248),
    NAME_FUNC_OFFSET( 2985, glPixelStoref, glPixelStoref, NULL, 249),
    NAME_FUNC_OFFSET( 2999, glPixelStorei, glPixelStorei, NULL, 250),
    NAME_FUNC_OFFSET( 3013, glPixelMapfv, glPixelMapfv, NULL, 251),
    NAME_FUNC_OFFSET( 3026, glPixelMapuiv, glPixelMapuiv, NULL, 252),
    NAME_FUNC_OFFSET( 3040, glPixelMapusv, glPixelMapusv, NULL, 253),
    NAME_FUNC_OFFSET( 3054, glReadBuffer, glReadBuffer, NULL, 254),
    NAME_FUNC_OFFSET( 3067, glCopyPixels, glCopyPixels, NULL, 255),
    NAME_FUNC_OFFSET( 3080, glReadPixels, glReadPixels, NULL, 256),
    NAME_FUNC_OFFSET( 3093, glDrawPixels, glDrawPixels, NULL, 257),
    NAME_FUNC_OFFSET( 3106, glGetBooleanv, glGetBooleanv, NULL, 258),
    NAME_FUNC_OFFSET( 3120, glGetClipPlane, glGetClipPlane, NULL, 259),
    NAME_FUNC_OFFSET( 3135, glGetDoublev, glGetDoublev, NULL, 260),
    NAME_FUNC_OFFSET( 3148, glGetError, glGetError, NULL, 261),
    NAME_FUNC_OFFSET( 3159, glGetFloatv, glGetFloatv, NULL, 262),
    NAME_FUNC_OFFSET( 3171, glGetIntegerv, glGetIntegerv, NULL, 263),
    NAME_FUNC_OFFSET( 3185, glGetLightfv, glGetLightfv, NULL, 264),
    NAME_FUNC_OFFSET( 3198, glGetLightiv, glGetLightiv, NULL, 265),
    NAME_FUNC_OFFSET( 3211, glGetMapdv, glGetMapdv, NULL, 266),
    NAME_FUNC_OFFSET( 3222, glGetMapfv, glGetMapfv, NULL, 267),
    NAME_FUNC_OFFSET( 3233, glGetMapiv, glGetMapiv, NULL, 268),
    NAME_FUNC_OFFSET( 3244, glGetMaterialfv, glGetMaterialfv, NULL, 269),
    NAME_FUNC_OFFSET( 3260, glGetMaterialiv, glGetMaterialiv, NULL, 270),
    NAME_FUNC_OFFSET( 3276, glGetPixelMapfv, glGetPixelMapfv, NULL, 271),
    NAME_FUNC_OFFSET( 3292, glGetPixelMapuiv, glGetPixelMapuiv, NULL, 272),
    NAME_FUNC_OFFSET( 3309, glGetPixelMapusv, glGetPixelMapusv, NULL, 273),
    NAME_FUNC_OFFSET( 3326, glGetPolygonStipple, glGetPolygonStipple, NULL, 274),
    NAME_FUNC_OFFSET( 3346, glGetString, glGetString, NULL, 275),
    NAME_FUNC_OFFSET( 3358, glGetTexEnvfv, glGetTexEnvfv, NULL, 276),
    NAME_FUNC_OFFSET( 3372, glGetTexEnviv, glGetTexEnviv, NULL, 277),
    NAME_FUNC_OFFSET( 3386, glGetTexGendv, glGetTexGendv, NULL, 278),
    NAME_FUNC_OFFSET( 3400, glGetTexGenfv, glGetTexGenfv, NULL, 279),
    NAME_FUNC_OFFSET( 3414, glGetTexGeniv, glGetTexGeniv, NULL, 280),
    NAME_FUNC_OFFSET( 3428, glGetTexImage, glGetTexImage, NULL, 281),
    NAME_FUNC_OFFSET( 3442, glGetTexParameterfv, glGetTexParameterfv, NULL, 282),
    NAME_FUNC_OFFSET( 3462, glGetTexParameteriv, glGetTexParameteriv, NULL, 283),
    NAME_FUNC_OFFSET( 3482, glGetTexLevelParameterfv, glGetTexLevelParameterfv, NULL, 284),
    NAME_FUNC_OFFSET( 3507, glGetTexLevelParameteriv, glGetTexLevelParameteriv, NULL, 285),
    NAME_FUNC_OFFSET( 3532, glIsEnabled, glIsEnabled, NULL, 286),
    NAME_FUNC_OFFSET( 3544, glIsList, glIsList, NULL, 287),
    NAME_FUNC_OFFSET( 3553, glDepthRange, glDepthRange, NULL, 288),
    NAME_FUNC_OFFSET( 3566, glFrustum, glFrustum, NULL, 289),
    NAME_FUNC_OFFSET( 3576, glLoadIdentity, glLoadIdentity, NULL, 290),
    NAME_FUNC_OFFSET( 3591, glLoadMatrixf, glLoadMatrixf, NULL, 291),
    NAME_FUNC_OFFSET( 3605, glLoadMatrixd, glLoadMatrixd, NULL, 292),
    NAME_FUNC_OFFSET( 3619, glMatrixMode, glMatrixMode, NULL, 293),
    NAME_FUNC_OFFSET( 3632, glMultMatrixf, glMultMatrixf, NULL, 294),
    NAME_FUNC_OFFSET( 3646, glMultMatrixd, glMultMatrixd, NULL, 295),
    NAME_FUNC_OFFSET( 3660, glOrtho, glOrtho, NULL, 296),
    NAME_FUNC_OFFSET( 3668, glPopMatrix, glPopMatrix, NULL, 297),
    NAME_FUNC_OFFSET( 3680, glPushMatrix, glPushMatrix, NULL, 298),
    NAME_FUNC_OFFSET( 3693, glRotated, glRotated, NULL, 299),
    NAME_FUNC_OFFSET( 3703, glRotatef, glRotatef, NULL, 300),
    NAME_FUNC_OFFSET( 3713, glScaled, glScaled, NULL, 301),
    NAME_FUNC_OFFSET( 3722, glScalef, glScalef, NULL, 302),
    NAME_FUNC_OFFSET( 3731, glTranslated, glTranslated, NULL, 303),
    NAME_FUNC_OFFSET( 3744, glTranslatef, glTranslatef, NULL, 304),
    NAME_FUNC_OFFSET( 3757, glViewport, glViewport, NULL, 305),
    NAME_FUNC_OFFSET( 3768, glArrayElement, glArrayElement, NULL, 306),
    NAME_FUNC_OFFSET( 3783, glBindTexture, glBindTexture, NULL, 307),
    NAME_FUNC_OFFSET( 3797, glColorPointer, glColorPointer, NULL, 308),
    NAME_FUNC_OFFSET( 3812, glDisableClientState, glDisableClientState, NULL, 309),
    NAME_FUNC_OFFSET( 3833, glDrawArrays, glDrawArrays, NULL, 310),
    NAME_FUNC_OFFSET( 3846, glDrawElements, glDrawElements, NULL, 311),
    NAME_FUNC_OFFSET( 3861, glEdgeFlagPointer, glEdgeFlagPointer, NULL, 312),
    NAME_FUNC_OFFSET( 3879, glEnableClientState, glEnableClientState, NULL, 313),
    NAME_FUNC_OFFSET( 3899, glIndexPointer, glIndexPointer, NULL, 314),
    NAME_FUNC_OFFSET( 3914, glIndexub, glIndexub, NULL, 315),
    NAME_FUNC_OFFSET( 3924, glIndexubv, glIndexubv, NULL, 316),
    NAME_FUNC_OFFSET( 3935, glInterleavedArrays, glInterleavedArrays, NULL, 317),
    NAME_FUNC_OFFSET( 3955, glNormalPointer, glNormalPointer, NULL, 318),
    NAME_FUNC_OFFSET( 3971, glPolygonOffset, glPolygonOffset, NULL, 319),
    NAME_FUNC_OFFSET( 3987, glTexCoordPointer, glTexCoordPointer, NULL, 320),
    NAME_FUNC_OFFSET( 4005, glVertexPointer, glVertexPointer, NULL, 321),
    NAME_FUNC_OFFSET( 4021, glAreTexturesResident, glAreTexturesResident, NULL, 322),
    NAME_FUNC_OFFSET( 4043, glCopyTexImage1D, glCopyTexImage1D, NULL, 323),
    NAME_FUNC_OFFSET( 4060, glCopyTexImage2D, glCopyTexImage2D, NULL, 324),
    NAME_FUNC_OFFSET( 4077, glCopyTexSubImage1D, glCopyTexSubImage1D, NULL, 325),
    NAME_FUNC_OFFSET( 4097, glCopyTexSubImage2D, glCopyTexSubImage2D, NULL, 326),
    NAME_FUNC_OFFSET( 4117, glDeleteTextures, glDeleteTextures, NULL, 327),
    NAME_FUNC_OFFSET( 4134, glGenTextures, glGenTextures, NULL, 328),
    NAME_FUNC_OFFSET( 4148, glGetPointerv, glGetPointerv, NULL, 329),
    NAME_FUNC_OFFSET( 4162, glIsTexture, glIsTexture, NULL, 330),
    NAME_FUNC_OFFSET( 4174, glPrioritizeTextures, glPrioritizeTextures, NULL, 331),
    NAME_FUNC_OFFSET( 4195, glTexSubImage1D, glTexSubImage1D, NULL, 332),
    NAME_FUNC_OFFSET( 4211, glTexSubImage2D, glTexSubImage2D, NULL, 333),
    NAME_FUNC_OFFSET( 4227, glPopClientAttrib, glPopClientAttrib, NULL, 334),
    NAME_FUNC_OFFSET( 4245, glPushClientAttrib, glPushClientAttrib, NULL, 335),
    NAME_FUNC_OFFSET( 4264, glBlendColor, glBlendColor, NULL, 336),
    NAME_FUNC_OFFSET( 4277, glBlendEquation, glBlendEquation, NULL, 337),
    NAME_FUNC_OFFSET( 4293, glDrawRangeElements, glDrawRangeElements, NULL, 338),
    NAME_FUNC_OFFSET( 4313, glColorTable, glColorTable, NULL, 339),
    NAME_FUNC_OFFSET( 4326, glColorTableParameterfv, glColorTableParameterfv, NULL, 340),
    NAME_FUNC_OFFSET( 4350, glColorTableParameteriv, glColorTableParameteriv, NULL, 341),
    NAME_FUNC_OFFSET( 4374, glCopyColorTable, glCopyColorTable, NULL, 342),
    NAME_FUNC_OFFSET( 4391, glGetColorTable, glGetColorTable, NULL, 343),
    NAME_FUNC_OFFSET( 4407, glGetColorTableParameterfv, glGetColorTableParameterfv, NULL, 344),
    NAME_FUNC_OFFSET( 4434, glGetColorTableParameteriv, glGetColorTableParameteriv, NULL, 345),
    NAME_FUNC_OFFSET( 4461, glColorSubTable, glColorSubTable, NULL, 346),
    NAME_FUNC_OFFSET( 4477, glCopyColorSubTable, glCopyColorSubTable, NULL, 347),
    NAME_FUNC_OFFSET( 4497, glConvolutionFilter1D, glConvolutionFilter1D, NULL, 348),
    NAME_FUNC_OFFSET( 4519, glConvolutionFilter2D, glConvolutionFilter2D, NULL, 349),
    NAME_FUNC_OFFSET( 4541, glConvolutionParameterf, glConvolutionParameterf, NULL, 350),
    NAME_FUNC_OFFSET( 4565, glConvolutionParameterfv, glConvolutionParameterfv, NULL, 351),
    NAME_FUNC_OFFSET( 4590, glConvolutionParameteri, glConvolutionParameteri, NULL, 352),
    NAME_FUNC_OFFSET( 4614, glConvolutionParameteriv, glConvolutionParameteriv, NULL, 353),
    NAME_FUNC_OFFSET( 4639, glCopyConvolutionFilter1D, glCopyConvolutionFilter1D, NULL, 354),
    NAME_FUNC_OFFSET( 4665, glCopyConvolutionFilter2D, glCopyConvolutionFilter2D, NULL, 355),
    NAME_FUNC_OFFSET( 4691, glGetConvolutionFilter, glGetConvolutionFilter, NULL, 356),
    NAME_FUNC_OFFSET( 4714, glGetConvolutionParameterfv, glGetConvolutionParameterfv, NULL, 357),
    NAME_FUNC_OFFSET( 4742, glGetConvolutionParameteriv, glGetConvolutionParameteriv, NULL, 358),
    NAME_FUNC_OFFSET( 4770, glGetSeparableFilter, glGetSeparableFilter, NULL, 359),
    NAME_FUNC_OFFSET( 4791, glSeparableFilter2D, glSeparableFilter2D, NULL, 360),
    NAME_FUNC_OFFSET( 4811, glGetHistogram, glGetHistogram, NULL, 361),
    NAME_FUNC_OFFSET( 4826, glGetHistogramParameterfv, glGetHistogramParameterfv, NULL, 362),
    NAME_FUNC_OFFSET( 4852, glGetHistogramParameteriv, glGetHistogramParameteriv, NULL, 363),
    NAME_FUNC_OFFSET( 4878, glGetMinmax, glGetMinmax, NULL, 364),
    NAME_FUNC_OFFSET( 4890, glGetMinmaxParameterfv, glGetMinmaxParameterfv, NULL, 365),
    NAME_FUNC_OFFSET( 4913, glGetMinmaxParameteriv, glGetMinmaxParameteriv, NULL, 366),
    NAME_FUNC_OFFSET( 4936, glHistogram, glHistogram, NULL, 367),
    NAME_FUNC_OFFSET( 4948, glMinmax, glMinmax, NULL, 368),
    NAME_FUNC_OFFSET( 4957, glResetHistogram, glResetHistogram, NULL, 369),
    NAME_FUNC_OFFSET( 4974, glResetMinmax, glResetMinmax, NULL, 370),
    NAME_FUNC_OFFSET( 4988, glTexImage3D, glTexImage3D, NULL, 371),
    NAME_FUNC_OFFSET( 5001, glTexSubImage3D, glTexSubImage3D, NULL, 372),
    NAME_FUNC_OFFSET( 5017, glCopyTexSubImage3D, glCopyTexSubImage3D, NULL, 373),
    NAME_FUNC_OFFSET( 5037, glActiveTextureARB, glActiveTextureARB, NULL, 374),
    NAME_FUNC_OFFSET( 5056, glClientActiveTextureARB, glClientActiveTextureARB, NULL, 375),
    NAME_FUNC_OFFSET( 5081, glMultiTexCoord1dARB, glMultiTexCoord1dARB, NULL, 376),
    NAME_FUNC_OFFSET( 5102, glMultiTexCoord1dvARB, glMultiTexCoord1dvARB, NULL, 377),
    NAME_FUNC_OFFSET( 5124, glMultiTexCoord1fARB, glMultiTexCoord1fARB, NULL, 378),
    NAME_FUNC_OFFSET( 5145, glMultiTexCoord1fvARB, glMultiTexCoord1fvARB, NULL, 379),
    NAME_FUNC_OFFSET( 5167, glMultiTexCoord1iARB, glMultiTexCoord1iARB, NULL, 380),
    NAME_FUNC_OFFSET( 5188, glMultiTexCoord1ivARB, glMultiTexCoord1ivARB, NULL, 381),
    NAME_FUNC_OFFSET( 5210, glMultiTexCoord1sARB, glMultiTexCoord1sARB, NULL, 382),
    NAME_FUNC_OFFSET( 5231, glMultiTexCoord1svARB, glMultiTexCoord1svARB, NULL, 383),
    NAME_FUNC_OFFSET( 5253, glMultiTexCoord2dARB, glMultiTexCoord2dARB, NULL, 384),
    NAME_FUNC_OFFSET( 5274, glMultiTexCoord2dvARB, glMultiTexCoord2dvARB, NULL, 385),
    NAME_FUNC_OFFSET( 5296, glMultiTexCoord2fARB, glMultiTexCoord2fARB, NULL, 386),
    NAME_FUNC_OFFSET( 5317, glMultiTexCoord2fvARB, glMultiTexCoord2fvARB, NULL, 387),
    NAME_FUNC_OFFSET( 5339, glMultiTexCoord2iARB, glMultiTexCoord2iARB, NULL, 388),
    NAME_FUNC_OFFSET( 5360, glMultiTexCoord2ivARB, glMultiTexCoord2ivARB, NULL, 389),
    NAME_FUNC_OFFSET( 5382, glMultiTexCoord2sARB, glMultiTexCoord2sARB, NULL, 390),
    NAME_FUNC_OFFSET( 5403, glMultiTexCoord2svARB, glMultiTexCoord2svARB, NULL, 391),
    NAME_FUNC_OFFSET( 5425, glMultiTexCoord3dARB, glMultiTexCoord3dARB, NULL, 392),
    NAME_FUNC_OFFSET( 5446, glMultiTexCoord3dvARB, glMultiTexCoord3dvARB, NULL, 393),
    NAME_FUNC_OFFSET( 5468, glMultiTexCoord3fARB, glMultiTexCoord3fARB, NULL, 394),
    NAME_FUNC_OFFSET( 5489, glMultiTexCoord3fvARB, glMultiTexCoord3fvARB, NULL, 395),
    NAME_FUNC_OFFSET( 5511, glMultiTexCoord3iARB, glMultiTexCoord3iARB, NULL, 396),
    NAME_FUNC_OFFSET( 5532, glMultiTexCoord3ivARB, glMultiTexCoord3ivARB, NULL, 397),
    NAME_FUNC_OFFSET( 5554, glMultiTexCoord3sARB, glMultiTexCoord3sARB, NULL, 398),
    NAME_FUNC_OFFSET( 5575, glMultiTexCoord3svARB, glMultiTexCoord3svARB, NULL, 399),
    NAME_FUNC_OFFSET( 5597, glMultiTexCoord4dARB, glMultiTexCoord4dARB, NULL, 400),
    NAME_FUNC_OFFSET( 5618, glMultiTexCoord4dvARB, glMultiTexCoord4dvARB, NULL, 401),
    NAME_FUNC_OFFSET( 5640, glMultiTexCoord4fARB, glMultiTexCoord4fARB, NULL, 402),
    NAME_FUNC_OFFSET( 5661, glMultiTexCoord4fvARB, glMultiTexCoord4fvARB, NULL, 403),
    NAME_FUNC_OFFSET( 5683, glMultiTexCoord4iARB, glMultiTexCoord4iARB, NULL, 404),
    NAME_FUNC_OFFSET( 5704, glMultiTexCoord4ivARB, glMultiTexCoord4ivARB, NULL, 405),
    NAME_FUNC_OFFSET( 5726, glMultiTexCoord4sARB, glMultiTexCoord4sARB, NULL, 406),
    NAME_FUNC_OFFSET( 5747, glMultiTexCoord4svARB, glMultiTexCoord4svARB, NULL, 407),
    NAME_FUNC_OFFSET( 5769, glAttachShader, glAttachShader, NULL, 408),
    NAME_FUNC_OFFSET( 5784, glCreateProgram, glCreateProgram, NULL, 409),
    NAME_FUNC_OFFSET( 5800, glCreateShader, glCreateShader, NULL, 410),
    NAME_FUNC_OFFSET( 5815, glDeleteProgram, glDeleteProgram, NULL, 411),
    NAME_FUNC_OFFSET( 5831, glDeleteShader, glDeleteShader, NULL, 412),
    NAME_FUNC_OFFSET( 5846, glDetachShader, glDetachShader, NULL, 413),
    NAME_FUNC_OFFSET( 5861, glGetAttachedShaders, glGetAttachedShaders, NULL, 414),
    NAME_FUNC_OFFSET( 5882, glGetProgramInfoLog, glGetProgramInfoLog, NULL, 415),
    NAME_FUNC_OFFSET( 5902, glGetProgramiv, glGetProgramiv, NULL, 416),
    NAME_FUNC_OFFSET( 5917, glGetShaderInfoLog, glGetShaderInfoLog, NULL, 417),
    NAME_FUNC_OFFSET( 5936, glGetShaderiv, glGetShaderiv, NULL, 418),
    NAME_FUNC_OFFSET( 5950, glIsProgram, glIsProgram, NULL, 419),
    NAME_FUNC_OFFSET( 5962, glIsShader, glIsShader, NULL, 420),
    NAME_FUNC_OFFSET( 5973, glStencilFuncSeparate, glStencilFuncSeparate, NULL, 421),
    NAME_FUNC_OFFSET( 5995, glStencilMaskSeparate, glStencilMaskSeparate, NULL, 422),
    NAME_FUNC_OFFSET( 6017, glStencilOpSeparate, glStencilOpSeparate, NULL, 423),
    NAME_FUNC_OFFSET( 6037, glUniformMatrix2x3fv, glUniformMatrix2x3fv, NULL, 424),
    NAME_FUNC_OFFSET( 6058, glUniformMatrix2x4fv, glUniformMatrix2x4fv, NULL, 425),
    NAME_FUNC_OFFSET( 6079, glUniformMatrix3x2fv, glUniformMatrix3x2fv, NULL, 426),
    NAME_FUNC_OFFSET( 6100, glUniformMatrix3x4fv, glUniformMatrix3x4fv, NULL, 427),
    NAME_FUNC_OFFSET( 6121, glUniformMatrix4x2fv, glUniformMatrix4x2fv, NULL, 428),
    NAME_FUNC_OFFSET( 6142, glUniformMatrix4x3fv, glUniformMatrix4x3fv, NULL, 429),
    NAME_FUNC_OFFSET( 6163, glClampColor, glClampColor, NULL, 430),
    NAME_FUNC_OFFSET( 6176, glClearBufferfi, glClearBufferfi, NULL, 431),
    NAME_FUNC_OFFSET( 6192, glClearBufferfv, glClearBufferfv, NULL, 432),
    NAME_FUNC_OFFSET( 6208, glClearBufferiv, glClearBufferiv, NULL, 433),
    NAME_FUNC_OFFSET( 6224, glClearBufferuiv, glClearBufferuiv, NULL, 434),
    NAME_FUNC_OFFSET( 6241, glGetStringi, glGetStringi, NULL, 435),
    NAME_FUNC_OFFSET( 6254, glTexBuffer, glTexBuffer, NULL, 436),
    NAME_FUNC_OFFSET( 6266, glFramebufferTexture, glFramebufferTexture, NULL, 437),
    NAME_FUNC_OFFSET( 6287, glGetBufferParameteri64v, glGetBufferParameteri64v, NULL, 438),
    NAME_FUNC_OFFSET( 6312, glGetInteger64i_v, glGetInteger64i_v, NULL, 439),
    NAME_FUNC_OFFSET( 6330, glVertexAttribDivisor, glVertexAttribDivisor, NULL, 440),
    NAME_FUNC_OFFSET( 6352, glLoadTransposeMatrixdARB, glLoadTransposeMatrixdARB, NULL, 441),
    NAME_FUNC_OFFSET( 6378, glLoadTransposeMatrixfARB, glLoadTransposeMatrixfARB, NULL, 442),
    NAME_FUNC_OFFSET( 6404, glMultTransposeMatrixdARB, glMultTransposeMatrixdARB, NULL, 443),
    NAME_FUNC_OFFSET( 6430, glMultTransposeMatrixfARB, glMultTransposeMatrixfARB, NULL, 444),
    NAME_FUNC_OFFSET( 6456, glSampleCoverageARB, glSampleCoverageARB, NULL, 445),
    NAME_FUNC_OFFSET( 6476, glCompressedTexImage1DARB, glCompressedTexImage1DARB, NULL, 446),
    NAME_FUNC_OFFSET( 6502, glCompressedTexImage2DARB, glCompressedTexImage2DARB, NULL, 447),
    NAME_FUNC_OFFSET( 6528, glCompressedTexImage3DARB, glCompressedTexImage3DARB, NULL, 448),
    NAME_FUNC_OFFSET( 6554, glCompressedTexSubImage1DARB, glCompressedTexSubImage1DARB, NULL, 449),
    NAME_FUNC_OFFSET( 6583, glCompressedTexSubImage2DARB, glCompressedTexSubImage2DARB, NULL, 450),
    NAME_FUNC_OFFSET( 6612, glCompressedTexSubImage3DARB, glCompressedTexSubImage3DARB, NULL, 451),
    NAME_FUNC_OFFSET( 6641, glGetCompressedTexImageARB, glGetCompressedTexImageARB, NULL, 452),
    NAME_FUNC_OFFSET( 6668, glDisableVertexAttribArrayARB, glDisableVertexAttribArrayARB, NULL, 453),
    NAME_FUNC_OFFSET( 6698, glEnableVertexAttribArrayARB, glEnableVertexAttribArrayARB, NULL, 454),
    NAME_FUNC_OFFSET( 6727, glGetProgramEnvParameterdvARB, glGetProgramEnvParameterdvARB, NULL, 455),
    NAME_FUNC_OFFSET( 6757, glGetProgramEnvParameterfvARB, glGetProgramEnvParameterfvARB, NULL, 456),
    NAME_FUNC_OFFSET( 6787, glGetProgramLocalParameterdvARB, glGetProgramLocalParameterdvARB, NULL, 457),
    NAME_FUNC_OFFSET( 6819, glGetProgramLocalParameterfvARB, glGetProgramLocalParameterfvARB, NULL, 458),
    NAME_FUNC_OFFSET( 6851, glGetProgramStringARB, glGetProgramStringARB, NULL, 459),
    NAME_FUNC_OFFSET( 6873, glGetProgramivARB, glGetProgramivARB, NULL, 460),
    NAME_FUNC_OFFSET( 6891, glGetVertexAttribdvARB, glGetVertexAttribdvARB, NULL, 461),
    NAME_FUNC_OFFSET( 6914, glGetVertexAttribfvARB, glGetVertexAttribfvARB, NULL, 462),
    NAME_FUNC_OFFSET( 6937, glGetVertexAttribivARB, glGetVertexAttribivARB, NULL, 463),
    NAME_FUNC_OFFSET( 6960, glProgramEnvParameter4dARB, glProgramEnvParameter4dARB, NULL, 464),
    NAME_FUNC_OFFSET( 6987, glProgramEnvParameter4dvARB, glProgramEnvParameter4dvARB, NULL, 465),
    NAME_FUNC_OFFSET( 7015, glProgramEnvParameter4fARB, glProgramEnvParameter4fARB, NULL, 466),
    NAME_FUNC_OFFSET( 7042, glProgramEnvParameter4fvARB, glProgramEnvParameter4fvARB, NULL, 467),
    NAME_FUNC_OFFSET( 7070, glProgramLocalParameter4dARB, glProgramLocalParameter4dARB, NULL, 468),
    NAME_FUNC_OFFSET( 7099, glProgramLocalParameter4dvARB, glProgramLocalParameter4dvARB, NULL, 469),
    NAME_FUNC_OFFSET( 7129, glProgramLocalParameter4fARB, glProgramLocalParameter4fARB, NULL, 470),
    NAME_FUNC_OFFSET( 7158, glProgramLocalParameter4fvARB, glProgramLocalParameter4fvARB, NULL, 471),
    NAME_FUNC_OFFSET( 7188, glProgramStringARB, glProgramStringARB, NULL, 472),
    NAME_FUNC_OFFSET( 7207, glVertexAttrib1dARB, glVertexAttrib1dARB, NULL, 473),
    NAME_FUNC_OFFSET( 7227, glVertexAttrib1dvARB, glVertexAttrib1dvARB, NULL, 474),
    NAME_FUNC_OFFSET( 7248, glVertexAttrib1fARB, glVertexAttrib1fARB, NULL, 475),
    NAME_FUNC_OFFSET( 7268, glVertexAttrib1fvARB, glVertexAttrib1fvARB, NULL, 476),
    NAME_FUNC_OFFSET( 7289, glVertexAttrib1sARB, glVertexAttrib1sARB, NULL, 477),
    NAME_FUNC_OFFSET( 7309, glVertexAttrib1svARB, glVertexAttrib1svARB, NULL, 478),
    NAME_FUNC_OFFSET( 7330, glVertexAttrib2dARB, glVertexAttrib2dARB, NULL, 479),
    NAME_FUNC_OFFSET( 7350, glVertexAttrib2dvARB, glVertexAttrib2dvARB, NULL, 480),
    NAME_FUNC_OFFSET( 7371, glVertexAttrib2fARB, glVertexAttrib2fARB, NULL, 481),
    NAME_FUNC_OFFSET( 7391, glVertexAttrib2fvARB, glVertexAttrib2fvARB, NULL, 482),
    NAME_FUNC_OFFSET( 7412, glVertexAttrib2sARB, glVertexAttrib2sARB, NULL, 483),
    NAME_FUNC_OFFSET( 7432, glVertexAttrib2svARB, glVertexAttrib2svARB, NULL, 484),
    NAME_FUNC_OFFSET( 7453, glVertexAttrib3dARB, glVertexAttrib3dARB, NULL, 485),
    NAME_FUNC_OFFSET( 7473, glVertexAttrib3dvARB, glVertexAttrib3dvARB, NULL, 486),
    NAME_FUNC_OFFSET( 7494, glVertexAttrib3fARB, glVertexAttrib3fARB, NULL, 487),
    NAME_FUNC_OFFSET( 7514, glVertexAttrib3fvARB, glVertexAttrib3fvARB, NULL, 488),
    NAME_FUNC_OFFSET( 7535, glVertexAttrib3sARB, glVertexAttrib3sARB, NULL, 489),
    NAME_FUNC_OFFSET( 7555, glVertexAttrib3svARB, glVertexAttrib3svARB, NULL, 490),
    NAME_FUNC_OFFSET( 7576, glVertexAttrib4NbvARB, glVertexAttrib4NbvARB, NULL, 491),
    NAME_FUNC_OFFSET( 7598, glVertexAttrib4NivARB, glVertexAttrib4NivARB, NULL, 492),
    NAME_FUNC_OFFSET( 7620, glVertexAttrib4NsvARB, glVertexAttrib4NsvARB, NULL, 493),
    NAME_FUNC_OFFSET( 7642, glVertexAttrib4NubARB, glVertexAttrib4NubARB, NULL, 494),
    NAME_FUNC_OFFSET( 7664, glVertexAttrib4NubvARB, glVertexAttrib4NubvARB, NULL, 495),
    NAME_FUNC_OFFSET( 7687, glVertexAttrib4NuivARB, glVertexAttrib4NuivARB, NULL, 496),
    NAME_FUNC_OFFSET( 7710, glVertexAttrib4NusvARB, glVertexAttrib4NusvARB, NULL, 497),
    NAME_FUNC_OFFSET( 7733, glVertexAttrib4bvARB, glVertexAttrib4bvARB, NULL, 498),
    NAME_FUNC_OFFSET( 7754, glVertexAttrib4dARB, glVertexAttrib4dARB, NULL, 499),
    NAME_FUNC_OFFSET( 7774, glVertexAttrib4dvARB, glVertexAttrib4dvARB, NULL, 500),
    NAME_FUNC_OFFSET( 7795, glVertexAttrib4fARB, glVertexAttrib4fARB, NULL, 501),
    NAME_FUNC_OFFSET( 7815, glVertexAttrib4fvARB, glVertexAttrib4fvARB, NULL, 502),
    NAME_FUNC_OFFSET( 7836, glVertexAttrib4ivARB, glVertexAttrib4ivARB, NULL, 503),
    NAME_FUNC_OFFSET( 7857, glVertexAttrib4sARB, glVertexAttrib4sARB, NULL, 504),
    NAME_FUNC_OFFSET( 7877, glVertexAttrib4svARB, glVertexAttrib4svARB, NULL, 505),
    NAME_FUNC_OFFSET( 7898, glVertexAttrib4ubvARB, glVertexAttrib4ubvARB, NULL, 506),
    NAME_FUNC_OFFSET( 7920, glVertexAttrib4uivARB, glVertexAttrib4uivARB, NULL, 507),
    NAME_FUNC_OFFSET( 7942, glVertexAttrib4usvARB, glVertexAttrib4usvARB, NULL, 508),
    NAME_FUNC_OFFSET( 7964, glVertexAttribPointerARB, glVertexAttribPointerARB, NULL, 509),
    NAME_FUNC_OFFSET( 7989, glBindBufferARB, glBindBufferARB, NULL, 510),
    NAME_FUNC_OFFSET( 8005, glBufferDataARB, glBufferDataARB, NULL, 511),
    NAME_FUNC_OFFSET( 8021, glBufferSubDataARB, glBufferSubDataARB, NULL, 512),
    NAME_FUNC_OFFSET( 8040, glDeleteBuffersARB, glDeleteBuffersARB, NULL, 513),
    NAME_FUNC_OFFSET( 8059, glGenBuffersARB, glGenBuffersARB, NULL, 514),
    NAME_FUNC_OFFSET( 8075, glGetBufferParameterivARB, glGetBufferParameterivARB, NULL, 515),
    NAME_FUNC_OFFSET( 8101, glGetBufferPointervARB, glGetBufferPointervARB, NULL, 516),
    NAME_FUNC_OFFSET( 8124, glGetBufferSubDataARB, glGetBufferSubDataARB, NULL, 517),
    NAME_FUNC_OFFSET( 8146, glIsBufferARB, glIsBufferARB, NULL, 518),
    NAME_FUNC_OFFSET( 8160, glMapBufferARB, glMapBufferARB, NULL, 519),
    NAME_FUNC_OFFSET( 8175, glUnmapBufferARB, glUnmapBufferARB, NULL, 520),
    NAME_FUNC_OFFSET( 8192, glBeginQueryARB, glBeginQueryARB, NULL, 521),
    NAME_FUNC_OFFSET( 8208, glDeleteQueriesARB, glDeleteQueriesARB, NULL, 522),
    NAME_FUNC_OFFSET( 8227, glEndQueryARB, glEndQueryARB, NULL, 523),
    NAME_FUNC_OFFSET( 8241, glGenQueriesARB, glGenQueriesARB, NULL, 524),
    NAME_FUNC_OFFSET( 8257, glGetQueryObjectivARB, glGetQueryObjectivARB, NULL, 525),
    NAME_FUNC_OFFSET( 8279, glGetQueryObjectuivARB, glGetQueryObjectuivARB, NULL, 526),
    NAME_FUNC_OFFSET( 8302, glGetQueryivARB, glGetQueryivARB, NULL, 527),
    NAME_FUNC_OFFSET( 8318, glIsQueryARB, glIsQueryARB, NULL, 528),
    NAME_FUNC_OFFSET( 8331, glAttachObjectARB, glAttachObjectARB, NULL, 529),
    NAME_FUNC_OFFSET( 8349, glCompileShaderARB, glCompileShaderARB, NULL, 530),
    NAME_FUNC_OFFSET( 8368, glCreateProgramObjectARB, glCreateProgramObjectARB, NULL, 531),
    NAME_FUNC_OFFSET( 8393, glCreateShaderObjectARB, glCreateShaderObjectARB, NULL, 532),
    NAME_FUNC_OFFSET( 8417, glDeleteObjectARB, glDeleteObjectARB, NULL, 533),
    NAME_FUNC_OFFSET( 8435, glDetachObjectARB, glDetachObjectARB, NULL, 534),
    NAME_FUNC_OFFSET( 8453, glGetActiveUniformARB, glGetActiveUniformARB, NULL, 535),
    NAME_FUNC_OFFSET( 8475, glGetAttachedObjectsARB, glGetAttachedObjectsARB, NULL, 536),
    NAME_FUNC_OFFSET( 8499, glGetHandleARB, glGetHandleARB, NULL, 537),
    NAME_FUNC_OFFSET( 8514, glGetInfoLogARB, glGetInfoLogARB, NULL, 538),
    NAME_FUNC_OFFSET( 8530, glGetObjectParameterfvARB, glGetObjectParameterfvARB, NULL, 539),
    NAME_FUNC_OFFSET( 8556, glGetObjectParameterivARB, glGetObjectParameterivARB, NULL, 540),
    NAME_FUNC_OFFSET( 8582, glGetShaderSourceARB, glGetShaderSourceARB, NULL, 541),
    NAME_FUNC_OFFSET( 8603, glGetUniformLocationARB, glGetUniformLocationARB, NULL, 542),
    NAME_FUNC_OFFSET( 8627, glGetUniformfvARB, glGetUniformfvARB, NULL, 543),
    NAME_FUNC_OFFSET( 8645, glGetUniformivARB, glGetUniformivARB, NULL, 544),
    NAME_FUNC_OFFSET( 8663, glLinkProgramARB, glLinkProgramARB, NULL, 545),
    NAME_FUNC_OFFSET( 8680, glShaderSourceARB, glShaderSourceARB, NULL, 546),
    NAME_FUNC_OFFSET( 8698, glUniform1fARB, glUniform1fARB, NULL, 547),
    NAME_FUNC_OFFSET( 8713, glUniform1fvARB, glUniform1fvARB, NULL, 548),
    NAME_FUNC_OFFSET( 8729, glUniform1iARB, glUniform1iARB, NULL, 549),
    NAME_FUNC_OFFSET( 8744, glUniform1ivARB, glUniform1ivARB, NULL, 550),
    NAME_FUNC_OFFSET( 8760, glUniform2fARB, glUniform2fARB, NULL, 551),
    NAME_FUNC_OFFSET( 8775, glUniform2fvARB, glUniform2fvARB, NULL, 552),
    NAME_FUNC_OFFSET( 8791, glUniform2iARB, glUniform2iARB, NULL, 553),
    NAME_FUNC_OFFSET( 8806, glUniform2ivARB, glUniform2ivARB, NULL, 554),
    NAME_FUNC_OFFSET( 8822, glUniform3fARB, glUniform3fARB, NULL, 555),
    NAME_FUNC_OFFSET( 8837, glUniform3fvARB, glUniform3fvARB, NULL, 556),
    NAME_FUNC_OFFSET( 8853, glUniform3iARB, glUniform3iARB, NULL, 557),
    NAME_FUNC_OFFSET( 8868, glUniform3ivARB, glUniform3ivARB, NULL, 558),
    NAME_FUNC_OFFSET( 8884, glUniform4fARB, glUniform4fARB, NULL, 559),
    NAME_FUNC_OFFSET( 8899, glUniform4fvARB, glUniform4fvARB, NULL, 560),
    NAME_FUNC_OFFSET( 8915, glUniform4iARB, glUniform4iARB, NULL, 561),
    NAME_FUNC_OFFSET( 8930, glUniform4ivARB, glUniform4ivARB, NULL, 562),
    NAME_FUNC_OFFSET( 8946, glUniformMatrix2fvARB, glUniformMatrix2fvARB, NULL, 563),
    NAME_FUNC_OFFSET( 8968, glUniformMatrix3fvARB, glUniformMatrix3fvARB, NULL, 564),
    NAME_FUNC_OFFSET( 8990, glUniformMatrix4fvARB, glUniformMatrix4fvARB, NULL, 565),
    NAME_FUNC_OFFSET( 9012, glUseProgramObjectARB, glUseProgramObjectARB, NULL, 566),
    NAME_FUNC_OFFSET( 9034, glValidateProgramARB, glValidateProgramARB, NULL, 567),
    NAME_FUNC_OFFSET( 9055, glBindAttribLocationARB, glBindAttribLocationARB, NULL, 568),
    NAME_FUNC_OFFSET( 9079, glGetActiveAttribARB, glGetActiveAttribARB, NULL, 569),
    NAME_FUNC_OFFSET( 9100, glGetAttribLocationARB, glGetAttribLocationARB, NULL, 570),
    NAME_FUNC_OFFSET( 9123, glDrawBuffersARB, glDrawBuffersARB, NULL, 571),
    NAME_FUNC_OFFSET( 9140, glClampColorARB, glClampColorARB, NULL, 572),
    NAME_FUNC_OFFSET( 9156, glDrawArraysInstancedARB, glDrawArraysInstancedARB, NULL, 573),
    NAME_FUNC_OFFSET( 9181, glDrawElementsInstancedARB, glDrawElementsInstancedARB, NULL, 574),
    NAME_FUNC_OFFSET( 9208, glRenderbufferStorageMultisample, glRenderbufferStorageMultisample, NULL, 575),
    NAME_FUNC_OFFSET( 9241, glFramebufferTextureARB, glFramebufferTextureARB, NULL, 576),
    NAME_FUNC_OFFSET( 9265, glFramebufferTextureFaceARB, glFramebufferTextureFaceARB, NULL, 577),
    NAME_FUNC_OFFSET( 9293, glProgramParameteriARB, glProgramParameteriARB, NULL, 578),
    NAME_FUNC_OFFSET( 9316, glVertexAttribDivisorARB, glVertexAttribDivisorARB, NULL, 579),
    NAME_FUNC_OFFSET( 9341, glFlushMappedBufferRange, glFlushMappedBufferRange, NULL, 580),
    NAME_FUNC_OFFSET( 9366, glMapBufferRange, glMapBufferRange, NULL, 581),
    NAME_FUNC_OFFSET( 9383, glTexBufferARB, glTexBufferARB, NULL, 582),
    NAME_FUNC_OFFSET( 9398, glBindVertexArray, glBindVertexArray, NULL, 583),
    NAME_FUNC_OFFSET( 9416, glGenVertexArrays, glGenVertexArrays, NULL, 584),
    NAME_FUNC_OFFSET( 9434, glCopyBufferSubData, glCopyBufferSubData, NULL, 585),
    NAME_FUNC_OFFSET( 9454, glClientWaitSync, glClientWaitSync, NULL, 586),
    NAME_FUNC_OFFSET( 9471, glDeleteSync, glDeleteSync, NULL, 587),
    NAME_FUNC_OFFSET( 9484, glFenceSync, glFenceSync, NULL, 588),
    NAME_FUNC_OFFSET( 9496, glGetInteger64v, glGetInteger64v, NULL, 589),
    NAME_FUNC_OFFSET( 9512, glGetSynciv, glGetSynciv, NULL, 590),
    NAME_FUNC_OFFSET( 9524, glIsSync, glIsSync, NULL, 591),
    NAME_FUNC_OFFSET( 9533, glWaitSync, glWaitSync, NULL, 592),
    NAME_FUNC_OFFSET( 9544, glDrawElementsBaseVertex, glDrawElementsBaseVertex, NULL, 593),
    NAME_FUNC_OFFSET( 9569, glDrawElementsInstancedBaseVertex, glDrawElementsInstancedBaseVertex, NULL, 594),
    NAME_FUNC_OFFSET( 9603, glDrawRangeElementsBaseVertex, glDrawRangeElementsBaseVertex, NULL, 595),
    NAME_FUNC_OFFSET( 9633, glMultiDrawElementsBaseVertex, glMultiDrawElementsBaseVertex, NULL, 596),
    NAME_FUNC_OFFSET( 9663, glBlendEquationSeparateiARB, glBlendEquationSeparateiARB, NULL, 597),
    NAME_FUNC_OFFSET( 9691, glBlendEquationiARB, glBlendEquationiARB, NULL, 598),
    NAME_FUNC_OFFSET( 9711, glBlendFuncSeparateiARB, glBlendFuncSeparateiARB, NULL, 599),
    NAME_FUNC_OFFSET( 9735, glBlendFunciARB, glBlendFunciARB, NULL, 600),
    NAME_FUNC_OFFSET( 9751, glBindSampler, glBindSampler, NULL, 601),
    NAME_FUNC_OFFSET( 9765, glDeleteSamplers, glDeleteSamplers, NULL, 602),
    NAME_FUNC_OFFSET( 9782, glGenSamplers, glGenSamplers, NULL, 603),
    NAME_FUNC_OFFSET( 9796, glGetSamplerParameterIiv, glGetSamplerParameterIiv, NULL, 604),
    NAME_FUNC_OFFSET( 9821, glGetSamplerParameterIuiv, glGetSamplerParameterIuiv, NULL, 605),
    NAME_FUNC_OFFSET( 9847, glGetSamplerParameterfv, glGetSamplerParameterfv, NULL, 606),
    NAME_FUNC_OFFSET( 9871, glGetSamplerParameteriv, glGetSamplerParameteriv, NULL, 607),
    NAME_FUNC_OFFSET( 9895, glIsSampler, glIsSampler, NULL, 608),
    NAME_FUNC_OFFSET( 9907, glSamplerParameterIiv, glSamplerParameterIiv, NULL, 609),
    NAME_FUNC_OFFSET( 9929, glSamplerParameterIuiv, glSamplerParameterIuiv, NULL, 610),
    NAME_FUNC_OFFSET( 9952, glSamplerParameterf, glSamplerParameterf, NULL, 611),
    NAME_FUNC_OFFSET( 9972, glSamplerParameterfv, glSamplerParameterfv, NULL, 612),
    NAME_FUNC_OFFSET( 9993, glSamplerParameteri, glSamplerParameteri, NULL, 613),
    NAME_FUNC_OFFSET(10013, glSamplerParameteriv, glSamplerParameteriv, NULL, 614),
    NAME_FUNC_OFFSET(10034, glColorP3ui, glColorP3ui, NULL, 615),
    NAME_FUNC_OFFSET(10046, glColorP3uiv, glColorP3uiv, NULL, 616),
    NAME_FUNC_OFFSET(10059, glColorP4ui, glColorP4ui, NULL, 617),
    NAME_FUNC_OFFSET(10071, glColorP4uiv, glColorP4uiv, NULL, 618),
    NAME_FUNC_OFFSET(10084, glMultiTexCoordP1ui, glMultiTexCoordP1ui, NULL, 619),
    NAME_FUNC_OFFSET(10104, glMultiTexCoordP1uiv, glMultiTexCoordP1uiv, NULL, 620),
    NAME_FUNC_OFFSET(10125, glMultiTexCoordP2ui, glMultiTexCoordP2ui, NULL, 621),
    NAME_FUNC_OFFSET(10145, glMultiTexCoordP2uiv, glMultiTexCoordP2uiv, NULL, 622),
    NAME_FUNC_OFFSET(10166, glMultiTexCoordP3ui, glMultiTexCoordP3ui, NULL, 623),
    NAME_FUNC_OFFSET(10186, glMultiTexCoordP3uiv, glMultiTexCoordP3uiv, NULL, 624),
    NAME_FUNC_OFFSET(10207, glMultiTexCoordP4ui, glMultiTexCoordP4ui, NULL, 625),
    NAME_FUNC_OFFSET(10227, glMultiTexCoordP4uiv, glMultiTexCoordP4uiv, NULL, 626),
    NAME_FUNC_OFFSET(10248, glNormalP3ui, glNormalP3ui, NULL, 627),
    NAME_FUNC_OFFSET(10261, glNormalP3uiv, glNormalP3uiv, NULL, 628),
    NAME_FUNC_OFFSET(10275, glSecondaryColorP3ui, glSecondaryColorP3ui, NULL, 629),
    NAME_FUNC_OFFSET(10296, glSecondaryColorP3uiv, glSecondaryColorP3uiv, NULL, 630),
    NAME_FUNC_OFFSET(10318, glTexCoordP1ui, glTexCoordP1ui, NULL, 631),
    NAME_FUNC_OFFSET(10333, glTexCoordP1uiv, glTexCoordP1uiv, NULL, 632),
    NAME_FUNC_OFFSET(10349, glTexCoordP2ui, glTexCoordP2ui, NULL, 633),
    NAME_FUNC_OFFSET(10364, glTexCoordP2uiv, glTexCoordP2uiv, NULL, 634),
    NAME_FUNC_OFFSET(10380, glTexCoordP3ui, glTexCoordP3ui, NULL, 635),
    NAME_FUNC_OFFSET(10395, glTexCoordP3uiv, glTexCoordP3uiv, NULL, 636),
    NAME_FUNC_OFFSET(10411, glTexCoordP4ui, glTexCoordP4ui, NULL, 637),
    NAME_FUNC_OFFSET(10426, glTexCoordP4uiv, glTexCoordP4uiv, NULL, 638),
    NAME_FUNC_OFFSET(10442, glVertexAttribP1ui, glVertexAttribP1ui, NULL, 639),
    NAME_FUNC_OFFSET(10461, glVertexAttribP1uiv, glVertexAttribP1uiv, NULL, 640),
    NAME_FUNC_OFFSET(10481, glVertexAttribP2ui, glVertexAttribP2ui, NULL, 641),
    NAME_FUNC_OFFSET(10500, glVertexAttribP2uiv, glVertexAttribP2uiv, NULL, 642),
    NAME_FUNC_OFFSET(10520, glVertexAttribP3ui, glVertexAttribP3ui, NULL, 643),
    NAME_FUNC_OFFSET(10539, glVertexAttribP3uiv, glVertexAttribP3uiv, NULL, 644),
    NAME_FUNC_OFFSET(10559, glVertexAttribP4ui, glVertexAttribP4ui, NULL, 645),
    NAME_FUNC_OFFSET(10578, glVertexAttribP4uiv, glVertexAttribP4uiv, NULL, 646),
    NAME_FUNC_OFFSET(10598, glVertexP2ui, glVertexP2ui, NULL, 647),
    NAME_FUNC_OFFSET(10611, glVertexP2uiv, glVertexP2uiv, NULL, 648),
    NAME_FUNC_OFFSET(10625, glVertexP3ui, glVertexP3ui, NULL, 649),
    NAME_FUNC_OFFSET(10638, glVertexP3uiv, glVertexP3uiv, NULL, 650),
    NAME_FUNC_OFFSET(10652, glVertexP4ui, glVertexP4ui, NULL, 651),
    NAME_FUNC_OFFSET(10665, glVertexP4uiv, glVertexP4uiv, NULL, 652),
    NAME_FUNC_OFFSET(10679, glBindTransformFeedback, glBindTransformFeedback, NULL, 653),
    NAME_FUNC_OFFSET(10703, glDeleteTransformFeedbacks, glDeleteTransformFeedbacks, NULL, 654),
    NAME_FUNC_OFFSET(10730, glDrawTransformFeedback, glDrawTransformFeedback, NULL, 655),
    NAME_FUNC_OFFSET(10754, glGenTransformFeedbacks, glGenTransformFeedbacks, NULL, 656),
    NAME_FUNC_OFFSET(10778, glIsTransformFeedback, glIsTransformFeedback, NULL, 657),
    NAME_FUNC_OFFSET(10800, glPauseTransformFeedback, glPauseTransformFeedback, NULL, 658),
    NAME_FUNC_OFFSET(10825, glResumeTransformFeedback, glResumeTransformFeedback, NULL, 659),
    NAME_FUNC_OFFSET(10851, glClearDepthf, glClearDepthf, NULL, 660),
    NAME_FUNC_OFFSET(10865, glDepthRangef, glDepthRangef, NULL, 661),
    NAME_FUNC_OFFSET(10879, glGetShaderPrecisionFormat, glGetShaderPrecisionFormat, NULL, 662),
    NAME_FUNC_OFFSET(10906, glReleaseShaderCompiler, glReleaseShaderCompiler, NULL, 663),
    NAME_FUNC_OFFSET(10930, glShaderBinary, glShaderBinary, NULL, 664),
    NAME_FUNC_OFFSET(10945, glGetGraphicsResetStatusARB, glGetGraphicsResetStatusARB, NULL, 665),
    NAME_FUNC_OFFSET(10973, glGetnColorTableARB, glGetnColorTableARB, NULL, 666),
    NAME_FUNC_OFFSET(10993, glGetnCompressedTexImageARB, glGetnCompressedTexImageARB, NULL, 667),
    NAME_FUNC_OFFSET(11021, glGetnConvolutionFilterARB, glGetnConvolutionFilterARB, NULL, 668),
    NAME_FUNC_OFFSET(11048, glGetnHistogramARB, glGetnHistogramARB, NULL, 669),
    NAME_FUNC_OFFSET(11067, glGetnMapdvARB, glGetnMapdvARB, NULL, 670),
    NAME_FUNC_OFFSET(11082, glGetnMapfvARB, glGetnMapfvARB, NULL, 671),
    NAME_FUNC_OFFSET(11097, glGetnMapivARB, glGetnMapivARB, NULL, 672),
    NAME_FUNC_OFFSET(11112, glGetnMinmaxARB, glGetnMinmaxARB, NULL, 673),
    NAME_FUNC_OFFSET(11128, glGetnPixelMapfvARB, glGetnPixelMapfvARB, NULL, 674),
    NAME_FUNC_OFFSET(11148, glGetnPixelMapuivARB, glGetnPixelMapuivARB, NULL, 675),
    NAME_FUNC_OFFSET(11169, glGetnPixelMapusvARB, glGetnPixelMapusvARB, NULL, 676),
    NAME_FUNC_OFFSET(11190, glGetnPolygonStippleARB, glGetnPolygonStippleARB, NULL, 677),
    NAME_FUNC_OFFSET(11214, glGetnSeparableFilterARB, glGetnSeparableFilterARB, NULL, 678),
    NAME_FUNC_OFFSET(11239, glGetnTexImageARB, glGetnTexImageARB, NULL, 679),
    NAME_FUNC_OFFSET(11257, glGetnUniformdvARB, glGetnUniformdvARB, NULL, 680),
    NAME_FUNC_OFFSET(11276, glGetnUniformfvARB, glGetnUniformfvARB, NULL, 681),
    NAME_FUNC_OFFSET(11295, glGetnUniformivARB, glGetnUniformivARB, NULL, 682),
    NAME_FUNC_OFFSET(11314, glGetnUniformuivARB, glGetnUniformuivARB, NULL, 683),
    NAME_FUNC_OFFSET(11334, glReadnPixelsARB, glReadnPixelsARB, NULL, 684),
    NAME_FUNC_OFFSET(11351, glPolygonOffsetEXT, glPolygonOffsetEXT, NULL, 685),
    NAME_FUNC_OFFSET(11370, gl_dispatch_stub_686, gl_dispatch_stub_686, NULL, 686),
    NAME_FUNC_OFFSET(11402, gl_dispatch_stub_687, gl_dispatch_stub_687, NULL, 687),
    NAME_FUNC_OFFSET(11434, gl_dispatch_stub_688, gl_dispatch_stub_688, NULL, 688),
    NAME_FUNC_OFFSET(11462, gl_dispatch_stub_689, gl_dispatch_stub_689, NULL, 689),
    NAME_FUNC_OFFSET(11491, gl_dispatch_stub_690, gl_dispatch_stub_690, NULL, 690),
    NAME_FUNC_OFFSET(11519, gl_dispatch_stub_691, gl_dispatch_stub_691, NULL, 691),
    NAME_FUNC_OFFSET(11548, gl_dispatch_stub_692, gl_dispatch_stub_692, NULL, 692),
    NAME_FUNC_OFFSET(11565, gl_dispatch_stub_693, gl_dispatch_stub_693, NULL, 693),
    NAME_FUNC_OFFSET(11585, glColorPointerEXT, glColorPointerEXT, NULL, 694),
    NAME_FUNC_OFFSET(11603, glEdgeFlagPointerEXT, glEdgeFlagPointerEXT, NULL, 695),
    NAME_FUNC_OFFSET(11624, glIndexPointerEXT, glIndexPointerEXT, NULL, 696),
    NAME_FUNC_OFFSET(11642, glNormalPointerEXT, glNormalPointerEXT, NULL, 697),
    NAME_FUNC_OFFSET(11661, glTexCoordPointerEXT, glTexCoordPointerEXT, NULL, 698),
    NAME_FUNC_OFFSET(11682, glVertexPointerEXT, glVertexPointerEXT, NULL, 699),
    NAME_FUNC_OFFSET(11701, glPointParameterfEXT, glPointParameterfEXT, NULL, 700),
    NAME_FUNC_OFFSET(11722, glPointParameterfvEXT, glPointParameterfvEXT, NULL, 701),
    NAME_FUNC_OFFSET(11744, glLockArraysEXT, glLockArraysEXT, NULL, 702),
    NAME_FUNC_OFFSET(11760, glUnlockArraysEXT, glUnlockArraysEXT, NULL, 703),
    NAME_FUNC_OFFSET(11778, glSecondaryColor3bEXT, glSecondaryColor3bEXT, NULL, 704),
    NAME_FUNC_OFFSET(11800, glSecondaryColor3bvEXT, glSecondaryColor3bvEXT, NULL, 705),
    NAME_FUNC_OFFSET(11823, glSecondaryColor3dEXT, glSecondaryColor3dEXT, NULL, 706),
    NAME_FUNC_OFFSET(11845, glSecondaryColor3dvEXT, glSecondaryColor3dvEXT, NULL, 707),
    NAME_FUNC_OFFSET(11868, glSecondaryColor3fEXT, glSecondaryColor3fEXT, NULL, 708),
    NAME_FUNC_OFFSET(11890, glSecondaryColor3fvEXT, glSecondaryColor3fvEXT, NULL, 709),
    NAME_FUNC_OFFSET(11913, glSecondaryColor3iEXT, glSecondaryColor3iEXT, NULL, 710),
    NAME_FUNC_OFFSET(11935, glSecondaryColor3ivEXT, glSecondaryColor3ivEXT, NULL, 711),
    NAME_FUNC_OFFSET(11958, glSecondaryColor3sEXT, glSecondaryColor3sEXT, NULL, 712),
    NAME_FUNC_OFFSET(11980, glSecondaryColor3svEXT, glSecondaryColor3svEXT, NULL, 713),
    NAME_FUNC_OFFSET(12003, glSecondaryColor3ubEXT, glSecondaryColor3ubEXT, NULL, 714),
    NAME_FUNC_OFFSET(12026, glSecondaryColor3ubvEXT, glSecondaryColor3ubvEXT, NULL, 715),
    NAME_FUNC_OFFSET(12050, glSecondaryColor3uiEXT, glSecondaryColor3uiEXT, NULL, 716),
    NAME_FUNC_OFFSET(12073, glSecondaryColor3uivEXT, glSecondaryColor3uivEXT, NULL, 717),
    NAME_FUNC_OFFSET(12097, glSecondaryColor3usEXT, glSecondaryColor3usEXT, NULL, 718),
    NAME_FUNC_OFFSET(12120, glSecondaryColor3usvEXT, glSecondaryColor3usvEXT, NULL, 719),
    NAME_FUNC_OFFSET(12144, glSecondaryColorPointerEXT, glSecondaryColorPointerEXT, NULL, 720),
    NAME_FUNC_OFFSET(12171, glMultiDrawArraysEXT, glMultiDrawArraysEXT, NULL, 721),
    NAME_FUNC_OFFSET(12192, glMultiDrawElementsEXT, glMultiDrawElementsEXT, NULL, 722),
    NAME_FUNC_OFFSET(12215, glFogCoordPointerEXT, glFogCoordPointerEXT, NULL, 723),
    NAME_FUNC_OFFSET(12236, glFogCoorddEXT, glFogCoorddEXT, NULL, 724),
    NAME_FUNC_OFFSET(12251, glFogCoorddvEXT, glFogCoorddvEXT, NULL, 725),
    NAME_FUNC_OFFSET(12267, glFogCoordfEXT, glFogCoordfEXT, NULL, 726),
    NAME_FUNC_OFFSET(12282, glFogCoordfvEXT, glFogCoordfvEXT, NULL, 727),
    NAME_FUNC_OFFSET(12298, gl_dispatch_stub_728, gl_dispatch_stub_728, NULL, 728),
    NAME_FUNC_OFFSET(12316, glBlendFuncSeparateEXT, glBlendFuncSeparateEXT, NULL, 729),
    NAME_FUNC_OFFSET(12339, glFlushVertexArrayRangeNV, glFlushVertexArrayRangeNV, NULL, 730),
    NAME_FUNC_OFFSET(12365, glVertexArrayRangeNV, glVertexArrayRangeNV, NULL, 731),
    NAME_FUNC_OFFSET(12386, glCombinerInputNV, glCombinerInputNV, NULL, 732),
    NAME_FUNC_OFFSET(12404, glCombinerOutputNV, glCombinerOutputNV, NULL, 733),
    NAME_FUNC_OFFSET(12423, glCombinerParameterfNV, glCombinerParameterfNV, NULL, 734),
    NAME_FUNC_OFFSET(12446, glCombinerParameterfvNV, glCombinerParameterfvNV, NULL, 735),
    NAME_FUNC_OFFSET(12470, glCombinerParameteriNV, glCombinerParameteriNV, NULL, 736),
    NAME_FUNC_OFFSET(12493, glCombinerParameterivNV, glCombinerParameterivNV, NULL, 737),
    NAME_FUNC_OFFSET(12517, glFinalCombinerInputNV, glFinalCombinerInputNV, NULL, 738),
    NAME_FUNC_OFFSET(12540, glGetCombinerInputParameterfvNV, glGetCombinerInputParameterfvNV, NULL, 739),
    NAME_FUNC_OFFSET(12572, glGetCombinerInputParameterivNV, glGetCombinerInputParameterivNV, NULL, 740),
    NAME_FUNC_OFFSET(12604, glGetCombinerOutputParameterfvNV, glGetCombinerOutputParameterfvNV, NULL, 741),
    NAME_FUNC_OFFSET(12637, glGetCombinerOutputParameterivNV, glGetCombinerOutputParameterivNV, NULL, 742),
    NAME_FUNC_OFFSET(12670, glGetFinalCombinerInputParameterfvNV, glGetFinalCombinerInputParameterfvNV, NULL, 743),
    NAME_FUNC_OFFSET(12707, glGetFinalCombinerInputParameterivNV, glGetFinalCombinerInputParameterivNV, NULL, 744),
    NAME_FUNC_OFFSET(12744, glResizeBuffersMESA, glResizeBuffersMESA, NULL, 745),
    NAME_FUNC_OFFSET(12764, glWindowPos2dMESA, glWindowPos2dMESA, NULL, 746),
    NAME_FUNC_OFFSET(12782, glWindowPos2dvMESA, glWindowPos2dvMESA, NULL, 747),
    NAME_FUNC_OFFSET(12801, glWindowPos2fMESA, glWindowPos2fMESA, NULL, 748),
    NAME_FUNC_OFFSET(12819, glWindowPos2fvMESA, glWindowPos2fvMESA, NULL, 749),
    NAME_FUNC_OFFSET(12838, glWindowPos2iMESA, glWindowPos2iMESA, NULL, 750),
    NAME_FUNC_OFFSET(12856, glWindowPos2ivMESA, glWindowPos2ivMESA, NULL, 751),
    NAME_FUNC_OFFSET(12875, glWindowPos2sMESA, glWindowPos2sMESA, NULL, 752),
    NAME_FUNC_OFFSET(12893, glWindowPos2svMESA, glWindowPos2svMESA, NULL, 753),
    NAME_FUNC_OFFSET(12912, glWindowPos3dMESA, glWindowPos3dMESA, NULL, 754),
    NAME_FUNC_OFFSET(12930, glWindowPos3dvMESA, glWindowPos3dvMESA, NULL, 755),
    NAME_FUNC_OFFSET(12949, glWindowPos3fMESA, glWindowPos3fMESA, NULL, 756),
    NAME_FUNC_OFFSET(12967, glWindowPos3fvMESA, glWindowPos3fvMESA, NULL, 757),
    NAME_FUNC_OFFSET(12986, glWindowPos3iMESA, glWindowPos3iMESA, NULL, 758),
    NAME_FUNC_OFFSET(13004, glWindowPos3ivMESA, glWindowPos3ivMESA, NULL, 759),
    NAME_FUNC_OFFSET(13023, glWindowPos3sMESA, glWindowPos3sMESA, NULL, 760),
    NAME_FUNC_OFFSET(13041, glWindowPos3svMESA, glWindowPos3svMESA, NULL, 761),
    NAME_FUNC_OFFSET(13060, glWindowPos4dMESA, glWindowPos4dMESA, NULL, 762),
    NAME_FUNC_OFFSET(13078, glWindowPos4dvMESA, glWindowPos4dvMESA, NULL, 763),
    NAME_FUNC_OFFSET(13097, glWindowPos4fMESA, glWindowPos4fMESA, NULL, 764),
    NAME_FUNC_OFFSET(13115, glWindowPos4fvMESA, glWindowPos4fvMESA, NULL, 765),
    NAME_FUNC_OFFSET(13134, glWindowPos4iMESA, glWindowPos4iMESA, NULL, 766),
    NAME_FUNC_OFFSET(13152, glWindowPos4ivMESA, glWindowPos4ivMESA, NULL, 767),
    NAME_FUNC_OFFSET(13171, glWindowPos4sMESA, glWindowPos4sMESA, NULL, 768),
    NAME_FUNC_OFFSET(13189, glWindowPos4svMESA, glWindowPos4svMESA, NULL, 769),
    NAME_FUNC_OFFSET(13208, gl_dispatch_stub_770, gl_dispatch_stub_770, NULL, 770),
    NAME_FUNC_OFFSET(13233, gl_dispatch_stub_771, gl_dispatch_stub_771, NULL, 771),
    NAME_FUNC_OFFSET(13260, gl_dispatch_stub_772, gl_dispatch_stub_772, NULL, 772),
    NAME_FUNC_OFFSET(13277, gl_dispatch_stub_773, gl_dispatch_stub_773, NULL, 773),
    NAME_FUNC_OFFSET(13293, gl_dispatch_stub_774, gl_dispatch_stub_774, NULL, 774),
    NAME_FUNC_OFFSET(13307, gl_dispatch_stub_775, gl_dispatch_stub_775, NULL, 775),
    NAME_FUNC_OFFSET(13322, gl_dispatch_stub_776, gl_dispatch_stub_776, NULL, 776),
    NAME_FUNC_OFFSET(13334, gl_dispatch_stub_777, gl_dispatch_stub_777, NULL, 777),
    NAME_FUNC_OFFSET(13347, gl_dispatch_stub_778, gl_dispatch_stub_778, NULL, 778),
    NAME_FUNC_OFFSET(13361, glAreProgramsResidentNV, glAreProgramsResidentNV, NULL, 779),
    NAME_FUNC_OFFSET(13385, glBindProgramNV, glBindProgramNV, NULL, 780),
    NAME_FUNC_OFFSET(13401, glDeleteProgramsNV, glDeleteProgramsNV, NULL, 781),
    NAME_FUNC_OFFSET(13420, glExecuteProgramNV, glExecuteProgramNV, NULL, 782),
    NAME_FUNC_OFFSET(13439, glGenProgramsNV, glGenProgramsNV, NULL, 783),
    NAME_FUNC_OFFSET(13455, glGetProgramParameterdvNV, glGetProgramParameterdvNV, NULL, 784),
    NAME_FUNC_OFFSET(13481, glGetProgramParameterfvNV, glGetProgramParameterfvNV, NULL, 785),
    NAME_FUNC_OFFSET(13507, glGetProgramStringNV, glGetProgramStringNV, NULL, 786),
    NAME_FUNC_OFFSET(13528, glGetProgramivNV, glGetProgramivNV, NULL, 787),
    NAME_FUNC_OFFSET(13545, glGetTrackMatrixivNV, glGetTrackMatrixivNV, NULL, 788),
    NAME_FUNC_OFFSET(13566, glGetVertexAttribPointervNV, glGetVertexAttribPointervNV, NULL, 789),
    NAME_FUNC_OFFSET(13594, glGetVertexAttribdvNV, glGetVertexAttribdvNV, NULL, 790),
    NAME_FUNC_OFFSET(13616, glGetVertexAttribfvNV, glGetVertexAttribfvNV, NULL, 791),
    NAME_FUNC_OFFSET(13638, glGetVertexAttribivNV, glGetVertexAttribivNV, NULL, 792),
    NAME_FUNC_OFFSET(13660, glIsProgramNV, glIsProgramNV, NULL, 793),
    NAME_FUNC_OFFSET(13674, glLoadProgramNV, glLoadProgramNV, NULL, 794),
    NAME_FUNC_OFFSET(13690, glProgramParameters4dvNV, glProgramParameters4dvNV, NULL, 795),
    NAME_FUNC_OFFSET(13715, glProgramParameters4fvNV, glProgramParameters4fvNV, NULL, 796),
    NAME_FUNC_OFFSET(13740, glRequestResidentProgramsNV, glRequestResidentProgramsNV, NULL, 797),
    NAME_FUNC_OFFSET(13768, glTrackMatrixNV, glTrackMatrixNV, NULL, 798),
    NAME_FUNC_OFFSET(13784, glVertexAttrib1dNV, glVertexAttrib1dNV, NULL, 799),
    NAME_FUNC_OFFSET(13803, glVertexAttrib1dvNV, glVertexAttrib1dvNV, NULL, 800),
    NAME_FUNC_OFFSET(13823, glVertexAttrib1fNV, glVertexAttrib1fNV, NULL, 801),
    NAME_FUNC_OFFSET(13842, glVertexAttrib1fvNV, glVertexAttrib1fvNV, NULL, 802),
    NAME_FUNC_OFFSET(13862, glVertexAttrib1sNV, glVertexAttrib1sNV, NULL, 803),
    NAME_FUNC_OFFSET(13881, glVertexAttrib1svNV, glVertexAttrib1svNV, NULL, 804),
    NAME_FUNC_OFFSET(13901, glVertexAttrib2dNV, glVertexAttrib2dNV, NULL, 805),
    NAME_FUNC_OFFSET(13920, glVertexAttrib2dvNV, glVertexAttrib2dvNV, NULL, 806),
    NAME_FUNC_OFFSET(13940, glVertexAttrib2fNV, glVertexAttrib2fNV, NULL, 807),
    NAME_FUNC_OFFSET(13959, glVertexAttrib2fvNV, glVertexAttrib2fvNV, NULL, 808),
    NAME_FUNC_OFFSET(13979, glVertexAttrib2sNV, glVertexAttrib2sNV, NULL, 809),
    NAME_FUNC_OFFSET(13998, glVertexAttrib2svNV, glVertexAttrib2svNV, NULL, 810),
    NAME_FUNC_OFFSET(14018, glVertexAttrib3dNV, glVertexAttrib3dNV, NULL, 811),
    NAME_FUNC_OFFSET(14037, glVertexAttrib3dvNV, glVertexAttrib3dvNV, NULL, 812),
    NAME_FUNC_OFFSET(14057, glVertexAttrib3fNV, glVertexAttrib3fNV, NULL, 813),
    NAME_FUNC_OFFSET(14076, glVertexAttrib3fvNV, glVertexAttrib3fvNV, NULL, 814),
    NAME_FUNC_OFFSET(14096, glVertexAttrib3sNV, glVertexAttrib3sNV, NULL, 815),
    NAME_FUNC_OFFSET(14115, glVertexAttrib3svNV, glVertexAttrib3svNV, NULL, 816),
    NAME_FUNC_OFFSET(14135, glVertexAttrib4dNV, glVertexAttrib4dNV, NULL, 817),
    NAME_FUNC_OFFSET(14154, glVertexAttrib4dvNV, glVertexAttrib4dvNV, NULL, 818),
    NAME_FUNC_OFFSET(14174, glVertexAttrib4fNV, glVertexAttrib4fNV, NULL, 819),
    NAME_FUNC_OFFSET(14193, glVertexAttrib4fvNV, glVertexAttrib4fvNV, NULL, 820),
    NAME_FUNC_OFFSET(14213, glVertexAttrib4sNV, glVertexAttrib4sNV, NULL, 821),
    NAME_FUNC_OFFSET(14232, glVertexAttrib4svNV, glVertexAttrib4svNV, NULL, 822),
    NAME_FUNC_OFFSET(14252, glVertexAttrib4ubNV, glVertexAttrib4ubNV, NULL, 823),
    NAME_FUNC_OFFSET(14272, glVertexAttrib4ubvNV, glVertexAttrib4ubvNV, NULL, 824),
    NAME_FUNC_OFFSET(14293, glVertexAttribPointerNV, glVertexAttribPointerNV, NULL, 825),
    NAME_FUNC_OFFSET(14317, glVertexAttribs1dvNV, glVertexAttribs1dvNV, NULL, 826),
    NAME_FUNC_OFFSET(14338, glVertexAttribs1fvNV, glVertexAttribs1fvNV, NULL, 827),
    NAME_FUNC_OFFSET(14359, glVertexAttribs1svNV, glVertexAttribs1svNV, NULL, 828),
    NAME_FUNC_OFFSET(14380, glVertexAttribs2dvNV, glVertexAttribs2dvNV, NULL, 829),
    NAME_FUNC_OFFSET(14401, glVertexAttribs2fvNV, glVertexAttribs2fvNV, NULL, 830),
    NAME_FUNC_OFFSET(14422, glVertexAttribs2svNV, glVertexAttribs2svNV, NULL, 831),
    NAME_FUNC_OFFSET(14443, glVertexAttribs3dvNV, glVertexAttribs3dvNV, NULL, 832),
    NAME_FUNC_OFFSET(14464, glVertexAttribs3fvNV, glVertexAttribs3fvNV, NULL, 833),
    NAME_FUNC_OFFSET(14485, glVertexAttribs3svNV, glVertexAttribs3svNV, NULL, 834),
    NAME_FUNC_OFFSET(14506, glVertexAttribs4dvNV, glVertexAttribs4dvNV, NULL, 835),
    NAME_FUNC_OFFSET(14527, glVertexAttribs4fvNV, glVertexAttribs4fvNV, NULL, 836),
    NAME_FUNC_OFFSET(14548, glVertexAttribs4svNV, glVertexAttribs4svNV, NULL, 837),
    NAME_FUNC_OFFSET(14569, glVertexAttribs4ubvNV, glVertexAttribs4ubvNV, NULL, 838),
    NAME_FUNC_OFFSET(14591, glGetTexBumpParameterfvATI, glGetTexBumpParameterfvATI, NULL, 839),
    NAME_FUNC_OFFSET(14618, glGetTexBumpParameterivATI, glGetTexBumpParameterivATI, NULL, 840),
    NAME_FUNC_OFFSET(14645, glTexBumpParameterfvATI, glTexBumpParameterfvATI, NULL, 841),
    NAME_FUNC_OFFSET(14669, glTexBumpParameterivATI, glTexBumpParameterivATI, NULL, 842),
    NAME_FUNC_OFFSET(14693, glAlphaFragmentOp1ATI, glAlphaFragmentOp1ATI, NULL, 843),
    NAME_FUNC_OFFSET(14715, glAlphaFragmentOp2ATI, glAlphaFragmentOp2ATI, NULL, 844),
    NAME_FUNC_OFFSET(14737, glAlphaFragmentOp3ATI, glAlphaFragmentOp3ATI, NULL, 845),
    NAME_FUNC_OFFSET(14759, glBeginFragmentShaderATI, glBeginFragmentShaderATI, NULL, 846),
    NAME_FUNC_OFFSET(14784, glBindFragmentShaderATI, glBindFragmentShaderATI, NULL, 847),
    NAME_FUNC_OFFSET(14808, glColorFragmentOp1ATI, glColorFragmentOp1ATI, NULL, 848),
    NAME_FUNC_OFFSET(14830, glColorFragmentOp2ATI, glColorFragmentOp2ATI, NULL, 849),
    NAME_FUNC_OFFSET(14852, glColorFragmentOp3ATI, glColorFragmentOp3ATI, NULL, 850),
    NAME_FUNC_OFFSET(14874, glDeleteFragmentShaderATI, glDeleteFragmentShaderATI, NULL, 851),
    NAME_FUNC_OFFSET(14900, glEndFragmentShaderATI, glEndFragmentShaderATI, NULL, 852),
    NAME_FUNC_OFFSET(14923, glGenFragmentShadersATI, glGenFragmentShadersATI, NULL, 853),
    NAME_FUNC_OFFSET(14947, glPassTexCoordATI, glPassTexCoordATI, NULL, 854),
    NAME_FUNC_OFFSET(14965, glSampleMapATI, glSampleMapATI, NULL, 855),
    NAME_FUNC_OFFSET(14980, glSetFragmentShaderConstantATI, glSetFragmentShaderConstantATI, NULL, 856),
    NAME_FUNC_OFFSET(15011, glPointParameteriNV, glPointParameteriNV, NULL, 857),
    NAME_FUNC_OFFSET(15031, glPointParameterivNV, glPointParameterivNV, NULL, 858),
    NAME_FUNC_OFFSET(15052, gl_dispatch_stub_859, gl_dispatch_stub_859, NULL, 859),
    NAME_FUNC_OFFSET(15075, gl_dispatch_stub_860, gl_dispatch_stub_860, NULL, 860),
    NAME_FUNC_OFFSET(15098, gl_dispatch_stub_861, gl_dispatch_stub_861, NULL, 861),
    NAME_FUNC_OFFSET(15124, gl_dispatch_stub_862, gl_dispatch_stub_862, NULL, 862),
    NAME_FUNC_OFFSET(15147, gl_dispatch_stub_863, gl_dispatch_stub_863, NULL, 863),
    NAME_FUNC_OFFSET(15168, glGetProgramNamedParameterdvNV, glGetProgramNamedParameterdvNV, NULL, 864),
    NAME_FUNC_OFFSET(15199, glGetProgramNamedParameterfvNV, glGetProgramNamedParameterfvNV, NULL, 865),
    NAME_FUNC_OFFSET(15230, glProgramNamedParameter4dNV, glProgramNamedParameter4dNV, NULL, 866),
    NAME_FUNC_OFFSET(15258, glProgramNamedParameter4dvNV, glProgramNamedParameter4dvNV, NULL, 867),
    NAME_FUNC_OFFSET(15287, glProgramNamedParameter4fNV, glProgramNamedParameter4fNV, NULL, 868),
    NAME_FUNC_OFFSET(15315, glProgramNamedParameter4fvNV, glProgramNamedParameter4fvNV, NULL, 869),
    NAME_FUNC_OFFSET(15344, glPrimitiveRestartIndexNV, glPrimitiveRestartIndexNV, NULL, 870),
    NAME_FUNC_OFFSET(15370, glPrimitiveRestartNV, glPrimitiveRestartNV, NULL, 871),
    NAME_FUNC_OFFSET(15391, gl_dispatch_stub_872, gl_dispatch_stub_872, NULL, 872),
    NAME_FUNC_OFFSET(15408, gl_dispatch_stub_873, gl_dispatch_stub_873, NULL, 873),
    NAME_FUNC_OFFSET(15435, glBindFramebufferEXT, glBindFramebufferEXT, NULL, 874),
    NAME_FUNC_OFFSET(15456, glBindRenderbufferEXT, glBindRenderbufferEXT, NULL, 875),
    NAME_FUNC_OFFSET(15478, glCheckFramebufferStatusEXT, glCheckFramebufferStatusEXT, NULL, 876),
    NAME_FUNC_OFFSET(15506, glDeleteFramebuffersEXT, glDeleteFramebuffersEXT, NULL, 877),
    NAME_FUNC_OFFSET(15530, glDeleteRenderbuffersEXT, glDeleteRenderbuffersEXT, NULL, 878),
    NAME_FUNC_OFFSET(15555, glFramebufferRenderbufferEXT, glFramebufferRenderbufferEXT, NULL, 879),
    NAME_FUNC_OFFSET(15584, glFramebufferTexture1DEXT, glFramebufferTexture1DEXT, NULL, 880),
    NAME_FUNC_OFFSET(15610, glFramebufferTexture2DEXT, glFramebufferTexture2DEXT, NULL, 881),
    NAME_FUNC_OFFSET(15636, glFramebufferTexture3DEXT, glFramebufferTexture3DEXT, NULL, 882),
    NAME_FUNC_OFFSET(15662, glGenFramebuffersEXT, glGenFramebuffersEXT, NULL, 883),
    NAME_FUNC_OFFSET(15683, glGenRenderbuffersEXT, glGenRenderbuffersEXT, NULL, 884),
    NAME_FUNC_OFFSET(15705, glGenerateMipmapEXT, glGenerateMipmapEXT, NULL, 885),
    NAME_FUNC_OFFSET(15725, glGetFramebufferAttachmentParameterivEXT, glGetFramebufferAttachmentParameterivEXT, NULL, 886),
    NAME_FUNC_OFFSET(15766, glGetRenderbufferParameterivEXT, glGetRenderbufferParameterivEXT, NULL, 887),
    NAME_FUNC_OFFSET(15798, glIsFramebufferEXT, glIsFramebufferEXT, NULL, 888),
    NAME_FUNC_OFFSET(15817, glIsRenderbufferEXT, glIsRenderbufferEXT, NULL, 889),
    NAME_FUNC_OFFSET(15837, glRenderbufferStorageEXT, glRenderbufferStorageEXT, NULL, 890),
    NAME_FUNC_OFFSET(15862, gl_dispatch_stub_891, gl_dispatch_stub_891, NULL, 891),
    NAME_FUNC_OFFSET(15883, gl_dispatch_stub_892, gl_dispatch_stub_892, NULL, 892),
    NAME_FUNC_OFFSET(15907, gl_dispatch_stub_893, gl_dispatch_stub_893, NULL, 893),
    NAME_FUNC_OFFSET(15937, glBindFragDataLocationEXT, glBindFragDataLocationEXT, NULL, 894),
    NAME_FUNC_OFFSET(15963, glGetFragDataLocationEXT, glGetFragDataLocationEXT, NULL, 895),
    NAME_FUNC_OFFSET(15988, glGetUniformuivEXT, glGetUniformuivEXT, NULL, 896),
    NAME_FUNC_OFFSET(16007, glGetVertexAttribIivEXT, glGetVertexAttribIivEXT, NULL, 897),
    NAME_FUNC_OFFSET(16031, glGetVertexAttribIuivEXT, glGetVertexAttribIuivEXT, NULL, 898),
    NAME_FUNC_OFFSET(16056, glUniform1uiEXT, glUniform1uiEXT, NULL, 899),
    NAME_FUNC_OFFSET(16072, glUniform1uivEXT, glUniform1uivEXT, NULL, 900),
    NAME_FUNC_OFFSET(16089, glUniform2uiEXT, glUniform2uiEXT, NULL, 901),
    NAME_FUNC_OFFSET(16105, glUniform2uivEXT, glUniform2uivEXT, NULL, 902),
    NAME_FUNC_OFFSET(16122, glUniform3uiEXT, glUniform3uiEXT, NULL, 903),
    NAME_FUNC_OFFSET(16138, glUniform3uivEXT, glUniform3uivEXT, NULL, 904),
    NAME_FUNC_OFFSET(16155, glUniform4uiEXT, glUniform4uiEXT, NULL, 905),
    NAME_FUNC_OFFSET(16171, glUniform4uivEXT, glUniform4uivEXT, NULL, 906),
    NAME_FUNC_OFFSET(16188, glVertexAttribI1iEXT, glVertexAttribI1iEXT, NULL, 907),
    NAME_FUNC_OFFSET(16209, glVertexAttribI1ivEXT, glVertexAttribI1ivEXT, NULL, 908),
    NAME_FUNC_OFFSET(16231, glVertexAttribI1uiEXT, glVertexAttribI1uiEXT, NULL, 909),
    NAME_FUNC_OFFSET(16253, glVertexAttribI1uivEXT, glVertexAttribI1uivEXT, NULL, 910),
    NAME_FUNC_OFFSET(16276, glVertexAttribI2iEXT, glVertexAttribI2iEXT, NULL, 911),
    NAME_FUNC_OFFSET(16297, glVertexAttribI2ivEXT, glVertexAttribI2ivEXT, NULL, 912),
    NAME_FUNC_OFFSET(16319, glVertexAttribI2uiEXT, glVertexAttribI2uiEXT, NULL, 913),
    NAME_FUNC_OFFSET(16341, glVertexAttribI2uivEXT, glVertexAttribI2uivEXT, NULL, 914),
    NAME_FUNC_OFFSET(16364, glVertexAttribI3iEXT, glVertexAttribI3iEXT, NULL, 915),
    NAME_FUNC_OFFSET(16385, glVertexAttribI3ivEXT, glVertexAttribI3ivEXT, NULL, 916),
    NAME_FUNC_OFFSET(16407, glVertexAttribI3uiEXT, glVertexAttribI3uiEXT, NULL, 917),
    NAME_FUNC_OFFSET(16429, glVertexAttribI3uivEXT, glVertexAttribI3uivEXT, NULL, 918),
    NAME_FUNC_OFFSET(16452, glVertexAttribI4bvEXT, glVertexAttribI4bvEXT, NULL, 919),
    NAME_FUNC_OFFSET(16474, glVertexAttribI4iEXT, glVertexAttribI4iEXT, NULL, 920),
    NAME_FUNC_OFFSET(16495, glVertexAttribI4ivEXT, glVertexAttribI4ivEXT, NULL, 921),
    NAME_FUNC_OFFSET(16517, glVertexAttribI4svEXT, glVertexAttribI4svEXT, NULL, 922),
    NAME_FUNC_OFFSET(16539, glVertexAttribI4ubvEXT, glVertexAttribI4ubvEXT, NULL, 923),
    NAME_FUNC_OFFSET(16562, glVertexAttribI4uiEXT, glVertexAttribI4uiEXT, NULL, 924),
    NAME_FUNC_OFFSET(16584, glVertexAttribI4uivEXT, glVertexAttribI4uivEXT, NULL, 925),
    NAME_FUNC_OFFSET(16607, glVertexAttribI4usvEXT, glVertexAttribI4usvEXT, NULL, 926),
    NAME_FUNC_OFFSET(16630, glVertexAttribIPointerEXT, glVertexAttribIPointerEXT, NULL, 927),
    NAME_FUNC_OFFSET(16656, glFramebufferTextureLayerEXT, glFramebufferTextureLayerEXT, NULL, 928),
    NAME_FUNC_OFFSET(16685, glColorMaskIndexedEXT, glColorMaskIndexedEXT, NULL, 929),
    NAME_FUNC_OFFSET(16707, glDisableIndexedEXT, glDisableIndexedEXT, NULL, 930),
    NAME_FUNC_OFFSET(16727, glEnableIndexedEXT, glEnableIndexedEXT, NULL, 931),
    NAME_FUNC_OFFSET(16746, glGetBooleanIndexedvEXT, glGetBooleanIndexedvEXT, NULL, 932),
    NAME_FUNC_OFFSET(16770, glGetIntegerIndexedvEXT, glGetIntegerIndexedvEXT, NULL, 933),
    NAME_FUNC_OFFSET(16794, glIsEnabledIndexedEXT, glIsEnabledIndexedEXT, NULL, 934),
    NAME_FUNC_OFFSET(16816, glClearColorIiEXT, glClearColorIiEXT, NULL, 935),
    NAME_FUNC_OFFSET(16834, glClearColorIuiEXT, glClearColorIuiEXT, NULL, 936),
    NAME_FUNC_OFFSET(16853, glGetTexParameterIivEXT, glGetTexParameterIivEXT, NULL, 937),
    NAME_FUNC_OFFSET(16877, glGetTexParameterIuivEXT, glGetTexParameterIuivEXT, NULL, 938),
    NAME_FUNC_OFFSET(16902, glTexParameterIivEXT, glTexParameterIivEXT, NULL, 939),
    NAME_FUNC_OFFSET(16923, glTexParameterIuivEXT, glTexParameterIuivEXT, NULL, 940),
    NAME_FUNC_OFFSET(16945, glBeginConditionalRenderNV, glBeginConditionalRenderNV, NULL, 941),
    NAME_FUNC_OFFSET(16972, glEndConditionalRenderNV, glEndConditionalRenderNV, NULL, 942),
    NAME_FUNC_OFFSET(16997, glBeginTransformFeedbackEXT, glBeginTransformFeedbackEXT, NULL, 943),
    NAME_FUNC_OFFSET(17025, glBindBufferBaseEXT, glBindBufferBaseEXT, NULL, 944),
    NAME_FUNC_OFFSET(17045, glBindBufferOffsetEXT, glBindBufferOffsetEXT, NULL, 945),
    NAME_FUNC_OFFSET(17067, glBindBufferRangeEXT, glBindBufferRangeEXT, NULL, 946),
    NAME_FUNC_OFFSET(17088, glEndTransformFeedbackEXT, glEndTransformFeedbackEXT, NULL, 947),
    NAME_FUNC_OFFSET(17114, glGetTransformFeedbackVaryingEXT, glGetTransformFeedbackVaryingEXT, NULL, 948),
    NAME_FUNC_OFFSET(17147, glTransformFeedbackVaryingsEXT, glTransformFeedbackVaryingsEXT, NULL, 949),
    NAME_FUNC_OFFSET(17178, glProvokingVertexEXT, glProvokingVertexEXT, NULL, 950),
    NAME_FUNC_OFFSET(17199, gl_dispatch_stub_951, gl_dispatch_stub_951, NULL, 951),
    NAME_FUNC_OFFSET(17230, gl_dispatch_stub_952, gl_dispatch_stub_952, NULL, 952),
    NAME_FUNC_OFFSET(17250, glGetObjectParameterivAPPLE, glGetObjectParameterivAPPLE, NULL, 953),
    NAME_FUNC_OFFSET(17278, glObjectPurgeableAPPLE, glObjectPurgeableAPPLE, NULL, 954),
    NAME_FUNC_OFFSET(17301, glObjectUnpurgeableAPPLE, glObjectUnpurgeableAPPLE, NULL, 955),
    NAME_FUNC_OFFSET(17326, glActiveProgramEXT, glActiveProgramEXT, NULL, 956),
    NAME_FUNC_OFFSET(17345, glCreateShaderProgramEXT, glCreateShaderProgramEXT, NULL, 957),
    NAME_FUNC_OFFSET(17370, glUseShaderProgramEXT, glUseShaderProgramEXT, NULL, 958),
    NAME_FUNC_OFFSET(17392, glTextureBarrierNV, glTextureBarrierNV, NULL, 959),
    NAME_FUNC_OFFSET(17411, gl_dispatch_stub_960, gl_dispatch_stub_960, NULL, 960),
    NAME_FUNC_OFFSET(17436, gl_dispatch_stub_961, gl_dispatch_stub_961, NULL, 961),
    NAME_FUNC_OFFSET(17465, gl_dispatch_stub_962, gl_dispatch_stub_962, NULL, 962),
    NAME_FUNC_OFFSET(17496, gl_dispatch_stub_963, gl_dispatch_stub_963, NULL, 963),
    NAME_FUNC_OFFSET(17520, gl_dispatch_stub_964, gl_dispatch_stub_964, NULL, 964),
    NAME_FUNC_OFFSET(17545, glEGLImageTargetRenderbufferStorageOES, glEGLImageTargetRenderbufferStorageOES, NULL, 965),
    NAME_FUNC_OFFSET(17584, glEGLImageTargetTexture2DOES, glEGLImageTargetTexture2DOES, NULL, 966),
    NAME_FUNC_OFFSET(17613, glArrayElement, glArrayElement, NULL, 306),
    NAME_FUNC_OFFSET(17631, glBindTexture, glBindTexture, NULL, 307),
    NAME_FUNC_OFFSET(17648, glDrawArrays, glDrawArrays, NULL, 310),
    NAME_FUNC_OFFSET(17664, glAreTexturesResident, glAreTexturesResidentEXT, glAreTexturesResidentEXT, 322),
    NAME_FUNC_OFFSET(17689, glCopyTexImage1D, glCopyTexImage1D, NULL, 323),
    NAME_FUNC_OFFSET(17709, glCopyTexImage2D, glCopyTexImage2D, NULL, 324),
    NAME_FUNC_OFFSET(17729, glCopyTexSubImage1D, glCopyTexSubImage1D, NULL, 325),
    NAME_FUNC_OFFSET(17752, glCopyTexSubImage2D, glCopyTexSubImage2D, NULL, 326),
    NAME_FUNC_OFFSET(17775, glDeleteTextures, glDeleteTexturesEXT, glDeleteTexturesEXT, 327),
    NAME_FUNC_OFFSET(17795, glGenTextures, glGenTexturesEXT, glGenTexturesEXT, 328),
    NAME_FUNC_OFFSET(17812, glGetPointerv, glGetPointerv, NULL, 329),
    NAME_FUNC_OFFSET(17829, glIsTexture, glIsTextureEXT, glIsTextureEXT, 330),
    NAME_FUNC_OFFSET(17844, glPrioritizeTextures, glPrioritizeTextures, NULL, 331),
    NAME_FUNC_OFFSET(17868, glTexSubImage1D, glTexSubImage1D, NULL, 332),
    NAME_FUNC_OFFSET(17887, glTexSubImage2D, glTexSubImage2D, NULL, 333),
    NAME_FUNC_OFFSET(17906, glBlendColor, glBlendColor, NULL, 336),
    NAME_FUNC_OFFSET(17922, glBlendEquation, glBlendEquation, NULL, 337),
    NAME_FUNC_OFFSET(17941, glDrawRangeElements, glDrawRangeElements, NULL, 338),
    NAME_FUNC_OFFSET(17964, glColorTable, glColorTable, NULL, 339),
    NAME_FUNC_OFFSET(17980, glColorTable, glColorTable, NULL, 339),
    NAME_FUNC_OFFSET(17996, glColorTableParameterfv, glColorTableParameterfv, NULL, 340),
    NAME_FUNC_OFFSET(18023, glColorTableParameteriv, glColorTableParameteriv, NULL, 341),
    NAME_FUNC_OFFSET(18050, glCopyColorTable, glCopyColorTable, NULL, 342),
    NAME_FUNC_OFFSET(18070, glGetColorTable, glGetColorTableEXT, glGetColorTableEXT, 343),
    NAME_FUNC_OFFSET(18089, glGetColorTable, glGetColorTableEXT, glGetColorTableEXT, 343),
    NAME_FUNC_OFFSET(18108, glGetColorTableParameterfv, glGetColorTableParameterfvEXT, glGetColorTableParameterfvEXT, 344),
    NAME_FUNC_OFFSET(18138, glGetColorTableParameterfv, glGetColorTableParameterfvEXT, glGetColorTableParameterfvEXT, 344),
    NAME_FUNC_OFFSET(18168, glGetColorTableParameteriv, glGetColorTableParameterivEXT, glGetColorTableParameterivEXT, 345),
    NAME_FUNC_OFFSET(18198, glGetColorTableParameteriv, glGetColorTableParameterivEXT, glGetColorTableParameterivEXT, 345),
    NAME_FUNC_OFFSET(18228, glColorSubTable, glColorSubTable, NULL, 346),
    NAME_FUNC_OFFSET(18247, glCopyColorSubTable, glCopyColorSubTable, NULL, 347),
    NAME_FUNC_OFFSET(18270, glConvolutionFilter1D, glConvolutionFilter1D, NULL, 348),
    NAME_FUNC_OFFSET(18295, glConvolutionFilter2D, glConvolutionFilter2D, NULL, 349),
    NAME_FUNC_OFFSET(18320, glConvolutionParameterf, glConvolutionParameterf, NULL, 350),
    NAME_FUNC_OFFSET(18347, glConvolutionParameterfv, glConvolutionParameterfv, NULL, 351),
    NAME_FUNC_OFFSET(18375, glConvolutionParameteri, glConvolutionParameteri, NULL, 352),
    NAME_FUNC_OFFSET(18402, glConvolutionParameteriv, glConvolutionParameteriv, NULL, 353),
    NAME_FUNC_OFFSET(18430, glCopyConvolutionFilter1D, glCopyConvolutionFilter1D, NULL, 354),
    NAME_FUNC_OFFSET(18459, glCopyConvolutionFilter2D, glCopyConvolutionFilter2D, NULL, 355),
    NAME_FUNC_OFFSET(18488, glGetConvolutionFilter, gl_dispatch_stub_356, gl_dispatch_stub_356, 356),
    NAME_FUNC_OFFSET(18514, glGetConvolutionParameterfv, gl_dispatch_stub_357, gl_dispatch_stub_357, 357),
    NAME_FUNC_OFFSET(18545, glGetConvolutionParameteriv, gl_dispatch_stub_358, gl_dispatch_stub_358, 358),
    NAME_FUNC_OFFSET(18576, glGetSeparableFilter, gl_dispatch_stub_359, gl_dispatch_stub_359, 359),
    NAME_FUNC_OFFSET(18600, glSeparableFilter2D, glSeparableFilter2D, NULL, 360),
    NAME_FUNC_OFFSET(18623, glGetHistogram, gl_dispatch_stub_361, gl_dispatch_stub_361, 361),
    NAME_FUNC_OFFSET(18641, glGetHistogramParameterfv, gl_dispatch_stub_362, gl_dispatch_stub_362, 362),
    NAME_FUNC_OFFSET(18670, glGetHistogramParameteriv, gl_dispatch_stub_363, gl_dispatch_stub_363, 363),
    NAME_FUNC_OFFSET(18699, glGetMinmax, gl_dispatch_stub_364, gl_dispatch_stub_364, 364),
    NAME_FUNC_OFFSET(18714, glGetMinmaxParameterfv, gl_dispatch_stub_365, gl_dispatch_stub_365, 365),
    NAME_FUNC_OFFSET(18740, glGetMinmaxParameteriv, gl_dispatch_stub_366, gl_dispatch_stub_366, 366),
    NAME_FUNC_OFFSET(18766, glHistogram, glHistogram, NULL, 367),
    NAME_FUNC_OFFSET(18781, glMinmax, glMinmax, NULL, 368),
    NAME_FUNC_OFFSET(18793, glResetHistogram, glResetHistogram, NULL, 369),
    NAME_FUNC_OFFSET(18813, glResetMinmax, glResetMinmax, NULL, 370),
    NAME_FUNC_OFFSET(18830, glTexImage3D, glTexImage3D, NULL, 371),
    NAME_FUNC_OFFSET(18846, glTexSubImage3D, glTexSubImage3D, NULL, 372),
    NAME_FUNC_OFFSET(18865, glCopyTexSubImage3D, glCopyTexSubImage3D, NULL, 373),
    NAME_FUNC_OFFSET(18888, glActiveTextureARB, glActiveTextureARB, NULL, 374),
    NAME_FUNC_OFFSET(18904, glClientActiveTextureARB, glClientActiveTextureARB, NULL, 375),
    NAME_FUNC_OFFSET(18926, glMultiTexCoord1dARB, glMultiTexCoord1dARB, NULL, 376),
    NAME_FUNC_OFFSET(18944, glMultiTexCoord1dvARB, glMultiTexCoord1dvARB, NULL, 377),
    NAME_FUNC_OFFSET(18963, glMultiTexCoord1fARB, glMultiTexCoord1fARB, NULL, 378),
    NAME_FUNC_OFFSET(18981, glMultiTexCoord1fvARB, glMultiTexCoord1fvARB, NULL, 379),
    NAME_FUNC_OFFSET(19000, glMultiTexCoord1iARB, glMultiTexCoord1iARB, NULL, 380),
    NAME_FUNC_OFFSET(19018, glMultiTexCoord1ivARB, glMultiTexCoord1ivARB, NULL, 381),
    NAME_FUNC_OFFSET(19037, glMultiTexCoord1sARB, glMultiTexCoord1sARB, NULL, 382),
    NAME_FUNC_OFFSET(19055, glMultiTexCoord1svARB, glMultiTexCoord1svARB, NULL, 383),
    NAME_FUNC_OFFSET(19074, glMultiTexCoord2dARB, glMultiTexCoord2dARB, NULL, 384),
    NAME_FUNC_OFFSET(19092, glMultiTexCoord2dvARB, glMultiTexCoord2dvARB, NULL, 385),
    NAME_FUNC_OFFSET(19111, glMultiTexCoord2fARB, glMultiTexCoord2fARB, NULL, 386),
    NAME_FUNC_OFFSET(19129, glMultiTexCoord2fvARB, glMultiTexCoord2fvARB, NULL, 387),
    NAME_FUNC_OFFSET(19148, glMultiTexCoord2iARB, glMultiTexCoord2iARB, NULL, 388),
    NAME_FUNC_OFFSET(19166, glMultiTexCoord2ivARB, glMultiTexCoord2ivARB, NULL, 389),
    NAME_FUNC_OFFSET(19185, glMultiTexCoord2sARB, glMultiTexCoord2sARB, NULL, 390),
    NAME_FUNC_OFFSET(19203, glMultiTexCoord2svARB, glMultiTexCoord2svARB, NULL, 391),
    NAME_FUNC_OFFSET(19222, glMultiTexCoord3dARB, glMultiTexCoord3dARB, NULL, 392),
    NAME_FUNC_OFFSET(19240, glMultiTexCoord3dvARB, glMultiTexCoord3dvARB, NULL, 393),
    NAME_FUNC_OFFSET(19259, glMultiTexCoord3fARB, glMultiTexCoord3fARB, NULL, 394),
    NAME_FUNC_OFFSET(19277, glMultiTexCoord3fvARB, glMultiTexCoord3fvARB, NULL, 395),
    NAME_FUNC_OFFSET(19296, glMultiTexCoord3iARB, glMultiTexCoord3iARB, NULL, 396),
    NAME_FUNC_OFFSET(19314, glMultiTexCoord3ivARB, glMultiTexCoord3ivARB, NULL, 397),
    NAME_FUNC_OFFSET(19333, glMultiTexCoord3sARB, glMultiTexCoord3sARB, NULL, 398),
    NAME_FUNC_OFFSET(19351, glMultiTexCoord3svARB, glMultiTexCoord3svARB, NULL, 399),
    NAME_FUNC_OFFSET(19370, glMultiTexCoord4dARB, glMultiTexCoord4dARB, NULL, 400),
    NAME_FUNC_OFFSET(19388, glMultiTexCoord4dvARB, glMultiTexCoord4dvARB, NULL, 401),
    NAME_FUNC_OFFSET(19407, glMultiTexCoord4fARB, glMultiTexCoord4fARB, NULL, 402),
    NAME_FUNC_OFFSET(19425, glMultiTexCoord4fvARB, glMultiTexCoord4fvARB, NULL, 403),
    NAME_FUNC_OFFSET(19444, glMultiTexCoord4iARB, glMultiTexCoord4iARB, NULL, 404),
    NAME_FUNC_OFFSET(19462, glMultiTexCoord4ivARB, glMultiTexCoord4ivARB, NULL, 405),
    NAME_FUNC_OFFSET(19481, glMultiTexCoord4sARB, glMultiTexCoord4sARB, NULL, 406),
    NAME_FUNC_OFFSET(19499, glMultiTexCoord4svARB, glMultiTexCoord4svARB, NULL, 407),
    NAME_FUNC_OFFSET(19518, glStencilOpSeparate, glStencilOpSeparate, NULL, 423),
    NAME_FUNC_OFFSET(19541, glLoadTransposeMatrixdARB, glLoadTransposeMatrixdARB, NULL, 441),
    NAME_FUNC_OFFSET(19564, glLoadTransposeMatrixfARB, glLoadTransposeMatrixfARB, NULL, 442),
    NAME_FUNC_OFFSET(19587, glMultTransposeMatrixdARB, glMultTransposeMatrixdARB, NULL, 443),
    NAME_FUNC_OFFSET(19610, glMultTransposeMatrixfARB, glMultTransposeMatrixfARB, NULL, 444),
    NAME_FUNC_OFFSET(19633, glSampleCoverageARB, glSampleCoverageARB, NULL, 445),
    NAME_FUNC_OFFSET(19650, glCompressedTexImage1DARB, glCompressedTexImage1DARB, NULL, 446),
    NAME_FUNC_OFFSET(19673, glCompressedTexImage2DARB, glCompressedTexImage2DARB, NULL, 447),
    NAME_FUNC_OFFSET(19696, glCompressedTexImage3DARB, glCompressedTexImage3DARB, NULL, 448),
    NAME_FUNC_OFFSET(19719, glCompressedTexSubImage1DARB, glCompressedTexSubImage1DARB, NULL, 449),
    NAME_FUNC_OFFSET(19745, glCompressedTexSubImage2DARB, glCompressedTexSubImage2DARB, NULL, 450),
    NAME_FUNC_OFFSET(19771, glCompressedTexSubImage3DARB, glCompressedTexSubImage3DARB, NULL, 451),
    NAME_FUNC_OFFSET(19797, glGetCompressedTexImageARB, glGetCompressedTexImageARB, NULL, 452),
    NAME_FUNC_OFFSET(19821, glDisableVertexAttribArrayARB, glDisableVertexAttribArrayARB, NULL, 453),
    NAME_FUNC_OFFSET(19848, glEnableVertexAttribArrayARB, glEnableVertexAttribArrayARB, NULL, 454),
    NAME_FUNC_OFFSET(19874, glGetVertexAttribdvARB, glGetVertexAttribdvARB, NULL, 461),
    NAME_FUNC_OFFSET(19894, glGetVertexAttribfvARB, glGetVertexAttribfvARB, NULL, 462),
    NAME_FUNC_OFFSET(19914, glGetVertexAttribivARB, glGetVertexAttribivARB, NULL, 463),
    NAME_FUNC_OFFSET(19934, glProgramEnvParameter4dARB, glProgramEnvParameter4dARB, NULL, 464),
    NAME_FUNC_OFFSET(19957, glProgramEnvParameter4dvARB, glProgramEnvParameter4dvARB, NULL, 465),
    NAME_FUNC_OFFSET(19981, glProgramEnvParameter4fARB, glProgramEnvParameter4fARB, NULL, 466),
    NAME_FUNC_OFFSET(20004, glProgramEnvParameter4fvARB, glProgramEnvParameter4fvARB, NULL, 467),
    NAME_FUNC_OFFSET(20028, glVertexAttrib1dARB, glVertexAttrib1dARB, NULL, 473),
    NAME_FUNC_OFFSET(20045, glVertexAttrib1dvARB, glVertexAttrib1dvARB, NULL, 474),
    NAME_FUNC_OFFSET(20063, glVertexAttrib1fARB, glVertexAttrib1fARB, NULL, 475),
    NAME_FUNC_OFFSET(20080, glVertexAttrib1fvARB, glVertexAttrib1fvARB, NULL, 476),
    NAME_FUNC_OFFSET(20098, glVertexAttrib1sARB, glVertexAttrib1sARB, NULL, 477),
    NAME_FUNC_OFFSET(20115, glVertexAttrib1svARB, glVertexAttrib1svARB, NULL, 478),
    NAME_FUNC_OFFSET(20133, glVertexAttrib2dARB, glVertexAttrib2dARB, NULL, 479),
    NAME_FUNC_OFFSET(20150, glVertexAttrib2dvARB, glVertexAttrib2dvARB, NULL, 480),
    NAME_FUNC_OFFSET(20168, glVertexAttrib2fARB, glVertexAttrib2fARB, NULL, 481),
    NAME_FUNC_OFFSET(20185, glVertexAttrib2fvARB, glVertexAttrib2fvARB, NULL, 482),
    NAME_FUNC_OFFSET(20203, glVertexAttrib2sARB, glVertexAttrib2sARB, NULL, 483),
    NAME_FUNC_OFFSET(20220, glVertexAttrib2svARB, glVertexAttrib2svARB, NULL, 484),
    NAME_FUNC_OFFSET(20238, glVertexAttrib3dARB, glVertexAttrib3dARB, NULL, 485),
    NAME_FUNC_OFFSET(20255, glVertexAttrib3dvARB, glVertexAttrib3dvARB, NULL, 486),
    NAME_FUNC_OFFSET(20273, glVertexAttrib3fARB, glVertexAttrib3fARB, NULL, 487),
    NAME_FUNC_OFFSET(20290, glVertexAttrib3fvARB, glVertexAttrib3fvARB, NULL, 488),
    NAME_FUNC_OFFSET(20308, glVertexAttrib3sARB, glVertexAttrib3sARB, NULL, 489),
    NAME_FUNC_OFFSET(20325, glVertexAttrib3svARB, glVertexAttrib3svARB, NULL, 490),
    NAME_FUNC_OFFSET(20343, glVertexAttrib4NbvARB, glVertexAttrib4NbvARB, NULL, 491),
    NAME_FUNC_OFFSET(20362, glVertexAttrib4NivARB, glVertexAttrib4NivARB, NULL, 492),
    NAME_FUNC_OFFSET(20381, glVertexAttrib4NsvARB, glVertexAttrib4NsvARB, NULL, 493),
    NAME_FUNC_OFFSET(20400, glVertexAttrib4NubARB, glVertexAttrib4NubARB, NULL, 494),
    NAME_FUNC_OFFSET(20419, glVertexAttrib4NubvARB, glVertexAttrib4NubvARB, NULL, 495),
    NAME_FUNC_OFFSET(20439, glVertexAttrib4NuivARB, glVertexAttrib4NuivARB, NULL, 496),
    NAME_FUNC_OFFSET(20459, glVertexAttrib4NusvARB, glVertexAttrib4NusvARB, NULL, 497),
    NAME_FUNC_OFFSET(20479, glVertexAttrib4bvARB, glVertexAttrib4bvARB, NULL, 498),
    NAME_FUNC_OFFSET(20497, glVertexAttrib4dARB, glVertexAttrib4dARB, NULL, 499),
    NAME_FUNC_OFFSET(20514, glVertexAttrib4dvARB, glVertexAttrib4dvARB, NULL, 500),
    NAME_FUNC_OFFSET(20532, glVertexAttrib4fARB, glVertexAttrib4fARB, NULL, 501),
    NAME_FUNC_OFFSET(20549, glVertexAttrib4fvARB, glVertexAttrib4fvARB, NULL, 502),
    NAME_FUNC_OFFSET(20567, glVertexAttrib4ivARB, glVertexAttrib4ivARB, NULL, 503),
    NAME_FUNC_OFFSET(20585, glVertexAttrib4sARB, glVertexAttrib4sARB, NULL, 504),
    NAME_FUNC_OFFSET(20602, glVertexAttrib4svARB, glVertexAttrib4svARB, NULL, 505),
    NAME_FUNC_OFFSET(20620, glVertexAttrib4ubvARB, glVertexAttrib4ubvARB, NULL, 506),
    NAME_FUNC_OFFSET(20639, glVertexAttrib4uivARB, glVertexAttrib4uivARB, NULL, 507),
    NAME_FUNC_OFFSET(20658, glVertexAttrib4usvARB, glVertexAttrib4usvARB, NULL, 508),
    NAME_FUNC_OFFSET(20677, glVertexAttribPointerARB, glVertexAttribPointerARB, NULL, 509),
    NAME_FUNC_OFFSET(20699, glBindBufferARB, glBindBufferARB, NULL, 510),
    NAME_FUNC_OFFSET(20712, glBufferDataARB, glBufferDataARB, NULL, 511),
    NAME_FUNC_OFFSET(20725, glBufferSubDataARB, glBufferSubDataARB, NULL, 512),
    NAME_FUNC_OFFSET(20741, glDeleteBuffersARB, glDeleteBuffersARB, NULL, 513),
    NAME_FUNC_OFFSET(20757, glGenBuffersARB, glGenBuffersARB, NULL, 514),
    NAME_FUNC_OFFSET(20770, glGetBufferParameterivARB, glGetBufferParameterivARB, NULL, 515),
    NAME_FUNC_OFFSET(20793, glGetBufferPointervARB, glGetBufferPointervARB, NULL, 516),
    NAME_FUNC_OFFSET(20813, glGetBufferSubDataARB, glGetBufferSubDataARB, NULL, 517),
    NAME_FUNC_OFFSET(20832, glIsBufferARB, glIsBufferARB, NULL, 518),
    NAME_FUNC_OFFSET(20843, glMapBufferARB, glMapBufferARB, NULL, 519),
    NAME_FUNC_OFFSET(20855, glUnmapBufferARB, glUnmapBufferARB, NULL, 520),
    NAME_FUNC_OFFSET(20869, glBeginQueryARB, glBeginQueryARB, NULL, 521),
    NAME_FUNC_OFFSET(20882, glDeleteQueriesARB, glDeleteQueriesARB, NULL, 522),
    NAME_FUNC_OFFSET(20898, glEndQueryARB, glEndQueryARB, NULL, 523),
    NAME_FUNC_OFFSET(20909, glGenQueriesARB, glGenQueriesARB, NULL, 524),
    NAME_FUNC_OFFSET(20922, glGetQueryObjectivARB, glGetQueryObjectivARB, NULL, 525),
    NAME_FUNC_OFFSET(20941, glGetQueryObjectuivARB, glGetQueryObjectuivARB, NULL, 526),
    NAME_FUNC_OFFSET(20961, glGetQueryivARB, glGetQueryivARB, NULL, 527),
    NAME_FUNC_OFFSET(20974, glIsQueryARB, glIsQueryARB, NULL, 528),
    NAME_FUNC_OFFSET(20984, glCompileShaderARB, glCompileShaderARB, NULL, 530),
    NAME_FUNC_OFFSET(21000, glGetActiveUniformARB, glGetActiveUniformARB, NULL, 535),
    NAME_FUNC_OFFSET(21019, glGetShaderSourceARB, glGetShaderSourceARB, NULL, 541),
    NAME_FUNC_OFFSET(21037, glGetUniformLocationARB, glGetUniformLocationARB, NULL, 542),
    NAME_FUNC_OFFSET(21058, glGetUniformfvARB, glGetUniformfvARB, NULL, 543),
    NAME_FUNC_OFFSET(21073, glGetUniformivARB, glGetUniformivARB, NULL, 544),
    NAME_FUNC_OFFSET(21088, glLinkProgramARB, glLinkProgramARB, NULL, 545),
    NAME_FUNC_OFFSET(21102, glShaderSourceARB, glShaderSourceARB, NULL, 546),
    NAME_FUNC_OFFSET(21117, glUniform1fARB, glUniform1fARB, NULL, 547),
    NAME_FUNC_OFFSET(21129, glUniform1fvARB, glUniform1fvARB, NULL, 548),
    NAME_FUNC_OFFSET(21142, glUniform1iARB, glUniform1iARB, NULL, 549),
    NAME_FUNC_OFFSET(21154, glUniform1ivARB, glUniform1ivARB, NULL, 550),
    NAME_FUNC_OFFSET(21167, glUniform2fARB, glUniform2fARB, NULL, 551),
    NAME_FUNC_OFFSET(21179, glUniform2fvARB, glUniform2fvARB, NULL, 552),
    NAME_FUNC_OFFSET(21192, glUniform2iARB, glUniform2iARB, NULL, 553),
    NAME_FUNC_OFFSET(21204, glUniform2ivARB, glUniform2ivARB, NULL, 554),
    NAME_FUNC_OFFSET(21217, glUniform3fARB, glUniform3fARB, NULL, 555),
    NAME_FUNC_OFFSET(21229, glUniform3fvARB, glUniform3fvARB, NULL, 556),
    NAME_FUNC_OFFSET(21242, glUniform3iARB, glUniform3iARB, NULL, 557),
    NAME_FUNC_OFFSET(21254, glUniform3ivARB, glUniform3ivARB, NULL, 558),
    NAME_FUNC_OFFSET(21267, glUniform4fARB, glUniform4fARB, NULL, 559),
    NAME_FUNC_OFFSET(21279, glUniform4fvARB, glUniform4fvARB, NULL, 560),
    NAME_FUNC_OFFSET(21292, glUniform4iARB, glUniform4iARB, NULL, 561),
    NAME_FUNC_OFFSET(21304, glUniform4ivARB, glUniform4ivARB, NULL, 562),
    NAME_FUNC_OFFSET(21317, glUniformMatrix2fvARB, glUniformMatrix2fvARB, NULL, 563),
    NAME_FUNC_OFFSET(21336, glUniformMatrix3fvARB, glUniformMatrix3fvARB, NULL, 564),
    NAME_FUNC_OFFSET(21355, glUniformMatrix4fvARB, glUniformMatrix4fvARB, NULL, 565),
    NAME_FUNC_OFFSET(21374, glUseProgramObjectARB, glUseProgramObjectARB, NULL, 566),
    NAME_FUNC_OFFSET(21387, glValidateProgramARB, glValidateProgramARB, NULL, 567),
    NAME_FUNC_OFFSET(21405, glBindAttribLocationARB, glBindAttribLocationARB, NULL, 568),
    NAME_FUNC_OFFSET(21426, glGetActiveAttribARB, glGetActiveAttribARB, NULL, 569),
    NAME_FUNC_OFFSET(21444, glGetAttribLocationARB, glGetAttribLocationARB, NULL, 570),
    NAME_FUNC_OFFSET(21464, glDrawBuffersARB, glDrawBuffersARB, NULL, 571),
    NAME_FUNC_OFFSET(21478, glDrawBuffersARB, glDrawBuffersARB, NULL, 571),
    NAME_FUNC_OFFSET(21495, glDrawArraysInstancedARB, glDrawArraysInstancedARB, NULL, 573),
    NAME_FUNC_OFFSET(21520, glDrawArraysInstancedARB, glDrawArraysInstancedARB, NULL, 573),
    NAME_FUNC_OFFSET(21542, glDrawElementsInstancedARB, glDrawElementsInstancedARB, NULL, 574),
    NAME_FUNC_OFFSET(21569, glDrawElementsInstancedARB, glDrawElementsInstancedARB, NULL, 574),
    NAME_FUNC_OFFSET(21593, glRenderbufferStorageMultisample, glRenderbufferStorageMultisample, NULL, 575),
    NAME_FUNC_OFFSET(21629, glBlendEquationSeparateiARB, glBlendEquationSeparateiARB, NULL, 597),
    NAME_FUNC_OFFSET(21663, glBlendEquationiARB, glBlendEquationiARB, NULL, 598),
    NAME_FUNC_OFFSET(21689, glBlendFuncSeparateiARB, glBlendFuncSeparateiARB, NULL, 599),
    NAME_FUNC_OFFSET(21719, glBlendFunciARB, glBlendFunciARB, NULL, 600),
    NAME_FUNC_OFFSET(21741, gl_dispatch_stub_692, gl_dispatch_stub_692, NULL, 692),
    NAME_FUNC_OFFSET(21757, gl_dispatch_stub_693, gl_dispatch_stub_693, NULL, 693),
    NAME_FUNC_OFFSET(21776, glPointParameterfEXT, glPointParameterfEXT, NULL, 700),
    NAME_FUNC_OFFSET(21794, glPointParameterfEXT, glPointParameterfEXT, NULL, 700),
    NAME_FUNC_OFFSET(21815, glPointParameterfEXT, glPointParameterfEXT, NULL, 700),
    NAME_FUNC_OFFSET(21837, glPointParameterfvEXT, glPointParameterfvEXT, NULL, 701),
    NAME_FUNC_OFFSET(21856, glPointParameterfvEXT, glPointParameterfvEXT, NULL, 701),
    NAME_FUNC_OFFSET(21878, glPointParameterfvEXT, glPointParameterfvEXT, NULL, 701),
    NAME_FUNC_OFFSET(21901, glSecondaryColor3bEXT, glSecondaryColor3bEXT, NULL, 704),
    NAME_FUNC_OFFSET(21920, glSecondaryColor3bvEXT, glSecondaryColor3bvEXT, NULL, 705),
    NAME_FUNC_OFFSET(21940, glSecondaryColor3dEXT, glSecondaryColor3dEXT, NULL, 706),
    NAME_FUNC_OFFSET(21959, glSecondaryColor3dvEXT, glSecondaryColor3dvEXT, NULL, 707),
    NAME_FUNC_OFFSET(21979, glSecondaryColor3fEXT, glSecondaryColor3fEXT, NULL, 708),
    NAME_FUNC_OFFSET(21998, glSecondaryColor3fvEXT, glSecondaryColor3fvEXT, NULL, 709),
    NAME_FUNC_OFFSET(22018, glSecondaryColor3iEXT, glSecondaryColor3iEXT, NULL, 710),
    NAME_FUNC_OFFSET(22037, glSecondaryColor3ivEXT, glSecondaryColor3ivEXT, NULL, 711),
    NAME_FUNC_OFFSET(22057, glSecondaryColor3sEXT, glSecondaryColor3sEXT, NULL, 712),
    NAME_FUNC_OFFSET(22076, glSecondaryColor3svEXT, glSecondaryColor3svEXT, NULL, 713),
    NAME_FUNC_OFFSET(22096, glSecondaryColor3ubEXT, glSecondaryColor3ubEXT, NULL, 714),
    NAME_FUNC_OFFSET(22116, glSecondaryColor3ubvEXT, glSecondaryColor3ubvEXT, NULL, 715),
    NAME_FUNC_OFFSET(22137, glSecondaryColor3uiEXT, glSecondaryColor3uiEXT, NULL, 716),
    NAME_FUNC_OFFSET(22157, glSecondaryColor3uivEXT, glSecondaryColor3uivEXT, NULL, 717),
    NAME_FUNC_OFFSET(22178, glSecondaryColor3usEXT, glSecondaryColor3usEXT, NULL, 718),
    NAME_FUNC_OFFSET(22198, glSecondaryColor3usvEXT, glSecondaryColor3usvEXT, NULL, 719),
    NAME_FUNC_OFFSET(22219, glSecondaryColorPointerEXT, glSecondaryColorPointerEXT, NULL, 720),
    NAME_FUNC_OFFSET(22243, glMultiDrawArraysEXT, glMultiDrawArraysEXT, NULL, 721),
    NAME_FUNC_OFFSET(22261, glMultiDrawElementsEXT, glMultiDrawElementsEXT, NULL, 722),
    NAME_FUNC_OFFSET(22281, glFogCoordPointerEXT, glFogCoordPointerEXT, NULL, 723),
    NAME_FUNC_OFFSET(22299, glFogCoorddEXT, glFogCoorddEXT, NULL, 724),
    NAME_FUNC_OFFSET(22311, glFogCoorddvEXT, glFogCoorddvEXT, NULL, 725),
    NAME_FUNC_OFFSET(22324, glFogCoordfEXT, glFogCoordfEXT, NULL, 726),
    NAME_FUNC_OFFSET(22336, glFogCoordfvEXT, glFogCoordfvEXT, NULL, 727),
    NAME_FUNC_OFFSET(22349, glBlendFuncSeparateEXT, glBlendFuncSeparateEXT, NULL, 729),
    NAME_FUNC_OFFSET(22369, glBlendFuncSeparateEXT, glBlendFuncSeparateEXT, NULL, 729),
    NAME_FUNC_OFFSET(22393, glWindowPos2dMESA, glWindowPos2dMESA, NULL, 746),
    NAME_FUNC_OFFSET(22407, glWindowPos2dMESA, glWindowPos2dMESA, NULL, 746),
    NAME_FUNC_OFFSET(22424, glWindowPos2dvMESA, glWindowPos2dvMESA, NULL, 747),
    NAME_FUNC_OFFSET(22439, glWindowPos2dvMESA, glWindowPos2dvMESA, NULL, 747),
    NAME_FUNC_OFFSET(22457, glWindowPos2fMESA, glWindowPos2fMESA, NULL, 748),
    NAME_FUNC_OFFSET(22471, glWindowPos2fMESA, glWindowPos2fMESA, NULL, 748),
    NAME_FUNC_OFFSET(22488, glWindowPos2fvMESA, glWindowPos2fvMESA, NULL, 749),
    NAME_FUNC_OFFSET(22503, glWindowPos2fvMESA, glWindowPos2fvMESA, NULL, 749),
    NAME_FUNC_OFFSET(22521, glWindowPos2iMESA, glWindowPos2iMESA, NULL, 750),
    NAME_FUNC_OFFSET(22535, glWindowPos2iMESA, glWindowPos2iMESA, NULL, 750),
    NAME_FUNC_OFFSET(22552, glWindowPos2ivMESA, glWindowPos2ivMESA, NULL, 751),
    NAME_FUNC_OFFSET(22567, glWindowPos2ivMESA, glWindowPos2ivMESA, NULL, 751),
    NAME_FUNC_OFFSET(22585, glWindowPos2sMESA, glWindowPos2sMESA, NULL, 752),
    NAME_FUNC_OFFSET(22599, glWindowPos2sMESA, glWindowPos2sMESA, NULL, 752),
    NAME_FUNC_OFFSET(22616, glWindowPos2svMESA, glWindowPos2svMESA, NULL, 753),
    NAME_FUNC_OFFSET(22631, glWindowPos2svMESA, glWindowPos2svMESA, NULL, 753),
    NAME_FUNC_OFFSET(22649, glWindowPos3dMESA, glWindowPos3dMESA, NULL, 754),
    NAME_FUNC_OFFSET(22663, glWindowPos3dMESA, glWindowPos3dMESA, NULL, 754),
    NAME_FUNC_OFFSET(22680, glWindowPos3dvMESA, glWindowPos3dvMESA, NULL, 755),
    NAME_FUNC_OFFSET(22695, glWindowPos3dvMESA, glWindowPos3dvMESA, NULL, 755),
    NAME_FUNC_OFFSET(22713, glWindowPos3fMESA, glWindowPos3fMESA, NULL, 756),
    NAME_FUNC_OFFSET(22727, glWindowPos3fMESA, glWindowPos3fMESA, NULL, 756),
    NAME_FUNC_OFFSET(22744, glWindowPos3fvMESA, glWindowPos3fvMESA, NULL, 757),
    NAME_FUNC_OFFSET(22759, glWindowPos3fvMESA, glWindowPos3fvMESA, NULL, 757),
    NAME_FUNC_OFFSET(22777, glWindowPos3iMESA, glWindowPos3iMESA, NULL, 758),
    NAME_FUNC_OFFSET(22791, glWindowPos3iMESA, glWindowPos3iMESA, NULL, 758),
    NAME_FUNC_OFFSET(22808, glWindowPos3ivMESA, glWindowPos3ivMESA, NULL, 759),
    NAME_FUNC_OFFSET(22823, glWindowPos3ivMESA, glWindowPos3ivMESA, NULL, 759),
    NAME_FUNC_OFFSET(22841, glWindowPos3sMESA, glWindowPos3sMESA, NULL, 760),
    NAME_FUNC_OFFSET(22855, glWindowPos3sMESA, glWindowPos3sMESA, NULL, 760),
    NAME_FUNC_OFFSET(22872, glWindowPos3svMESA, glWindowPos3svMESA, NULL, 761),
    NAME_FUNC_OFFSET(22887, glWindowPos3svMESA, glWindowPos3svMESA, NULL, 761),
    NAME_FUNC_OFFSET(22905, glBindProgramNV, glBindProgramNV, NULL, 780),
    NAME_FUNC_OFFSET(22922, glDeleteProgramsNV, glDeleteProgramsNV, NULL, 781),
    NAME_FUNC_OFFSET(22942, glGenProgramsNV, glGenProgramsNV, NULL, 783),
    NAME_FUNC_OFFSET(22959, glGetVertexAttribPointervNV, glGetVertexAttribPointervNV, NULL, 789),
    NAME_FUNC_OFFSET(22985, glGetVertexAttribPointervNV, glGetVertexAttribPointervNV, NULL, 789),
    NAME_FUNC_OFFSET(23014, glIsProgramNV, glIsProgramNV, NULL, 793),
    NAME_FUNC_OFFSET(23029, glPointParameteriNV, glPointParameteriNV, NULL, 857),
    NAME_FUNC_OFFSET(23047, glPointParameterivNV, glPointParameterivNV, NULL, 858),
    NAME_FUNC_OFFSET(23066, gl_dispatch_stub_861, gl_dispatch_stub_861, NULL, 861),
    NAME_FUNC_OFFSET(23087, gl_dispatch_stub_863, gl_dispatch_stub_863, NULL, 863),
    NAME_FUNC_OFFSET(23103, glPrimitiveRestartIndexNV, glPrimitiveRestartIndexNV, NULL, 870),
    NAME_FUNC_OFFSET(23127, gl_dispatch_stub_873, gl_dispatch_stub_873, NULL, 873),
    NAME_FUNC_OFFSET(23151, gl_dispatch_stub_873, gl_dispatch_stub_873, NULL, 873),
    NAME_FUNC_OFFSET(23178, glBindFramebufferEXT, glBindFramebufferEXT, NULL, 874),
    NAME_FUNC_OFFSET(23196, glBindRenderbufferEXT, glBindRenderbufferEXT, NULL, 875),
    NAME_FUNC_OFFSET(23215, glCheckFramebufferStatusEXT, glCheckFramebufferStatusEXT, NULL, 876),
    NAME_FUNC_OFFSET(23240, glDeleteFramebuffersEXT, glDeleteFramebuffersEXT, NULL, 877),
    NAME_FUNC_OFFSET(23261, glDeleteRenderbuffersEXT, glDeleteRenderbuffersEXT, NULL, 878),
    NAME_FUNC_OFFSET(23283, glFramebufferRenderbufferEXT, glFramebufferRenderbufferEXT, NULL, 879),
    NAME_FUNC_OFFSET(23309, glFramebufferTexture1DEXT, glFramebufferTexture1DEXT, NULL, 880),
    NAME_FUNC_OFFSET(23332, glFramebufferTexture2DEXT, glFramebufferTexture2DEXT, NULL, 881),
    NAME_FUNC_OFFSET(23355, glFramebufferTexture3DEXT, glFramebufferTexture3DEXT, NULL, 882),
    NAME_FUNC_OFFSET(23378, glGenFramebuffersEXT, glGenFramebuffersEXT, NULL, 883),
    NAME_FUNC_OFFSET(23396, glGenRenderbuffersEXT, glGenRenderbuffersEXT, NULL, 884),
    NAME_FUNC_OFFSET(23415, glGenerateMipmapEXT, glGenerateMipmapEXT, NULL, 885),
    NAME_FUNC_OFFSET(23432, glGetFramebufferAttachmentParameterivEXT, glGetFramebufferAttachmentParameterivEXT, NULL, 886),
    NAME_FUNC_OFFSET(23470, glGetRenderbufferParameterivEXT, glGetRenderbufferParameterivEXT, NULL, 887),
    NAME_FUNC_OFFSET(23499, glIsFramebufferEXT, glIsFramebufferEXT, NULL, 888),
    NAME_FUNC_OFFSET(23515, glIsRenderbufferEXT, glIsRenderbufferEXT, NULL, 889),
    NAME_FUNC_OFFSET(23532, glRenderbufferStorageEXT, glRenderbufferStorageEXT, NULL, 890),
    NAME_FUNC_OFFSET(23554, gl_dispatch_stub_891, gl_dispatch_stub_891, NULL, 891),
    NAME_FUNC_OFFSET(23572, glBindFragDataLocationEXT, glBindFragDataLocationEXT, NULL, 894),
    NAME_FUNC_OFFSET(23595, glGetFragDataLocationEXT, glGetFragDataLocationEXT, NULL, 895),
    NAME_FUNC_OFFSET(23617, glGetUniformuivEXT, glGetUniformuivEXT, NULL, 896),
    NAME_FUNC_OFFSET(23633, glGetVertexAttribIivEXT, glGetVertexAttribIivEXT, NULL, 897),
    NAME_FUNC_OFFSET(23654, glGetVertexAttribIuivEXT, glGetVertexAttribIuivEXT, NULL, 898),
    NAME_FUNC_OFFSET(23676, glUniform1uiEXT, glUniform1uiEXT, NULL, 899),
    NAME_FUNC_OFFSET(23689, glUniform1uivEXT, glUniform1uivEXT, NULL, 900),
    NAME_FUNC_OFFSET(23703, glUniform2uiEXT, glUniform2uiEXT, NULL, 901),
    NAME_FUNC_OFFSET(23716, glUniform2uivEXT, glUniform2uivEXT, NULL, 902),
    NAME_FUNC_OFFSET(23730, glUniform3uiEXT, glUniform3uiEXT, NULL, 903),
    NAME_FUNC_OFFSET(23743, glUniform3uivEXT, glUniform3uivEXT, NULL, 904),
    NAME_FUNC_OFFSET(23757, glUniform4uiEXT, glUniform4uiEXT, NULL, 905),
    NAME_FUNC_OFFSET(23770, glUniform4uivEXT, glUniform4uivEXT, NULL, 906),
    NAME_FUNC_OFFSET(23784, glVertexAttribI1iEXT, glVertexAttribI1iEXT, NULL, 907),
    NAME_FUNC_OFFSET(23802, glVertexAttribI1ivEXT, glVertexAttribI1ivEXT, NULL, 908),
    NAME_FUNC_OFFSET(23821, glVertexAttribI1uiEXT, glVertexAttribI1uiEXT, NULL, 909),
    NAME_FUNC_OFFSET(23840, glVertexAttribI1uivEXT, glVertexAttribI1uivEXT, NULL, 910),
    NAME_FUNC_OFFSET(23860, glVertexAttribI2iEXT, glVertexAttribI2iEXT, NULL, 911),
    NAME_FUNC_OFFSET(23878, glVertexAttribI2ivEXT, glVertexAttribI2ivEXT, NULL, 912),
    NAME_FUNC_OFFSET(23897, glVertexAttribI2uiEXT, glVertexAttribI2uiEXT, NULL, 913),
    NAME_FUNC_OFFSET(23916, glVertexAttribI2uivEXT, glVertexAttribI2uivEXT, NULL, 914),
    NAME_FUNC_OFFSET(23936, glVertexAttribI3iEXT, glVertexAttribI3iEXT, NULL, 915),
    NAME_FUNC_OFFSET(23954, glVertexAttribI3ivEXT, glVertexAttribI3ivEXT, NULL, 916),
    NAME_FUNC_OFFSET(23973, glVertexAttribI3uiEXT, glVertexAttribI3uiEXT, NULL, 917),
    NAME_FUNC_OFFSET(23992, glVertexAttribI3uivEXT, glVertexAttribI3uivEXT, NULL, 918),
    NAME_FUNC_OFFSET(24012, glVertexAttribI4bvEXT, glVertexAttribI4bvEXT, NULL, 919),
    NAME_FUNC_OFFSET(24031, glVertexAttribI4iEXT, glVertexAttribI4iEXT, NULL, 920),
    NAME_FUNC_OFFSET(24049, glVertexAttribI4ivEXT, glVertexAttribI4ivEXT, NULL, 921),
    NAME_FUNC_OFFSET(24068, glVertexAttribI4svEXT, glVertexAttribI4svEXT, NULL, 922),
    NAME_FUNC_OFFSET(24087, glVertexAttribI4ubvEXT, glVertexAttribI4ubvEXT, NULL, 923),
    NAME_FUNC_OFFSET(24107, glVertexAttribI4uiEXT, glVertexAttribI4uiEXT, NULL, 924),
    NAME_FUNC_OFFSET(24126, glVertexAttribI4uivEXT, glVertexAttribI4uivEXT, NULL, 925),
    NAME_FUNC_OFFSET(24146, glVertexAttribI4usvEXT, glVertexAttribI4usvEXT, NULL, 926),
    NAME_FUNC_OFFSET(24166, glVertexAttribIPointerEXT, glVertexAttribIPointerEXT, NULL, 927),
    NAME_FUNC_OFFSET(24189, glFramebufferTextureLayerEXT, glFramebufferTextureLayerEXT, NULL, 928),
    NAME_FUNC_OFFSET(24215, glFramebufferTextureLayerEXT, glFramebufferTextureLayerEXT, NULL, 928),
    NAME_FUNC_OFFSET(24244, glColorMaskIndexedEXT, glColorMaskIndexedEXT, NULL, 929),
    NAME_FUNC_OFFSET(24257, glDisableIndexedEXT, glDisableIndexedEXT, NULL, 930),
    NAME_FUNC_OFFSET(24268, glEnableIndexedEXT, glEnableIndexedEXT, NULL, 931),
    NAME_FUNC_OFFSET(24278, glGetBooleanIndexedvEXT, glGetBooleanIndexedvEXT, NULL, 932),
    NAME_FUNC_OFFSET(24294, glGetIntegerIndexedvEXT, glGetIntegerIndexedvEXT, NULL, 933),
    NAME_FUNC_OFFSET(24310, glIsEnabledIndexedEXT, glIsEnabledIndexedEXT, NULL, 934),
    NAME_FUNC_OFFSET(24323, glGetTexParameterIivEXT, glGetTexParameterIivEXT, NULL, 937),
    NAME_FUNC_OFFSET(24344, glGetTexParameterIuivEXT, glGetTexParameterIuivEXT, NULL, 938),
    NAME_FUNC_OFFSET(24366, glTexParameterIivEXT, glTexParameterIivEXT, NULL, 939),
    NAME_FUNC_OFFSET(24384, glTexParameterIuivEXT, glTexParameterIuivEXT, NULL, 940),
    NAME_FUNC_OFFSET(24403, glBeginConditionalRenderNV, glBeginConditionalRenderNV, NULL, 941),
    NAME_FUNC_OFFSET(24428, glEndConditionalRenderNV, glEndConditionalRenderNV, NULL, 942),
    NAME_FUNC_OFFSET(24451, glBeginTransformFeedbackEXT, glBeginTransformFeedbackEXT, NULL, 943),
    NAME_FUNC_OFFSET(24476, glBindBufferBaseEXT, glBindBufferBaseEXT, NULL, 944),
    NAME_FUNC_OFFSET(24493, glBindBufferRangeEXT, glBindBufferRangeEXT, NULL, 946),
    NAME_FUNC_OFFSET(24511, glEndTransformFeedbackEXT, glEndTransformFeedbackEXT, NULL, 947),
    NAME_FUNC_OFFSET(24534, glGetTransformFeedbackVaryingEXT, glGetTransformFeedbackVaryingEXT, NULL, 948),
    NAME_FUNC_OFFSET(24564, glTransformFeedbackVaryingsEXT, glTransformFeedbackVaryingsEXT, NULL, 949),
    NAME_FUNC_OFFSET(24592, glProvokingVertexEXT, glProvokingVertexEXT, NULL, 950),
    NAME_FUNC_OFFSET(-1, NULL, NULL, NULL, 0)
};

#undef NAME_FUNC_OFFSET
