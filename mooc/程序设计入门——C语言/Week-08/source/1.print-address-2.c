#include <stdio.h>

int main()
{
    int i;
    int p;

    printf("%p\n", &i);
    // 0x7ffee83f62d8
    printf("%p\n", &p);
    // 0x7ffee83f62d4

    // 栈，自底向上，存放变量，从输出的地址可以看出：
    // 变量 i 在 变量 p 的上面

    int a[10];

    printf("%p\n", &a);
    // 0x7ffee83f62e0
    printf("%p\n", a);
    // 0x7ffee83f62e0
    printf("%p\n", &a[0]);
    // 0x7ffee83f62e0
    printf("%p\n", &a[1]);
    // 0x7ffee83f62e4

    // 数组和数组第一个成员的地址都是一样的，每个数组单元之间间隔4个字节

    return 0;
}