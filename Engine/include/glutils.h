/**
 * @file glutils.h
 * @brief Useful OpenGL utility functions
 */
#ifndef GLUTILS_H_INCLUDED
#define GLUTILS_H_INCLUDED

#include "common.h"
#include <GL/glew.h>
#include <stdlib.h>


/* Generating buffers (Array buffers + Element array buffers) */
GLuint gen_buffer(GLenum type, GLsizei size, const void *data) ATTR_NONNULL(3);
void   attrib_buffer(GLuint index, GLint size, GLenum type, 
        GLsizei stride, intptr_t offset);
void   del_buffer(GLuint buffer);

/* Generating vertex array objects */
GLuint gen_array(void);
void   bind_array(GLuint vao);
void   del_array(GLuint vao);

/* Generating shaders */
GLuint make_shader(GLenum type, const char *src)  ATTR_NONNULL(2);
GLuint load_shader(GLenum type, const char *path) ATTR_NONNULL(2); 

/* Generating shader programs */
GLuint make_program(GLuint shader1, GLuint shader2);
GLuint load_program(const char *vpath, const char *fpath) ATTR_NONNULL(1,2);
void   use_program(GLuint prog); 
void   del_program(GLuint prog);

/* Generating textures */
GLuint load_texture(const char *path);
void   bind_texture(GLuint tex);
void   del_texture(GLuint tex);

/**
 * @brief Call an OpenGL function, checking for errors 
 * @param call The function call to make
 */
#if IS_DEBUG_BUILD
# define GLCHECK(call) do {                                                  \
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
