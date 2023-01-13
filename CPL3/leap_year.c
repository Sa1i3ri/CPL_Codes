//
// Created by 14832 on 2022/10/7.
//

#include <stdio.h>

int main() {
    //约定int 0为假 1为真
    int year = 0 ;
    int leap = 0 ;
    scanf("%d",&year);
    //可以用else if使其整洁
//    if (year % 4 == 0) {
//        if (year % 100 == 0) {
//            if (year % 400 == 0) {
//                leap = 1;
//            } else {
//                leap = 0;
//            }
//        } else {
//            leap = 1;
//        }
//    } else {
//        leap = 0;
//    }


    //或|| 且&& 取反!
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        leap = 1;
    } else {
        leap = 0;
    }

//    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400) == 0;
    printf("%d",leap);




}

