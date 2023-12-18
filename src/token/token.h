#ifndef TOKEN_H_
#define TOKEN_H_

#include <stdint.h>

#define MAX_TOKEN_LEN 50
#define ILLEGAL_CHAR "@~$"
#define COMMENT_CHAR "#"
#define OPERATOR "+-/*%="
#define IDENT_START_CHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"
#define LITERAL_CHAR "1234567890"
#define LEGAL_CHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_1234567890"
#define SKIP_CHAR "\t\n\r "

typedef enum {
    GID_OP_CBRC,
    GID_CL_CBRC,
    GID_OP_RBRC,
    GID_CL_RBRC,
    GID_SUM,
    GID_SUB,
    GID_DIV,
    GID_MUL,
    GID_MOD,
    GID_EQUAL,
    GID_IDENT,
    GID_SEMI,
    GID_RETURN,
    GID_NUM,
    GID_STR,
    GID_LIT,
    GID_ENDOF
} GidoxTokenType;

typedef struct gidox_token_data {
    GidoxTokenType type;
    size_t line;
    void *value;
} gidox_token_data;

typedef struct gidox_token_s {
    gidox_token_data data;
    struct gidox_token_s *next;
} gidox_token;

void print_token_list(gidox_token *token_list);
int add_in_token_list(gidox_token_data data, gidox_token **token_list);
void free_token_list(gidox_token **token_list);

#endif /* TOKEN_H_ */