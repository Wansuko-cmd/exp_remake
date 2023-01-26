#include <stdio.h>
#include "usecase/parser.h"

int main() {
    Profiles *profiles = profiles_create();
    printf("%s", parse_line(profiles, "%R /Users/ryookizuka/CLionProjects/exp2/sample.csv").message);
    printf("%s", parse_line(profiles, "%P 10").message);
    printf("%s", parse_line(profiles, "%W /Users/ryookizuka/CLionProjects/exp2/hoge.csv").message);
    return 0;
}
