// 大小写转换
#include <stdio.h>

int main()
{
    char c1 = 'A';
    c1 = c1 + ('a' - 'A');

    printf("c1=%d\n", c1);
    // c1=97
    printf("c1='%c'\n", c1);
    // c1='a'

    char c2 = 'a';
    c2 = c2 - ('a' - 'A');

    printf("c2=%d\n", c2);
    // c2=65
    printf("c2='%c'\n", c2);
    // c2='A'

    return 0;
}