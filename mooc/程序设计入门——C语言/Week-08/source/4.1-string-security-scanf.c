// 安全的输入
#include <stdio.h>

int main()
{
    char s1[8];
    char s2[8];

    scanf("%7s", s1);
    scanf("%7s", s2);
    // 输入：123456789abcdefgh

    printf("s1=%s, s2=%s\n", s1, s2);
    // 输出：s1=1234567, s2=89abcde

    return 0;
}