// 在线处理-O(n)
#include <stdio.h>

int maxSubseqSum4(int A[], int N);

int main()
{
    // int A[] = {-2, 11, -4, 13, -5, -2};
    // int N = sizeof(A) / sizeof(A[0]);

    int i, N;

    scanf("%d", &N);

    int A[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int sum = maxSubseqSum4(A, N);

    printf("最大子序和为：%d\n", sum);

    return 0;
}

int maxSubseqSum4(int A[], int N)
{
    int maxSum = 0, thisSum = 0;
    int i;

    for (i = 0; i < N; i++)
    {
        thisSum += A[i];
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
        }
    }

    return maxSum;
}