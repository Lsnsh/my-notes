// 求100以内的素数
#include <stdio.h>

// 是否是素数
int isPrimeNumber(int x)
{
    int i, ret = 1;
    for (i = 2; i < x; i++)
    {
        // 能被1和自己以外的数整除的数，就不是素数
        if (x % i == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

int main()
{
    int x;

    for (x = 2; x < 100; x++)
    {
        if (isPrimeNumber(x) == 1)
        {
            printf("%d ", x);
        }
    }

    printf("\n");

    return 0;
}