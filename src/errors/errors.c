#include "errors.h"
#include "utils.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

void print_error(const char *error_msg, const char *where)
{
    printf("%s%s\n", error_msg, where);
}

int error_pre_tokenization(const char **filepath_array)
{
    for (int i = 0; filepath_array[i] != NULL; i++) {
        if (check_file_extension(filepath_array[i], "gid") != 0) {
            printf("%s: Wrong type of file.\n", filepath_array[i]);
            return (1);
        }
    }
    return (0);
}