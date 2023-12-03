#ifndef UTILS_H_
#define UTILS_H_

char **str_to_word_array(const char *str, const char *separators);
int check_file_extension(const char *filepath, const char *extension);
void free_2D_array(void **array);
void show_2D_array(void **array, const char *flag);

#endif /* UTILS_H_ */