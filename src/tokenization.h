#ifndef TOKENIZATION_H_
#define TOKENIZATION_H_

enum TokenType {
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

typedef struct token_s {
    TokenType token;
    void *value;
} token;

#endif /* TOKENIZATION_H_ */