#include <stdlib.h>
#include "result.h"

Result result_continue(char* message) {
    return (Result){ Continue, message };
}

Result result_exit(char* message) {
    return (Result){ Exit, message };
}

Result result_error(char* message) {
    return (Result){ Error, message };
}
