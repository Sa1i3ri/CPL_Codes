//
// Created by 14832 on 2022/10/20.
//

int n,k;

#include "stdio.h"

int main(){
    int s[100]={0};

    scanf("%d %d",&n,&k);
    getchar();
    for(int i = 0;i<n;i++){
        scanf("%d",&s[i]);
    }

    int l = 0,r=n-1,pivot=s[k-1],mid,o=k-1;

    while (l!=r){
        while(1){
            if(l==r || s[l]>=pivot){
                break;
            }
            l++;
        }

        while (1){
            if(l==r || s[r]<pivot){
                break;
            }
            r--;
        }

        if(l!=r){
            if(l==k-1){
                o=r;
            }else if(r==k-1){
                o=l;
            }
            mid = s[l];
            s[l]=s[r];
            s[r]=mid;
        }
    }

    if(s[l]!= pivot){
        mid = s[l];
        s[l]=s[o];
        s[o]=mid;
    }


    for(int i = 0;i<n;i++){
        printf("%d ",s[i]);
    }

}