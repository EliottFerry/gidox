#ifndef ERRORS_H_
#define ERRORS_H_

typedef enum {
    TYPES,
} GidoxErrorType;

typedef struct gidox_error_s {
    GidoxErrorType type;
    int line;
    char *filename;
    struct gidox_error_s *next;

} gidox_error;

int error_pre_tokenization(const char **argv);

#endif /* ERRORS_H_*/