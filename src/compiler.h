#ifndef COMPILER_H_
#define COMPILER_H_

#include "errors.h"

typedef struct gidox_compiler_s {
    gidox_error *error_list;
    char **file_source;
} gidox_compiler;

#endif /* COMPILER_H_ */