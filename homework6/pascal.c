//
// Created by 14832 on 2022/11/6.
//

#include "stdio.h"

int c(int a,int b);

int main(){
    int a,b,n;
    scanf("%d %d",&a,&b);
    n=c(a,b);
    printf("%d",n);
}

int c(int a,int b ){
    if(a == 1 && b == 1){
        return 1;
    }

    if(b == 1 || b == a){
        return 1;
    }

    return c(a-1,b-1)+c(a-1,b);
}
