#include <stdlib.h>
#include "parser.h"
#include "command/register.h"
#include "command/print.h"
#include "../utils/char_utils.h"

Result parse_line(Profiles *profiles, char* line) {
    if (*line != '%') return command_register(profiles, line);
    char command = line[1];
    char *param = &line[2];
    switch (command) {
        case 'P':
            if (!is_num(param)) return result_error("%%P command please use num as n.\n");
            return command_print(profiles, atoi(param));
        default:
            return result_error("Invalid command %c: ignored.\n");
    }
}