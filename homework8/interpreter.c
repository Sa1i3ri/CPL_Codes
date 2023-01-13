//
// Created by 14832 on 2022/11/21.
//

#include "stdio.h"

int main(){
    int number = 0;
    int  *ptr = &number;
    scanf("%x", &number);

    printf("%d\n",*ptr);
    printf("%u\n",*ptr);

    float *s=  &number;

    printf("%.6f\n",*s);
    printf("%.3e\n",*s);
}
