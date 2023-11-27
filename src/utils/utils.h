#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char **str_to_word_array(char const *str, char const *separators);
int check_file_extension(const char *filepath, const char *extension);

#endif /* UTILS_H_ */