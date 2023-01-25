#include <string.h>
#include <stdlib.h>

int split(char* target, char* ret[], char separator, int max){
    int i;
    int count = 0;
    int length = (int)strlen(target);

    ret[count++] = target;

    for(i = 0; i < length; i++){
        if(count >= max) break;

        if(target[i] == separator){
            target[i] = '\0';
            ret[count++] = &target[i + 1];
        }
    }
    return count;
}

int replace(char* target, char old, char new){

    int i;
    int count = 0;
    int length = (int)strlen(target);

    for(i = 0; i < length; i++){
        if(target[i] == old) {
            target[i] = new;
            count++;
        }
    }

    return count;
}

int is_num(char* value){
    if(strcmp(value, "0") != 0 && atoi(value) == 0) return 0;
    return 1;
}
