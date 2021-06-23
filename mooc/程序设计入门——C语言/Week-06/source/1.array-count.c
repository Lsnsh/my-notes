#include <stdio.h>

int main()
{
    const int LENGTH = 10;
    int count[LENGTH], x, i;

    for (i = 0; i < LENGTH; i++)
    {
        count[i] = 0;
    }

    scanf("%d", &x);
    while (x != -1)
    {
        if (x >= 0 && x <= 9)
        {
            count[x]++;
        }
        scanf("%d", &x);
    }

    for (i = 0; i < LENGTH; i++)
    {
        printf("%d的个数是：%d\n", i, count[i]);
    }
    return 0;
}