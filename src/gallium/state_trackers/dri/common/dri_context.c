/**************************************************************************
 *
 * Copyright 2009, VMware, Inc.
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
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/
/*
 * Author: Keith Whitwell <keithw@vmware.com>
 * Author: Jakob Bornecrantz <wallbraker@gmail.com>
 */

#include "utils.h"

#include "dri_screen.h"
#include "dri_drawable.h"
#include "dri_context.h"

#include "pipe/p_context.h"
#include "state_tracker/st_context.h"

static void
dri_pp_query(struct dri_context *ctx)
{
   unsigned int i;

   for (i = 0; i < PP_FILTERS; i++) {
      ctx->pp_enabled[i] = driQueryOptioni(&ctx->optionCache, pp_filters[i].name);
   }
}

GLboolean
dri_create_context(gl_api api, const struct gl_config * visual,
		   __DRIcontext * cPriv, void *sharedContextPrivate)
{
   __DRIscreen *sPriv = cPriv->driScreenPriv;
   struct dri_screen *screen = dri_screen(sPriv);
   struct st_api *stapi = screen->st_api;
   struct dri_context *ctx = NULL;
   struct st_context_iface *st_share = NULL;
   struct st_context_attribs attribs;

   memset(&attribs, 0, sizeof(attribs));
   switch (api) {
   case API_OPENGLES:
      attribs.profile = ST_PROFILE_OPENGL_ES1;
      break;
   case API_OPENGLES2:
      attribs.profile = ST_PROFILE_OPENGL_ES2;
      break;
   default:
      attribs.profile = ST_PROFILE_DEFAULT;
      break;
   }

   if (sharedContextPrivate) {
      st_share = ((struct dri_context *)sharedContextPrivate)->st;
   }

   ctx = CALLOC_STRUCT(dri_context);
   if (ctx == NULL)
      goto fail;

   cPriv->driverPrivate = ctx;
   ctx->cPriv = cPriv;
   ctx->sPriv = sPriv;
   ctx->lock = screen->drmLock;

   driParseConfigFiles(&ctx->optionCache,
		       &screen->optionCache, sPriv->myNum, "dri");

   dri_fill_st_visual(&attribs.visual, screen, visual);
   ctx->st = stapi->create_context(stapi, &screen->base, &attribs, st_share);
   if (ctx->st == NULL)
      goto fail;
   ctx->st->st_manager_private = (void *) ctx;
   ctx->stapi = stapi;

   // Context successfully created. See if post-processing is requested.
   dri_pp_query(ctx);

   ctx->pp = pp_init(screen->base.screen, ctx->pp_enabled);

   return GL_TRUE;

 fail:
   if (ctx && ctx->st)
      ctx->st->destroy(ctx->st);

   FREE(ctx);
   return GL_FALSE;
}

void
dri_destroy_context(__DRIcontext * cPriv)
{
   struct dri_context *ctx = dri_context(cPriv);

   /* note: we are freeing values and nothing more because
    * driParseConfigFiles allocated values only - the rest
    * is owned by screen optionCache.
    */
   FREE(ctx->optionCache.values);

   /* No particular reason to wait for command completion before
    * destroying a context, but it is probably worthwhile flushing it
    * to avoid having to add code elsewhere to cope with flushing a
    * partially destroyed context.
    */
   ctx->st->flush(ctx->st, 0, NULL);
   ctx->st->destroy(ctx->st);

   if (ctx->pp) pp_free(ctx->pp);

   FREE(ctx);
}

GLboolean
dri_unbind_context(__DRIcontext * cPriv)
{
   /* dri_util.c ensures cPriv is not null */
   struct dri_screen *screen = dri_screen(cPriv->driScreenPriv);
   struct dri_context *ctx = dri_context(cPriv);
   struct st_api *stapi = screen->st_api;

   if (--ctx->bind_count == 0) {
      if (ctx->st == ctx->stapi->get_current(ctx->stapi)) {
         ctx->st->flush(ctx->st, ST_FLUSH_FRONT, NULL);
         stapi->make_current(stapi, NULL, NULL, NULL);
      }
   }

   return GL_TRUE;
}

GLboolean
dri_make_current(__DRIcontext * cPriv,
		 __DRIdrawable * driDrawPriv,
		 __DRIdrawable * driReadPriv)
{
   /* dri_util.c ensures cPriv is not null */
   struct dri_context *ctx = dri_context(cPriv);
   struct dri_drawable *draw = dri_drawable(driDrawPriv);
   struct dri_drawable *read = dri_drawable(driReadPriv);
   struct st_context_iface *old_st = ctx->stapi->get_current(ctx->stapi);

   if (old_st && old_st != ctx->st)
      old_st->flush(old_st, ST_FLUSH_FRONT, NULL);

   ++ctx->bind_count;

   if (!driDrawPriv && !driReadPriv)
      return ctx->stapi->make_current(ctx->stapi, ctx->st, NULL, NULL);
   else if (!driDrawPriv || !driReadPriv)
      return GL_FALSE;

   if (ctx->dPriv != driDrawPriv) {
      ctx->dPriv = driDrawPriv;
      draw->texture_stamp = driDrawPriv->lastStamp - 1;
   }
   if (ctx->rPriv != driReadPriv) {
      ctx->rPriv = driReadPriv;
      read->texture_stamp = driReadPriv->lastStamp - 1;
   }

   ctx->stapi->make_current(ctx->stapi, ctx->st, &draw->base, &read->base);

   // This is ok to call here. If they are already init, it's a no-op.
   if (draw->textures[ST_ATTACHMENT_BACK_LEFT] && draw->textures[ST_ATTACHMENT_DEPTH_STENCIL]
      && ctx->pp)
         pp_init_fbos(ctx->pp, draw->textures[ST_ATTACHMENT_BACK_LEFT]->width0,
            draw->textures[ST_ATTACHMENT_BACK_LEFT]->height0,
            draw->textures[ST_ATTACHMENT_DEPTH_STENCIL]);

   return GL_TRUE;
}

struct dri_context *
dri_get_current(__DRIscreen *sPriv)
{
   struct dri_screen *screen = dri_screen(sPriv);
   struct st_api *stapi = screen->st_api;
   struct st_context_iface *st;

   st = stapi->get_current(stapi);

   return (struct dri_context *) (st) ? st->st_manager_private : NULL;
}

/* vim: set sw=3 ts=8 sts=3 expandtab: */
