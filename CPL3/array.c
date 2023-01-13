//
// Created by 14832 on 2022/10/7.
//

#include "stdio.h"
#define NUM 5

int main(){
    //[]内必须是常量
    int numbers[NUM] = {0};

    for(int i = 0;i < NUM; i++){
        scanf("%d",&numbers[i]);
        printf("%d ",numbers[i]);
    }
    //i = 1 ; j = i  变量左边叫左值（为一个空间），把1赋值给i 右边叫右值，把空间里的值赋值给左边1

    int min = numbers[1];
    // for(1 2 3)  1：准备部分 2：判断逻辑表达式 3：收尾工作
    for(int i = 1; i < NUM; i++){
        if(numbers[i]<min){
            min = numbers[i];
        }
    }

    printf("min = %d",min);

}

