//
// Created by 14832 on 2022/11/21.
//

#include "stdio.h"
#define SIZE 100

void change(char s[][SIZE],int a,int b,int c);

void paint(char s[][SIZE],int a,int b,int c);


int main(){
    int n,a,b,c;
    char s[SIZE][SIZE] = {0};
    int t[SIZE][3] = {0};
    scanf("%d",&n);
    getchar();

    for(int i = 1;i<=n;i++){
        scanf("%d %d %d",&t[i][0],&t[i][1],&t[i][2]);
        getchar();
    }

    for(int i = 1;i<=n;i++){
        change(s,t[i][0],t[i][1],t[i][2]);
        paint(s,t[i][0],t[i][1],t[i][2]);
    }


}

void change(char s[][SIZE],int a,int b,int c){

    if(a==0 && b==0 && c==0){
        return;
    }


    for(int i = 1;i<=2*b+1;i++){

        for(int j = 2*b-i+2; j<=2*a+1+2*b-i+1;j++){
            if(i % 2 ==1){
                if((j-(2*b-i+1))%2==1){
                    s[i][j] = '+';
                }else{
                    s[i][j] = '-';
                }
            }else{
                if((j-(2*b-i+1))%2==1){
                    s[i][j] = '/';
                }else{
                    s[i][j] = ' ';
                }
            }

            for(int t = 1; t<= 2*b-i+1;t++){
                s[i][t] = ' ';
            }

        }


    }

    for(int i =2*b+2;i<=2*b+1+2*c;i++){
        for(int j = 1 ; j<=2*a+1;j++){

            if((i-(2*b+1))%2==1){
                if(j%2==1){
                    s[i][j] = '|';
                }else{
                    s[i][j] = ' ';
                }
            }else{
                if(j%2==1){
                    s[i][j] = '+';
                }else{
                    s[i][j] = '-';
                }
            }

        }
    }

    for(int j = 2*a+2;j<=2*a+1+2*b;j++){
        for(int i = 2*c+1+2*b;i>=1-j+(2*a+1+2*b);i--){

            if((j-(2*a-1))%2==1){
                if((2*c+1+2*b-i)%2==1){
                    s[i][j]='/';
                }else{
                    s[i][j]=' ';
                }
            }else{
                if((2*c+1+2*b-i)%2==1){
                    s[i][j]='|';
                }else{
                    s[i][j]='+';
                }
            }


        }


        for(int p =2*c+1+2*b;p>2*c+1+2*b-(j-(2*a+1));p--){
            s[p][j]=' ';
        }


    }



}

void paint(char s[][SIZE],int a,int b,int c){
    for(int i = 1;i<=2*b+1+2*c;i++){

        for(int j = 1;j<=2*a+1+2*b;j++){
            printf("%c",s[i][j]);
        }
        printf("\n");
    }


}





