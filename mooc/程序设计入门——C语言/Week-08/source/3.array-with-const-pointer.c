#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    printf("sizeof(arr)=%lu\n", sizeof(arr));
    // sizeof(arr)=20
    printf("sizeof(*arr)=%lu\n", sizeof(*arr));
    // sizeof(*arr)=4

    int const *p = arr;

    printf("sizeof(p)=%lu\n", sizeof(p));
    // sizeof(p)=8
    printf("sizeof(*p)=%lu\n", sizeof(*p));
    // sizeof(*p)=4

    int *p2;

    printf("sizeof(p2)=%lu\n", sizeof(p2));
    // sizeof(p2)=8

    return 0;
}