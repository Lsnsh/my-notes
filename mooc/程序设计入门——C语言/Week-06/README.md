# 数组与函数

## 数组

数据可以存放在变量里，每一个变量有一个名字，有一个类型，还有它的生存空间。如果我们需要保存一些相同类型、相似含义、相同生存空间的数据，我们可以用数组来保存这些数据，而不是用很多个独立的变量。数组是长度固定的数据结构，用来存放指定的类型的数据。一个数组里可以有很多个数据，所有的数据的类型都是相同的。

### 定义数组

- <类型> 变量名称\[元素数量\]
  - int grades\[100\];
  - double weight\[20\];
- 元素数量必须是整数
- C99 之前：元素数量必须是编译时刻确定的字面量

### 数组的特点

- 是一种容器（放东西的东西），特点是：
  - 其中所有的元素具有相同的数据类型
  - 一旦创建，不能改变大小
  - 数组中的元素在内存中是连续依次排列的
- int a\[10\];
  - 一个 int 的数组
  - 10 个单元：a\[0\],a\[1\],...,a\[9\]
  - 每个单元即使一个 int 类型的变量
  - 可以出现在赋值符号的左边或右边
    - a\[2\] = a\[1\] + 6;
  - 在赋值符号左边的叫做左值

### 数组的单元

- 数组的每个单元就是数组类型的一个变量
- 使用数组时放在\[\]中的数字叫做下标或索引，下标从 0 开始计算，一直到 n-1
  - a\[0\]
  - a\[9\]

### 有效的下标范围

- 编译器和运行环境都不会检查数组下标是否越界，无论是对数组单元做读还是写操作
- 一旦程序运行，越界的数组访问可能造成问题，导致程序崩溃
  - segmentation fault
- 但是也可能运气好，没造成严重的后果
- 所以这是程序猿的责任，需要保证程序只使用有效的下标值：\[0，数组的大小 -1\]

### 长度为 0 的数组

- int a\[0\];
- 可以存在，但是无用

### 计算平均数

- 如何写出一个程序计算用户输入的数字的平均数，并输出所有大于平均数的数？

```c++
// 计算平均数，并输出大于平均数的数有哪些
#include <stdio.h>

int main()
{
    int x = 0,  count = 0;
    double sum = 0.0, avg = 0.0;
    int number[100];

    scanf("%d", &x);

    while (x != -1)
    {
        number[count] = x;

        sum += x;
        count++;

        scanf("%d", &x);
    }

    if (count > 0)
    {
        avg = sum / count;
        printf("平均数是：%f\n", avg);

        printf("大于平均数的数有：");
        for (int i = 0; i < count; i++)
        {
            if (number[i] > avg)
            {
                printf("%d ", number[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
```

上述程序存在的问题：

- 因为用户输入的数据可能超过 100 个
  - 可以让用户先决定要输入多少个数，然后再去初始化数组

### 用数组做散列计算

- 写一个程序，输入数量不确定的的\[0,9\]范围内的整数，统计每一种数字出现的次数，输入-1 表示结束。

```c++
#include <stdio.h>

int main()
{
    const int LENGTH = 10;
    int count[LENGTH], x, i;

    for (i = 0; i < LENGTH; i++)
    {
        count[i] = 0;
    }

    scanf("%d", &x);
    while (x != -1)
    {
        if (x >= 0 && x <= 9)
        {
            count[x]++;
        }
        scanf("%d", &x);
    }

    for (i = 0; i < LENGTH; i++)
    {
        printf("%d的个数是：%d\n", i, count[i]);
    }
    return 0;
}
```

### 二维数组

- int a\[3\]\[5\];
- 通常理解 a 是一个 3 行 5 列的矩阵

二维数组的初始化：

```c++
int a[][5] = {
    {0,1,2,3,4},
    {2,3,4,5,6},
};

// 一维的写法，因为在内存中是按顺序排列的，实际表示的是二维数组
int b[][5] = {
    0,1,2,3,4,
    2,3,4,5,6,
}
```

- 列数是必须给出的，行数可以由编译器来数
- 每一行一个 {}，用逗号分隔
- 最后的逗号可以存在，有古老的传统
- 如果 {} 内的值省略，表示补零

## 函数

### 什么是函数？

- 函数是一块代码，接受领个或者多个参数，做一件事，并返回领个或一个值
- 可以现象成数学中的函数：
  - y = f(x)

### 井字棋游戏

- 检查目前棋盘的胜负情况

### 函数定义和使用

- void sum(int begin, int end) { //... }
- \[返回值类型\] 函数名(参数表) { 函数体 }
- 调用函数
  - 函数名(参数)
  - () 起到来表示函数调用的重要作用
    - 即使没有参数也需要 ()
  - 如果有参数，则需要给出正确的数量和顺序
  - 这些只会被按照顺序，依次用来初始化函数中的参数
    - sum(1, 10);
- 函数返回
  - return 1;
  - 函数知道每一次是哪里调用它，执行完之后，会返回到正确的地方
  - 没有返回值的函数
    - void 函数名(参数表)
    - 不能使用带值的 return
      - 可以没有 return
    - 调用的时候不能做返回值的赋值

### 求素数

```c++
// 求100以内的素数
#include <stdio.h>

// 是否是素数
int isPrimeNumber(int x)
{
    int i, ret = 1;
    for (i = 2; i < x; i++)
    {
        // 能被1和自己以外的数整除的数，就不是素数
        if (x % i == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

int main()
{
    int x;

    for (x = 2; x < 100; x++)
    {
        if (isPrimeNumber(x) == 1)
        {
            printf("%d ", x);
        }
    }

    printf("\n");

    return 0;
}
```

### 求和

- 求出 1 到 10、20 到 30、35 到 45 的三个区间和

```c++
#include <stdio.h>

int sum(int begin, int end)
{
    int i, ret = 0;
    for (i = begin; i < end; i++)
    {
        ret += i;
    }
    return ret;
}

int main()
{
    int sum3 = sum(1, 10) + sum(20, 30) + sum(35, 45);

    printf("1 到 10、20 到 30、35 到 45 的三个区间的和是：%d\n", sum3);

    return 0;
}
```

### 素数求和

### 函数的参数和变量

#### 函数的先后关系

- 先定义，后使用，否则会报错
- C 的编译器自上而下顺序分析你的代码

```c++
//  error: implicit declaration of function 'sum' is invalid in C99
//       [-Werror,-Wimplicit-function-declaration]
//     int sum3 = sum(1, 10) + sum(20, 30) + sum(35, 45);

#include <stdio.h>

int main()
{
    int sum3 = sum(1, 10) + sum(20, 30) + sum(35, 45);

    printf("1 到 10、20 到 30、35 到 45 的三个区间的和是：%d\n", sum3);

    return 0;
}

int sum(int begin, int end)
{
    int i, ret = 0;
    for (i = begin; i < end; i++)
    {
        ret += i;
    }
    return ret;
}
```

#### 函数原型

- 函数头，以分号“;”结尾，就构成了函数的原型
- 函数原型的目的是告诉编译器，这个函数长什么样子
  - 名称
  - 参数（数量及类型）
    - 参数名，可以不一样，甚至不设置
      - int sum(int, int);
  - 返回类型
- 旧标准下习惯把函数原型写在调用它的函数里面
- 现在一般写在调用它的函数前面
- 函数定义

```c++
#include <stdio.h>

// 函数原型
int sum(int begin, int end);

int main()
{
    int sum3 = sum(1, 10) + sum(20, 30) + sum(35, 45);

    printf("1 到 10、20 到 30、35 到 45 的三个区间的和是：%d\n", sum3);

    return 0;
}

// 函数定义
int sum(int begin, int end)
{
    int i, ret = 0;
    for (i = begin; i < end; i++)
    {
        ret += i;
    }
    return ret;
}
```

#### 参数传递

- 如果函数有参数，调用函数时必须传递给它数量、类型正确的值
- 可以传递给函数的值是表达式的结果，这包括：
  - 字面量
    - sum(1, 10);
  - 变量
    - sum(1, a);
  - 函数的返回值
    - sum(1, sum(1, 10));
  - 计算的结果
    - sum(1, 2 + 3);
- 传递的参数与定义的函数参数不匹配会怎样？
  - 调用函数时给的值与参数的类型不匹配是 C 语言传统上最大的“漏洞”
  - 编译器会悄悄替你把类型转换好，但是这很可能不是你所期望的
  - 后续的语言，比如 C++/Java 在这方面做的很严格

```c++
#include <stdio.h>

void foo(int num)
{
    printf("%d\n", num);
}

int main()
{
    double n1 = 2.0;
    foo(n1); // 输出：2

    double n2 = 2.4;
    foo(n2); // 输出：2

    foo(2.0); // 输出：2

    foo(2.4);
    // 输出警告信息：warning: implicit conversion from 'double' to 'int' changes value from 2.4
    //   to 2 [-Wliteral-conversion]
    // 然后输出：2

    return 0;
}
```

- 传值（参数和值）：
  - C 语言在调用函数时，永远只能传值给函数
  - 每个函数有自己的变量空间，参数也位于这个独立的空间中，和其中函数没有关系
  - 过去：对胡函数参数表中的参数，叫做“形式参数”，调用函数时给 i 的值，叫做“实际参数”
  - 由于容易让初学者误会实际参数就是实际在函数中进行计算的参数，误会调用函数的时候把变量而不是值传进去了，所以我们不建议继续用这种古老的方式来称呼它们
  - 我们认为，它们是参数和值的关系
    - void swap(int a, int b);
      - a 和 b 是参数
    - swap(5, 6);
      - 5 和 6 是值

```c++
#include <stdio.h>

// 交换值
void swap(int a, int b);

int main()
{
    int a = 5, b = 6;

    swap(a, b);

    // a 和 b 的值并没有被交换
    // 输出：main: a=5, b=6
    printf("main: a=%d, b=%d\n", a, b);

    return 0;
}

void swap(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;

    // 函数内参数 a 和 参数 b的值，交换成功，并不会影响外部调用函数的值
    // 输出：main: a=5, b=6
    printf("swap: a=%d, b=%d\n", a, b);
}
```

#### 本地变量

- 函数的每次运行，就产生了一个独立的变量空间，在这空间的变量，是函数的这次运行所独有的，称作本地变量/局部变量
- 定义在函数内部的变量就是本地变量
- 参数也是本地变量

变量的生存期和作用域：

- 生存期：什么这个变量开始出现了，到什么时候它消亡了
- 作用域：在（代码的）一定范围内可以访问这个变量（这个变量可以起作用）
- 对于本地变量，这两个问题的答案是同意的：“{}”大括号内——快

本地变量的规则：

- 本地变量是定义在块内的
  - 它可以是定义在函数的块内
  - 也可以定义在语句的块内
  - 甚至可以随便拉一对大括号来定义变量
- 程序运行进入这个块之前，其中的变量不存在，离开这个块，其中的变量就消失了
- 块外面定义的变量在里面仍然有效
- 块里面定义了和外面同名的变量则掩盖了来外面的变量
- 不能在一个块内定义同名的变量
- 本地变量不会被默认初始化
- 参数在进入函数前就被初始化来

#### 其他

函数定义时，没有参数：

- void f(void);
  - 建议
- void f();
  - 不建议
  - 在传统 C 中，它表示函数的参数是未知的，并不表示没有参数

逗号运算符：

- f(a,b);
  - 没有用到逗号运算符
  - 调用函数时的括号里的逗号是标点符号，不是运算符
- f((a,b));
  - 有用到逗号运算符
  - 调用函数时，第二层括号是运算符，结果就是传入参数 b

函数里定义其他的函数：

- C 语言不允许函数的嵌套定义
  - 最多只可以放函数的声明

关于 main：

- int main() 也是一个函数
- 要不要写成 int main(void) ?
- return 的 0 有人看到吗？
  - Windows: if error level 1 ...
  - Unix Bash: echo %?
  - csh: echo $status
