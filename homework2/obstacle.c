//
// Created by 14832 on 2022/10/10.
//

#include "stdio.h"
#include "math.h"

int main() {
    int xa, ya, xb, yb, xc, yc;
    int U = 0;
    int D = 0;
    int L = 0;
    int R = 0;
    int c;
    scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
    int y = yb - ya;
    int x = xb - xa;

    if (ya == yb && yb== yc) {
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
        c = R + L + 2;
        printf("%d\n",c);
        printf("U");
        while (R > 0) {
            printf("R");
            R--;
        }
        while (L > 0) {
            printf("L");
            L--;
        }
        printf("D");
    }
        if (xa == xb && xb== xc) {
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
        c = U + D + 2;
        printf("%d\n",c);
        printf("R");
        while (U > 0) {
            printf("U");
            U--;
        }
        while (D > 0) {
            printf("D");
            D--;
        }
        printf("L");
    }
        if ((xa != xb)&&(yb!= yc)&&(xc == xb || yc == ya)) {
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

    } else if((xa != xb)&&(yb!= yc)){
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