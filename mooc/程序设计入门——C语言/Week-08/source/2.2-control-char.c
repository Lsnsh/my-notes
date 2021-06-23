// \b - BackSpace
#include <stdio.h>

int main()
{
    printf("123\b\n456\n");
    // 123
    // 456

    printf("123\bA\n456\n");
    // 12A
    // 456

    return 0;
}