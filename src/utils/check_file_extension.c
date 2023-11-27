#include <string.h>

int check_file_extension(const char *filepath, const char *extension)
{
    const char *dot = strchr(filepath, '.');
    if (!dot)
        return (1);
    if (strcmp((dot + 1), extension) != 0)
        return (1);
    return (0);
}