#include <stdio.h>
#include "usecase/parser.h"

void read_line(Profiles *profiles, char *line);

int main() {
    Profiles *profiles = profiles_create();
    printf("%s", parse_line(profiles, "%R /Users/ryookizuka/CLionProjects/exp2/sample.csv").message);
    read_line(profiles, "%F Applecross Primary School");
    return 0;
}

void read_line(Profiles *profiles, char *line) {
    Result result = parse_line(profiles, line);
    printf("%s", result.message);
    while (result.next != NULL) {
        result = result.next();
        printf("%s", result.message);
    }
}
