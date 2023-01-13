//
// Created by 14832 on 2022/10/1.
//

#include <stdio.h>

int main(){
    const double G = 6.674e-11;
    const double M = 77.15;
    double m,r;
    scanf("%lf %lf",&m,&r);
    double N = (G*M*m)/(r*r);
    printf("%.3e",N);
}
