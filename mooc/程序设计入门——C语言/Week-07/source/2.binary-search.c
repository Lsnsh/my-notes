#include <stdio.h>

int binarySearch(int k, int arr[], int length);

int main()
{
    int arr[] = {2, 4, 7, 11, 13, 16, 21, 24, 27, 32, 36, 40, 46};
    int length = sizeof(arr) / sizeof(arr[0]) - 1;

    int k;
    printf("请输入要查找的数：");
    scanf("%d", &k);

    int index = binarySearch(k, arr, length);

    printf("%d 在数组中的位置：%d\n", k, index);

    return 0;
}

int binarySearch(int k, int arr[], int length)
{
    int ret = -1;

    int left = 0, right = length - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        printf("%d, %d, %d\n", left, right, mid);

        if (arr[mid] == k)
        {
            ret = mid;
            break;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ret;
}