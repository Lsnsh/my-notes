#include <stdio.h>

int main()
{
    int a[] = {
        1,
        2,
        3,
        4,
        5,
    };
    int i, length = sizeof(a) / sizeof(a[0]);

    printf("length=%d\n", length);

    for (i = 0; i < length; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }

    return 0;
}