# MQL5学习笔记


## 第一章

### 学习路径
- 第一阶段：学习MQL5语言的基础语法，比如数据类型、变量、逻辑运算、条件表达式、循环表达式等
- 第二阶段：学习函数式编程，编写各种功能函数组件
- 第三阶段：将多个函数组成函数库，进行调用开发
- 第四阶段：学习结构体，面向对象编程（OOP）
- 第五阶段：开始真实的自动交易系统开发：指标开发、页面控件、智能EA等
- 第六阶段：进行业务的扩展，比如连接互联网、数据库、FTP上传、授权管理、多账户管理

### 认识MT5软件

### 外汇基础知识




























------------------
## 语言基础

### 语法
MQL5语言与C++语言十分相似，除了以下特点：
- 没有运算地址；
- 没有goto语句；
- 匿名计算无法删除；
- 无成倍继承；

#### 注释
多行注释使用`/*`作为开始到`*/`结束，在这之间不能够嵌套。单行注释使用`//`作为开始到新的一行结束，可以被嵌套到多行注释之中。

#### 标识符
标识符用来给变量和函数进行命名，长度不能超过63个字节。首字母不可以是数字，标识符不能和保留字冲突。

#### 关键词
下面列出的是固定的保留字标识符。

|数据类型| | | | | | |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| bool | char | class | color | datetime | double | enum |
| float | int | long | short | string | struct | uchar |
| uint | ulong | union | ushort | void |

|访问分类符| | | | | | |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| const | delete | override | private | protected | public | virtual |

|存储类型| | |
| :-: | :-: | :-: |
| extern | input | static |

|操作符| | | | | | |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| break | case | continue | default | delete | do | dynamic_cast |
| else | for | if | new | offsetof | operator | pack |
| return | sizeof | switch | while |

|其他| | | | | | |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| this | true | false | template | typename | #define | #ifdef |
| #ifndef | #else | #endif | #import | #include | #property | group |
| namespace |

### 数据类型
不同的数据类型有不同的处理速度，整型数据是最快的。双精度的数据处理需要特殊的协同处理器，然而，因为处理浮点型数据比较复杂， 所以它比处理整型数据慢一些。字符串是处理速度最慢的，因为它要存取动态内存。

基本数据类型：
- 整型数据（char, short, int, long, uchar, ushort, uint, ulong）
- 逻辑数据（bool）
- 字符数据（ushort）
- 字符串数据（string）
- 浮点型数据（double, float）
- 颜色（color）
- 日期和时间数据（datetime）
- 计数（enum）

复杂的数据类型：
- structures
- classes

#### 整型
| 类型 | 字节大小 | 最小值 | 最大值 | C++类比 |
| :-:  | :-:     | :-:   | :-:    | :-:    |
| char | 1       | -128  | 127    | char   |
| uchar | 1 | 0 | 255 | unsigned char, BYTE |
| bool | 1 | 0 (false) | 1 (true) | bool |
| short | 2 | -32768 | 32767 | short, wchar_t |
| ushort | 2 | 0 | 65535 | unsigned short, WORD |
| int | 4 | -2147483648 | 2147483647 | int |
| uint | 4 | 0 | 4294967295 | unsigned int, DWORD |
| color | 4 | -1 | 16777215 | int, COLORREF |
| long | 8 | -9223372036854775808 | 9223372036854775807 | __int64|
| ulong | 8 | 0 | 18446744073709551615 | unsigned __int64 |
| datetime | 8 | 0 (1970.01.01 0:00:00) | 32 535 244 799 (3000.12.31 23:59:59) | __time64_t |

##### 字符型、短整型、整型和长整型
负值不能存储在无符号类型中，将负值赋给无符号类型会导致奇怪的结果。对于整型变量，值可以使用B前缀以二进制格式设置。

##### 字符常量