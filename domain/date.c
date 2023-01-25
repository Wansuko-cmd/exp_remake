#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utils/char_utils.h"
#include "date.h"

Date* date_create(int year, int month, int day) {
    Date* result = malloc(sizeof(Date));
    result->year = year;
    result->month = month;
    result->day = day;
    return result;
}

char* date_to_string(Date* target) {
    char *result = malloc(11);
    sprintf(result, "%d-%d-%d", target->year, target->month, target->day);
    return result;
}

Date* string_to_date(char *target) {
    char* tmp[4];

    if(split(target, tmp, '-', 4) != 3){
        fprintf(stderr, "Invalid BIRTH. 3 hyphen required.\n");
        return NULL;
    }

    if(
            !is_num(tmp[0]) ||
            !is_num(tmp[1]) ||
            !is_num(tmp[2])
            ){
        fprintf(stderr, "Invalid BIRTH. Please use number as BIRTH\n");
        return NULL;
    }

    return date_create(atoi(tmp[0]), atoi(tmp[1]), atoi(tmp[2]));
}

int date_compare_to_date(Date* d1, Date* d2) {
    if(d1->year != d2->year) return d1->year - d2->year;
    if(d1->month != d2->month) return d1->month - d2->month;
    return d1->day - d2->day;
}
