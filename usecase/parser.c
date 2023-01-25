#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "command/register.h"
#include "command/print.h"
#include "command/find.h"
#include "../utils/char_utils.h"
#include "command/sort.h"

Result parse_line(Profiles *profiles, char* line) {
    /* エラー用メッセージ */
    char message[100];

    if (*line != '%') return command_register(profiles, line);
    char command = line[1];
    char *param = &line[3];
    switch (command) {
        case 'P':
            if (!is_num(param)) return result_error("%%P command please use num as n.\n");
            return command_print(profiles, atoi(param));
        case 'S':
            if (!is_num(param)) return result_error("%%S command please use num as n.\n");
            command_sort(profiles, atoi(param));
        case 'F':
            return command_find(profiles, param);
        case 'Q':
            return result_exit("");
        default:
            sprintf(message, "Invalid command %c: ignored.\n", command);
            return result_error(message);
    }
}