#ifndef EXP2_PROFILE_H
#define EXP2_PROFILE_H

#include "date.h"

#define MAX_STR_LENGTH 70

typedef struct {
    int id;
    char name[MAX_STR_LENGTH + 1];
    Date *birthday;
    char address[MAX_STR_LENGTH + 1];
    char* comment;
} Profile;

typedef enum {
    ID,
    NAME,
    BIRTHDAY,
    ADDRESS,
    COMMENT
} Column;

Profile* profile_create(int id, char* name, Date* birthday, char* address, char* comment);
int profile_compare_to_profile(Profile *p1, Profile *p2, Column column);

#endif //EXP2_PROFILE_H
