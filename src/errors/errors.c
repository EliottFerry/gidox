#include "errors.h"
#include "utils.h"

void handle_stat_error(const char *filepath)
{
    printf("The file: %s has encountered an error. Error code: %d\n", filepath, errno);
}

int error_pre_tokenization(const char **filepath_array)
{
    struct stat fs;
    for (int i = 0; filepath_array[i] != NULL; i++) {
        if (lstat(filepath_array[i], &fs) == -1) {
            handle_stat_error(filepath_array[i]);
            return (errno);
        }
        if (check_file_extension(filepath_array[i], "gid") != 0) {
            printf("%s: Wrong type of file.\n", filepath_array[i]);
            return (1);
        }
    }
    return (0);
}