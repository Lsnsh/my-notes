#include <stdio.h>

int main()
{
    int i;
    int j;

    j = i + 10;
    printf("%d\n", j); // 输出（一长串的数字）：120328239

    i = 2;
    j = i + 10;
    printf("%d\n", j); // 输出：12

    return 0;
}