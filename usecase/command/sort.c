#include <stdio.h>
#include "sort.h"

Result command_sort(Profiles *target, int column) {
    char message[100];
    if (column < 0 || 5 < column) {
        sprintf(message, "%%S command failed incorrect column %d.\n", column);
        return result_error(message);
    }
    profiles_sort(target, int_to_column(column));
    return result_continue("");
}
