#include <stdio.h>

int main()
{
    int x;
    printf("请输入10元以内的金额：");
    scanf("%d", &x);

    int one, two, five;

    // 将元转换为角，然后循环
    for (one = 1; one < x * 10; one++)
    {
        for (two = 1; two < x * 10 / 5; two++)
        {
            for (five = 1; five < x * 10 / 2; five++)
            {
                if (one + two * 2 + five * 5 == x * 10)
                {
                    // 只输出一组结果
                    printf("%d个1角+%d个2角+%d个5角=%d元\n", one, two, five, x);
                    goto out;
                }
            }
        }
    }

out:;

    return 0;
}