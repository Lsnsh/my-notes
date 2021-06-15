#include <stdio.h>

int main()
{
    int i;

    printf("%x\n", (int)&i);
    // ee34a308
    printf("%p\n", &i);
    // 0x7ffeee34a308

    printf("%lu\n", sizeof(int));
    // 4
    printf("%lu\n", sizeof(&i));
    // 8

    return 0;
}