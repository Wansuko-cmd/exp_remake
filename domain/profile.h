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

Profile* profile_create(int id, char* name, Date* birthday, char* address, char* comment);

#endif //EXP2_PROFILE_H
