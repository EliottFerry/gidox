#include "utils.h"
#include "errors.h"
#include <stdio.h>

int main(int argc, char const **argv)
{
    if (argc < 2) {
        printf("Error: please enter files to compile\n");
        return (84);
    }
    if (error_pre_tokenization(argv + 1) != 0)
        return (84);
    
    return (0);
}