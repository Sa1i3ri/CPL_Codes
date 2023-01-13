//
// Created by 14832 on 2022/10/18.
//

#include "stdio.h"
#include "math.h"


int main(){
    int len = 0,n = 0,bool = 1;
    char s[100]=" ";
    int num = 0;
    scanf("%d %d",&len,&n);
    getchar();



    for(int i = 0;i<len;i++){
        scanf("%c",&s[i]);
        if((s[i]-48>=n && s[i]-48<=9) || (s[i]-55>=n && s[i]>=65)){
            printf("Error");
            bool = 0;
            break;
        }

        if(s[i]-48<=9 && s[i]>=48){
            num = num + (s[i]-48) * pow(n,len-i-1);
        }else if(s[i]>=65 && s[i]<=54+n){
            num = num + (s[i]-55) * pow(n,len-i-1);
        }


    }
    if(bool == 1){
        printf("%d",num);
    }

}
