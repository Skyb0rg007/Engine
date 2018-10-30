#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include "config.h"
#include <GL/glew.h>
#include <SDL_assert.h>
#include <SDL_log.h>
#include <assert.h>

/* Convenience macros */
#define ARRAY_SIZE(arr) (sizeof (arr) / sizeof ((arr)[0]))
#define PI 3.14159265359
#define DEGREES(X) ((X) * 180.0 / PI)
#define RADIANS(X) ((X) * PI / 180.0)

/* Logging and error checking mechanisms */
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

#ifdef static_assert
    #define STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else
    #define STATIC_ASSERT(cond, msg) ((void)sizeof (char[1 - 2*!!(cond)]))
#endif

/* Use this to check if the current configuration is debug */
#ifndef NDEBUG
    #define IS_DEBUG_BUILD 1
#endif

#endif
