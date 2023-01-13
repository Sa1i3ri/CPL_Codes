//
// Created by 14832 on 2022/10/10.
//

#include "stdio.h"

int main(){
    int n;
    int a=1;
    int result = 0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        a=(a*i)%10007;
        result = result + a;
    }
    int p =result%10007;
    printf("%d",p);
}