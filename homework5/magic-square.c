//
// Created by 14832 on 2022/11/1.
//

#include "stdio.h"

#define SIZE 50

int main(){
    int n;
    scanf("%d",&n);
    int s[SIZE][SIZE]={0};
    int row = 1;
    int col = n/2+1;
    int new_row = row;
    int new_col = col;

    s[row][col]=1;

    for(int i = 2;i<=n*n;i++){
            if(col + 1 <=n && row - 1 <1){
                new_col++;
                new_row = n;
            }else if(col+1 >n && row-1 >=1){
                new_col = 1;
                new_row--;
            }else if(col + 1 >n && row -1 <1){
                new_col = 1;
                new_row = n;
            }else{
                new_col++;
                new_row--;
            }

            if(s[new_row][new_col]!=0){
                new_row = row+1;
                new_col = col;
            }
            row = new_row;
            col = new_col;
            s[row][col] = i;

    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }


}