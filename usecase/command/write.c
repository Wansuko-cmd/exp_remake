#include <stdio.h>
#include <stdlib.h>
#include "write.h"

Result command_write(Profiles *target, char *filename) {
    FILE* fp = fopen(filename, "w");
    char *message;
    int i;

    /*指定したファイルが存在しなかった場合*/
    if(fp == NULL){
        message = malloc(100);
        sprintf(message, "%%W command failed to open %s.\n", filename);
        return result_error(message);
    }

    for(i = 0; i < target->size; i++){
        fprintf(fp, "%s", profile_to_string(target->data[i]));
    }
    fclose(fp);
    return result_continue("");
}
