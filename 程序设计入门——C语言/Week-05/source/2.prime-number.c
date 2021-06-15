#include <stdio.h>

int main()
{
    int x;

    // 100以内的素数
    for (x = 2; x < 100; x++)
    {
        int i, isPrimeNumber = 1;

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
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}