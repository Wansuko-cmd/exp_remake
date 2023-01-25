#include <stdio.h>
#include "delete.h"

Result command_delete(Profiles *target, int id) {
    char message[100];
    sprintf(message, "Delete %d profile(s)\\n", profiles_delete_profile(target, id));
    return result_continue(message);
}
