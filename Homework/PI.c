//
// Created by 14832 on 2022/10/1.
//

#include <stdio.h>
#include <math.h>

int main(){
    double pi1 = 16*atan(0.2) - 4*atan(1.0/239);
    printf("%.15f\n",pi1);

    double pi2 = (log(pow(640320,3)+744))*1.0 / sqrt(163);
    printf("%.15f", pi2);
}

