/**
 * EGL desktop implementation.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) since 2014 Norbert Nopper
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <EGL/egl.h>
#include <GL/picaGL.h>
#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>

EGLAPI EGLBoolean EGLAPIENTRY eglChooseConfig (EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglCopyBuffers (EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLContext EGLAPIENTRY eglCreateContext (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list)
{
  pglInit();
	return NULL;
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferSurface (EGLDisplay dpy, EGLConfig config, const EGLint *attrib_list)
{
	return EGL_NO_SURFACE;
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePixmapSurface (EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint *attrib_list)
{
	// TODO Implement.

	return EGL_NO_SURFACE;
}

EGLAPI EGLSurface EGLAPIENTRY eglCreateWindowSurface (EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint *attrib_list)
{
	return EGL_NO_SURFACE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroyContext (EGLDisplay dpy, EGLContext ctx)
{
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroySurface (EGLDisplay dpy, EGLSurface surface)
{
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigAttrib (EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value)
{
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetConfigs (EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
	return EGL_TRUE;
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetCurrentDisplay (void)
{
	return EGL_NO_DISPLAY;
}

EGLAPI EGLSurface EGLAPIENTRY eglGetCurrentSurface (EGLint readdraw)
{
	return EGL_NO_SURFACE;
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetDisplay (EGLNativeDisplayType display_id)
{
	return EGL_NO_DISPLAY;
}

EGLAPI EGLint EGLAPIENTRY eglGetError (void)
{
	return 0;
}

EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress (const char *procname)
{
	return NULL;
}

EGLBoolean eglInitialize (EGLDisplay dpy, EGLint *major, EGLint *minor)
{
	static int initialized = 0;

	if (!initialized) {
		atexit((void *) eglTerminate);
		gfxInit(GSP_RGBA8_OES,GSP_RGB565_OES,false);

		initialized = 1;
	}

	if (major)
		*major = 1;
	if (minor)
		*minor = 1;

	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglMakeCurrent (EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx)
{
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglQueryContext (EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value)
{
	return EGL_TRUE;
}

EGLAPI const char *EGLAPIENTRY eglQueryString (EGLDisplay dpy, EGLint name)
{
	return NULL;
}

EGLAPI EGLBoolean EGLAPIENTRY eglQuerySurface (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value)
{
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglSwapBuffers (EGLDisplay dpy, EGLSurface surface)
{
	// TODO: implement properly
  pglSwapBuffers();
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglTerminate (EGLDisplay dpy)
{
	return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitGL (void)
{
#if 0
	EGLBoolean result;

    EGLenum api = _eglQueryAPI();

    _eglBindAPI(EGL_OPENGL_ES_API);

    result = _eglWaitClient();

    _eglBindAPI(api);

#endif
    return EGL_TRUE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitNative (EGLint engine)
{
	return EGL_TRUE;
}

//
// EGL_VERSION_1_1
//

EGLAPI EGLBoolean EGLAPIENTRY eglBindTexImage (EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseTexImage (EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglSurfaceAttrib (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglSwapInterval (EGLDisplay dpy, EGLint interval)
{
	return EGL_TRUE;
}

//
// EGL_VERSION_1_2
//

EGLAPI EGLBoolean EGLAPIENTRY eglBindAPI (EGLenum api)
{
	return EGL_TRUE;
}

EGLAPI EGLenum EGLAPIENTRY eglQueryAPI (void)
{
	return EGL_TRUE;
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePbufferFromClientBuffer (EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list)
{
	// TODO Implement.

	return EGL_NO_SURFACE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglReleaseThread (void)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitClient (void)
{
	return EGL_TRUE;
}

//
// EGL_VERSION_1_3
//

//
// EGL_VERSION_1_4
//

EGLAPI EGLContext EGLAPIENTRY eglGetCurrentContext (void)
{
	return EGL_NO_CONTEXT;
}

//
// EGL_VERSION_1_5
//

EGLAPI EGLSync EGLAPIENTRY eglCreateSync (EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list)
{
	// TODO Implement.

	return EGL_NO_SYNC;
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroySync (EGLDisplay dpy, EGLSync sync)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLint EGLAPIENTRY eglClientWaitSync (EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglGetSyncAttrib (EGLDisplay dpy, EGLSync sync, EGLint attribute, EGLAttrib *value)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLImage EGLAPIENTRY eglCreateImage (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint *attrib_list)
{
	// TODO Implement.

	return EGL_NO_IMAGE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglDestroyImage (EGLDisplay dpy, EGLImage image)
{
	// TODO Implement.

	return EGL_FALSE;
}

EGLAPI EGLDisplay EGLAPIENTRY eglGetPlatformDisplay (EGLenum platform, void *native_display, const EGLAttrib *attrib_list)
{
	// TODO Implement.

	return EGL_NO_DISPLAY;
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePlatformWindowSurface (EGLDisplay dpy, EGLConfig config, void *native_window, const EGLAttrib *attrib_list)
{
	// TODO Implement.

	return EGL_NO_SURFACE;
}

EGLAPI EGLSurface EGLAPIENTRY eglCreatePlatformPixmapSurface (EGLDisplay dpy, EGLConfig config, void *native_pixmap, const EGLAttrib *attrib_list)
{
	// TODO Implement.

	return EGL_NO_SURFACE;
}

EGLAPI EGLBoolean EGLAPIENTRY eglWaitSync (EGLDisplay dpy, EGLSync sync, EGLint flags)
{
	// TODO Implement.

	return EGL_FALSE;
}

/*
EGLAPI EGLBoolean EGLAPIENTRY eglGetPlatformDependentHandles (EGLContextInternals* out, EGLDisplay dpy, EGLSurface surface, EGLContext ctx)
{
	return _eglGetPlatformDependentHandles (out, dpy, surface, ctx);
}
*/
