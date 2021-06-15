# 循环控制

## 多重循环

### 素数

- 只能被 1 和自己整数的数，不包括 1
  - 2,3,5,6,11,13,17,19

```c++
#include <stdio.h>

int main()
{
    int x;
    printf("请输入数字：");
    scanf("%d", &x);

    int i, isPrimeNumber = 1;
    if (x == 1)
    {
        isPrimeNumber = 0;
    }

    for (i = 2; i < x; i++)
    {
        // 能被1和自己以外的数整除的数，就不是素数
        if (x % i == 0)
        {
            isPrimeNumber = 0;
            break;
        }
    }

    if (isPrimeNumber == 1)
    {
        printf("是素数\n");
    }
    else
    {
        printf("不是素数\n");
    }

    return 0;
}
```

### break vs continue

- break 跳出循环
- continue 停止执行剩下的语句，跳过循环这一轮，进入下一轮循环

### 100 以内的素数

- 如何写程序输出 100 以内的素数？

```c++
#include <stdio.h>

int main()
{
    int x;

    // 100以内的素数
    for (x = 2; x < 100; x++)
    {
        int i, isPrimeNumber = 1;

        for (i = 2; i < x; i++)
        {
            // 能被1和自己以外的数整除的数，就不是素数
            if (x % i == 0)
            {
                isPrimeNumber = 0;
                break;
            }
        }

        if (isPrimeNumber == 1)
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
```

### 前 50 个素数

```c++
#include <stdio.h>

int main()
{
    int x = 2, count = 0;

    // 前50个素数
    while (count < 50)
    {
        int i, isPrimeNumber = 1;

        for (i = 2; i < x; i++)
        {
            // 能被1和自己以外的数整除的数，就不是素数
            if (x % i == 0)
            {
                isPrimeNumber = 0;
                break;
            }
        }

        if (isPrimeNumber == 1)
        {
            printf("%d ", i);
            count++;
        }
        x++;
    }

    printf("\n");

    return 0;
}
```

### 凑硬币

- 如何用 1 角、2 角和 5 角的硬币凑出 10 元以下的金额呢？

```c++
#include <stdio.h>

int main()
{
    int x;
    printf("请输入10元以内的金额：");
    scanf("%d", &x);

    int one, two, five;

    // 将元转换为角，然后循环
    for (one = 1; one < x * 10; one++)
    {
        for (two = 1; two < x * 10 / 5; two++)
        {
            for (five = 1; five < x * 10 / 2; five++)
            {
                if (one + two * 2 + five * 5 == x * 10)
                {
                    printf("%d个1角+%d个2角+%d个5角=%d元\n", one, two, five, x);
                }
            }
        }
    }

    return 0;
}
```

### break 接力 vs goto

- 更新标记后，由内往外逐层 break，得以跳出多层循环

```c++
int exit = 0;

for (...)
{
    for (...)
    {
        for (...)
        {
            if (...) {
                exit = 1;
                break;
            }
        }
        if (exit == 1) {
            break;
        }
    }
    if (exit == 1) {
        break;
    }
}
```

- goto 关键词，让程序跳转到某处执行，得以跳出多层循环

```c++
int exit = 0;

for (...)
{
    for (...)
    {
        for (...)
        {
            if (...) {
                goto out;
            }
        }
    }
}

out:;

return 0;
```

## 循环应用

### 前 n 项求和

```c++
// f(n)=1 + 1/2 + 1/3 + ... + 1/n;
#include <stdio.h>

int main()
{
    int x, i;
    double sum = 0.0;

    printf("n=");
    scanf("%d", &x);

    for (i = 1; i <= x; i++)
    {
        sum += 1.0 / i;
    }

    printf("f(%d)=%f\n", x, sum);

    return 0;
}
```

### 求最大公约数

- 输入两个数，输出它们的最大公约数
- 输入：12 18
- 输出：6

#### 枚举

#### 辗转相除法

1. 如果 b 等于 0，计算结束，a 就是最大公约数
2. 否则，计算 a 除以 b 的余数，让 a 等于 b，而 b 等于那个余数
3. 回到第一步

```c++
// 辗转相除法
#include <stdio.h>

int main()
{
    int a, b, t;

    scanf("%d %d", &a, &b);
    printf("%d和%d的最大公约数=", a, b);

    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }

    printf("%d\n", a);

    return 0;
}
```

### 整数分解

- 输入一个非负整数，正序输出它的每一位数字
- 输入：13425
- 输出：1 3 4 2 5

```c++
// 整数分解（五位数整数）
#include <stdio.h>

int main()
{
    int x, d;
    printf("请输入一个非负整数，x=");
    scanf("%d", &x);

    int t = x;
    int mask = 1;

    while (t > 9)
    {
        t = t / 10;
        mask = mask * 10;
    }

    // printf("%d\n", mask);

    while (mask > 0)
    {
        d = x / mask;
        x = x % mask;
        mask = mask / 10;

        printf("%d", d);
        if (mask > 0)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}
```
