#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lexical_analyser.h"
#include "token.h"
#include "compiler.h"
#include "utils.h"

void clear_buffer(char *buffer)
{
    for (size_t i = 0; buffer[i]; i++)
        buffer[i] = 0;
}

gidox_token *tokenization(gidox_compiler *engine)
{
    char buffer[MAX_TOKEN_LEN + 1] = { 0 };
    gidox_token *token_list = NULL;
    size_t line_idx = 0;
    size_t buffer_idx = 0;
    GidoxTokenType next_token = GID_ENDOF;

    for (size_t line = 0; engine->file_source[line]; line++) {
        for (size_t col = 0; engine->file_source[line][col]; col++) {
            if (char_is_in_array(engine->file_source[line][col], ILLEGAL_CHAR)) {
                printf("Illegal character used line n°%ld in file: %s.\n", line + 1, engine->filename);
                return (NULL);
            }
        }
    }

    for (; engine->file_source[line_idx] != NULL; line_idx++) {
        for (size_t col = 0; engine->file_source[line_idx][col]; col++) {
            buffer_idx = 0;
            if (char_is_in_array(engine->file_source[line_idx][col], SKIP_CHAR)) {
                continue;
            }
            if (char_is_in_array(engine->file_source[line_idx][col], COMMENT_CHAR)){
                col = 0;
                break;
            }
            if (char_is_in_array(engine->file_source[line_idx][col], IDENT_START_CHAR)) {
                next_token = GID_IDENT;
                while (char_is_in_array(engine->file_source[line_idx][col], LEGAL_CHAR)) {
                    if (buffer_idx > MAX_TOKEN_LEN - 1) {
                        printf("Token exceed maximum size in line %ld.\n", line_idx);
                        return (NULL);
                    }
                    buffer[buffer_idx] = engine->file_source[line_idx][col];
                    col++;
                    buffer_idx++;
                }
            }
            if (strlen(buffer) != 0) {
                if (add_in_token_list((gidox_token_data) {
                    .line = line_idx + 1,
                    .token = next_token,
                    .value = (void *)(buffer)
                }, &token_list) == ERROR) {
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