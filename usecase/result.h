#ifndef EXP2_RESULT_H
#define EXP2_RESULT_H

typedef enum {
    Continue,
    Exit,
    Error,
} Code;

typedef struct result {
    Code code;
    char* message;
    struct result(*next)(void);
} Result;

Result result_continue(char* message);
Result result_continue_with_next(char* message, Result (*next)(void));
Result result_exit(char* message);
Result result_error(char* message);

#endif //EXP2_RESULT_H
