#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    printf("arr=%p\n", arr);
    // arr=0x7ffee142f2f0
    printf("&arr[0]=%p\n", &arr[0]);
    // &arr[0]=0x7ffee142f2f0
    printf("&*arr=%p\n", &*arr);
    // &*arr=0x7ffee142f2f0
    printf("*arr=%d\n\n", *arr);
    // *arr=1

    *arr = 6;

    printf("arr=%p\n", arr);
    // arr=0x7ffee142f2f0
    printf("&arr[0]=%p\n", &arr[0]);
    // &arr[0]=0x7ffee142f2f0
    printf("&*arr=%p\n", &*arr);
    // &*arr=0x7ffee142f2f0
    printf("*arr=%d\n\n", *arr);
    // *arr=6

    int *p = arr;
    printf("p[0]==arr[0]=%d\n", p[0] == arr[0]);
    // p[0]==arr[0]=1

    // arr = 1;
    // error: 表达式必须是可修改的左值

    return 0;
}