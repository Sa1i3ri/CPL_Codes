#include <stdio.h>

int main(){
    int money;
    scanf("%d",&money);
    int change50 = money/50 ;
    money = money-50*change50;
    int change20= (money/20);
    money = money-20*change20;
    int change10= (money/10);
    money = money-10*change10;
    int change5= (money/5);
    money = money-5*change5;
    int change1= (money/1);
    money = money-1*change1;
    printf("%d\n%d\n%d\n%d\n%d\n",
           change50,change20,change10,change5,change1);


    return 0;
}
