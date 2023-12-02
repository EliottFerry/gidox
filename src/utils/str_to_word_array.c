#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static int is_sep(char c, char const *separators)
{
    for (int i = 0; separators[i]; i++)
        if (c == separators[i])
            return (1);
    return (0);
}

static int count_nb_word(char const *str, char const *separators)
{
    int count = 0;
    for (int i = 0; str[i];i++) {
        if (is_sep(str[i], separators)) {
            for (; is_sep(str[i], separators) && str[i + 1]; i++);
            continue;
        } else {
            count++;
            for (; !is_sep(str[i], separators) && str[i + 1]; i++);
            continue;
        }
    }
    return (count);
}

static int word_size(char const *str, char const *separators)
{
    int i = 0;
    for (; !is_sep(str[i], separators) && str[i]; i++);
    return i;
}

static void go_to_next_word(char **str, char const *separators)
{
    for (; is_sep(**str, separators); (*str)++);
}

static void add_word(char **array, int pos, char **str, int word_len)
{
    int i = 0;
    array[pos] = malloc(sizeof(char) * word_len + 1);
    for (; i < word_len; (*str)++, i++)
        array[pos][i] = **str;
    array[pos][i] = '\0';
}

char **str_to_word_array(char const *str, char const *separators)
{
    char *str_cpy = strdup(str);
    int nb_word = count_nb_word(str_cpy, separators);
    char **array = malloc(sizeof(char *) * (nb_word + 1));
    
    for (int i = 0; i < nb_word; i++) {
        go_to_next_word(&str_cpy, separators);
        add_word(array, i, &str_cpy, word_size(str_cpy, separators));
    }
    go_to_next_word(&str_cpy, separators);
    array[nb_word] = NULL;
    str_cpy -= strlen(str);
    free(str_cpy);
    return (array);
}