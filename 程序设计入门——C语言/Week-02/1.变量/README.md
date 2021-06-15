# 变量

## 算找零

如何能在程序运行时输入那个数字 23，然后计算输出结果？

```
printf("100-23=%d", 100-23);
```

需要：

- 有地方放输入的数字
- 有办法输入数字
- 输入的数字能参与计算

### 如何输入

- 输入也是在终端中
- 输入以行为单位进行的，行的结束标志就是你按下了回车键。在你按下回车键之前，你的程序不会读到任何东西

## 如何定义一个变量

```c++
#include <stdio.h>

int main()
{
    int price = 0;

    printf("请输入金额（元）：");
    scanf("%d", &price);

    int change = 100 - price;

    printf("找您%d元。\n", change);

    return 0;
}
```

- int price = 0;
- 这一行，定义了一个变量。变量名字是 price，类型是 int，初始值是 0
- 变量是一个保存数据的地方，当我们需要在程序里保存数据时，比如上面的例子中要记录用户输入的价格，就需要一个变量来保存它。用一个变量保存了数据，它才能参加到后面的计算中，比如计算找零。

### 变量定义

- 变量定义的一般形式就是：
  - <类型名称> <变量名称>
- int price;
- int price, amount;
- float change;

### 变量的名字

- 变量需要一个名字，变量的名字是一种“标识符”，意思是它用来识别这个和那个的不同的名字。
- 标识符有标识符的构造规则。基本的原则是：标识符只能由字母、数字和下划线组成，数字不可以出现在第一个位置上，C 语言的关键字（有的地方叫它们保留字）不可以用做标识符。

## 赋值和初始化

```c++
int price = 0;

printf("请输入金额（元）：");
scanf("%d", &price);

int change = 100 - price;

printf("找您%d元。", change);
```

- int price = 0;
- 这一行。定义了一个变量。变量的名字是 price，类型是 int，初始值是 0。
- price = 0 是一个式子，这里的“=”是一个赋值运算符，表示将“=”（等号）右边的值赋值给左边的变量。

### 赋值

- 和数学不同，a=b 在数学中表示关系，即 a 和 b 的值一样；
- 而在程序设计中。a=b 表示要求计算机做一个动作：将 b 的值赋值给 a；
- 关系是静态的，而动作是动态的；
- 在数学中，a=b 和 b=a 是等价的，而在程序设计中，两者的意思完全相反。

### 初始化

- 当赋值发生在定义变量的时候，就像程序中的这句：int price = 0;，就是变量的初始化；
- 虽然在 C 语言中没有强制要求所有的变量都在定义的地方做初始化，但是所有的变量在第一次被使用（出现在赋值运算符的右边）之前应该被赋值一次；

如果没有初始化，会怎么样？

```c++
#include <stdio.h>

int main()
{
    int i;
    int j;

    j = i + 10;
    printf("%d\n", j); // 输出（一长串的数字）：120328239

    i = 2; // 初始化
    j = i + 10;
    printf("%d\n", j); // 输出：12

    return 0;
}
```

- 定义了 i，但是没有初始化，此时 i 的值是原有内存地址上存放的值，所以在运算输出后，会得到奇怪的结果
- 初始化 i 后，运算得到的结果，就是符合我们预期的结果了

#### 变量初始化

- <类型名称> <变量名称> = <初始值>;
  - int price = 0;
  - int amount = 100;
- 组合变量定义的时候，也可以在这个定义中单独给单个变量赋初值，如：
  - int price = 0, amount = 100;

### 变量类型

- int price = 0;
- 这一行，定义了一个变量。变量的名字是 price，类型是 int，初始值是 0
- C 是一种有类型的语言，所有的变量在使用之前必须定义或声明，所有的变量必须具有确定的数据类型。数据类型表示在变量中可以存放什么样的数据，变量中只能存放指定类型的数据，程序运行过程中也不能改变变量的类型。

## 第二个变量

- int change = 100 - price;
- 定义了第二个变量 change
- 并且做了计算

备注：C99 之后允许在任何地方定义变量，只要这个变量定义出现第一次使用之前就可以。

### ANSI C

- 只能在代码开头的地方定义变量

```c++
int price = 0;
int change = 0;

printf("请输入金额（元）：");
scanf("%d", &price);

change = 100 - price;

printf("找您%d元。\n", change);
```

## 读整数

- scanf("%d", &price);
- 要求 scanf 这个函数读入下一个整数，读到的结果赋值给变量 price
- 注意 price 前面的&

### 关于 scanf

- 出现在 scanf 里边的内容，是一定要输入的内容，以满足特定的匹配规则，这样才能从输入的内容中取到特定位置的值

```c++
#include <stdio.h>

int main()
{
    int a = 0, b = 0;

    scanf("a=%d, b=%d", &a, &b);
    printf("%d, %d\n", a, b);

    return 0;
}
```

### scanf 出错

- 这是变量未初始化的情况，没有处理 scanf 输入的值导致的

```c++
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
```

## 常量 VS 变量

- int change = 100 - price;
- 固定不变的数，是常量。直接卸载程序里，我们称作直接量（literal）。
- 更好的方式，是定义一个常量：
  - const int AMOUNT = 100;

```c++
#include <stdio.h>

int main()
{

    const int AMOUNT = 100; // C99 的写法
    int price = 0;

    printf("请输入金额（元）：");
    scanf("%d", &price);

    int change = AMOUNT - price;

    printf("找您%d元。\n", change);

    return 0;
}
```

### const

- const 是一个修饰符，加在 int 的前面，用来给这个变量加上一个 const（不变的）的属性。这个 const 的属性表示这个变量的值一旦初始化，就不能在修改了。
  - int change = AMOUNT - price;
- 如果你试图对常量做修改，把它放在赋值运算符的左边，就会被编译器发现，指出为一个错误。
  - AMOUNT = 90;
  - error: cannot assign to variable 'AMOUNT' with const-qualified type 'const int'
