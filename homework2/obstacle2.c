//
// Created by 14832 on 2022/10/14.
//

#include "stdio.h"

int main(){
    int xa, ya, xb, yb, xc, yc;
    int U = 0;
    int D = 0;
    int L = 0;
    int R = 0;
    int c;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    int y = yb - ya;
    int x = xb - xa;

    if(xc == xb || yc == ya){
        if(ya == yb && yb== yc && ((xc<xb && xc>xa)||(xc>xb && xc<xa))){
            if(x>0){
                for(int i = x;i>0;i--){
                    R++;
                }
            }else{
                for(int i = -1*x;i>0;i--){
                    L++;
                }
            }
            c=R+L+2;
            printf("%d\n",c);
            printf("U");
            while(R>0){
                printf("R");
                R--;
            }
            while (L>0){
                printf("L");
                L--;
            }
            printf("D");
        }else if(xa == xb && xb == xc && ((yc<yb && yc>ya)||(yc>yb && yc<ya))){
            if(y>0){
                for(int i = y;i>0;i--){
                    U++;
                }
            }else{
                for(int i = -1*y; i>0 ; i--){
                    D++;
                }
            }
            c=U+D+2;
            printf("%d\n",c);
            printf("R");
            while (U>0){
                printf("U");
                U--;
            }
            while (D>0){
                printf("D");
                D--;
            }
            printf("L");
        }else{
            if (y > 0) {
                for (int i = yb - ya; i > 0; i--) {
                    U++;
                }
            }
            if (y < 0) {
                for (int i = ya - yb; i > 0; i--) {
                    D++;
                }
            }

            if (x > 0) {
                for (int i = xb - xa; i > 0; i--) {
                    R++;
                }
            }
            if (x < 0) {
                for (int i = xa - xb; i > 0; i--) {
                    L++;
                }
            }
            c = U + D + R + L;
            printf("%d\n", c);
            while (U > 0) {
                printf("U");
                U--;
            }
            while (D > 0) {
                printf("D");
                D--;
            }
            while (R > 0) {
                printf("R");
                R--;
            }
            while (L > 0) {
                printf("L");
                L--;
            }
        }


    }else{
        if (x > 0) {
            for (int i = xb - xa; i > 0; i--) {
                R++;
            }
        }
        if (x < 0) {
            for (int i = xa - xb; i > 0; i--) {
                L++;
            }
        }

        if (y > 0) {
            for (int i = yb - ya; i > 0; i--) {
                U++;
            }
        }
        if (y < 0) {
            for (int i = ya - yb; i > 0; i--) {
                D++;
            }
        }

        c = U + D + R + L;
        printf("%d\n", c);

        while (R > 0) {
            printf("R");
            R--;
        }
        while (L > 0) {
            printf("L");
            L--;
        }
        while (U > 0) {
            printf("U");
            U--;
        }
        while (D > 0) {
            printf("D");
            D--;
        }

    }
}
