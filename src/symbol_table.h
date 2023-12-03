#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

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

typedef struct symbol_table_s {
    gidox_token *token;
    struct symbol_table_s *next;
} symbol_table;

#endif /* SYMBOL_TABLE_H_ */