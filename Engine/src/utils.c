#include "common.h"
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

ATTR_INTERNAL
char *load_file(const char *path)
{
    int ret;

    FILE *file = fopen(path, "rt");
    ASSERT(file != NULL);

    ret = fseek(file, 0, SEEK_END);
    ASSERT(ret != -1);
    long file_length = ftell(file);
    ASSERT(file_length != -1);
    rewind(file);
    char *data = calloc(file_length + 1, sizeof (char));
    ASSERT(data != NULL);
    size_t read_length = fread(data, sizeof (char), file_length, file);
    ASSERT((long)read_length == file_length);
    ret = fclose(file);
    ASSERT(ret != EOF);

    return data;
}
