//
// Created by 14832 on 2022/10/1.
//
#include <stdio.h>

int main(){
    char month[20] , weekday[20];
    int day , year , hour , minute ,second;
    scanf("%s %d %d %s %d %d %d",
          month, &day, &year, weekday, &hour, &minute, &second);

    printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d",
           weekday,month,day,hour,minute,second,year);

    return 0;

}
