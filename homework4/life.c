//
// Created by 14832 on 2022/10/28.
//

#include "stdio.h"
#include "string.h"

#define SIZE 1005

int main(){
    int n;
    scanf("%d",&n);
    int count=n;
    getchar();
    char s1[SIZE]={0};
    char s2[SIZE]={0};
    int vec[6]={-3,-2,-1,1,2,3};
    int num = 0;
    char input[SIZE+3]={0};

    scanf("%s",&input);
    num = strlen(input);

    for(int i = 3;i<=num+2;i++){
        s1[i]=input[i-3];
        s2[i]=input[i-3];
    }

    while (count>0){
        for (int i = 3; i <= num + 2; i++) {
            int sides_A = 0;
            int sides_B = 0;
            for (int k = 0; k < 6; k++) {
                int new_i = i + vec[k];
                if(s1[new_i]=='A'){
                    sides_A++;
                } else if (s1[new_i] == 'B') {
                    sides_B++;
                }
            }

            if (s1[i] == 'A' && (sides_A >= 5 || sides_A <= 1 || sides_B > 0)) {
                s2[i] = '.';
            }else if (s1[i] == 'B' && (sides_B >= 5 || sides_B <= 1 || sides_A > 0)) {
                s2[i] = '.';
            }else if (s1[i] == '.') {
                if (sides_A >= 2 && sides_A <= 4 && sides_B == 0) {
                    s2[i] = 'A';
                } else if (sides_B >= 2 && sides_B <= 4 && sides_A == 0) {
                    s2[i] = 'B';
                }
            }
        }
        count--;
        for(int i = 3;i<=num+2;i++){
            s1[i]=s2[i];
        }

    }
    for(int i = 3;i<=num+2;i++){
        printf("%c",s1[i]);
    }


}
