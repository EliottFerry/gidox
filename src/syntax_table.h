#ifndef SYNTAX_TABLE_H_
#define SYNTAX_TABLE_H_

enum GidoxTokenType {
    OP_CBRC,
    CL_CBRC,
    OP_RBRC,
    CL_CBRC,
    SUM,
    DIV,
    MUL,
    DIV,
    MOD,
    EQUAL,
    CUSTOM,
    SEMI,
    RETURN,
    NUM,
    STR,
};

typedef struct gidox_token_s {
    GidoxTokenType token;
    void *value;
} gidox_token;

typedef struct syntax_table_s {
    gidox_token *token;
    struct syntax_table_s *next;
} syntax_table;

#endif /* SYNTAX_TABLE_H_ */