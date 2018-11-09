/**
 * @file components.h
 * @brief The component structures used within the ECS
 *
 * We use X-macros to ensure all components are stored,
 * have getters, and have unique bitmasks
 */
#include "common.h"
#include <GL/glew.h>
#include "kvec.h"

/**
 * @brief X-macro to register getters, setters, and storage for all components
 * @param X a macro taking 4 arguments 
 *
 * The X macro takes the arguments (in order):
 * - the @c struct name
 * - the access name
 * - the @c enum name
 * - the component number
 *
 * The @c struct name is in PascalCase, 
 * the access name is in snake_case,
 * the @c enum name is in UPPERCASE, 
 * and the component number is a constantly increasing number
 */
#define COMPONENTS(X)                                                        \
    X(struct Location, location,  LOCATION,  0)                              \
    X(struct Render,   render,    RENDER,    1)                              \
    X(struct RenderGC, render_gc, RENDER_GC, 2)                              

/****************************************************************************/

/**
 * @brief Handles an object's location in space
 */
struct Location {
    GLint x, y, z; /**< The object's position */
    GLint rotx, roty, rotz; /**< The object's rotation */
    GLint scale; /**< The size of the object */
};

/**
 * @brief Holds data needed to render an object onto the screen
 */
struct Render {
    GLuint program; /**< The shader */
    GLuint VAO; /**< Holds all VBOs and EBO together */
    GLsizei num_indices; /**< The number of indices */

    struct UniformsCommon {
        GLint model_matrix;
        GLint view_matrix;
        GLint projection_matrix;
    } uniforms; /**< The location of the uniforms */
};

/**
 * @brief Holds handles to data that needs to be freed when the entity does
 */
struct RenderGC {
    kvec_t(GLuint) buffers; /**< Array of buffers needing to be freed */
};
