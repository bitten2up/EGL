#include "egl_internal.h"
#include "GL/picaGL.h"

typedef GLXContext (*__PFN_glXCreateContextAttribsARB)(Display*, GLXFBConfig,
                                                       GLXContext, Bool,
                                                       const int*);
typedef void (*__PFN_glXSwapIntervalEXT)(Display*, GLXDrawable, int);
typedef void(*__PFN_glFinish)();

__PFN_glXCreateContextAttribsARB glXCreateContextAttribsARB_PTR = NULL;
__PFN_glXSwapIntervalEXT glXSwapIntervalEXT_PTR = NULL;
__PFN_glFinish glFinish_PTR = NULL;

typedef struct {
    unsigned screen;
} picaDisplay;


EGLBoolean __internalInit(NativeLocalStorageContainer* nativeLocalStorageContainer, EGLint* GL_max_supported, EGLint* ES_max_supported)
{
    if (nativeLocalStorageContainer->display && nativeLocalStorageContainer->window && nativeLocalStorageContainer->ctx)
	{
		return EGL_TRUE;
	}

	if (nativeLocalStorageContainer->display)
	{
		return EGL_FALSE;
	}

	if (nativeLocalStorageContainer->window)
	{
		return EGL_FALSE;
	}

	if (nativeLocalStorageContainer->ctx)
	{
		return EGL_FALSE;
	}

    nativeLocalStorageContainer->display = malloc(size_of(picaDisplay));
    nativeLocalStorageContainer->display->screen = GFX_TOP;

    if (!nativeLocalStorageContainer->display)
	{
		return EGL_FALSE;
	}
    
    int pglMajor;
	int pglMinor;

    nativeLocalStorageContainer->window = &nativeLocalStorageContainer->display.screen;
    
    nativeLocalStorageContainer->ctx = *(pglGrabContext)(void); // todo: fix this

	if (!nativeLocalStorageContainer->ctx)
	{
		nativeLocalStorageContainer->window = 0;
        pglExit();
		nativeLocalStorageContainer->display = 0;

		return EGL_FALSE;
	}

    pglSelectScreen(nativeLocalStorageContainer->window, 0);
    ES_max_supported[0] = 1;
    ES_max_supported[1] = 1;
    return EGL_TRUE;
}

EGLBoolean __internalTerminate(NativeLocalStorageContainer* nativeLocalStorageContainer)
{
    return EGL_FALSE;
}

EGLBoolean __deleteContext(const EGLDisplayImpl* walkerDpy, const NativeContextContainer* nativeContextContainer)
{
    return EGL_FALSE;
}

EGLBoolean __processAttribList(EGLenum api, EGLint* target_attrib_list, const EGLint* attrib_list, EGLint* error)
{
    return EGL_FALSE;
}

EGLBoolean __createWindowSurface(EGLSurfaceImpl* newSurface, EGLNativeWindowType win, const EGLint *attrib_list, const EGLDisplayImpl* walkerDpy, const EGLConfigImpl* walkerConfig, EGLint* error)
{
    return EGL_FALSE;
}

EGLBoolean __createPbufferSurface(EGLSurfaceImpl* newSurface, const EGLint* attrib_list, const EGLDisplayImpl* walkerDpy, const EGLConfigImpl* walkerConfig, EGLint* error)
{
    return EGL_FALSE;
}

EGLBoolean __destroySurface(EGLNativeDisplayType dpy, const EGLSurfaceImpl* surface)
{
    return EGL_FALSE;
}

__eglMustCastToProperFunctionPointerType __getProcAddress(const char *procname)
{
    return NULL;
}

EGLBoolean __initialize(EGLDisplayImpl* walkerDpy, const NativeLocalStorageContainer* nativeLocalStorageContainer, EGLint* error)
{
    return EGL_FALSE;
}

EGLBoolean __createContext(NativeContextContainer* nativeContextContainer, const EGLDisplayImpl* walkerDpy, const NativeSurfaceContainer* nativeSurfaceContainer, const NativeContextContainer* sharedNativeContextContainer, const EGLint* attribList)
{
    return EGL_FALSE;
}

EGLBoolean __makeCurrent(const EGLDisplayImpl* walkerDpy, const NativeSurfaceContainer* nativeSurfaceContainer, const NativeContextContainer* nativeContextContainer)
{
    return EGL_FALSE;
}

EGLBoolean __swapBuffers(const EGLDisplayImpl* walkerDpy, const EGLSurfaceImpl* walkerSurface)
{
    pglSwapBuffers();
    return EGL_TRUE;
}

EGLBoolean __swapInterval(const EGLDisplayImpl* walkerDpy, EGLint interval)
{
    return EGL_FALSE;
}

EGLBoolean __getPlatformDependentHandles(void* out, const EGLDisplayImpl* walkerDpy, const NativeSurfaceContainer* nativeSurfaceContainer, const NativeContextContainer* nativeContextContainer)
{
    return EGL_FALSE;
}