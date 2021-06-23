#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    printf("arr[-1]=%d\n", arr[-1]);
    // warning: array index -1 is before the beginning of the array
    // arr[-1]=0
    printf("arr[0]=%d\n", arr[0]);
    // arr[0]=1
    printf("arr[1]=%d\n", arr[1]);
    // arr[1]=2

    int const *p = &arr[3];

    printf("p[-1]=%d\n", p[-1]);
    // p[-1]=3
    printf("p[0]=%d\n", p[0]);
    // p[0]=4
    printf("p[1]=%d\n", p[1]);
    // p[1]=5

    return 0;
}