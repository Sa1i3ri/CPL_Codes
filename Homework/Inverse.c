//
// Created by 14832 on 2022/10/1.
//

#include <stdio.h>

int main(){
    int numbers;
    scanf("%d",&numbers);
    int a = numbers / 10000;
    int b = (numbers / 1000)%10;
    int c = (numbers / 100)%10;
    int d = (numbers / 10)%10;
    int e = (numbers / 1)%10;
    printf("%d%d%d%d%d",
           c,b,a,e,d);
}
