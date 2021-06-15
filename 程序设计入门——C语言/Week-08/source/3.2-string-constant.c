// 字符串常量
#include <stdio.h>

int main()
{
    int n1, n2;
    char *s1 = "Hello World";
    char *s2 = "Hello World";
    char s3[] = "Hello World";

    printf("n1=%p\n", &n1);
    // n1=0x7ffee6ec42e4
    printf("n2=%p\n", &n2);
    // n2=0x7ffee6ec42e0
    printf("s3=%p\n", s3);
    // s3=0x7ffee6ec42ec

    s3[0] = 'A';

    printf("s3[0]=%c\n", s3[0]);
    // s3[0]=A

    // char * 定义的字符串是字符串常量，并且不和本地变量存放在一起
    printf("s1=%p\n", s1);
    // s1=0x104dfaf74
    printf("s2=%p\n", s2);
    // s2=0x104dfaf74

    // s1[0] = 'A';
    // [1]    79176 bus error

    printf("s1[0]=%c\n", s1[0]);

    return 0;
}