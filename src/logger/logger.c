#include "logger.h"

void logger(const char *str, const char *color, ...)
{
    printf(color);
    printf(str);
    printf(COLOR_BASE);
}