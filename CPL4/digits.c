//
// Created by 14832 on 2022/10/14.
//

#include "stdio.h"

int main(){
    int number = 0;
    scanf("%d",&number);
    int digits = 0;



//    while(number>0){
//        number /=10;
//        digits++;
//    }

    do{
        number /=10;
        digits++;
    }while(number>0);

    printf("%d",digits);
}
