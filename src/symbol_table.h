#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include "token.h"

enum Types {
    NUM,
    STR,
};

typedef struct symbol_table_s {
    gidox_token *token;
    char *name;
    Types type;
    int size;
    int dimension;
    int declaration_line;
    int usage_line;
    void *addr;
    struct symbol_table_s *next;
} symbol_table;

#endif /* SYMBOL_TABLE_H_ */