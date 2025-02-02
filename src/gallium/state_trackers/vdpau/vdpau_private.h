/**************************************************************************
 *
 * Copyright 2010 Younes Manton & Thomas Balling Sørensen.
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

#ifndef VDPAU_PRIVATE_H
#define VDPAU_PRIVATE_H

#include <assert.h>

#include <vdpau/vdpau.h>
#include <vdpau/vdpau_x11.h>

#include "pipe/p_compiler.h"
#include "pipe/p_video_decoder.h"

#include "util/u_debug.h"
#include "vl/vl_compositor.h"

#include "vl_winsys.h"

/* Full VDPAU API documentation available at :
 * ftp://download.nvidia.com/XFree86/vdpau/doxygen/html/index.html */

#define INFORMATION G3DVL VDPAU Driver Shared Library version VER_MAJOR.VER_MINOR
#define QUOTEME(x) #x
#define TOSTRING(x) QUOTEME(x)
#define INFORMATION_STRING TOSTRING(INFORMATION)
#define VL_HANDLES

static inline enum pipe_video_chroma_format
ChromaToPipe(VdpChromaType vdpau_type)
{
   switch (vdpau_type) {
      case VDP_CHROMA_TYPE_420:
         return PIPE_VIDEO_CHROMA_FORMAT_420;
      case VDP_CHROMA_TYPE_422:
         return PIPE_VIDEO_CHROMA_FORMAT_422;
      case VDP_CHROMA_TYPE_444:
         return PIPE_VIDEO_CHROMA_FORMAT_444;
      default:
         assert(0);
   }

   return -1;
}

static inline VdpChromaType
PipeToChroma(enum pipe_video_chroma_format pipe_type)
{
   switch (pipe_type) {
      case PIPE_VIDEO_CHROMA_FORMAT_420:
         return VDP_CHROMA_TYPE_420;
      case PIPE_VIDEO_CHROMA_FORMAT_422:
         return VDP_CHROMA_TYPE_422;
      case PIPE_VIDEO_CHROMA_FORMAT_444:
         return VDP_CHROMA_TYPE_444;
      default:
         assert(0);
   }

   return -1;
}

static inline enum pipe_format
FormatYCBCRToPipe(VdpYCbCrFormat vdpau_format)
{
   switch (vdpau_format) {
      case VDP_YCBCR_FORMAT_NV12:
         return PIPE_FORMAT_NV12;
      case VDP_YCBCR_FORMAT_YV12:
         return PIPE_FORMAT_YV12;
      case VDP_YCBCR_FORMAT_UYVY:
         return PIPE_FORMAT_UYVY;
      case VDP_YCBCR_FORMAT_YUYV:
         return PIPE_FORMAT_YUYV;
      case VDP_YCBCR_FORMAT_Y8U8V8A8: /* Not defined in p_format.h */
         return PIPE_FORMAT_NONE;
      case VDP_YCBCR_FORMAT_V8U8Y8A8:
	     return PIPE_FORMAT_VUYA;
      default:
         assert(0);
   }

   return PIPE_FORMAT_NONE;
}

static inline VdpYCbCrFormat
PipeToFormatYCBCR(enum pipe_format p_format)
{
   switch (p_format) {
      case PIPE_FORMAT_NV12:
         return VDP_YCBCR_FORMAT_NV12;
      case PIPE_FORMAT_YV12:
         return VDP_YCBCR_FORMAT_YV12;
      case PIPE_FORMAT_UYVY:
         return VDP_YCBCR_FORMAT_UYVY;
      case PIPE_FORMAT_YUYV:
         return VDP_YCBCR_FORMAT_YUYV;
      //case PIPE_FORMAT_YUVA:
        // return VDP_YCBCR_FORMAT_Y8U8V8A8;
      case PIPE_FORMAT_VUYA:
         return VDP_YCBCR_FORMAT_V8U8Y8A8;
      default:
         assert(0);
   }

   return -1;
}

static inline enum pipe_format
FormatRGBAToPipe(VdpRGBAFormat vdpau_format)
{
   switch (vdpau_format) {
      case VDP_RGBA_FORMAT_A8:
         return PIPE_FORMAT_A8_UNORM;
      case VDP_RGBA_FORMAT_B10G10R10A2:
         return PIPE_FORMAT_B10G10R10A2_UNORM;
      case VDP_RGBA_FORMAT_B8G8R8A8:
         return PIPE_FORMAT_B8G8R8A8_UNORM;
      case VDP_RGBA_FORMAT_R10G10B10A2:
         return PIPE_FORMAT_R10G10B10A2_UNORM;
      case VDP_RGBA_FORMAT_R8G8B8A8:
         return PIPE_FORMAT_R8G8B8A8_UNORM;
      default:
         assert(0);
   }

   return PIPE_FORMAT_NONE;
}

static inline VdpRGBAFormat
PipeToFormatRGBA(enum pipe_format p_format)
{
   switch (p_format) {
      case PIPE_FORMAT_A8_UNORM:
         return VDP_RGBA_FORMAT_A8;
      case PIPE_FORMAT_B10G10R10A2_UNORM:
         return VDP_RGBA_FORMAT_B10G10R10A2;
      case PIPE_FORMAT_B8G8R8A8_UNORM:
         return VDP_RGBA_FORMAT_B8G8R8A8;
      case PIPE_FORMAT_R10G10B10A2_UNORM:
         return VDP_RGBA_FORMAT_R10G10B10A2;
      case PIPE_FORMAT_R8G8B8A8_UNORM:
         return VDP_RGBA_FORMAT_R8G8B8A8;
      default:
         assert(0);
   }

   return -1;
}

static inline enum pipe_format
FormatIndexedToPipe(VdpRGBAFormat vdpau_format)
{
   switch (vdpau_format) {
      case VDP_INDEXED_FORMAT_A4I4:
         return PIPE_FORMAT_A4R4_UNORM;
      case VDP_INDEXED_FORMAT_I4A4:
         return PIPE_FORMAT_R4A4_UNORM;
      case VDP_INDEXED_FORMAT_A8I8:
         return PIPE_FORMAT_A8R8_UNORM;
      case VDP_INDEXED_FORMAT_I8A8:
         return PIPE_FORMAT_R8A8_UNORM;
      default:
         assert(0);
   }

   return PIPE_FORMAT_NONE;
}

static inline enum pipe_format
FormatColorTableToPipe(VdpColorTableFormat vdpau_format)
{
   switch(vdpau_format) {
      case VDP_COLOR_TABLE_FORMAT_B8G8R8X8:
         return PIPE_FORMAT_B8G8R8X8_UNORM;
      default:
         assert(0);
   }

   return PIPE_FORMAT_NONE;
}

static inline enum pipe_video_profile
ProfileToPipe(VdpDecoderProfile vdpau_profile)
{
   switch (vdpau_profile) {
      case VDP_DECODER_PROFILE_MPEG1:
         return PIPE_VIDEO_PROFILE_MPEG1;
      case VDP_DECODER_PROFILE_MPEG2_SIMPLE:
         return PIPE_VIDEO_PROFILE_MPEG2_SIMPLE;
      case VDP_DECODER_PROFILE_MPEG2_MAIN:
         return PIPE_VIDEO_PROFILE_MPEG2_MAIN;
      case VDP_DECODER_PROFILE_H264_BASELINE:
         return PIPE_VIDEO_PROFILE_MPEG4_AVC_BASELINE;
      case VDP_DECODER_PROFILE_H264_MAIN:
         return PIPE_VIDEO_PROFILE_MPEG4_AVC_MAIN;
      case VDP_DECODER_PROFILE_H264_HIGH:
         return PIPE_VIDEO_PROFILE_MPEG4_AVC_HIGH;
      default:
         return PIPE_VIDEO_PROFILE_UNKNOWN;
   }
}

static inline VdpDecoderProfile
PipeToProfile(enum pipe_video_profile p_profile)
{
   switch (p_profile) {
      case PIPE_VIDEO_PROFILE_MPEG1:
         return VDP_DECODER_PROFILE_MPEG1;
      case PIPE_VIDEO_PROFILE_MPEG2_SIMPLE:
         return VDP_DECODER_PROFILE_MPEG2_SIMPLE;
      case PIPE_VIDEO_PROFILE_MPEG2_MAIN:
         return VDP_DECODER_PROFILE_MPEG2_MAIN;
      case PIPE_VIDEO_PROFILE_MPEG4_AVC_BASELINE:
         return VDP_DECODER_PROFILE_H264_BASELINE;
      case PIPE_VIDEO_PROFILE_MPEG4_AVC_MAIN:
         return VDP_DECODER_PROFILE_H264_MAIN;
      case PIPE_VIDEO_PROFILE_MPEG4_AVC_HIGH:
         return VDP_DECODER_PROFILE_H264_HIGH;
      default:
         assert(0);
         return -1;
   }
}

static inline struct pipe_video_rect *
RectToPipe(const VdpRect *src, struct pipe_video_rect *dst)
{
   if (src) {
      dst->x = MIN2(src->x1, src->x0);
      dst->y = MIN2(src->y1, src->y0);
      dst->w = abs(src->x1 - src->x0);
      dst->h = abs(src->y1 - src->y0);
      return dst;
   }
   return NULL;
}

typedef struct
{
   struct vl_screen *vscreen;
   struct vl_context *context;
   struct vl_compositor compositor;
} vlVdpDevice;

typedef struct
{
   vlVdpDevice *device;
   Drawable drawable;
} vlVdpPresentationQueueTarget;

typedef struct
{
   vlVdpDevice *device;
   Drawable drawable;
   struct vl_compositor compositor;
} vlVdpPresentationQueue;

typedef struct
{
   vlVdpDevice *device;
   struct vl_compositor compositor;
} vlVdpVideoMixer;

typedef struct
{
   vlVdpDevice *device;
   struct pipe_video_buffer *video_buffer;
} vlVdpSurface;

typedef uint64_t vlVdpTime;

typedef struct
{
   vlVdpTime timestamp;
   vlVdpDevice *device;
   struct pipe_surface *surface;
   struct pipe_sampler_view *sampler_view;
   struct pipe_fence_handle *fence;
} vlVdpOutputSurface;

typedef struct
{
   vlVdpDevice *device;
   struct pipe_video_decoder *decoder;
   unsigned num_buffers;
   void **buffers;
   unsigned cur_buffer;
} vlVdpDecoder;

typedef uint32_t vlHandle;

boolean vlCreateHTAB(void);
void vlDestroyHTAB(void);
vlHandle vlAddDataHTAB(void *data);
void* vlGetDataHTAB(vlHandle handle);
void vlRemoveDataHTAB(vlHandle handle);

boolean vlGetFuncFTAB(VdpFuncId function_id, void **func);

/* Public functions */
VdpDeviceCreateX11 vdp_imp_device_create_x11;
VdpPresentationQueueTargetCreateX11 vlVdpPresentationQueueTargetCreateX11;

/* Internal function pointers */
VdpGetErrorString vlVdpGetErrorString;
VdpDeviceDestroy vlVdpDeviceDestroy;
VdpGetProcAddress vlVdpGetProcAddress;
VdpGetApiVersion vlVdpGetApiVersion;
VdpGetInformationString vlVdpGetInformationString;
VdpVideoSurfaceQueryCapabilities vlVdpVideoSurfaceQueryCapabilities;
VdpVideoSurfaceQueryGetPutBitsYCbCrCapabilities vlVdpVideoSurfaceQueryGetPutBitsYCbCrCapabilities;
VdpDecoderQueryCapabilities vlVdpDecoderQueryCapabilities;
VdpOutputSurfaceQueryCapabilities vlVdpOutputSurfaceQueryCapabilities;
VdpOutputSurfaceQueryGetPutBitsNativeCapabilities vlVdpOutputSurfaceQueryGetPutBitsNativeCapabilities;
VdpOutputSurfaceQueryPutBitsIndexedCapabilities vlVdpOutputSurfaceQueryPutBitsIndexedCapabilities;
VdpOutputSurfaceQueryPutBitsYCbCrCapabilities vlVdpOutputSurfaceQueryPutBitsYCbCrCapabilities;
VdpBitmapSurfaceQueryCapabilities vlVdpBitmapSurfaceQueryCapabilities;
VdpVideoMixerQueryFeatureSupport vlVdpVideoMixerQueryFeatureSupport;
VdpVideoMixerQueryParameterSupport vlVdpVideoMixerQueryParameterSupport;
VdpVideoMixerQueryParameterValueRange vlVdpVideoMixerQueryParameterValueRange;
VdpVideoMixerQueryAttributeSupport vlVdpVideoMixerQueryAttributeSupport;
VdpVideoMixerQueryAttributeValueRange vlVdpVideoMixerQueryAttributeValueRange;
VdpVideoSurfaceCreate vlVdpVideoSurfaceCreate;
VdpVideoSurfaceDestroy vlVdpVideoSurfaceDestroy;
VdpVideoSurfaceGetParameters vlVdpVideoSurfaceGetParameters;
VdpVideoSurfaceGetBitsYCbCr vlVdpVideoSurfaceGetBitsYCbCr;
VdpVideoSurfacePutBitsYCbCr vlVdpVideoSurfacePutBitsYCbCr;
VdpDecoderCreate vlVdpDecoderCreate;
VdpDecoderDestroy vlVdpDecoderDestroy;
VdpDecoderGetParameters vlVdpDecoderGetParameters;
VdpDecoderRender vlVdpDecoderRender;
VdpOutputSurfaceCreate vlVdpOutputSurfaceCreate;
VdpOutputSurfaceDestroy vlVdpOutputSurfaceDestroy;
VdpOutputSurfaceGetParameters vlVdpOutputSurfaceGetParameters;
VdpOutputSurfaceGetBitsNative vlVdpOutputSurfaceGetBitsNative;
VdpOutputSurfacePutBitsNative vlVdpOutputSurfacePutBitsNative;
VdpOutputSurfacePutBitsIndexed vlVdpOutputSurfacePutBitsIndexed;
VdpOutputSurfacePutBitsYCbCr vlVdpOutputSurfacePutBitsYCbCr;
VdpOutputSurfaceRenderOutputSurface vlVdpOutputSurfaceRenderOutputSurface;
VdpOutputSurfaceRenderBitmapSurface vlVdpOutputSurfaceRenderBitmapSurface;
VdpBitmapSurfaceCreate vlVdpBitmapSurfaceCreate;
VdpBitmapSurfaceDestroy vlVdpBitmapSurfaceDestroy;
VdpBitmapSurfaceGetParameters vlVdpBitmapSurfaceGetParameters;
VdpBitmapSurfacePutBitsNative vlVdpBitmapSurfacePutBitsNative;
VdpPresentationQueueTargetDestroy vlVdpPresentationQueueTargetDestroy;
VdpPresentationQueueCreate vlVdpPresentationQueueCreate;
VdpPresentationQueueDestroy vlVdpPresentationQueueDestroy;
VdpPresentationQueueSetBackgroundColor vlVdpPresentationQueueSetBackgroundColor;
VdpPresentationQueueGetBackgroundColor vlVdpPresentationQueueGetBackgroundColor;
VdpPresentationQueueGetTime vlVdpPresentationQueueGetTime;
VdpPresentationQueueDisplay vlVdpPresentationQueueDisplay;
VdpPresentationQueueBlockUntilSurfaceIdle vlVdpPresentationQueueBlockUntilSurfaceIdle;
VdpPresentationQueueQuerySurfaceStatus vlVdpPresentationQueueQuerySurfaceStatus;
VdpPreemptionCallback vlVdpPreemptionCallback;
VdpPreemptionCallbackRegister vlVdpPreemptionCallbackRegister;
VdpVideoMixerSetFeatureEnables vlVdpVideoMixerSetFeatureEnables;
VdpVideoMixerCreate vlVdpVideoMixerCreate;
VdpVideoMixerRender vlVdpVideoMixerRender;
VdpVideoMixerSetAttributeValues vlVdpVideoMixerSetAttributeValues;
VdpVideoMixerGetFeatureSupport vlVdpVideoMixerGetFeatureSupport;
VdpVideoMixerGetFeatureEnables vlVdpVideoMixerGetFeatureEnables;
VdpVideoMixerGetParameterValues vlVdpVideoMixerGetParameterValues;
VdpVideoMixerGetAttributeValues vlVdpVideoMixerGetAttributeValues;
VdpVideoMixerDestroy vlVdpVideoMixerDestroy;
VdpGenerateCSCMatrix vlVdpGenerateCSCMatrix;

#define VDPAU_OUT   0
#define VDPAU_ERR   1
#define VDPAU_WARN  2
#define VDPAU_TRACE 3

static inline void VDPAU_MSG(unsigned int level, const char *fmt, ...)
{
   static int debug_level = -1;

   if (debug_level == -1) {
      debug_level = MAX2(debug_get_num_option("VDPAU_DEBUG", 0), 0);
   }

   if (level <= debug_level) {
      va_list ap;
      va_start(ap, fmt);
      _debug_vprintf(fmt, ap);
      va_end(ap);
   }
}

#endif /* VDPAU_PRIVATE_H */
