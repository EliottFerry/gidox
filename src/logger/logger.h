#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>

#define COLOR_ERROR "\e[1;31m"
#define COLOR_WARNING "\e[1;35m"
#define COLOR_INFO "\e[1;36m"
#define COLOR_BASE "\e[0;37m"

void logger(const char *str, const char *color);

#endif /* LOGGER_H_ */
