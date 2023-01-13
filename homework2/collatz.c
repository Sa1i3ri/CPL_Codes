//
// Created by 14832 on 2022/10/10.
//

#include "stdio.h"

int main()
{
    int n;
    int i = 0;
    int max = 0;
    scanf("%d", &n);
    while (n != 1)
    {
        if (n >= max)
        {
            max = n;
        }
        if (n % 2 == 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }
        i++;
    }
    if (n >= max)
    {
        max = n;
    }
    printf("%d %d", i, max);
}
