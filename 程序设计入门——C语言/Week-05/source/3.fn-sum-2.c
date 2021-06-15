// f(n)=1 - 1/2 + 1/3 - 1/4 + ... + 1/n;
#include <stdio.h>

int main()
{
    int x, i;
    double sum = 0.0, sign = 1.0;

    printf("n=");
    scanf("%d", &x);

    for (i = 1; i <= x; i++)
    {
        sum += sign / i;
        sign = -sign;
    }

    printf("f(%d)=%f\n", x, sum);

    return 0;
}