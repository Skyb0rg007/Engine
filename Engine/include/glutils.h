/**
 * @file glutils.h
 * @brief Useful OpenGL utility functions
 */
#ifndef GLUTILS_H_INCLUDED
#define GLUTILS_H_INCLUDED

#include "common.h"
#include <GL/glew.h>
#include <stdlib.h>

/**
 * @brief Call an OpenGL function, checking for errors 
 * @param call The function call to make
 */
#if IS_DEBUG_BUILD
# define GLCHECK(call) do {                                                   \
    call;                                                                    \
    GLenum gl_err;                                                           \
    int gl_had_error = 0;                                                    \
    while ((gl_err = glGetError()) != GL_NO_ERROR) {                         \
        LOG_ERROR("%s\nGL error %#x: %s",                                    \
            #call, gl_err, glEnumName(gl_err));                              \
        gl_had_error = 1;                                                    \
    }                                                                        \
    if (gl_had_error)                                                        \
        exit(EXIT_FAILURE);                                                  \
} while (0)
#else
# define GLCHECK(call) call
#endif

/**
 * @brief Returns a readable name from OpenGL error codes
 * @param e the error code
 * @return pointer to an internal, statically-allocated string
 */
ATTR_INTERNAL
const char *glEnumName(GLenum e) ATTR_RETURNS_NONNULL;

#endif
