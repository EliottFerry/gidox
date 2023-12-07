#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "lexical_analyser.h"
#include "utils.h"

void clear_buffer(char *buffer)
{
    for (uint32_t i = 0; buffer[i]; i++)
        buffer[i] = 0;
}

gidox_token *tokenization(gidox_compiler *engine)
{
    char buffer[MAX_TOKEN_LEN + 1] = { 0 };
    gidox_token *token_list = NULL;
    uint32_t line_idx = 0;
    uint32_t buffer_idx = 0;

    for (uint32_t line = 0; engine->file_source[line]; line++) {
        for (uint32_t col = 0; engine->file_source[line][col]; col++) {
            if (char_is_in_array(engine->file_source[line][col], ILLEGAL_CHAR)) {
                printf("Illegal character used line n°%d in file: %s.\n", line + 1, engine->filename);
                return (NULL);
            }
        }
    }

    while (engine->file_source[line_idx] != NULL) {
        buffer_idx = 0;
        for (uint32_t col = 0; engine->file_source[line_idx][col]; col++) {
            if (char_is_in_array(engine->file_source[line_idx][col], SKIP_CHAR)) {
                continue;
            }
            if (char_is_in_array(engine->file_source[line_idx][col], COMMENT_CHAR)){
                col = 0;
                break;
            }
            if (char_is_in_array(engine->file_source[line_idx][col], IDENT_START_CHAR)) {
                while (char_is_in_array(engine->file_source[line_idx][col], LEGAL_CHAR)) {
                    if (buffer_idx > MAX_TOKEN_LEN - 1) {
                        printf("Token exceed maximum size in line %d.\n", line_idx);
                        return (NULL);
                    }
                    buffer[buffer_idx] = engine->file_source[line_idx][col];
                    col++;
                    buffer_idx++;
                }
                printf("Buffer after while: %s\n", buffer);
                clear_buffer(buffer);
                buffer_idx = 0;
            }
        }
        line_idx++;
        clear_buffer(buffer);
    }
    return (token_list);
}