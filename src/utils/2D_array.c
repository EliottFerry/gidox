#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void show_2D_array(void **array, const char *flag)
{
    for (int i = 0; array[i] != NULL; i++)
        printf(flag, array[i]);
}

void free_2D_array(void **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}