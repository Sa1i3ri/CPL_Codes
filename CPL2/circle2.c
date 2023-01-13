//
// Created by 14832 on 2022/9/30.
//
#include <stdio.h>
#include <math.h>
int main(){
    const double PI = 3.14159;
    int radius = 100;
    double surface_area = 4 * PI * pow(radius,2);
    double volume = 4/3.0 * PI * pow(radius , 3);
    // 15.4 15至少输出几位 .4保留几位小数
    printf("%-15.4f : surface_area\n%-15.4f : volume\n",
           surface_area, volume);
}

