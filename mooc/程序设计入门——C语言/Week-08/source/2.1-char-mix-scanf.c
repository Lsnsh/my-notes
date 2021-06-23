// scanf %d 和 %c 之间有空格和没空格的区别
#include <stdio.h>

int main()
{
    int i;
    char c1;

    scanf("%d %c", &i, &c1);
    // 12a
    // 12 a
    printf("i=%d c1=%d c1='%c'\n", i, c1, c1);
    // i=12 c1=97 c1='a'
    // i=12 c1=97 c1='a'

    scanf("%d%c", &i, &c1);
    // 12a
    // 12 a
    printf("i=%d c1=%d c1='%c'\n", i, c1, c1);
    // i=12 c1=97 c1='a'
    // i=12 c1=32 c1=' '

    return 0;
}