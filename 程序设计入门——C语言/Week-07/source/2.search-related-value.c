// 输入多少美分，输出多少美分的英文
#include <stdio.h>

int search(int x, int arr[], int length);

int main()
{
    int arr[] = {1, 5, 10, 25, 50};
    char *name[] = {"penny", "nickel", "dime", "quarter", "half-dollar"};
    int x = 1, length = sizeof(arr) / sizeof(arr[0]);

    printf("请输入美分：");
    scanf("%d", &x);

    int index = search(x, arr, length);
    char *word = "unknown";
    if (index != -1)
    {
        word = name[index];
    }
    printf("%d 美分对应的英文是：%s\n", x, word);

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