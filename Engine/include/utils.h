/**
 * @file utils.h 
 * @brief Basic program utilities
 */
#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "common.h"

/** 
 * @brief convert a filepath into a content string
 * @param path the filepath to load
 * @return the file as a @c malloc ed string
 *
 * @note 
 * - @p path must be non-null and a valid file path
 * - Must call @c free() on the returned string
 */
ATTR_INTERNAL char *load_file(const char *path) ATTR_NONNULL(1);

#endif
