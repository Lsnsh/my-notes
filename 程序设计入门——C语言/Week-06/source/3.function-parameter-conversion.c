#include <stdio.h>

void foo(int num)
{
    printf("%d\n", num);
}

int main()
{
    double n1 = 2.0;
    foo(n1); // 输出：2

    double n2 = 2.4;
    foo(n2); // 输出：2

    foo(2.0); // 输出：2

    foo(2.4);
    // 输出警告信息：warning: implicit conversion from 'double' to 'int' changes value from 2.4
    //   to 2 [-Wliteral-conversion]
    // 然后输出：2

    return 0;
}