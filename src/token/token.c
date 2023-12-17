#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "errors.h"

void print_token_list(gidox_token *token_list)
{
    size_t idx = 0;
    for (; token_list != NULL; token_list = token_list->next, idx++) {
        printf("Token n°%ld:\n\tType of token: %d\n\tLine of the token: %ld\n\tValue of the token: %s\n",
            idx,
            token_list->data.token,
            token_list->data.line,
            (char *)token_list->data.value
        );
    }
}

int add_in_token_list(gidox_token_data data, gidox_token **token_list)
{
    gidox_token *new_token = malloc(sizeof(gidox_token));
    gidox_token *tmp = *token_list;
    if (new_token == NULL)
        return (ERROR);
    new_token->data.line = data.line;
    new_token->data.value = strdup((char *)data.value);
    new_token->data.token = data.token;
    new_token->next = NULL;
    if (*token_list == NULL) {
        *token_list = new_token;
        return (SUCCESS);
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new_token;
    return (SUCCESS);
}

void free_token_list(gidox_token **token_list)
{
    gidox_token *current = *token_list;
    gidox_token *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current->data.value);
        free(current);
        current = next;
    }
    *token_list = NULL;
}