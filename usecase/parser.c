#include "parser.h"
#include "command/register.h"

Result parse_line(Profiles *profiles, char* line) {
    if (*line != '%') return command_register(profiles, line);
    char command = line[1];
    char *param = &line[2];
    switch (command) {
        default:
            return result_error("Invalid command %c: ignored.\n");
    }
}