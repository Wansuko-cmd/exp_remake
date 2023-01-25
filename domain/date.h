#ifndef EXP2_DATE_H
#define EXP2_DATE_H

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* date_create(int year, int month, int day);
char* date_to_string(Date* target);
Date* string_to_date(char *target);
int date_compare_to_date(Date* d1, Date* d2);

#endif //EXP2_DATE_H
