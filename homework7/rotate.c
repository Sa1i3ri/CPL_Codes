//
// Created by 14832 on 2022/11/24.

#include "stdio.h"
#include "string.h"

#define SIZE 1005

void W(int ordinate[],int *a,int *b,int *c);
void S(int ordinate[],int *a,int *b,int *c);
void A(int ordinate[],int *a,int *b,int *c);
void D(int ordinate[],int *a,int *b,int *c);

int main(){
    int a,b,c;
    char order[SIZE]={0};
    int ordinate[5]={0};
    int W_times = 0;
    int S_times = 0;
    int A_times = 0;
    int D_times = 0;

    scanf("%d %d %d",&a,&b,&c);
    getchar();
    gets(order);
    int count = strlen(order);

    ordinate[1]=0;
    ordinate[2]=a;
    ordinate[3]=0;
    ordinate[4]=b;

    for(int i = 0;i<count;i++){
        if(order[i] == 'W'){
            W(ordinate,&a,&b,&c);
        }
        if(order[i] == 'S'){
            S(ordinate,&a,&b,&c);
        }
        if(order[i] == 'A'){
            A(ordinate,&a,&b,&c);
        }
        if(order[i] == 'D'){
            D(ordinate,&a,&b,&c);
        }
    }

    for (int i = 1; i <=4 ; ++i) {
        printf("%d ",ordinate[i]);
    }







}

void W(int ordinate[],int *a,int *b,int *c){

    ordinate[2] = ordinate[1];
    ordinate[1] -= *c;
    int temp = *a;
    *a = *c;
    *c = temp;

}

void S(int ordinate[],int *a,int *b,int *c){

    ordinate[1] = ordinate[2];
    ordinate[2] += *c;
    int temp = *a;
    *a = *c;
    *c = temp;

}

void A(int ordinate[],int *a,int *b,int *c){

    ordinate[4] = ordinate[3];
    ordinate[3] -= *c;
    int temp = *b;
    *b = *c;
    *c = temp;

}

void D(int ordinate[],int *a,int *b,int *c){

    ordinate[3] = ordinate[4];
    ordinate[4] += *c;
    int temp = *b;
    *b = *c;
    *c = temp;

}



