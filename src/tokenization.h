#ifndef TOKENIZATION_H_
#define TOKENIZATION_H_

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

#endif /* TOKENIZATION_H_ */