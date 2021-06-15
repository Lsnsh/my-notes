// 输入多少美分，输出多少美分的英文
#include <stdio.h>

struct CoinType
{
    int amount;
    char *name;
};
struct CoinType search(int x, struct CoinType coins[], int length);

int main()
{
    struct CoinType coins[] = {
        {1, "penny"},
        {5, "nickel"},
        {10, "dime"},
        {25, "quarter"},
        {50, "half-dollar"},
    };
    int x = 1, length = sizeof(coins) / sizeof(coins[0]);

    printf("请输入美分：");
    scanf("%d", &x);

    struct CoinType coin = search(x, coins, length);
    char *name = "unknown";

    if (coin.name)
    {
        name = coin.name;
    }
    printf("%d 美分对应的英文是：%s\n", x, name);

    return 0;
}

struct CoinType search(int x, struct CoinType coins[], int length)
{
    int i;
    struct CoinType ret;

    for (i = 0; i < length; i++)
    {
        if (coins[i].amount == x)
        {
            ret = coins[i];
            break;
        }
    }

    return ret;
}