#include <stdio.h>

int main()
{
    const int LENGTH = 100;
    int isPrime[LENGTH];
    int i, x;

    // 初始化数组
    for (i = 0; i < LENGTH; i++)
    {
        // 默认情况下 i 都先标记为 1，即是素数
        isPrime[i] = 1;
    }

    for (x = 2; x < LENGTH; x++)
    {
        if (isPrime[x])
        {
            for (i = 2; i * x < LENGTH; i++)
            {
                // 标记为0，即非素数
                isPrime[i * x] = 0;
            }
        }
    }

    for (i = 2; i < LENGTH; i++)
    {
        if (isPrime[i])
        {
            // 输出素数
            printf("%d\t", i);
        }
    }

    printf("\n");

    return 0;
}