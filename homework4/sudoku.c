//
// Created by 14832 on 2022/10/25.
//

#include "stdio.h"

#define SIZE  9

int main(){
    int s[SIZE][SIZE]={0};
    int count[10]={0,1,2,3,4,5,6,7,8,9};
    int count_c[20]={0};
    int judge = 1;

    for(int i = 0;i<SIZE;i++){
        for(int j = 0;j<SIZE;j++){
            scanf("%d", &s[i][j]);
        }
        getchar();
    }

    for(int row = 0;row<SIZE;row++){
        for(int i = 0;i<20;i++){
            count_c[i]=0;
        }
        for(int col = 0;col<SIZE;col++){
            if(s[row][col]==count[s[row][col]]){
                count_c[s[row][col]] = 1;
            }
        }

        for(int i =1;i<10;i++){
            if(count_c[i] !=1){
                judge = 0;
                break;
            }
        }

    }

    for(int col = 0;col<SIZE;col++){
        for(int i = 0;i<20;i++){
            count_c[i]=0;
        }
        for(int row = 0;row<SIZE;row++){
            if(s[row][col]==count[s[row][col]]){
                count_c[s[row][col]] = 1;
            }
        }

        for(int i =1;i<10;i++){
            if(count_c[i] !=1){
                judge = 0;
                break;
            }
        }

    }
    //s[i][j]
    for(int i = 0;i<=6;i+=3){
        for(int j = 0;j<=6;j+=3){

            for(int i = 0;i<20;i++){
                count_c[i]=0;
            }

            for(int n = 0;n<=2;n++){
                for(int p = 0;p<=2;p++){
                    if(s[i+n][j+p]== count[s[i+n][j+p]]){
                        count_c[s[i+n][j+p]] = 1;
                    }
                }
            }

            for(int l =1;l<10;l++){
                if(count_c[l] !=1){
                    judge = 0;
                    break;
                }
            }
        }
    }


    if(judge == 1){
        printf("YES");
    }else{
        printf("NO");
    }

}


