#include <stdio.h>
#include "usecase/command.h"

int main() {
    Profiles *profiles = profiles_create();
    command_register(profiles, "5107520,Achfary Primary School,1987-4-10,By Lairg,01971 500260 Primary 9 1.5 Open");
    return 0;
}
