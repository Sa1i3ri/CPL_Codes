//
// Created by 14832 on 2022/12/3.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SIZE 1000

//void combine(char *s1,char *s2);
int find_index(char *s1,char *s2);


int main(){



    int n = 0;
    scanf("%d",&n);


    for (int i = 0; i < n; ++i) {
        char *s1 = malloc(SIZE * sizeof *s1);
        char *s2 = malloc(SIZE * sizeof *s2);
     //   getchar();
        scanf("%s",s1);
        scanf("%s",s2);
        int index = find_index(s1,s2);
        for(int j = 0;j< strlen(s1);j++){
            printf("%c",*(s1+j));
        }

        for(int j = index;j< strlen(s2);j++){
            printf("%c",*(s2+j));
        }

        printf("\n");
        free(s1);
        free(s2);
    }



}

//void combine(char *s1,char *s2){
//    int count_s1 = strlen(s1);
//    int count_s2 = strlen(s2);
//    int index = find_index(s1,s2);
//
//    for(int i =index;i<count_s2;i++){
//
//        *(s1 + count_s1 + i - index) = *(s2+i);
//    }
//
//
//}

int find_index(char *s1,char *s2){
    int count_s1 = strlen(s1);
    int count_s2 = strlen(s2);

    int index = 0;
    int index_i = 0;

    again:

    for(int i = index_i;i<count_s1;i++){
        if(*(s2+index) == *(s1+i)){
            index_i = i;
            break;
        }
    }

    for(int i =index_i;i<count_s1;i++){
        if(*(s1 + i) == *(s2 + index)){
            index++;
        }else{
            index = 0;
            index_i++;
            goto again;
        }
    }




    return index;


}
