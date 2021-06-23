#include <stdio.h>

int main()
{
    // int a, b;

    // scanf("%d %d", &a, &b);

    int result = 2;
    result = (result = result * 2) * 6 * (result = 3 + result);

    printf("%d", result);

    return 0;
}