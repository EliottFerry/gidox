#ifndef TOKEN_H_
#define TOKEN_H_

#include <stdint.h>

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

typedef struct gidox_token_s {
    GidoxTokenType token;
    uint32_t line;
    void *value;
    struct gidox_token_s *next;
} gidox_token;

#endif /* TOKEN_H_ */