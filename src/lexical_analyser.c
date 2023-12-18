#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"
#include "utils.h"

void clear_buffer(char *buffer)
{
    for (size_t i = 0; buffer[i]; i++)
        buffer[i] = 0;
}

gidox_token_data get_new_token_data(
    size_t token_line,
    GidoxTokenType type,
    void *value)
{
    return ((gidox_token_data){.line = token_line, .type = type, .value = value});
}

static int fill_buffer(
    char buffer[MAX_TOKEN_LEN + 1],
    const char elem,
    size_t *buffer_idx,
    size_t *column,
    const size_t token_line
)
{
    if ((*buffer_idx) > (MAX_TOKEN_LEN - 1)) {
        printf("Token exceed maximum size in line %ld.\n", token_line);
        return (ERROR);
    }
    buffer[(*buffer_idx)] = elem;
    (*buffer_idx)++;
    (*column)++;
    return (SUCCESS);
}

gidox_token *tokenization(const char **file_source, const char *filename)
{
    char buffer[MAX_TOKEN_LEN + 1] = { 0 };
    gidox_token *token_list = NULL;
    size_t line_idx = 0;
    size_t buffer_idx = 0;
    GidoxTokenType next_token_type = GID_ENDOF;
    gidox_token_data next_token = {0};

    for (size_t line = 0; file_source[line]; line++)
        for (size_t col = 0; file_source[line][col]; col++)
            if (char_is_in_array(file_source[line][col], ILLEGAL_CHAR)) {
                printf("Illegal character used line n°%ld in file: %s.\n", line + 1, filename);
                return (NULL);
            }

    for (; file_source[line_idx] != NULL; line_idx++)
    {
        next_token_type = GID_ENDOF;
        for (size_t col = 0; file_source[line_idx][col]; col++)
        {
            buffer_idx = 0;
            if (char_is_in_array(file_source[line_idx][col], SKIP_CHAR))
                continue;
            if (char_is_in_array(file_source[line_idx][col], COMMENT_CHAR))
            {
                col = 0;
                break;
            }
            if (char_is_in_array(file_source[line_idx][col], IDENT_START_CHAR))
            {
                next_token_type = GID_IDENT;
                while (char_is_in_array(file_source[line_idx][col], LEGAL_CHAR))
                    if (fill_buffer((buffer), file_source[line_idx][col], &buffer_idx, &col, line_idx) == ERROR)
                        return (NULL);
            }
            next_token = get_new_token_data(line_idx, next_token_type, (void *)buffer);
            if (next_token.type != GID_ENDOF && strlen(buffer) != 0)
            {
                if (add_in_token_list(next_token, &token_list) == ERROR)
                {
                    printf("Error while getting new token.\n");
                    return (NULL);
                }
            }
            clear_buffer(buffer);
        }
        clear_buffer(buffer);
    }
    return (token_list);
}