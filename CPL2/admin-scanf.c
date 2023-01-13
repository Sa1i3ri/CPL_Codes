//
// Created by 14832 on 2022/9/30.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(){
    //变量是一个字符串
    //[]用这个语法 前面本身就代表了地址
    char first_name[10];
    char last_name[10];
    char gender;
    int birth_year ;
    int birth_month;
    int birth_day ;
    char weekday[10];

    int c_score ;
    int music_socre ;
    int medicine_score ;
    int rank;

    // %c不会忽略空白符 %s会忽略空白符
    //f:在输入带小数点的数字 l:要存储的时候决定存储到哪里 加*意思就是不存储了
    scanf("%9s%9s %c %d-%d-%d %9s %d%d%d %*lf%*lf %d%%",
          first_name,last_name,&gender,
          &birth_month,&birth_day,&birth_year,weekday,
          &c_score,&music_socre,&medicine_score,
          &rank);

    double mean = (c_score+music_socre+medicine_score)/3.0;
    double sd = sqrt((pow(c_score, 2)
                      + pow (music_socre, 2)
                      + pow (medicine_score,2))/3);

    printf("%s %s \t %c\n"
           "%.2d-%.2d-%.2d\t %.3s\n"
           "%d\t %d\t %d\n"
           "%.1f\t %.2f\t %d% \n"
            ,first_name,last_name,toupper(gender)
            ,birth_month,birth_day,birth_year,weekday
            ,c_score,music_socre,medicine_score
            ,mean,sd,rank);


}
