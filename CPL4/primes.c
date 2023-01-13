//
// Created by 14832 on 2022/10/14.
//

#include "stdio.h"
#include "math.h"
#include "stdbool.h"

int main(){
    int max;
    int count = 0;
    scanf("%d",&max);

    for(int number = 2;number<=max;number++){
        bool is_prime = true;

        for(int i = 2;i*i<=number;i++){
            if(number%i==0){
                is_prime = false;
                break;
            }
        }
        //判断prime不是0 判断是不是为真：也就是不是0
        if(is_prime){
            printf("%d ",number);
            count++;
        }
    }
    printf("\n%d",count);
}
