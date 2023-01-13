//
// Created by 14832 on 2022/10/28.
//

#include "stdio.h"
#define SIZE 105

int main(){
    int s1[SIZE][SIZE]={0};
    int s2[SIZE][SIZE]={0};
    int ans[SIZE][SIZE]={0};
    int m,n,p;
    scanf("%d %d %d",&m,&n,&p);
    getchar();

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            scanf("%d",&s1[i][j]);
        }
        getchar();
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=p;j++){
            scanf("%d",&s2[i][j]);
        }
        getchar();
    }


    for(int i = 1;i<= m;i++){
        for(int k = 1;k<=p;k++){
            int output = 0;
            for(int j = 1;j<=n;j++){
                output += s1[i][j] * s2[j][k];
            }
            printf("%d ",output);
        }
        printf("\n");
    }


}
