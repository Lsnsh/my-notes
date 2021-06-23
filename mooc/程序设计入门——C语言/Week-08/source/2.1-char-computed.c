#include <stdio.h>

int main()
{
    char c1 = 'a', c2 = 'Z';

    c1++;
    printf("c1=%d\n", c1);
    // c1=98
    printf("c1='%c'\n", c1);
    // c1='b'

    c2 = c2 - 'A';
    printf("c2=%d\n", c2);
    // c2=25
    printf("c2='%c'\n", c2);
    // c2=''

    return 0;
}