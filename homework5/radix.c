//
// Created by 14832 on 2022/11/1.
//

#include "stdio.h"
#include "math.h"

int find_the_biggest(int num);
int compare_big(int a,int b,int c);
int turn_to_10(int num,int b);

int main(){
    int p,q,r,n;
    int b=41;
    scanf("%d %d %d",&p,&q,&r);

    n = compare_big(find_the_biggest(p),find_the_biggest(q),find_the_biggest(r));
    for(int i = n+1;i<41;i++){
        if(turn_to_10(p,i) * turn_to_10(q,i) == turn_to_10(r,i) && i<=b){
            b = i;
        }
    }
    if(b>40){
        printf("0");
    }else{
        printf("%d",b);
    }

}

int find_the_biggest(int num){
    int p[5] = {0};
    int big = 0;
    for (int i = 4; i >= 1; i--) {
        int s = 0;
        s = num / pow(10, i - 1);
        p[i] = s % 10;
        if (big < p[i]) {
            big = p[i];
        }
    }
    return big;
}

int compare_big(int a,int b, int c){
    int big = 0;
    if(a>=b){
        big = a;
    }else{
        big = b;
    }

    if(c>=big){
        big = c;
    }
    return big;
}

int turn_to_10(int num, int b){
    int sum = 0;
    int s[5]={0};
    for(int i = 4;i>=1;i--){
        int p = 0;
        p =  num / pow(10,i-1) ;
        s[i] = p % 10;
    }

    while(num!=0){
        num /=10;
    }

    for (int i = 0; i <= 4; i++) {
        sum += s[i] * pow(b, i-1);
    }
    return sum;
}
