#include <stdio.h>

int main()
{
    int x = 2, count = 0;

    // 前50个素数
    while (count < 50)
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
            count++;
        }
        x++;
    }

    printf("\n");

    return 0;
}