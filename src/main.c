#include "config.h"
#include <SDL.h>
#include <SDL_image.h>
#include <GL/glew.h>
#include <stdio.h>
#include <assert.h>

static void check_SDL(void);
static void check_SDL_image(void);
static void check_OpenGL(void);

int main(int argc, char *argv[])
{
	(void)argc; (void)argv;
    check_SDL();
    check_SDL_image();
    check_OpenGL();
    printf("RESOURCE_DIR = %s\n", RESOURCE_DIR);
#ifdef DISABLE_ATTRIBUTES
    printf("Attributes are disabled\n");
#else
    printf("Attributes are enabled\n");
#endif

    return 0;
}

static void check_SDL(void)
{
    SDL_version compiled, linked;
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);
    printf("Compiled against SDL version %d.%d.%d\n",
            compiled.major, compiled.minor, compiled.patch);
    printf("Linked against SDL version %d.%d.%d\n",
            linked.major, linked.minor, linked.patch);
}

static void check_SDL_image(void)
{
    SDL_version compiled;
    SDL_IMAGE_VERSION(&compiled);
    const SDL_version *linked = IMG_Linked_Version();
    printf("Compiled against SDL_image version %d.%d.%d\n",
            compiled.major, compiled.minor, compiled.patch);
    printf("Linked against SDL_image version %d.%d.%d\n",
            linked->major, linked->minor, linked->patch);
}

static void check_OpenGL(void)
{
    int ret = SDL_Init(SDL_INIT_VIDEO);
    assert(ret == 0);

    SDL_Window *window = SDL_CreateWindow("unused", 0, 0, 100, 100,
            SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);
    assert(window != NULL);

    SDL_GLContext ctx = SDL_GL_CreateContext(window);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    assert(err == GLEW_OK);

    printf("Using GLEW version %s\n", glewGetString(GLEW_VERSION));

    const GLubyte *version = glGetString(GL_VERSION);
    assert(glGetError() == GL_NO_ERROR);
    printf("Using OpenGL version %s\n", (const char *)version);

    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
