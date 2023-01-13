//
// Created by 14832 on 2022/10/15.
//

#include "stdio.h"

int main(){
    int num[2000]={0};
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        for(int j = 1;j<(n/i+1);j++){
            if(num[i*j]==1){
                num[i*j]=0;
            }else{
                num[i*j]=1;
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(num[i]==1){
            printf("%d ",i);
        }
    }

}
