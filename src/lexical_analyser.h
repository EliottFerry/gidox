#ifndef LEXICAL_ANALYSER_H_
#define LEXICAL_ANALYSER_H_

#include "token.h"

gidox_token *tokenization(const char **file_source, const char *filename);

#endif /* LEXICAL_ANALYSER_H_ */