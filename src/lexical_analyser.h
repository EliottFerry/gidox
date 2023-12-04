#ifndef LEXICAL_ANALYSER_H_
#define LEXICAL_ANALYSER_H_

#define MAX_TOKEN_LEN 50

#include "token.h"
#include "compiler.h"

gidox_token *tokenization(gidox_compiler *engine);

#endif /* LEXICAL_ANALYSER_H_ */