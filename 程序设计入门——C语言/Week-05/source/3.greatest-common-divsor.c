// 辗转相除法
#include <stdio.h>

int main()
{
    int a, b, t;

    scanf("%d %d", &a, &b);
    printf("%d和%d的最大公约数=", a, b);

    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }

    printf("%d\n", a);

    return 0;
}