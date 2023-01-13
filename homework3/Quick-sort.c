//
// Created by 14832 on 2022/10/19.
//

#include "stdio.h"

int main(){
    int n=0,k=0;
    int mid=0;
    int s[100]={0};
    scanf("%d %d",&n,&k);
    getchar();
    int l = 0;
    int r = n-1;
    for(int i = 0;i<n;i++){
        scanf("%d",&s[i]);
    }
    int pivot = s[k-1];

    while(l<r){
        while(s[l]<=pivot){
            l++;
            if(l>=r){
                break;
            }
        }

        while (s[r]>pivot){
            r--;
            if(l>=r){
                break;
            }
        }

        if(s[l]==pivot && l!=k-1){
            l++;
        }else if(s[r]==pivot && r!=k-1){
            r--;
        }else if(l<r){
            mid = s[l];
            s[l]=s[r];
            s[r]=mid;
        }

    }

    if(s[l]> pivot){
        mid = s[l];
        s[l]=s[k-1];
        s[k-1]=mid;
    }else if(s[r]< pivot){
        mid = s[r];
        s[r]=s[k-1];
        s[k-1]=mid;
    }


    for(int i = 0;i<n;i++){
        printf("%d ",s[i]);
    }

}
