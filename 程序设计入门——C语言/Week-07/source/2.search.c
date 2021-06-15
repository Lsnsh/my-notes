#include <stdio.h>

int search(int x, int arr[], int length);

int main()
{
    int arr[] = {2, 7, 4, 2, 7, 8, 3, 1, 12, 5, 7, 53};
    int x = 1, length = sizeof(arr) / sizeof(arr[0]);

    int index = search(x, arr, length);
    printf("%d 在数组中的位置：%d\n", x, index);

    return 0;
}

int search(int x, int arr[], int length)
{
    int i, ret = -1;
    for (i = 0; i < length; i++)
    {
        if (arr[i] == x)
        {
            ret = i;
            break;
        }
    }

    return ret;
}