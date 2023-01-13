//
// Created by 14832 on 2022/11/21.
//

#include "stdio.h"

#define SIZE 100005

int len(const char *s);

int main(){
    char s[SIZE] = {0};
    char t[SIZE] = {0};
    gets(s);
    gets(t);

    int count_s = len(s);
    int count_t = len(t);

    for(int i = 0;i<count_s;i++){
        int judge = 1;
        for(int j = i;j<i+count_t;j++){
            int temp = j-i;
            if(*(t+temp)!=*(s+j)){
                judge = 0;
            }
        }

        if(judge){
            printf("%d ", i);
        }
    }

}

int len(const char *s){
    for(int i = 0;i<SIZE;i++){
        if(*(s+i)==0){
            return i;
        }
    }
}