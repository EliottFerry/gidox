
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "utils.h"
#include "compiler.h"
#include "lexical_analyser.h"

int get_source_file(char const *filepath, gidox_compiler *engine)
{
    int fd = 0;
    char *buffer;
    struct stat fs;

    engine->filename = malloc(sizeof(char) * strlen(filepath));
    if (engine->filename == NULL)
        return (MALLOC_ERROR);
    stat(filepath, &fs);
    buffer = malloc(sizeof(char) * fs.st_size + 1);
    if (buffer == NULL) {
        
        return (MALLOC_ERROR);
    }
    buffer[fs.st_size] = '\0';
    fd = open(filepath, O_RDONLY);
    if (read(fd, buffer, fs.st_size) == -1) {
        free(buffer);
        close(fd);
        return (MALLOC_ERROR);
    }
    engine->file_source = str_to_word_array(buffer, "\n");
    free(buffer);
    close(fd);
    return (SUCCESS);
}

void free_engine(gidox_compiler *engine)
{
    free_2D_array((void **)(engine->file_source));
    free(engine->filename);
    free(engine);
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
    gidox_token *token_list = NULL;
    for (int i = 0; argv[i] != NULL; i++) {
        if (get_source_file(argv[i], engine) == MALLOC_ERROR) {
            free(engine);
            return (84);
        }
        token_list = tokenization(engine);
        if (token_list == NULL)
            break;
    }
    free_engine(engine);
    return (0);
}