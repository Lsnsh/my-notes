# 数组运算

## 数组的集成初始化

- 直接用大括号给出的数组的所有元素作为初始值
- 不需要给出数组的大小，编译器替我们数

```c++
int a[] = {1,2,3,4,5,};
```

- 数组的成员默认会被初始化为 0

```c++
int a1[5] = {1};
// 等价于
int a2[5] = {1,0,0,0,0,};
```

- 集成初始化时的定位
  - 用 \[n\] 在初始化数据中给出定位
  - 没有定位的数据紧接在前面定位数据的后面
    - 举例：下面例子中的 4 的索引值是 3，因为是跟在 \[2\] = 3 的后面
  - 其他位置的值补零
  - 也可以不给出数组的大小，让编译器数
  - 特别适合初始数据稀疏、或者存在个别特殊值的数组

```c++
int b1[5] = {
    [0] = 1, [2] = 3, 4,
};
// 等价于
int b2[5] = {1,0,3,4,0,};
```

## 数组的大小

- sizeof 方法
  - 给出整个数组所占据的内容的大小，单位是字节
  - int 数组长度 = sizeof(数组) / sizeof(数组\[0\]);
- sizeof(数组\[0\]) 给出数组中单个元素的大小，于是相除就得到来数组中单元的个数
- 这样的代码，即使就该数组中初始的数据，也不需要修改后续遍历的代码

```c++
#include <stdio.h>

int main()
{
    int a[] = {
        1,
        2,
        3,
        4,
        5,
    };
    int i, length = sizeof(a) / sizeof(a[0]);

    printf("length=%d\n", length);

    for (i = 0; i < length; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }

    return 0;
}
```

## 数组的赋值

- 数组变量本身不能被赋值
  - 涉及到指针的知识，后面会讲
- 想要拷贝数组，必须采用遍历的方式

```c++
int a[] = {1,2,3,4,5,};
int b[] = a;
```

## 数组作为参数

- 数组作为函数参数时，必须再用另外一个参数来传入数组的大小
  - 不能在 int a[] 的 [] 中给出数组的大小
  - 不能利用 sizeof 方法来计算数组的元素个数
  - 涉及到指针的知识，后面会讲

```c++
#include <stdio.h>

void iterate(int a[], int length);

int main()
{
    int a[] = {
        1,
        2,
        3,
        4,
        5,
    };
    int length = sizeof(a) / sizeof(a[0]);

    iterate(a, length);

    return 0;
}

void iterate(int a[], int length)
{
    int len = sizeof(a) / sizeof(a[0]);
    printf("len=%d\n", len);
    // warning: 'sizeof (a)' will return the size of the pointer, not the array
    //   itself [-Wsizeof-pointer-div]
    // 输出的大小是指针的大小，而不是数组的大小
    // 输出：len=2

    int i;

    for (i = 0; i < length; i++)
    {
        printf("a[%d]=%d\n", i, a[i]);
    }
}
```

## 数组和素数表

**构造素数表**的四种方式：

1. 从 2 到 x-1 检查是否可以整除
2. 去掉偶数后，从 3 到 x-1，每次加 2
   - for (i = 3; i < x; i+=2)
3. 无须到 x-1，到 sqrt(x) 就够了
   - for (i = 3; i < sqrt(x); i+=2)
4. 判断是否能被已知的且 < x 的素数整除

**方式四：判断是否能被已知的且 < x 的素数整除：**

- 构造 n 以内的素数表
  - 令 x 为 2
  - 将 2 倍，3 倍，4 倍直至 (n 倍的 x) < n 的数标记为非素数
  - 令 x 为下一个没有标记为非素数的数，重复步骤 2，直到所有的数都检查完。
- 伪代码：
  - 开辟数组 prime\[n\]，初始化其所有元素为 1，prime\[x\] 为 1 表示 i 是素数
  - 令 x 为 2
  - 如果 x 是素数，满足 (i=2; i \* x < n; i++) 时，令 prime[i \* x] 为 0
  - 令 x++，如果 x < n，重复步骤 3，否则结束

```c++
#include <stdio.h>

int main()
{
    const int LENGTH = 100;
    int isPrime[LENGTH];
    int i, x;

    // 初始化数组
    for (i = 0; i < LENGTH; i++)
    {
        // 默认情况下 i 都先标记为 1，即是素数
        isPrime[i] = 1;
    }

    for (x = 2; x < LENGTH; x++)
    {
        if (isPrime[x])
        {
            for (i = 2; i * x < LENGTH; i++)
            {
                // 标记为0，即非素数
                isPrime[i * x] = 0;
            }
        }
    }

    for (i = 2; i < LENGTH; i++)
    {
        if (isPrime[i])
        {
            // 输出素数
            printf("%d\t", i);
        }
    }

    printf("\n");

    return 0;
}
```

## 搜索

### 线性搜索

**遍历查找：**

```c++
#include <stdio.h>

int search(int x, int arr[], int length);

int main()
{
    int arr[] = {2, 7, 4, 2, 7, 8, 3, 1, 12, 5, 7, 53};
    int x = 1, length = sizeof(arr) / sizeof(arr[0]);

    int index = search(x, arr, length);
    printf("%d 在数组中的位置：%d\n", x, index);

    return 0;
}

int search(int x, int arr[], int length)
{
    int i, ret = -1;
    for (i = 0; i < length; i++)
    {
        if (arr[i] == x)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
```

### 线性查找（使用结构）

- 输入多少美分，输出多少美分的英文：
  - 1, 5, 10, 25, 50 美分对应下面的英文名
  - "penny", "nickel", "dime", "quarter", "half-dollar"

#### 使用两个数组

使用两个数组，人为定义关联关系，来实现：

```c++
// 输入多少美分，输出多少美分的英文
#include <stdio.h>

int search(int x, int arr[], int length);

int main()
{
    int arr[] = {1, 5, 10, 25, 50};
    char *name[] = {"penny", "nickel", "dime", "quarter", "half-dollar"};
    int x = 1, length = sizeof(arr) / sizeof(arr[0]);

    printf("请输入美分：");
    scanf("%d", &x);

    int index = search(x, arr, length);
    char *word = "unknown";
    if (index != -1)
    {
        word = name[index];
    }
    printf("%d 美分对应的英文是：%s\n", x, word);

    return 0;
}

int search(int x, int arr[], int length)
{
    int i, ret = -1;
    for (i = 0; i < length; i++)
    {
        if (arr[i] == x)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
```

#### 使用结构

使用结构（struct 关键词）的概念，来实现不同类型的数据互相建立关联关系：

```c++
// 输入多少美分，输出多少美分的英文
#include <stdio.h>

struct CoinType
{
    int amount;
    char *name;
};
struct CoinType search(int x, struct CoinType coins[], int length);

int main()
{
    struct CoinType coins[] = {
        {1, "penny"},
        {5, "nickel"},
        {10, "dime"},
        {25, "quarter"},
        {50, "half-dollar"},
    };
    int x = 1, length = sizeof(coins) / sizeof(coins[0]);

    printf("请输入美分：");
    scanf("%d", &x);

    struct CoinType coin = search(x, coins, length);
    char *name = "unknown";

    if (coin.name)
    {
        name = coin.name;
    }
    printf("%d 美分对应的英文是：%s\n", x, name);

    return 0;
}

struct CoinType search(int x, struct CoinType coins[], int length)
{
    int i;
    struct CoinType ret;

    for (i = 0; i < length; i++)
    {
        if (coins[i].amount == x)
        {
            ret = coins[i];
            break;
        }
    }

    return ret;
}
```

### 二分查找

时间复杂度：log 以 2 为底，n 的对数

- 100 个数最多查找 7 次
- 1000 个数，最多查找 10 次
- 10000 个数，最多查找 14 次
- ...

```c++
#include <stdio.h>

int binarySearch(int k, int arr[], int length);

int main()
{
    int arr[] = {2, 4, 7, 11, 13, 16, 21, 24, 27, 32, 36, 40, 46};
    int length = sizeof(arr) / sizeof(arr[0]) - 1;

    int k;
    printf("请输入要查找的数：");
    scanf("%d", &k);

    int index = binarySearch(k, arr, length);

    printf("%d 在数组中的位置：%d\n", k, index);

    return 0;
}

int binarySearch(int k, int arr[], int length)
{
    int ret = -1;

    int left = 0, right = length - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        printf("%d, %d, %d\n", left, right, mid);

        if (arr[mid] == k)
        {
            ret = mid;
            break;
        }
        else if (arr[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ret;
}
```

### 选择排序

- 遍历数组，找到数组中最大的值，移动到数组的右边
- 查找范围，向左收缩，因为遍历一次就确定了这一轮最大数的位置
- 重复第一步，第二步，直到查找范围里只有一个数

```c++
#include <stdio.h>

int * selectionSort(int arr[], int length);

int main()
{
    int arr1[] = {2, 45, 6, 12, 87, 34, 90, 24, 23, 11, 65};
    int i, length = sizeof(arr1) / sizeof(arr1[0]);

    printf("排序前：");
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    int *arr2 = selectionSort(arr1, length);

    printf("排序后：");
    for (i = 0; i < length; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}

int * selectionSort(int arr[], int length)
{
    int *retArr = arr;
    int i, j;

    for (i = length - 1; i > 0; i--)
    {
        // 内存循环：找剩余区间内最大的值，然后移到右边
        int maxIndex = 0;
        for (j = 1; j <= i; j++)
        {
            if (retArr[j] > retArr[maxIndex])
            {
                maxIndex = j;
            }
        }

        // 交换位置，移到右边
        int t = retArr[i];
        retArr[i] = retArr[maxIndex];
        retArr[maxIndex] = t;
    }

    return retArr;
}
```
