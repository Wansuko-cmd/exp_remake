#include <stdlib.h>
#include <string.h>
#include "find.h"

static Profiles *profiles;
static int find_index;
static char *g_word;

Result command_find_next();

Result command_find(Profiles *target, char *word) {
    profiles = target;
    g_word = malloc(strlen(word));
    strcpy(g_word, word);

    return command_find_next();
}

Result command_find_next() {
    while (find_index < profiles->size) {
        Profile* target = profiles->data[find_index++];
        /*一致するプロフィールであれば*/
        if(profile_is_match_by_word(target, g_word)){
            return result_continue_with_next(
                    profile_to_print_format(target),
                    command_find_next
                    );
        }
    }
    profiles = NULL;
    free(g_word);
    return result_continue("");
}
