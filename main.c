#include <stdio.h>
#include "usecase/parser.h"

int main() {
    Profiles *profiles = profiles_create();
    char csv[1000] = "5107520,Achfary Primary School,1987-4-10,By Lairg,01971 500260 Primary 9 1.5 Open";
    printf("%s", parse_line(profiles, csv).message);
    printf("%s", parse_line(profiles, "%F Achfary Primary School").message);
    return 0;
}
