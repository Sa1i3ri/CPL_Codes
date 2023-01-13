//
// Created by 14832 on 2022/10/7.
//

#include "stdio.h"

int main(){
    int a = 0;
    int b = 0;
    scanf("%d%d",a,b);
    int min = 0;
    if(a>=b){
        min = b;
    }else{
        min = a;
    }
    printf("%d",min);

}
