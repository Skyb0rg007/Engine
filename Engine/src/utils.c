#include "common.h"
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* load_file - convert a filepath into a content string
 * @path: the filepath
 *
 * Contracts:
 *  - @path is non-null and a valid file path
 * Responsibilities:
 *  - Call free() on the returned string
 */
ATTR_INTERNAL
char *load_file(const char *path)
{
    FILE *file = fopen(path, "rb");
    ASSERT(file != NULL);

    int ret = fseek(file, 0, SEEK_END);
    ASSERT(ret != -1);
    int file_length = ftell(file);
    ASSERT(file_length != -1);
    rewind(file);
    char *data = calloc(file_length + 1, sizeof (char));
    ASSERT(data != NULL);
    ret = fread(data, sizeof (char), file_length, file);
    ASSERT(ret == file_length);
    ret = fclose(file);
    ASSERT(ret != EOF);
    return data;
}
