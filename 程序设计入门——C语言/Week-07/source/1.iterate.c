#include <stdio.h>

void iterate(int a[], int length);

int main()
{
    int a[] = {
        1,
        2,
        3,
        4,
        5,
    };
    int length = sizeof(a) / sizeof(a[0]);

    iterate(a, length);

    return 0;
}

void iterate(int a[], int length)
{
    int len = sizeof(a) / sizeof(a[0]);
    printf("len=%d\n", len);
    // warning: 'sizeof (a)' will return the size of the pointer, not the array
    //   itself [-Wsizeof-pointer-div]
    // 输出的大小是指针的大小，而不是数组的大小
    // 输出：len=2

    int i;

    for (i = 0; i < length; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
}