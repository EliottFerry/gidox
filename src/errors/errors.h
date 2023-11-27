#ifndef ERRORS_H_
#define ERRORS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int error_pre_tokenization(const char **argv);

#endif /* ERRORS_H_*/