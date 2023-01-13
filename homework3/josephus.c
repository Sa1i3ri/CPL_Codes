//
// Created by 14832 on 2022/10/18.
//

#include "stdio.h"

int main(){
    int n = 0;
    int k = 0;
    scanf("%d %d",&n,&k);
    int survival = n;
    int origin = k;
    int people[100]={0};//1活0死

    for(int i = 0;i<n;i++){
        people[i] = 1;
    }


    for(int i = 0;i<n;i++){
        if(people[i]==1){
            k--;
            if(k==0){
                people[i]=0;
                survival--;
                k=origin;

                if(survival==1){
                    for(int j = 0;j<n;j++){
                        if(people[j]==1){
                            printf("%d",j+1);
                        }
                    }
                    break;
                }

            }
        }

        if(i == n-1){
            i=-1;
        }

    }
    return 0;
}
