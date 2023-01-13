//
// Created by 14832 on 2022/10/19.
//

#include "stdio.h"
#include "stdlib.h"

int main() {
    char s[1000] = {0};
    int n;
    int a = 0, b = -1;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c", &s[i]);
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 63 && s[n - 1 - i] != 63) {
            s[i] = s[n - 1 - i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != 63) {
            if (s[i] >= 48 && s[i] <= 57) {
                printf("%d", s[i] - 48);
            } else {
                printf("%c", s[i]);
            }
        } else {
            if (i <= n / 2-1) {
                b++;
                if (b > 9) {
                    a++;
                    b = 0;
                }
                printf("%d%d", a, b);
            }else{
                printf("%d%d",b,a);
                b--;
                if(b<0){
                    a--;
                    b=9;
                }
            }
        }
    }

}
