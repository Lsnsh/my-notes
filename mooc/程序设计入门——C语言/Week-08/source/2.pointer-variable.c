#include <stdio.h>

void f(int *p);
void g(int a);

int main()
{
    int i = 6;
    printf("&i=%p\n", &i);
    // &i=0x7ffee4a342f8

    g(i);
    // a=6
    f(&i);
    // p=0x7ffee4a342f8
    // *p=6
    g(i);
    // a=3

    return 0;
}

void f(int *p)
{
    printf("p=%p\n", p);
    printf("*p=%d\n", *p);

    // 通过单目运算符 “*” 星号，读写指针 p 的地址对应的变量的值
    *p = *p / 2;
}
void g(int a)
{
    printf("a=%d\n", a);
}