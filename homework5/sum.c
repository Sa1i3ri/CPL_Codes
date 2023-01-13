//
// Created by 14832 on 2022/11/1.
//

#include "stdio.h"
#include "math.h"

int sum(int n,int t){
    int sum = 0;
    int sum_past = 0;
    for(int i = 0;i<n;i++){
        sum_past += pow(10,i) * t;
        sum += sum_past;
    }
    return sum;

}

int main(){
    int n,t,ans;
    scanf("%d %d",&n,&t);
    ans = sum(n,t);
    printf("%d",ans);
}
