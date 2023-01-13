//
// Created by 14832 on 2022/10/17.
//

#include "stdio.h"

int main(){
    int n;
    int max =-1 ;
    int count_space=0;
    char s[1000]={0};
    int count[200]={0};
    scanf("%d",&n);
    getchar();
    //count下标是字母 数字是出现几次
    for(int i = 0;i<n;i++){
        scanf("%c",&s[i]);
        count[s[i]]++;
    }
    //找最多次是多少
    for(int i = 0;i<200;i++){
        if(count[i] >= max){
            max = count[i];
        }
    }
    for(int j = max ; j >0 ; j--){
        for(int i = 97;i<=122;i++){
            if(count[i]!=0) {
                if (count[i] >= j && count[i - 32] != 0) {
                    printf("=");
                    count_space++;
                } else if (count[i] >= j && count[i - 32] == 0) {
                    printf("= ");
                    count_space+=2;
                } else if (count[i] < j && count[i - 32] == 0) {
                    printf("  ");
                    count_space+=2;
                }else if (count[i] < j && count[i - 32] != 0) {
                    printf(" ");
                    count_space+=1;
                }
            }

            if(count[i-32]!=0) {
                if (count[i - 32] >= j) {
                    printf("= ");
                    count_space+=2;
                } else if (count[i - 32] < j) {
                    printf("  ");
                    count_space+=2;
                }
            }
                if (i == 122) {
                    printf("\n");
                }
        }
        if(j == 1){
            count_space=count_space/max;
            for(int p = count_space-1;p>0;p--){
                printf("-");
                if(p==1){
                    printf("\n");
                }
            }
        }
    }

    for(int i = 97;i<=122;i++){
        if(count[i]!=0 && count[i-32]!=0){
            printf("%c",i);
        }else if(count[i]!=0 && count[i-32]==0){
            printf("%c ",i);
        }

        if(count[i-32]!=0){
            printf("%c ",i-32);
        }

    }
}


