//
// Created by 14832 on 2022/10/1.
//

#include <stdio.h>
#include <math.h>

int main(){
    int p,q;
    scanf("%d %d",&p,&q);
    double a,b;
    if(-q/2.0+ sqrt(pow(q/2.0,2)+ pow(p/3.0,3))>=0){
        a =pow(-q/2.0+ sqrt(pow(q/2.0,2)+ pow(p/3.0,3)),1/3.0);
    }else{
        a =-pow(q/2.0- sqrt(pow(q/2.0,2)+ pow(p/3.0,3)),1/3.0);
    }

    if(-q/2.0- sqrt(pow(q/2.0,2)+ pow(p/3.0,3))>=0){
        b =pow(-q/2.0- sqrt(pow(q/2.0,2)+ pow(p/3.0,3)),1/3.0);
    }else{
        b =-pow(q/2.0+ sqrt(pow(q/2.0,2)+ pow(p/3.0,3)),1/3.0);
    }

    double x = a+b;
    printf("%.3f",x);
}
