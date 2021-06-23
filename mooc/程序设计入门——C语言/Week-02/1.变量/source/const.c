#include <stdio.h>

int main()
{

    const int AMOUNT = 100;
    int price = 0;

    // AMOUNT = 90;
    // error: cannot assign to variable 'AMOUNT' with
    //   const-qualified type 'const int'

    printf("请输入金额（元）：");
    scanf("%d", &price);

    int change = AMOUNT - price;

    printf("找您%d元。\n", change);

    return 0;
}