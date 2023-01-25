#ifndef EXP2_PROFILES_H
#define EXP2_PROFILES_H
#include "profile.h"

#define MAX_PROFILE_STORE_NUM 10000

typedef struct {
    Profile *data[MAX_PROFILE_STORE_NUM];
    int size;
} Profiles;

Profiles* profiles_create();
void profiles_append(Profiles *target, Profile *value);
void profiles_sort(Profiles *target, Column column);

#endif //EXP2_PROFILES_H
