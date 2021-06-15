// 整数分解（五位数整数）
#include <stdio.h>

int main()
{
    int x, d;
    printf("请输入一个五位数整数，x=");
    scanf("%d", &x);

    int mask = 10000;

    while (mask > 0)
    {
        d = x / mask;
        x = x % mask;
        mask = mask / 10;

        printf("%d", d);
        if (mask > 0)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}