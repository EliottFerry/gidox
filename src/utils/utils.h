#ifndef UTILS_H_
#define UTILS_H_

#include <stddef.h>

char **str_to_word_array(const char *str, const char *separators);
int check_file_extension(const char *filepath, const char *extension);
void free_2D_array(void **array);
void show_2D_array(void **array, const char *flag);
int char_is_in_array(const char elem, const char *array);
char **str_to_word_array_with_empty_lines(char const *str, char const *separators);

#endif /* UTILS_H_ */