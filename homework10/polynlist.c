//
// Created by 14832 on 2022/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10005


void num_p1_plus_p2(const int p1[],const int p2[],int ans[],int high_p1,int high_p2);
void num_p1_minus_p2(const int p1[],const int p2[],int ans[],int high_p1,int high_p2);
void num_p1_multiply_p2(const int p1[],const int p2[],int ans[],int high_p1,int high_p2);
void print_ans_and_clean(int ans[],int len,char name[]);
bool is_head(int i, int ans[],int len);


int main(){
    int high_p1 = 0;
    int high_p2 = 0;
    char name[15]={0};
    scanf("%d %d",&high_p1,&high_p2);
    getchar();
    scanf("%s",name);
    getchar();
    int *num_p1 = malloc((high_p1+1) * sizeof(*num_p1));
    int *num_p2 = malloc((high_p2+1) * sizeof(*num_p2));

    for(int i = high_p1;i>=0;i--){
        scanf("%d",&num_p1[i]);
    }
    getchar();
    for(int i = high_p2;i>=0;i--){
        scanf("%d",&num_p2[i]);
    }
    getchar();
    int len = high_p1 + high_p2 + 1;
    int *ans = malloc(len * sizeof(int));
    for(int i = 0;i<len;i++){
        ans[i] = 0;
    }

    num_p1_plus_p2(num_p1,num_p2,ans,high_p1,high_p2);
    print_ans_and_clean(ans,len,name);
    printf("\n");
    num_p1_minus_p2(num_p1,num_p2,ans,high_p1,high_p2);
    print_ans_and_clean(ans,len,name);
    printf("\n");
    num_p1_multiply_p2(num_p1,num_p2,ans,high_p1,high_p2);
    print_ans_and_clean(ans,len,name);



    free(ans);
    free(num_p1);
    free(num_p2);
}

void print_ans_and_clean(int ans[],int len,char name[]){
    for(int i = len - 1;i>=0;i--){
        if(ans[i] == 0){
            continue;
        }
        //系数不为0了

        if(ans[i] > 0 && !is_head(i,ans,len)) {
            //系数为正且不是头一个的时候 加一个'+'
            printf("+");
        }

        if (i == 0) {
            //指数为0
            printf("%d", ans[i]);
        } else if (i == 1) {
            //指数为1
            if (ans[i] == 1) {
                //指数为1，系数为1
                printf("%s", name);
            } else if(ans[i] == -1){
                //指数为1，系数为-1
                printf("-%s",  name);
            }else{
                //指数为1，系数不为1和-1
                printf("%d%s", ans[i], name);
            }
        } else {
            //指数不为1也不为0
            if (ans[i] == 1) {
                //指数不为1也不为0，系数为1
                printf("%s^%d", name, i);
            } else if(ans[i] == -1){
                //指数不为1也不为0，系数为-1
                printf("-%s^%d",  name, i);
            }else {
                //指数不为1也不为0，系数不为1和-1
                printf("%d%s^%d", ans[i], name, i);
            }

        }

    }

    for(int i = 0;i<len;i++){
        ans[i] = 0;
    }


}

void num_p1_plus_p2(const int p1[],const int p2[],int ans[],int high_p1,int high_p2){

    int small_of_two = (high_p1 < high_p2) ? high_p1 : high_p2;
    int big_of_two = (high_p1 > high_p2) ? high_p1 : high_p2;

    for(int i = 0;i<=small_of_two;i++){
        ans[i] += p1[i] + p2[i];
    }

    if(high_p1 > high_p2){
        for(int i = small_of_two+1;i<=big_of_two;i++){
            ans[i] += p1[i];
        }
    }else{
        for(int i = small_of_two+1;i<=big_of_two;i++){
            ans[i] += p2[i];
        }
    }


}
void num_p1_minus_p2(const int p1[],const int p2[],int ans[],int high_p1,int high_p2){

    int small_of_two = (high_p1<high_p2) ? high_p1:high_p2;
    int big_of_two = (high_p1>high_p2) ? high_p1:high_p2;

    for(int i = 0;i<=small_of_two;i++){
        ans[i] += p1[i] - p2[i];
    }

    if(high_p1>high_p2){
        for(int i = small_of_two+1;i<=big_of_two;i++){
            ans[i] += p1[i];
        }
    }else{
        for(int i = small_of_two+1;i<=big_of_two;i++){
            ans[i] += (-1) * p2[i];
        }
    }


}
void num_p1_multiply_p2(const int p1[],const int p2[],int ans[],int high_p1,int high_p2){

    for(int op_p1 = 0;op_p1<=high_p1;op_p1++){
        for(int op_p2 = 0;op_p2<=high_p2;op_p2++){
            ans[op_p1+op_p2] += p1[op_p1] * p2[op_p2];
        }
    }

}

bool is_head(int i, int ans[],int len){
    int op = -1;
    for(int j = len -1;j>=0;j--){
        if(ans[j] !=0){
            op = j;
            break;
        }
    }

    if(i == op){
        return true;
    }else{
        return false;
    }
}
