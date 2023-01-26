#include <stdio.h>
#include "usecase/parser.h"

int main() {
    Profiles *profiles = profiles_create();
    printf("%s", parse_line(profiles, "%P 10").message);
    return 0;
}
