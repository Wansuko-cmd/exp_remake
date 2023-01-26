#include "result.h"

Result result_continue(char* message) {
    return (Result){ Continue, message };
}

Result result_continue_with_next(char* message, Result (*next)(void)) {
    return (Result){ Continue, message, next };
}

Result result_exit(char* message) {
    return (Result){ Exit, message };
}

Result result_error(char* message) {
    return (Result){ Error, message };
}
