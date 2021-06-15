#include <stdio.h>

int * selectionSort(int arr[], int length);

int main()
{
    int arr1[] = {2, 45, 6, 12, 87, 34, 90, 24, 23, 11, 65};
    int i, length = sizeof(arr1) / sizeof(arr1[0]);

    printf("排序前：");
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int *arr2 = selectionSort(arr1, length);

    printf("排序后：");
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}

int * selectionSort(int arr[], int length)
{
    int *retArr = arr;
    int i, j;

    for (i = length - 1; i > 0; i--)
    {
        // 内存循环：找剩余区间内最大的值，然后移到右边
        int maxIndex = 0;
        for (j = 1; j <= i; j++)
        {
            if (retArr[j] > retArr[maxIndex])
            {
                maxIndex = j;
            }
        }

        // 交换位置，移到右边
        int t = retArr[i];
        retArr[i] = retArr[maxIndex];
        retArr[maxIndex] = t;
    }

    return retArr;
}