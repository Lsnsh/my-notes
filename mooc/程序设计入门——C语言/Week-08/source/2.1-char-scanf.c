#include <stdio.h>

int main()
{
    char c1, c2;
    int n2;

    printf("赋值给c1，请输入字符：");
    scanf("%c", &c1);
    // 赋值给c1，请输入字符：1
    printf("c1=%d\n", c1);
    // c1=49
    printf("c1='%c'\n", c1);
    // c1='1'

    printf("赋值给n2，请输入整数：");
    scanf("%d", &n2);
    // 赋值给n2，请输入整数：65
    c2 = n2;
    printf("c2=%d\n", c2);
    // c2=65
    printf("c2='%c'\n", c2);
    // c2='A'

    return 0;
}