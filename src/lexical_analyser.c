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

int is_illegal_char(char c)
{
    for (int i = 0; ILLEGAL_CHAR[i]; i++)
        if (c == ILLEGAL_CHAR[i])
            return (1);
    return (0);
}

int is_legal_char(char c)
{
    for (int i = 0; LEGAL_CHAR[i]; i++)
        if (c == LEGAL_CHAR[i])
            return (1);
    return (0);
}

int get_first_char_type(char c)
{
    for (int i = 0; LEGAL_CHAR[i]; i++) {
        if (c == LEGAL_CHAR[i])
            return (GID_STR);
    }
}

gidox_token *tokenization(gidox_compiler *engine)
{
    char buffer[MAX_TOKEN_LEN + 1] = { 0 };
    GidoxTokenType next_token = -2;
    gidox_token *token_list = NULL;
    uint32_t line_idx = 0;
    uint32_t buffer_idx = 0;
    for (uint32_t line = 0; engine->file_source[line]; line++) {
        for (uint32_t col = 0; engine->file_source[line][col]; col++) {
            if (is_illegal_char(engine->file_source[line][col])) {
                printf("Illegal character used line n°%d in file: %s.\n", line + 1, engine->filename);
                return (NULL);
            }
        }
    }

    while (next_token != GID_ENDOF) {
        buffer_idx = 0;
        if (engine->file_source[line_idx] == NULL) {
            return (token_list);
        }
        for (uint32_t col = 0; engine->file_source[line_idx][col]; col++) {

            if (char_is_in_array(engine->file_source[line_idx][col], SKIP_CHAR)) {
                continue;
            }
            if (char_is_in_array(engine->file_source[line_idx][col], COMMENT_CHAR)){
                col = 0;
                break;
            }
            if (engine->file_source[line_idx][col] == '\0') {
                next_token = GID_ENDOF;
                continue;
            }
            if (char_is_in_array(engine->file_source[line_idx][col], IDENT_START_CHAR)) {
                while (char_is_in_array(engine->file_source[line_idx][col], LEGAL_CHAR)) {
                    buffer[buffer_idx] = engine->file_source[line_idx][col];
                    col++;
                    buffer_idx++;
                }
                printf("Buffer after while: %s\n", buffer);
                clear_buffer(buffer);
                buffer_idx = 0;
            }
            // switch (get_first_char_type(engine->file_source[line_idx][col])) {
            //     case 
            //     buffer[col % MAX_TOKEN_LEN] = engine->file_source[line_idx][col];
            // }
        }
        line_idx++;
        clear_buffer(buffer);
    }
}