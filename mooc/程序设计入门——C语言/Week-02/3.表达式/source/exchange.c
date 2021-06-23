#include <stdio.h>

int main()
{
    int a = 5;
    int b = 6;
    int t;

    printf("交换前：a=%d b=%d\n", a, b);

    // 将 a 的值暂时存放到 t 中
    t = a;
    // a 的值做过备份后，将 b 的值赋值给 a
    a = b;
    // 最后将 a 备份的值 t 赋值给 b
    b = t;

    printf("交换后：a=%d b=%d\n", a, b);

    return 0;
}