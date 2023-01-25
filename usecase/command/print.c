#include <stdio.h>
#include <stdlib.h>
#include "print.h"

char* profile_to_print_format(Profile* target);

Result command_print(Profiles *target, int amount) {
    int i, start = 0;
    int end = target->size;

    /*指定された値が負の数の場合*/
    if(amount < 0){

        /*指定された値より保存数の方が多ければ引いた値を、そうでない時は全部表示のため0を渡す*/
        start = target->size > -amount ? target->size - (-amount) : 0;
    }
        /*指定された値が正の数の場合*/
    else if(amount > 0){
        /*指定された値より保存数の方が多ければ指定された値を、そうでない時は全部表示のため保存数を渡す*/
        end = target->size > amount ? amount : target->size;
    }

    for(i = start; i < end; i++){

    }
    return result_continue(profile_to_print_format(target->data[0]));
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
