//
// Created by 14832 on 2022/9/30.
//

#include <stdio.h>

int main(){
    const double MOL = 6.02e23;
    const int MOL_PER_GRAM = 32;
    int mass = 6;
    double quantity = mass * 1.0 / MOL_PER_GRAM * MOL;
    // e科学计数法 g保留有效数字
    printf("quantity = %.3e\n quantity = %.5g\n",
           quantity, quantity);
}
