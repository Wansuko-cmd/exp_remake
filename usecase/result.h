#ifndef EXP2_RESULT_H
#define EXP2_RESULT_H

typedef enum {
    Continue,
    Exit,
    Error,
} Code;

typedef struct {
    Code code;
    char* message;
} Result;

Result result_continue(char* message);
Result result_exit(char* message);
Result result_error(char* message);

#endif //EXP2_RESULT_H
