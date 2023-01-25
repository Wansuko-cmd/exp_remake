#include <string.h>
#include <stdio.h>
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