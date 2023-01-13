//
// Created by 14832 on 2022/11/23.
//


#include "stdio.h"

#define SIZE  10000

void push(char s[],int *top,char m);

void pop(char s[],int *top);
void top1(const char s[],const int *top);
void print(const char s[],const int *top);

int main(){
    int n=0;
    int top = 0;
    scanf("%d",&n);
    getchar();

    char s[SIZE]={0};
    char order[SIZE][15]={0};
    for(int i = 1;i<=n;i++) {
        gets(order[i]);
    }
    for(int i = 1;i<=n;i++){
        if(order[i][0]=='p' && order[i][1] == 'u' && order[i][2] == 's' && order[i][3] == 'h'){
            push(s,&top,order[i][5]);
        }else if(order[i][0]=='p' && order[i][1] == 'o' && order[i][2] == 'p'){
            pop(s,&top);
        }else if(order[i][0]=='t' && order[i][1] == 'o' && order[i][2] == 'p'){
            top1(s,&top);
        }else if(order[i][0]=='p' && order[i][1] == 'r' && order[i][2] == 'i' && order[i][3] == 'n' && order[i][4] == 't'){
            print(s,&top);
        }
    }


}

void push(char s[],int *top,char m){
    *top = *top +1;
    s[*top]=m;
    return;
}

void pop(char s[],int *top){
    if(*top <= 0){
        return;
    }else{
        s[*top]=0;
        *top = *top -1;
        return;
    }

}

void top1(const char s[],const int *top){
    if(*top <= 0){
        printf("Empty\n");
        return;
    }else{
        printf("%c\n",s[*top]);
        return;
    }
}


void print(const char s[],const int *top){
    if(*top <= 0){
        printf("Empty\n");
        return;
    }else{
        for(int i = *top;i>=0;i--){
            if(s[i]!=0){
                printf("| %c |\n",s[i]);
            }
        }
        printf("|===|\n");
    }
}



