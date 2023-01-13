//
// Created by 14832 on 2022/11/6.
//

#include "stdio.h"

int count(int num);

int main(){
    int n,ans;
    scanf("%d",&n);
    ans = count(n);
    printf("%d",ans);
}

int count(int num){
    if(num == 1 || num == 2 || num == 3){
        return num;
    }

    return count(num-1) + count(num-2);

}
