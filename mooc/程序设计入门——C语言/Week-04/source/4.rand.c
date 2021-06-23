#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    // 向 100 取余，得到100以内的随机数
    int number = rand() % 100 + 1;
    int a, count = 0;

    printf("我已经想好了一个1到100之间的数。\n");

    while (a != number)
    {
        printf("请猜猜这个1到100之间的数：");
        scanf("%d", &a);

        count++;

        if (a > number)
        {
            printf("大\n");
        }
        else
        {
            printf("小\n");
        }
    }

    printf("太好了，你用了%d次就猜到了答案。\n", count);

    return 0;
}