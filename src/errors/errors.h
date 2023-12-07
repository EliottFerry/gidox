#ifndef ERRORS_H_
#define ERRORS_H_

#define ERROR_STR_ALLOC "Error while allocation memory for: "
#define ERROR_STR_STAT "Error while getting stat of: "
#define ERROR_STR_MEMCPY "Error while copying memory in: "
#define ERROR_STR_OPEN "Error while opening file: "
#define ERROR_STR_READ "Error while reading file: "
typedef enum {
    TYPES,
} GidoxErrorType;

typedef struct gidox_error_s {
    GidoxErrorType type;
    int line;
    char *filename;
} gidox_error;

typedef struct gidox_error_list_s {
    gidox_error error;
    struct gidox_error_list_s *next;
} gidox_error_list;

extern gidox_error_list *error_list;

int error_pre_tokenization(const char **argv);
void print_error(const char *error_msg, const char *where);

#endif /* ERRORS_H_*/