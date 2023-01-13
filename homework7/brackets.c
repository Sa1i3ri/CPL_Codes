//
// Created by 14832 on 2022/11/23.
//

#include "stdio.h"
#include "string.h"

#define N 10005

char pop(char b[],int *top);
void push(char b[],int *top,char m);





int main(){

    int t;
    scanf("%d",&t);
    getchar();
    int judge[35]={0};
    for(int i = 0;i<=t;i++){
        judge[i]=1;
    }

    for(int i =1;i<=t;i++){
        int top = 0;
        char stack[N]={0};
        char s[N]={0};

        gets(s);
        int count = strlen(s);

        for(int j = 0;j<count;j++){
            if(s[j] == '(' || s[j] == '[' || s[j]=='{'){
                push(stack,&top,s[j]);
            }else if(s[j] == ')' ){
                if(pop(stack,&top) != '('){
                    judge[i]=0;
                    break;
                }
            }else if(s[j] == ']' ){
                if(pop(stack,&top) != '['){
                    judge[i]=0;
                    break;
                }
            }else if(s[j] == '}' ){
                if(pop(stack,&top) != '{'){
                    judge[i]=0;
                    break;
                }
            }
        }

        if(top !=0){
            judge[i]=0;
        }





    }


    for(int i = 1;i<=t;i++){
        if(judge[i]){
            printf("True\n");
        }else{
            printf("False\n");
        }
    }




}

void push(char b[],int *top,char m){
    *top = *top +1;
    b[*top]=m;
}

char pop(char b[],int *top){
    if(*top <= 0){
        return 0;
    }else{
        char m = b[*top];
        b[*top]=0;
        *top = *top -1;
        return m;
    }

}

