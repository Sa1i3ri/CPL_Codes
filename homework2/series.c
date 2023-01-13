//
// Created by 14832 on 2022/10/10.
//

#include "stdio.h"
#include "math.h"

int main(){
    int n;
    double x;
    double p=0;
    scanf("%lf %d",&x,&n);
    for(int i = 0;i<=n;i++){
        p=p+(pow(-1,i)* pow(x,2*i+1))/(2*i+1);
    }
    double t=4*p;
    printf("%.10f",t);
}
