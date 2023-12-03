#ifndef PARSE_TREE_H_
#define PARSE_TREE_H_

#include "tokenization.h"

typedef struct gidox_parse_tree_s {
    gidox_token node_token;
    struct gidox_parse_tree_s *right;
    struct gidox_parse_tree_s *left;
} gidox_parse_tree;

#endif /* PARSE_TREE_H_ */