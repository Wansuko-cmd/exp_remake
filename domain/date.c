#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "date.h"

char* date_to_string(Date* target) {
    char *result = malloc(11);
    sprintf(result, "%d-%d-%d", target->year, target->month, target->day);
    return result;
}
int date_compare_to_date(Date* d1, Date* d2) {
    if(d1->year != d2->year) return d1->year - d2->year;
    if(d1->month != d2->month) return d1->month - d2->month;
    return d1->day - d2->day;
}
