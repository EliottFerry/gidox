#ifndef COMPILER_H_
#define COMPILER_H_

#include "errors.h"
#include "token.h"

#define var_name_str(s) #s
#define enum_var_str(s) var_name_str(s)
#define SUCCESS 0
#define ERROR -99

typedef struct gidox_compiler_s {
    char *filename;
    char **file_source;
    gidox_error_list *error_list;
    gidox_token *token_list;
} gidox_compiler;

#endif /* COMPILER_H_ */