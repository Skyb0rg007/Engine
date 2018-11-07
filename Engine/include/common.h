/**
 * @file common.h
 * @brief Macros for debugging and controlling linkage.
 *
 * common.h is included first in all Engine files. This ensures the linkage
 * for all functions is correct, notably the definition of GLEW_STATIC or
 * GLEW_BUILD when statically linking the GLEW library on Windows.
 * Additionally, all files will eventually use logging and assertion
 * facilities, so having them all pre-included doesn't cloud any namespace
 *
 */
#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include "config.h"     /* Platform specific macros */
#include <SDL_assert.h> /* SDL_assert */
#include <SDL_log.h>    /* SDL_LogMessage */
#include <assert.h>     /* static_assert */

/************************************************
 * Convenience Macros
 ************************************************/
#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof ((arr)[0]))
#define PI 3.14159265359
#define DEGREES(X) ((X) * 180.0 / PI)
#define RADIANS(X) ((X) * PI / 180.0)

/************************************************
 * Logging Macros
 ************************************************/
#define LOG_INFO(...)     SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, \
        SDL_LOG_PRIORITY_INFO, __VA_ARGS__)
#define LOG_DEBUG(...)    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, \
        SDL_LOG_PRIORITY_DEBUG, __VA_ARGS__)
#define LOG_WARN(...)     SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, \
        SDL_LOG_PRIORITY_WARN, __VA_ARGS__)
#define LOG_ERROR(...)    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, \
        SDL_LOG_PRIORITY_ERROR, __VA_ARGS__)
#define LOG_CRITICAL(...) SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, \
        SDL_LOG_PRIORITY_CRITICAL, __VA_ARGS__)

#define ASSERT(X)          SDL_assert(X)
#define ASSERT_RELEASE(X)  SDL_assert_release(X)
#define ASSERT_PARANOID(X) SDL_assert_paranoid(X)

#define LOG_SETLEVEL(X) SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, X)

#ifdef static_assert
    #define STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
    #define STATIC_ASSERT(cond, msg) ((void)sizeof (struct{ int:-!!(cond);}))
#endif

/************************************************
 * Config Checking
 ************************************************/
#ifdef NDEBUG
    #define IS_DEBUG_BUILD 0
#else
    #define IS_DEBUG_BUILD 1
#endif

#endif
