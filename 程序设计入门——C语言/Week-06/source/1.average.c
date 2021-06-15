// 计算平均数，并输出大于平均数的数有哪些
#include <stdio.h>

int main()
{
    int x = 0,  count = 0;
    double sum = 0.0, avg = 0.0;
    int number[100];

    scanf("%d", &x);

    while (x != -1)
    {
        number[count] = x;

        sum += x;
        count++;

        scanf("%d", &x);
    }

    if (count > 0)
    {
        avg = sum / count;
        printf("平均数是：%f\n", avg);

        printf("大于平均数的数有：");
        for (int i = 0; i < count; i++)
        {
            if (number[i] > avg)
            {
                printf("%d ", number[i]);
            }
        }
        printf("\n");
    }

    return 0;
}