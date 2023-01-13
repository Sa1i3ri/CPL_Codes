//
// Created by 14832 on 2022/11/6.
//


#include "stdio.h"

int s[1000]={0};

int find(int x);

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 1;i<=n;i++){
        scanf("%d",&s[i]);
    }

    for(int i = 1;i<=n;i++){
        s[i] = find(i);
        printf("%d ",s[i]);
    }
}

int find(int x){
    if(x == s[x]){
        return x;
    }else{
        return find(s[x]);
    }
}
