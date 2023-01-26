#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include "../../utils/char_utils.h"
#include "register.h"

#define MAX_LINE_LENGTH 1024

int get_line(FILE* fp, char* line);

Result command_read(Profiles *target, char *filename) {
    FILE* fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    char *message;

    /*指定したファイルが存在しなかった場合*/
    if(fp == NULL){
        message = malloc(100);
        sprintf(message, "%%R command failed to open %s.\n", filename);
        return result_error(message);
    }

    while(get_line(fp, line)){
        command_register(target, line);
    }

    fclose(fp);
    return result_continue("");
}

int get_line(FILE* fp, char* line){

    /*受け取った文字列がNULLであれば0を返す*/
    if(fgets(line, MAX_LINE_LENGTH + 1, fp) == NULL) return 0;

    /*改行文字をヌル文字に置き換える*/
    replace(line, '\n', '\0');

    return 1;
}
