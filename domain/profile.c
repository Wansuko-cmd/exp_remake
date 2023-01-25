#include <string.h>
#include <stdlib.h>
#include "profile.h"

Profile* profile_create(int id, char* name, Date* birthday, char* address, char* comment) {
    Profile *result = malloc(sizeof(Profile));
    result->id = id;

    /*名前*/
    strncpy(result->name, name, MAX_STR_LENGTH);
    result->name[MAX_STR_LENGTH] = '\0';

    result->birthday = birthday;

    /* 住所 */
    strncpy(result->address, address, MAX_STR_LENGTH);
    result->address[MAX_STR_LENGTH] = '\0';

    result->comment = comment;
    return result;
}

int profile_compare_to_profile(Profile *p1, Profile *p2, int column) {
    switch (column) {
        case 1:
            return p1->id - p2->id;
        case 2:
            return strcmp(p1->name, p2->name);
        case 3:
            return date_compare_to_date(p1->birthday, p2->birthday);
        case 4:
            return strcmp(p1->address, p2->address);
        case 5:
            return strcmp(p1->comment, p2->comment);
        default:
            return 0;
    }
}
