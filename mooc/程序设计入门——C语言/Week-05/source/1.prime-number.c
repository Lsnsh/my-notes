#include <stdio.h>

int main()
{
    int x;
    printf("请输入数字：");
    scanf("%d", &x);

    int i, isPrimeNumber = 1;
    if (x == 1)
    {
        isPrimeNumber = 0;
    }

    for (i = 2; i < x; i++)
    {
        // 能被1和自己以外的数整除的数，就不是素数
        if (x % i == 0)
        {
            isPrimeNumber = 0;
            break;
        }
    }

    if (isPrimeNumber == 1)
    {
        printf("是素数\n");
    }
    else
    {
        printf("不是素数\n");
    }

    return 0;
}