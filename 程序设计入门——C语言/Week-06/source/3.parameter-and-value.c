#include <stdio.h>

// 交换值
void swap(int a, int b);

int main()
{
    int a = 5, b = 6;

    swap(a, b);

    // a 和 b 的值并没有被交换
    // 输出：main: a=5, b=6
    printf("main: a=%d, b=%d\n", a, b);

    return 0;
}

void swap(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;

    // 函数内参数 a 和 参数 b的值，交换成功，并不会影响外部调用函数的值
    // 输出：main: a=5, b=6
    printf("swap: a=%d, b=%d\n", a, b);
}