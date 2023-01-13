//
// Created by 14832 on 2022/10/14.
//


#include  "stdio.h"
#include "math.h"
int main(  ) {
    int xa, xb, xc, ya, yb, yc, step;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    if (xa == xb) {
        if (xc != xa || (yb > ya && (ya > yc || yc > yb)) || (yb < ya && (yc > ya || yc < yb))) {
            step = abs(xb - xa) + abs(ya - yb);
            printf("%d\n", step);
            for (int i = ya; i != yb; i += (yb > ya) ? 1 : -1) {
                if (yb > ya) {
                    printf("U");
                }else {
                    printf("D");
                }
            }
        } else {
            step = abs(xa - xb) + abs(ya - yb) + 2;
            printf("%d\n", step);
            printf("R");
            for (int i = ya; i != yb; i += (yb > ya) ? 1 : -1) {
                if (yb > ya) {
                    printf("U");
                }else {
                    printf("D");
                }
            }
            printf("L");
        }
    }
    if (ya == yb) {
        if (yc != yb || (xb > xa && (xc < xa || xc > xb)) || (xb < xa && (xa < xc || xc<xb))) {
            step = abs(xb - xa) + abs(ya - yb);
            printf("%d\n", step);
            for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                if (xb > xa) {
                    printf("R");
                }else {
                    printf("L");
                }
            }
        } else {
            step = abs(xa - xb) + abs(ya - yb) + 2;
            printf("%d\n", step);
            printf("U");
            for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                if (xb > xa) {
                    printf("R");
                }else {
                    printf("L");
                }
            }
            printf("D");
        }
    }
    else if(xa!=xb){
        step = abs(xa - xb) + abs(ya - yb);
        printf("%d\n", step);
        if (yb > ya) {
            if ((yc == ya)&&((xc <= xb && xc > xa) || (xc >= xb && xc < xa))) {
                for (int i = ya; i != yb; i++) {
                    printf("U");
                }
                for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                    if (xb > xa)
                        printf("R");
                    if (xa > xb)
                        printf("L");
                }
            } else if ((yc < yb && yc > ya) && (xc == xb)) {
                for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                    printf("U");
                }
                for (int i = ya; i != yb; i++) {
                    if (xb > xa)
                        printf("R");
                    else
                        printf("L");
                }
            } else {
                for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                    if (xa < xb) {
                        printf("R");
                    }else {
                        printf("L");
                    }
                }
                for (int i = ya; i != yb; i++)
                    printf("U");
            }
        } else if (ya > yb){
            if ((yc == ya) &&((xc <= xb && xc > xa) || (xc >=xb && xc < xa))) {
                for (int i = ya; i != yb; i--) {
                    printf("D");
                }
                for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                    if (xb > xa) {
                        printf("R");
                    }
                    if (xa > xb) {
                        printf("L");
                    }
                }
            } else if ((yc < ya && yc > yb) && (xc == xb)) {
                for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                    printf("D");
                }
                for (int i = ya; i != yb; i--) {
                    if (xb > xa)
                        printf("R");
                    else
                        printf("L");
                }
            } else {
                for (int i = xa; i != xb; i += (xb > xa) ? 1 : -1) {
                    if (xa < xb) {
                        printf("R");
                    }else {
                        printf("L");
                    }
                }
                for (int i = ya; i != yb; i--) {
                    printf("D");
                }
            }
        }
    }
}


