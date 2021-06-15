#include <stdio.h>
#include <string.h>

int main()
{
    // char a[20] = "cehiknqtw";
    // char *s = "fbla", *p;
    // int i, j;

    // p = s;

    // printf("%c\n", *p);

    // for (p = s; *p; p++)
    // {
    //     j = 0;
    //     while (*p >= a[j] && a[j] != '\0')
    //         j++;
    //     for (i = strlen(a); i >= j; i--)
    //         a[i + 1] = a[i];
    //     a[j] = *p;
    // }
    // printf("%s", a);
    // abcefhiklnqtw
    
    // cehiknqtw

    char s1[] = "I Love GPLT";
    int length = strlen(s1);

    for (int i = 0; i < length; i++) {
        printf("%c\n", s1[i]);
    }

    return 0;
}