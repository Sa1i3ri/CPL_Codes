//
// Created by 14832 on 2022/11/24.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SIZE 10000

int main(){
    char *s = malloc(SIZE * sizeof(char));
    gets(s);
    int count_s = strlen(s);
    for(int i = 0;i<count_s;i++){
        if(*s>=97 && *s <=122){
            *s = *s - 32;
            continue;
        }

        if( *(s+i-1) >48 && *(s+i)>=65 && *(s+i) <=90){
            *(s+i) = *(s+i) + 32;
        }else if(*(s+i-1) ==' ' && *(s+i)>=97 && *(s+i) <=122){
            *(s+i) = *(s+i) - 32;
}
    }
    for (int i = 0; i < count_s; ++i) {
        printf("%c",*(s+i));
    }

    free(s);



}
