//
// Created by 14832 on 2022/10/1.
//

#include <stdio.h>
#include <math.h>

int main(){
    int year,month,day;
    scanf("%d %d %d",&year,&month,&day);
    int a,y,m,JDU;
    a=floor((14-month)/12);
    y=year+4800-a;
    m=month+12*a-3;
    JDU=day+(153*m+2)/5+365*y+y/4- y/100+ y/400-32045;
    printf("%d",JDU);
}
