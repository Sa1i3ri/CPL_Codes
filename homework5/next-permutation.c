//
// Created by 14832 on 2022/11/1.
//

#include "stdio.h"

int find_last(const int s[],int len);

int find_back_small(const int s[], int len,int last_big_i);


int main(){
    int n;
    int s[2003]={0};
    int mid = 0;
    scanf("%d",&n);
    getchar();
    for(int i = 0;i<n;i++){
        scanf("%d",&s[i]);
    }

    int last_big = find_last(s,n);
    int back_small = find_back_small(s,n,last_big);

    mid = s[last_big];
    s[last_big] = s[back_small];
    s[back_small] = mid;

    for(int i = 0; i<=last_big;i++){
        printf("%d ",s[i]);
    }

    for(int i =n-1;i>last_big;i--){
        printf("%d ",s[i]);
    }

}

int find_last(const int s[],int len){
    int t = 0;
    for(int i = len-1;i>=1;i--){
        if(s[i-1]<s[i]){
            t = i-1;
            break;
        }
    }
    return t;
}

int find_back_small(const int s[], int len,int last_big_i) {
    int count[2003] = {0};
    for (int i = last_big_i + 1; i < len; i++) {
        if(s[i]>s[last_big_i]){
            count[i] = 1;
        }
    }
    int k=0;

    for(int i = 0;i<len;i++){
        if(count[i]==1){
            k=i;
            break;
        }
    }

    for (int i = 0; i < len; i++) {
        if (count[i] == 1 && s[i]<=s[k]){
            k = i;
        }
    }
    return k;

}
