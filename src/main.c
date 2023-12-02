#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "utils.h"
#include "errors.h"

int start_compile(char const **filepaths)
{
    int fd = 0;

    char buffer[1];
    for (int i = 0; filepaths[i] != NULL; i++) {
        fd = open(filepaths[i], O_RDONLY);
        while (read(fd, buffer, 1)) {
            
        }
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
    
    start_compile(argv);
    return (0);
}