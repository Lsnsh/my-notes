#include <stdio.h>

int main()
{
    int number;
    int sum = 0, count = 0;

    scanf("%d", &number);
    while (number != -1)
    {
        sum += number;
        count++;
        scanf("%d", &number);
    }

    // 不带小数点：
    // printf("平均数是：%d\n", sum / count);

    // 带小数点：
    printf("平均数是：%f\n", 1.0 * sum / count);

    return 0;
}