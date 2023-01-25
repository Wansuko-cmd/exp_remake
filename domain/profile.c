#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

int profile_compare_to_profile(Profile *p1, Profile *p2, Column column) {
    switch (column) {
        case ID:
            return p1->id - p2->id;
        case NAME:
            return strcmp(p1->name, p2->name);
        case BIRTHDAY:
            return date_compare_to_date(p1->birthday, p2->birthday);
        case ADDRESS:
            return strcmp(p1->address, p2->address);
        case COMMENT:
            return strcmp(p1->comment, p2->comment);
        default:
            return 0;
    }
}

int profile_is_match_by_word(Profile *profile, char word[]) {

    char id[MAX_STR_LENGTH];
    sprintf(id, "%d", profile->id);

    if(!strcmp(id, word)) return 1;
    if(!strcmp(profile->name, word)) return 1;
    if(!strcmp(date_to_string(profile->birthday), word)) return 1;
    if(!strcmp(profile->address, word)) return 1;
    if(!strcmp(profile->comment, word)) return 1;

    return 0;
}

char* profile_to_print_format(Profile* target) {
    char *buf = malloc(1024);
    sprintf(
            buf,
            "Id    : %d\n"
            "Name  : %s\n"
            "Birth : %s\n"
            "Addr. : %s\n"
            "Comm. : %s\n",
            target->id, target->name, date_to_string(target->birthday), target->address, target->comment
    );
    return buf;
}

Column int_to_column(int value) {
    switch (value) {
        case 1:
            return ID;
        case 2:
            return NAME;
        case 3:
            return BIRTHDAY;
        case 4:
            return ADDRESS;
        case 5:
            return COMMENT;
        default:
            return -1;
    }
}