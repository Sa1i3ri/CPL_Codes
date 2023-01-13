//
// Created by 14832 on 2022/9/30.
//
#include <stdio.h>

int main(){
    //const常量
    const double PI =3.14159;
    int radius = 10;
    double circumference = 2* PI * radius;
    double circumsquare = PI * radius * radius;
    printf("circcumference = %.2f \n area = %.2f",
           circumference, circumsquare);

    return 0;
}
