#include <stdio.h>

// 函数原型
int sum(int begin, int end);

int main()
{
    int sum3 = sum(1, 10) + sum(20, 30) + sum(35, 45);

    printf("1 到 10、20 到 30、35 到 45 的三个区间的和是：%d\n", sum3);

    return 0;
}

// 函数定义
int sum(int begin, int end)
{
    int i, ret = 0;
    for (i = begin; i < end; i++)
    {
        ret += i;
    }
    return ret;
}