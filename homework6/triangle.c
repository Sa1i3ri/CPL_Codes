//
// Created by 14832 on 2022/11/11.
//

#include "stdio.h"
#include "math.h"

char xy[2060][2060]={0};

void sp(char s[][2060],int n,int x,int y){
    if(n == 1){
        s[x][y] = '/';
        s[x+1][y] = '\\';
        s[x-1][y+1]= '/';
        s[x][y+1] = '_';
        s[x+1][y+1] = '_';
        s[x+2][y+1] = '\\';
        return;
    }else{
        sp(s,n-1,x,y);
        sp(s,n-1,x-pow(2,n-1),y+ pow(2,n-1));
        sp(s,n-1,x+pow(2,n-1),y+pow(2,n-1));
    }


}



int main(){
    int n=0;
    int x = 1024;
    int y = 0;
    scanf("%d",&n);


        for(int j = 0; j<pow(2,n);j++) {
            for (int i = 1024 - pow(2, n)+1; i <= 1025 + pow(2, n); i++) {
                xy[i][j] = ' ';
            }
        }




    sp(xy,n,x,y);


    for(int i = 0; i<2060;i++){
        for(int j = 0; j<2060;j++){
            if(xy[j][i] != 0){
                printf("%c",xy[j][i]);
                if(xy[j+1][i]==0){
                    printf("\n");
                }
            }
        }
    }



}
