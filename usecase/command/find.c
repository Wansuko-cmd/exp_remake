#include <stdio.h>
#include "find.h"

Result command_find(Profiles *target, char *word) {
    int i;

    for(i = 0; i < target->size; i++){
        /*一致するプロフィールであれば*/
        if(profile_is_match_by_word(target->data[i], word)){
            printf("%s", profile_to_print_format(target->data[i]));
        }
    }

    return result_continue("");
}
