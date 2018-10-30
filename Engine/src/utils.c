#include "common.h"
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
    if (file == NULL) {
        FATAL("Could not open %s: %s", path, strerror(errno));
    }

    int ret = fseek(file, 0, SEEK_END);
    ASSERT(ret != -1, "fseek: %s", strerror(errno));
    int file_length = ftell(file);
    ASSERT(file_length != -1, "ftell: %s", strerror(errno));
    rewind(file);
    char *data = calloc(file_length + 1, sizeof (char));
    ASSERT(data != NULL, "Out of memory");
    ret = fread(data, sizeof (char), file_length, file);
    ASSERT(ret == file_length, "fread");
    ret = fclose(file);
    ASSERT(ret != EOF, "fclose: %s", strerror(errno));
    return data;
}
