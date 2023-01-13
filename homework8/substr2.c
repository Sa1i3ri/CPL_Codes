//
// Created by 14832 on 2022/11/21.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIZE 100005

int len(const char *s){
    for(int i = 0;i<SIZE;i++){
        if(*(s+i)==0){
            return i;
        }
    }
}

int main(){
    char *s = malloc(SIZE * sizeof(char));
    char *t = malloc(SIZE * sizeof(char));
    int *store = malloc(SIZE * sizeof(char));
    gets(s);
    gets(t);


    int count_s = strlen(s);
    int count_t = strlen(t);
    for (int i = 0; i < count_s; ++i) {
        *(store+i) = -1;
    }


    for(int i = 0;i<count_s;i++){
        int judge = 1;
        for(int j = i;j<i+count_t;j++){
            int temp = j-i;
            if(*(t+temp)!=*(s+j)){
                judge = 0;
            }
        }

        if(judge){
            *(store+i) = i;
        }
    }

    for(int i =0;i<count_s;i++){
        if(*(store+i) != -1){
            printf("%d ",*(store+i));
        }
    }

    free(s);
    free(t);
    free(store);



}
