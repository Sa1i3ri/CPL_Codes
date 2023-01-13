//
// Created by 14832 on 2022/11/1.
//

#include "stdio.h"
#include "stdbool.h"
#include "math.h"

bool is_prime(int x){
    int flag = 1; // 1 表示该数是素数
    for (int i = 2; i <= sqrt(x + 0.5); i++) {
        if (x % i == 0) {
            flag = 0;
        }
    }

    if(x == 1){
        flag = 0;
    }
    return flag;
}

int reverse(int x){
    int count = 0;
    int sum = 0;
    int num[5]={0};
    for(int i = 4;i>=1;i--){
        int s = 0;
        s =  x / pow(10,i-1) ;
        num[i] = s % 10;
    }

    while(x!=0){
        x /=10;
        count++;
    }

    for (int i = 0; i <= 4; i++) {
        sum += num[i] * pow(10, count - i);
    }
    return sum;

}

int main(){
    int count = 0;
    int n = 0;
    scanf("%d",&n);


    for(int i = 1;i<=n;i++){
            if(is_prime(i) && is_prime(reverse(i))){
                count ++;
            }

    }
    printf("%d",count);
}
