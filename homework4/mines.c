//
// Created by 14832 on 2022/10/25.
//

#include "stdio.h"
#define SIZE 105

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    int vectors[8][2] ={{-1,1},
                        {0,1},
                        {1,1},
                        {1,0},
                        {1,-1},
                        {0,-1},
                        {-1,-1},
                        {-1,0}};
    char s[SIZE][SIZE] = {0};

    for (int i = 1; i < n + 1; i++) {
        for(int j = 1;j<n+1;j++){
            scanf("%c",&s[i][j]);
        }
        getchar();
    }

    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<n+1;j++){
            if(s[i][j]==111){
                char count = 48;
                for(int k=0;k<8;k++){
                    int new_i = i + vectors[k][0];
                    int new_j = j + vectors[k][1];
                    if(s[new_i][new_j]==42){
                        count ++;
                    }
                }
                s[i][j]= count ;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for(int j = 1;j<n+1;j++){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }

}
