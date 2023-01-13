//
// Created by 14832 on 2022/11/15.
//

#include "stdio.h"
#define SIZE 105

void quick_sort(int s[],int p[],int left,int right);

int main(){
    int n,L;
    int sum = 0;
    scanf("%d %d",&n,&L);

    int v[SIZE]={0};
    int l[SIZE]={0};

    for(int i = 0;i<n;i++){
        scanf("%d ",&v[i]);
    }
    for(int i = 0;i<n;i++){
        scanf("%d ",&l[i]);
    }

    quick_sort(v,l,0,n-1);

    for(int i =n-1;i>=0;i--){
        while (l[i]!=0 && L!=0){
            sum += v[i];
            l[i]--;
            L--;
        }
        if(L==0){
            break;
        }

    }
    printf("%d",sum);

}


void quick_sort(int s[],int p[],int left,int right){
    int temp1;
    int temp2;
    int mid = s[(left+right)/2];
    int i =left;
    int j =right;

    while (i<=j){
        while (s[i]<mid){
            i++;
        }
        while ((s[j])>mid){
            j--;
        }

        if(i<=j){
            temp1 = s[i];
            s[i] = s[j];
            s[j] = temp1;
            temp2 = p[i];
            p[i] = p[j];
            p[j] = temp2;
            i++;
            j--;

        }

    }

    if(i<right){
        quick_sort(s,p,i,right);
    }

    if(j>left){
        quick_sort(s,p,left,j);
    }

}
