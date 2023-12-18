#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "errors.h"

const char *get_token_type_name(GidoxTokenType type)
{
    switch (type) {
        case (GID_OP_CBRC):
            return ("Opened curly bracket");
        case (GID_CL_CBRC):
            return ("Closed curly bracket");
        case (GID_OP_RBRC):
            return ("Opened round bracket");
        case (GID_CL_RBRC):
            return ("Closed round bracket");
        case (GID_SUM):
            return ("Addition");
        case (GID_SUB):
            return ("Substraction");
        case (GID_DIV):
            return ("Division");
        case (GID_MUL):
            return ("Multiplication");
        case (GID_MOD):
            return ("Modulo");
        case (GID_EQUAL):
            return ("Equal");
        case (GID_IDENT):
            return ("Identifier");
        case (GID_SEMI):
            return ("Semi-column");
        case (GID_RETURN):
            return ("Return");
        case (GID_NUM):
            return ("Num");
        case (GID_STR):
            return ("Str");
        case (GID_LIT):
            return ("Literal");
        case (GID_ENDOF):
            return ("EOF");
        default:
            return ("Unknown");
    }
}

void print_token_list(gidox_token *token_list)
{
    size_t idx = 0;
    for (; token_list != NULL; token_list = token_list->next, idx++) {
        printf("Token n°%ld:\n\tType of token: %s\n\tLine of the token: %ld\n\tValue of the token: %s\n",
            idx,
            get_token_type_name(token_list->data.type),
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
    if (new_token->data.value == NULL)
        return (ERROR);
    new_token->data.type = data.type;
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