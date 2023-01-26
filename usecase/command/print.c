#include <printf.h>
#include "print.h"

static Profiles *profiles;
static int print_index, print_end;

Result command_print_next();

Result command_print(Profiles *target, int amount) {
    profiles = target;
    print_index = 0;
    print_end = target->size;

    /*指定された値が負の数の場合*/
    if(amount < 0){

        /*指定された値より保存数の方が多ければ引いた値を、そうでない時は全部表示のため0を渡す*/
        print_index = target->size > -amount ? target->size - (-amount) : 0;
    }
    /*指定された値が正の数の場合*/
    else if(amount > 0){
        /*指定された値より保存数の方が多ければ指定された値を、そうでない時は全部表示のため保存数を渡す*/
        print_end = target->size > amount ? amount : target->size;
    }

    return command_print_next();
}

Result command_print_next() {
    if (print_index >= print_end) {
        profiles = NULL;
        return result_continue("");
    }
    return result_continue_with_next(
            profile_to_print_format(profiles->data[print_index++]),
            command_print_next
            );
}
