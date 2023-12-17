
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
    int return_value = SUCCESS;
    
    if (stat(filepath, &fs) == -1) {
        print_error(ERROR_STR_STAT, filepath);
        return (ERROR);
    }

    engine->filename = malloc(sizeof(char) * strlen(filepath));
    if (engine->filename == NULL) {
        print_error(ERROR_STR_ALLOC, var_name_str(engine->filename));
        return (ERROR);
    }
    if (memcpy(engine->filename, filepath, strlen(filepath)) == NULL) {
        print_error(ERROR_STR_MEMCPY, var_name_str(engine->filename));
        return (ERROR);
    }
    buffer = malloc(sizeof(char) * fs.st_size + 1);
    if (buffer == NULL) {
        print_error(ERROR_STR_ALLOC, var_name_str(buffer));
        return (ERROR);
    }
    buffer[fs.st_size] = '\0';

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        print_error(ERROR_STR_OPEN, filepath);
        return_value = ERROR;
        goto leave_buffer;
    }

    if (read(fd, buffer, fs.st_size) == -1) {
        print_error(ERROR_STR_READ, filepath);
        return_value = ERROR;
        goto leave_open;
    }

    engine->file_source = str_to_word_array(buffer, "\n");
    if (engine->file_source == NULL) {
        print_error(ERROR_STR_ALLOC, var_name_str(engine->file_source));
        return_value = ERROR;
        goto leave_open;
    }
    leave_open:
    close(fd);
    leave_buffer:
    free(buffer);
    return (return_value);
}

void free_engine(gidox_compiler *engine)
{
    free_2D_array((void **)(engine->file_source));
    free_token_list(&(engine->token_list));
    free(engine->filename);
    free(engine);
    free(engine->error_list);
}

int main(int argc, char const **argv)
{
    if (argc < 2) {
        printf("Error: please enter files to compile\n");
        return (84);
    }
    ++argv;
    gidox_compiler *engine = malloc(sizeof(gidox_compiler));
    if (engine == NULL) {
        print_error(ERROR_STR_ALLOC, var_name_str(engine));
        return (84);
    }
    engine->error_list = malloc(sizeof(gidox_error_list));
    if (engine->error_list == NULL) {
        print_error(ERROR_STR_ALLOC, var_name_str(engine->error_list));
        return (84);
    }

    if (error_pre_tokenization(argv) != 0)
        return (84);

    for (int i = 0; argv[i] != NULL; i++) {
        if (get_source_file(argv[i], engine) == ERROR) {
            free(engine);
            return (84);
        }
        engine->token_list = tokenization(engine);
        if (engine->token_list == NULL)
            break;
        print_token_list(engine->token_list);
    }
    free_engine(engine);
    return (0);
}