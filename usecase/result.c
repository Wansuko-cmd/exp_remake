#include <stdlib.h>
#include "result.h"

Result* result_continue(char* message) {
    Result *result = malloc(sizeof(Result));
    result->code = Continue;
    result->message = message;
    return result;
}

Result* result_exit(char* message) {
    Result *result = malloc(sizeof(Result));
    result->code = Exit;
    result->message = message;
    return result;
}

Result* result_error(char* message) {
    Result *result = malloc(sizeof(Result));
    result->code = Error;
    result->message = message;
    return result;
}
