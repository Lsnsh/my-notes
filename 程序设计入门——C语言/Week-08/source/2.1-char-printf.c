#include <stdio.h>

int main()
{
    char c1, c2;
    c1 = 66, c2 = 'A';

    printf("c1=%d\n", c1);
    // c1=66
    printf("c1=%c\n", c1);
    // c1=B

    printf("c2=%d\n", c2);
    // c2=65
    printf("c2=%c\n", c2);
    // c2=A

    printf("49 == '1'=%d\n", 49 == '1');
    // 49 == '1'=1

    return 0;
}