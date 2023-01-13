//
// Created by 14832 on 2022/10/10.
//

#include "stdio.h"

int main(){
    int n,k;
    scanf("%d",&n);
    getchar();
    char sp[100] = "handsome";
    for(int i = 0;i<n;i++){
        scanf("%c",&sp[i]);
    }
    getchar();

    scanf("%d",&k);
    for(int i =k-1;i>=0;i--){
        printf("%c",sp[i]);
    }
    for(int i = n-1;i>=k;i--){
        printf("%c",sp[i]);
    }
}
