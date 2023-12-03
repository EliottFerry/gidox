#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "errors.h"
#include "compiler.h"

int start_compile(char const **filepaths, gidox_compiler *engine)
{
    int fd = 0;
    char *buffer;
    struct stat fs;
    for (int i = 0; filepaths[i] != NULL; i++) {
        stat(filepaths[i], &fs);
        buffer = malloc(sizeof(char) * fs.st_size + 1);
        buffer[fs.st_size] = '\0';
        fd = open(filepaths[i], O_RDONLY);
        read(fd, buffer, fs.st_size);
        engine->file_source = str_to_word_array(buffer, "\n");
        show_2D_array((void **)(engine->file_source), "%s\n");
        free_2D_array((void **)(engine->file_source));
        free(buffer);
        close(fd);
    }
    return (0);
}

int main(int argc, char const **argv)
{
    if (argc < 2) {
        printf("Error: please enter files to compile\n");
        return (84);
    }
    if (error_pre_tokenization(++argv) != 0)
        return (84);

    gidox_compiler *engine = malloc(sizeof(gidox_compiler));
    start_compile(argv, engine);
    free(engine);
    return (0);
}