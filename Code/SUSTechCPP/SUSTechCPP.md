- [课程介绍](#课程介绍)
- [入门](#入门)
  - [一个简单的例子](#一个简单的例子)
  - [编译与链接](#编译与链接)
    - [函数原型与定义](#函数原型与定义)
  - [错误与调试](#错误与调试)
  - [预处理和宏](#预处理和宏)
    - [预处理 (Preprocessor)](#预处理-preprocessor)
    - [宏 (Macros)](#宏-macros)
  - [简单输入与输出](#简单输入与输出)
    - [C++风格的输出](#c风格的输出)
    - [C++风格的输入](#c风格的输入)
    - [C风格的输出](#c风格的输出-1)
    - [C风格的输入](#c风格的输入-1)
  - [Command line arguments](#command-line-arguments)
  - [Exercises](#exercises)
- [Data Types and Arithmetic Operators](#data-types-and-arithmetic-operators)
  - [Integer numbers](#integer-numbers)
  - [Different integer types](#different-integer-types)
  - [Floating-point numbers](#floating-point-numbers)
  - [Constant numbers and constant variables](#constant-numbers-and-constant-variables)
  - [Arithmetic operators](#arithmetic-operators)
  - [Special notes](#special-notes)


# 课程介绍

GitHub Repo：[Programming in C/C++ Efficiently - GitHub](https://github.com/ShiqiYu/CPP)

# 入门

## 一个简单的例子

```C++
// the first example
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
```

- 编译hello.cpp  
  `g++ hello.cpp`
- 指定编译的标准  
  `g++ hello.cpp --std=c++11`
- 使用`-o`选项指定编译输出文件名  
  `g++ hello.cpp --std=c++11 -o hello`
- 执行  
  `./hello`

## 编译与链接

### 函数原型与定义

- 函数原型 (prototypes) 通常在头文件（*.h; *.hpp）  
  `int mul(int a, int b);`
- 函数定义 (definitions) 通常在源文件（*.c; *.cpp）  
  ```C++
  int mul(int a, int b)
  {
    return a * b;
  }
  ```

在[mainmul.cpp](./src/chapter1/mainmul.cpp)中，我们定义了两个函数，一个`mul`函数，一个`main`函数。可以预见，当程序非常庞大，函数非常多时，如果也像这样全部写在一个源文件里，编译将会非常耗时。因此我们可以将程序拆分成不同的部分存放在不同的文件里面，例如将`main`函数放在[main.cpp](./src/chapter1/main.cpp)，`mul`函数放在[mul.cpp](./src/chapter1/mul.cpp)，需要注意的是，我们还需要一个头文件[mul.hpp](./src/chapter1/mul.hpp)来存放`mul`函数的声明，并在main.cpp和mul.cpp中include这个头文件。对于这三个文件，编译和链接的过程如下：

![Compile and Link](./img/compile_and_link.png)

首先，我们分别编译main.cpp和mul.cpp得到main.o和mul.o（`-c`选项表示只编译不链接），从Object文件（`*.o`）生成可执行文件的过程就叫链接，我们使用`-o`选项来从两个Object文件生成可执行文件。上述过程也可以只用一条命令来完成：`g++ main.cpp mul.cpp -o mul`。

## 错误与调试

- 编译错误 (Compilation errors)：编译环节出现错误，一般是因为源文件里存在语法错误；
- 链接错误 (Link errors)：每个源文件内部没有语法错误，编译成功，但是在链接时存在错误。例如上述main.cpp文件中我们调用了`mul`函数，如果我们在mul.cpp文件中不小心将函数名写成了`Mul`，就会出现链接错误，因为链接时找不到main.o需要的`mul`函数。链接错误的报错信息通常为"Undefined symbols..."或者"symbol(s) not found..."。
- 运行时错误 (Runtime errors)：编译和链接都成功，程序运行时出现了异常，比如除数为零。

## 预处理和宏

### 预处理 (Preprocessor)

- 预处理在编译之前运行，处理完以后编译器才开始编译，如下图所示；
  ![Preprocessor](./img/preprocessor.png)
- 预处理指令指的是程序中以`#`开头的语句，例如
  ```C++
  #include <iostream>

  #define PI 3.1415926535

  #if defined(_OPENMP)
  #include <omp.h>
  #endif
  ```
- 每条预处理指令只能占一行，超过一行用转义符连接；
- 预处理指令：`define`, `undef`, `include`, `if `, `ifdef`, `ifndef`, `else`, `elif`, `endif`, `line`, `error`, `pragma`.

### 宏 (Macros)

宏就是将一段代码替换为另一段代码，通过`#define`语句定义。例如我们程序中定义了`#define PI 3.1415926`，则在预处理时程序中所有的`PI`都会被替换成`3.1415926`，然后再交给编译器编译，如下图所示。
![Macros](./img/macros.png)
需要注意的是，这里的`PI`不能理解为变量，应该当作纯粹的文本替换。事实上，不仅可以将常量定义为宏，函数也可以定义为宏，例如`#define ADD(a, b) (a + b)`

## 简单输入与输出

### C++风格的输出

`cout`：`cout`是`std`命名空间`ostream`类型的对象，即`std::ostream cout；`。`<<`是一个运算符，表示将其后面的内容传递给前面的对象，例如`cout << "hello";`表示将`hello`传递给`cout`进行输出。`endl`表示一个换行符。

### C++风格的输入

`cin`：与`cout`类似，数据类型为`std::istream`，`>>`与`<<`也类似，例如`cin >> a;`表示将通过`cin`获取的数据传给变量`a`。

### C风格的输出

C使用`printf()`或者`fprintf()`进行输出，这两个都是函数，按照调用函数的方式使用即可，输出的内容可以使用`%d`、`%.2f`等进行格式化输出，例如`printf("Hello, value = %d\n", 100);`。

### C风格的输入

C风格的输入使用`scanf`，这也是一个函数，例如`scanf("%d", &a);`表示将输出的数据作为十进制整数赋给变量`a`。需要注意的是，这里的`a`前面必须加上`&`，表示取变量`a`的地址。















## Command line arguments

## Exercises

# Data Types and Arithmetic Operators

## Integer numbers

## Different integer types

## Floating-point numbers

## Constant numbers and constant variables

## Arithmetic operators

## Special notes