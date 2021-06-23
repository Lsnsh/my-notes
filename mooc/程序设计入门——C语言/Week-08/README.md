# 指针与字符串

## 指针

### 取地址运算

& 运算符取得变量的地址

#### 运算符 &

sizeof：

- 是一个方法

scanf 里的 &：

- 获取变量的地址，它的操作数必须是变量
  - int i; printf("%x", &i);
- 地址的大小是否与 int 相同取决于编译器
  - int i; printf("%p", &i);
    - 显示地址，使用 %p 而不是 %x
  - 在 32 位上，地址的大小和 int 相同，都是 4 个字节
  - 而 64 位上，地址的大小是 8 个字节，int 是 4 个字节

```c++
#include <stdio.h>

int main()
{
    int i;

    printf("%x\n", (int)&i);
    // ee34a308
    printf("%p\n", &i);
    // 0x7ffeee34a308

    printf("%lu\n", sizeof(int));
    // 4
    printf("%lu\n", sizeof(&i));
    // 8

    return 0;
}
```

- 不能取的地址，非变量
  - &(a+b)
  - &(a++)
  - &(++a)
- 尝试取一下这些情况的地址
  - 变量的地址
  - 相邻变量的地址
  - 数组的地址
  - 数组单元的地址
  - 相邻的数组单元的地址

```c++
#include <stdio.h>

int main()
{
    int i;
    int p;

    printf("%p\n", &i);
    // 0x7ffee83f62d8
    printf("%p\n", &p);
    // 0x7ffee83f62d4

    // 栈，自底向上，存放变量，从输出的地址可以看出：
    // 变量 i 在 变量 p 的上面

    int a[10];

    printf("%p\n", &a);
    // 0x7ffee83f62e0
    printf("%p\n", a);
    // 0x7ffee83f62e0
    printf("%p\n", &a[0]);
    // 0x7ffee83f62e0
    printf("%p\n", &a[1]);
    // 0x7ffee83f62e4

    // 数组和数组第一个成员的地址都是一样的，每个数组单元之间间隔4个字节

    return 0;
}
```

### 指针变量

指针变量就是记录地址的变量

- 变量的值是内存的地址
  - 普通变量的值是实际的值
  - 指针变量的值是具有实际值的变量的地址

#### scanf

- 如果能够将取得的变量的地址传递给一个函数，能否通过这个地址在那个函数内访问这个变量
  - scanf("%d", &i);
- scanf() 的原型应该是怎样的？我们需要一个参数能保存别的变量的地址，如果表达能够保存地址的变量？

- 指针，就是保存地址的变量
  - int i;
  - int\* p = &i;
- 定义指针变量，需要用到 “\*” 星号
  - int\* p, q;
    - 表示定义一个指针 p 变量，定义一个 int 类型的 q 变量
  - int \*p, q;
    - 和上面一样，表示定义一个指针 p 变量，定义一个 int 类型的 q 变量

#### 作为参数的指针

- void f(int \*p);
- 在被调用的时候得到了某个变量的地址：
  - int i = 0; f(&i);
- 在函数里面可以通过这个指针访问外面这个 i

#### 访问那个地址上的变量\*：

- \* 是一个单目运算符，用来访问指针的值所表示的地址上的变量
- 可以做友值也可以做左值
  - int k = \*p;
  - \*p = k + 1;

```c++
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
```

#### 传入地址

- 为什么
  - int i; scanf("%d", i);
- 编译器没有报错？
  - scanf 函数以为读进来的数字，是表示地址的数字
  - 所以会将输入的值写入到这个数字对应的地址上，写到了不该写的地方
- 编译不一定报错，但是运行一定会出错

```c++
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
```

### 指针与数组

为什么数组传进函数后 sizeof 的值不对了。传入函数的数组成了什么？

- 函数参数表中的数组实际上是指针
  - sizeof(arr) === sizeof(int \*);
- 但是可以用数组的运算符 [] 进行运算

#### 数组参数

- ，以下四种函数原型是等价的：
  - int sum(int \*arr, int n);
  - int sum(int \*, int);
  - int sum(int arr[], int n);
  - int sum(int [], int);

#### 数组变量是特殊的指针

- 数组变量本身表达地址，所以
  - int a[10]; int \*p = a; // 无需用 & 取地址
  - 但是数组的单元表达的是变量，需要用 & 取地址
  - a == &a[0];
- [] 运算符可以对数组做，也可以对指针做：
  - p[0] <==> a[0]
- \* 运算符可以对指针做，也可以对数组做：
  - \*a = 25;
    - 等价于：a[0] = 25;
- 数组变量是常量（const）指针，所以不能被赋值：
  - int a[] = {1}; <==> int \* const a = {1};

```c++
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    printf("arr=%p\n", arr);
    // arr=0x7ffee142f2f0
    printf("&arr[0]=%p\n", &arr[0]);
    // &arr[0]=0x7ffee142f2f0
    printf("&*arr=%p\n", &*arr);
    // &*arr=0x7ffee142f2f0
    printf("*arr=%d\n\n", *arr);
    // *arr=1

    *arr = 6;

    printf("arr=%p\n", arr);
    // arr=0x7ffee142f2f0
    printf("&arr[0]=%p\n", &arr[0]);
    // &arr[0]=0x7ffee142f2f0
    printf("&*arr=%p\n", &*arr);
    // &*arr=0x7ffee142f2f0
    printf("*arr=%d\n\n", *arr);
    // *arr=6

    int *p = arr;
    printf("p[0]==arr[0]=%d\n", p[0] == arr[0]);
    // p[0]==arr[0]=1

    // arr = 1;
    // error: 表达式必须是可修改的左值

    return 0;
}
```

#### 数组变量和常量指针变量

数组变量是常量指针变量，但常量指针变量不是数组变量：

```c++
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    printf("sizeof(arr)=%lu\n", sizeof(arr));
    // sizeof(arr)=20
    printf("sizeof(*arr)=%lu\n", sizeof(*arr));
    // sizeof(*arr)=4

    int const *p = arr;

    printf("sizeof(p)=%lu\n", sizeof(p));
    // sizeof(p)=8
    printf("sizeof(*p)=%lu\n", sizeof(*p));
    // sizeof(*p)=4

    int *p2;

    printf("sizeof(p2)=%lu\n", sizeof(p2));
    // sizeof(p2)=8

    return 0;
}
```

#### 数组变量和常量指针变量访问-1

数组变量访问越界时（-1），会有警告信息；而指针变量没有。

```c++
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    printf("arr[-1]=%d\n", arr[-1]);
    // warning: array index -1 is before the beginning of the array
    // arr[-1]=0
    printf("arr[0]=%d\n", arr[0]);
    // arr[0]=1
    printf("arr[1]=%d\n", arr[1]);
    // arr[1]=2

    int const *p = &arr[3];

    printf("p[-1]=%d\n", p[-1]);
    // p[-1]=3
    printf("p[0]=%d\n", p[0]);
    // p[0]=4
    printf("p[1]=%d\n", p[1]);
    // p[1]=5

    return 0;
}
```

## 字符类型

- char 是一种整数，也是一种特殊的类型：字符，因为：
  - 是用单引号表示的字符字面量：'a', '1'
  - '' 也是一个字符

### 字符的输入输出

- scanf 和 printf 里用 %c 来输入输出字符
  - 字母等字符对应的整数是 ASCII 表中的整数
    - 比如：'A' 对应的整数是 65
- 如何输入 '1' 这个字符给 char c ?
  - scanf("%c", &c1); --> 1
  - ’1‘ 的 ASCII 编码是 49，所以当 c == 49 时，它代表 '1'
- 49 == '1'; --> 相等
  - 49 可以表示是整数 49，也可以表示是字符 '1'

printf 输出：

```c++
#include <stdio.h>

int main()
{
    char c1, c2;
    c1 = 66, c2 = 'A';

    printf("c1=%d\n", c1);
    // c1=66
    printf("c1=%c\n", c1);
    // c1=B

    printf("c2=%d\n", c2);
    // c2=65
    printf("c2=%c\n", c2);
    // c2=A

    printf("49 == '1'=%d\n", 49 == '1');
    // 49 == '1'=1

    return 0;
}
```

scanf 输入：

```c++
#include <stdio.h>

int main()
{
    char c1, c2;
    int n2;

    printf("赋值给c1，请输入字符：");
    scanf("%c", &c1);
    // 赋值给c1，请输入字符：1
    printf("c1=%d\n", c1);
    // c1=49
    printf("c1='%c'\n", c1);
    // c1='1'

    printf("赋值给n2，请输入整数：");
    scanf("%d", &n2);
    // 赋值给n2，请输入整数：65
    c2 = n2;
    printf("c2=%d\n", c2);
    // c2=65
    printf("c2='%c'\n", c2);
    // c2='A'

    return 0;
}
```

混合输入：

```c++
// scanf %d 和 %c 之间有空格和没空格的区别
#include <stdio.h>

int main()
{
    int i;
    char c1;

    // %d 和 %c 之间有空格
    scanf("%d %c", &i, &c1);
    // 12a
    // 12 a
    printf("i=%d c1=%d c1='%c'\n", i, c1, c1);
    // i=12 c1=97 c1='a'
    // i=12 c1=97 c1='a'

    // %d 和 %c 之间没有空格
    scanf("%d%c", &i, &c1);
    // 12a
    // 12 a
    printf("i=%d c1=%d c1='%c'\n", i, c1, c1);
    // i=12 c1=97 c1='a'
    // i=12 c1=32 c1=' '

    return 0;
}
```

字符计算：

- 一个字符加一个数字得到 ASCII 码表中那个数之后的字符
- 两个字符相减，得到它们在 ASCII 码表中的距离

```c++
#include <stdio.h>

int main()
{
    char c1 = 'a', c2 = 'Z';

    c1++;
    printf("c1=%d\n", c1);
    // c1=98
    printf("c1='%c'\n", c1);
    // c1='b'

    c2 = c2 - 'A';
    printf("c2=%d\n", c2);
    // c2=25
    printf("c2='%c'\n", c2);
    // c2=''

    return 0;
}
```

大小写转换：

- 字母在 ASCII 码表中是顺序排列的
- 大写字母和小写字母是分开排序的，并不在一起
- 'a' - 'A' 可以得到两段之间的距离，于是
  - c1 + ('a' - 'A') 可以把一个大写字母变成小写字母，而
  - c1 - ('a' - 'A') 可以把一个小写字母变成大写字母

```c++
// 大小写转换
#include <stdio.h>

int main()
{
    char c1 = 'A';
    c1 = c1 + ('a' - 'A');

    printf("c1=%d\n", c1);
    // c1=97
    printf("c1='%c'\n", c1);
    // c1='a'

    char c2 = 'a';
    c2 = c2 - ('a' - 'A');

    printf("c2=%d\n", c2);
    // c2=65
    printf("c2='%c'\n", c2);
    // c2='A'

    return 0;
}
```

### 逃逸字符

| 字符 | 含义           |
| ---- | -------------- |
| \b   | 回退一格       |
| \t   | 到下一个表格位 |
| \n   | 换行           |
| \r   | 回车           |
| \"   | 双引号         |
| \'   | 单引号         |
| \\   | 反斜杠本身     |

- 用来表达无法印出来的控制字符或特殊字符，它由一个反斜杠“\”开头，后面跟上另一个字符，这两个字符合起来，组成来一个字符
- printf("请分别输入身高的英尺和英寸，如输入 \"5 7\" 表示 5 英寸 7 英尺：");

\b - BackSpace:

- 表示回退一格
  - 回退一格之后，如果当前行有其他字符输出，会覆盖所在位置应该输出的字符
    - printf("123\bA\n"); --> 12A
  - 回退一格之后，如果当前行没有其他字符输出，不会删除所在位置的字符（某些 Shell 可能会删除）
    - printf("123\b\n"); --> 123

```c++
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
```

\t - Tab Character ：

- 制表位，到下一个表格位
  - 每行固定位置
  - 一个 \t 使得输出从下一个制表位开始
  - 用 \t 才能使得上下两行对其

```c++
// \t - Tab Character
#include <stdio.h>

int main()
{
    printf("123\t456\n");
    // 123     456

    printf("12\t456\n");
    // 12      456

    return 0;
}
```

\n - NextLine：

- 换行，光标到下一行
  - 源自打字机的动作（让“车”的滚筒卷一下）
  - 通常 Shell 会自动补全 \r

\r - Return：

- 回车，光标回到行首
  - 源自打字机的动作（让“车”回到右边）

## 字符串

### 字符数组和字符串

- 字符数组
  - char arr1[] = {'H', 'e', 'l', 'l', 'o', '!'};
  - 不能用字符串的方式做计算
- 字符串
  - char arr2[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
  - 以 0 （整数 0）结尾的一串字符
    - 0 或 ‘\0’ 是一样的，但是和 '0' 不同
  - 0 表示字符串的结束，但它不是字符串的一部分
    - 计算字符串长度的时候不包含这个 0
  - 字符串以数组的形式存在，以数组或指针的形式访问
    - 更多的是以指针的形式
  - string.h 里有很多处理字符串的函数

### 字符串变量

- 定义字符串变量
  - char \*str = "Hello";
  - char word[] = "Hello";
  - char line[10] = "Hello";
- "Hello" 会被编译器变成一个字符数组放在某处，这个数组的长度是 6，结尾还有表示结束的 0
- C 语言的字符串是以字符数组的形式存在的
  - 不能用运算符对字符串做运算
  - 通过数组的方式可以遍历字符串
- 唯一特殊的地方是字符串字面量可以用来初始化字符数组
- 以及标准库中提供来一系列的字符串函数

字符串常量：

- char \*s = "Hello World";
- s 是一个指针，初始化为一个指向字符串的常量
  - 由于这个常量所在的地方，所以实际上 s 是 const char \*s; 但是由于历史的原因，编译器接受不带 const 的写法
  - 但是试图对 s 所指的字符串做「写入」会导致严重的后果
- 如果需要修改字符串，应该用数组：
  - char s[] = "Hello World";

```c++
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
```

指针还是数组，如何选择？

- char word[] = "Hello";
  - 数组：这个字符串在这里
    - 作为本地变量两空间会自动被回收
  - 如果要构造一个字符串 --> 数组
- char \*str = "Hello";
  - 指针：这个字符串不知道在哪里
    - 表达只读的字符串
    - 函数参数，处理参数
    - 动态分配空间
  - 如果要处理一个字符串 --> 指针

char\* 就是字符串？

- 字符串可以表达为 char\* 的形式
- char\* 不一定是字符串
  - 本意是指向字符的指针，可能指向的是字符的数组（就像 int\* 一样）
  - 只有当它所指的字符数组有结尾的 0，才能说它所指的是字符串

## 字符串计算

### 字符串输入输出

- 使用 %s 表示要读入一个字符串
  - char string[8];
  - scanf("%s", string);
  - printf("%s", string);
- scanf 读入一个单词（到空格、tab 或者回车为止）
  - 输出：Hello World
  - 输出：s1=Hello, s2=World
- scanf 是不安全的，因为不知道要读入的内容的长度
  - 输出：12345678 9
  - 输出：s1=12345678, s2=9
    - 以及错误信息：[1] 80205 abort

```c++
#include <stdio.h>

int main()
{
    char s1[8];
    char s2[8];

    scanf("%s", s1);
    scanf("%s", s2);
    // 输入：Hello World

    printf("s1=%s, s2=%s\n", s1, s2);
    // 输出：s1=Hello, s2=World

    return 0;
}
```

安全的输入：

- 使用 %7s 表示要读入一个长度最长为 7 的字符串
  - char string[8];
  - scanf("%7s", string);
- 在 % 和 s 之间的数字表示最多允许读入的字符的数量，这个数字应该比字符串数组的大小小一
  - 因为字符串数组的末尾有一个结尾 0
  - 那下一次 scanf 从哪里开始？

```c++
// 安全的输入
#include <stdio.h>

int main()
{
    char s1[8];
    char s2[8];

    scanf("%7s", s1);
    scanf("%7s", s2);
    // 输入：123456789abcdefgh

    printf("s1=%s, s2=%s\n", s1, s2);
    // 输出：s1=1234567, s2=89abcde

    return 0;
}
```

常见的错误：

- 指针变量没有初始化
  - char \*string;
  - scanf("%s", string);
  - 以为 char\* 是字符串类型，定义了一个字符串类型的变量 string 就可以直接使用了
    - 没有让指针指向一个实际有效的地址，没有对 string 变量初始化为 0，所以不一定每次运行都出错
- 空字符串
  - char buffer[100] = "";
    - 这是一个空字符串，buffer[0] == '\0'
  - char buffer[] = "";
    - 这个数组的长度只有 1 ！

### 字符串函数

```c++
#include <string.h>
```

- strlen
  - size_t strlen(const char \*s);
  - 返回字符串的长度（不包括结尾的 0）
- strcmp
  - int strcmp(const char \*s1, const char \*s2);
  - 比较两个字符串（从左到右逐个比较）
    - s1 == s2 --> 0
    - s1 > s2 --> 1（准确来说是 s1 - s2 的差值）
    - s1 < s2 --> -1（准确来说是 s1 - s2 的差值）
  - 另外一个版本（size_t 表示参与比较的字符串的位数，eg: 3 --> 字符串的前三位参与比较，后面的忽略）
    - int strncmp(const char \*s1, const char \*s2, size_t n);
- strcpy
  - char \*strcpy(char \*restrict dst, const char \*restrict src);
  - 把 src 的字符串拷贝到 dst
    - restrict 表明 src 和 dst 不重叠（C99）
  - 返回 dst
    - 为了能链起来代码
  - 存在安全问题
    - dst 必须具有足够的空间
  - 安全版本
    - char \*strmcpy(char \*restrict dst, const char \*restrict src, size_t n);
- strcat
  - char \*strcat(char \*restrict s1, const char \*restrict s2);
  - 把 s2 拷贝到 s1 的后面，接成一个长的字符串
  - 返回 s1
  - 存在安全问题
    - s1 必须具有足够的空间
  - 安全版本
    - char \*strmcat(char \*restrict s1, const char \*restrict s2, size_t n);
- strchr
  - char \*strchr(const char \*s, int c);
  - 字符串中找字符，找 c 第一次出现的位置
  - 另外一个版本（从右往左逆序找 - reverse）
    - char \*strrchr(const char \*s, int c);
  - 返回 NULL 表示没有找到
  - 如果寻找指定字符第二次出现的位置？
- strstr
  - char \*strstr(const char \*big, const char \*little)
  - 字符串中找字符串，找 little 第一次出现的位置
  - 返回 NULL 表示没有找到
