#include <stdio.h>

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);

    return 0;
}

// 输入；hello
// 输出：280395813 + 32766 = 280428579
// 注意：这是变量未初始化的情况，因此需要处理 scanf 输入的值