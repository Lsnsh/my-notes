#include <stdio.h>

int main()
{
    int i;
    scanf("%d", i);

    // warning: format specifies type 'int *' but the argument has type
    //   'int' [-Wformat]
    // scanf("%d", i);
    // [1]    75071 segmentation fault
}