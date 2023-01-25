#include <string.h>
#include <stdlib.h>
#include "command.h"
#include "../utils/char_utils.h"

Result* command_register(Profiles *target, char *csv){
    char* tmp[6];
    Date *date;
    Profile *profile;

    /*　5個に分割することができなければ処理を終了　*/
    if (split(csv, tmp, ',', 6) != 5){
        return result_error("Invalid value. 5 comma required.\n");
    }
    /* idが数字かどうか */
    if(!is_num(tmp[0])) {
        return result_error("Invalid ID. Please use number as ID.\n");
    }
    /* 名前の文字数 */
    if(strlen(tmp[1]) > MAX_STR_LENGTH){
        return result_error("Invalid NAME. Too long value.\n");
    }
    /* アドレスの文字数 */
    if(strlen(tmp[3]) > MAX_STR_LENGTH){
        return result_error("Invalid ADDRESS. Too long value.\n");
    }

    date = string_to_date(tmp[2]);
    if (date == NULL) {
        return result_error("Invalid date");
    }

    profile = profile_create(atoi(tmp[0]), tmp[1], date, tmp[3], tmp[4]);
    if (profile == NULL) {
        return result_error("Invalid Profile");
    }

    profiles_append(target, profile);
    return result_continue("");
}
