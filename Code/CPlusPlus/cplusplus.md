- [C++ Language](#c-language)
  - [Introduction](#introduction)
    - [Compilers](#compilers)
      - [What is a compiler?](#what-is-a-compiler)
      - [Console programs](#console-programs)
  - [Basics of C++](#basics-of-c)
    - [Structure of a program](#structure-of-a-program)
      - [Comments](#comments)
      - [Using namespace std](#using-namespace-std)
    - [Variables and types](#variables-and-types)
      - [Identifiers](#identifiers)
      - [Fundamental data types](#fundamental-data-types)
      - [Declaration of variables](#declaration-of-variables)
      - [Initialization of variables](#initialization-of-variables)
      - [Type deduction: auto and decltype](#type-deduction-auto-and-decltype)
    - [Constants](#constants)
      - [Literals](#literals)
      - [Typed constant expressions](#typed-constant-expressions)
      - [Preprocessor definitions (#define)](#preprocessor-definitions-define)
    - [Operators](#operators)
      - [Assignment Operator (=)](#assignment-operator-)
      - [Arithmetic operators ( +, -, \*, /, % )](#arithmetic-operators--------)
      - [Compound assignment (+=, -=, \*=, /=, %=, \>\>=, \<\<=, \&=, ^=, |=)](#compound-assignment-----------)


# C++ Language

## Introduction

### Compilers

#### What is a compiler?

Because a computer can only understand machine language (zeros and ones) and humans wish to write in high level languages high level languages have to be re-written (translated) into machine language at some point. This is done by special programs called compilers, interpreters, or assemblers that are built into the various programming applications.

C++ is designed to be a compiled language, meaning that it is generally translated into machine language that can be understood directly by the system, making the generated program highly efficient. For that, a set of tools are needed, known as the development toolchain, whose core are a compiler and its linker.

#### Console programs

Console programs are programs that use text to communicate with the user and the environment, such as printing text to the screen or reading input from a keyboard.

If you happen to have a Linux or Mac environment with development features, you should be able to compile any of the examples in this tutorial directly from a terminal just by including C++11 flags in the command for the compiler:

| Compiler | Platform | Command |
| :---: | :---: | :---: |
| GCC | Linux, among others... | `g++ -std=C++0x example.cpp -o example_program` |
| Clang | OS X, among others... | `clang++ -std=C++11 -stdlib=libc++ example.cpp -o example_program` |

## Basics of C++

### Structure of a program

`// my first program in C++`
Two slash signs (`//`) indicate that the rest of the line is a comment.

`#include <iostream>`
Lines beginning with a hash sign (`#`) are directives read and interpreted by what is known as the preprocessor. They are special lines interpreted before the compilation of the program itself begins.

`int main ()`
The function named main is a special function in all C++ programs; it is the function called when the program is run. The execution of all C++ programs begins with the main function, regardless of where the function is actually located within the code.

#### Comments

C++ supports two ways of commenting code:

```
// line comment
/* block comment */
```

#### Using namespace std

In order to refer to the elements in the `std` namespace a program shall either qualify each and every use of elements of the library (as we have done by prefixing `cout` with `std::`), or introduce visibility of its components. The most typical way to introduce visibility of these components is by means of **using declarations**:

`using namespace std;`

### Variables and types

#### Identifiers

A valid identifier is a sequence of one or more letters, digits, or underscore characters (`_`). In addition, identifiers shall always begin with a letter. They can also begin with an underline character (`_`), but such identifiers are **on most cases** considered reserved for compiler-specific keywords or external identifiers, as well as identifiers containing two successive underscore characters anywhere. In no case can they begin with a digit.

#### Fundamental data types

Fundamental data types are basic types implemented directly by the language that represent the basic storage units supported natively by most systems. They can mainly be classified into:
- **Character types:** They can represent a single character, such as `'A'` or `'$'`. The most basic type is `char`, which is a one-byte character. Other types are also provided for wider characters.
- **Numerical integer types:** They can store a whole number value, such as `7` or `1024`. They exist in a variety of sizes, and can either be signed or unsigned, depending on whether they support negative values or not.
- **Floating-point types:** They can represent real values, such as `3.14` or `0.01`, with different levels of precision, depending on which of the three floating-point types is used.
- **Boolean type:** The boolean type, known in C++ as `bool`, can only represent one of two states, `true` or `false`.

The type is not required (and in many cases is not) exactly its minimum size. This does not mean that these types are of an undetermined size, but that there is no standard size across all compilers and machines; each compiler implementation may specify the sizes for these types that fit the best the architecture where the program is going to run. This rather generic size specification for types gives the C++ language a lot of flexibility to be adapted to work optimally in all kinds of platforms, both present and future.

#### Declaration of variables

C++ is a strongly-typed language, and requires every variable to be declared with its type before its first use.

If declaring more than one variable of the same type, they can all be declared in a single statement by separating their identifiers with commas. For example: `int a, b, c;`

#### Initialization of variables

In C++, there are three ways to initialize variables. They are all equivalent and are reminiscent of the evolution of the language over the years:

- The first one, known as **c-like initialization** (because it is inherited from the C language), consists of appending an equal sign followed by the value to which the variable is initialized: `type identifier = initial_value;` For example: `int x = 0;`

- A second method, known as **constructor initialization** (introduced by the C++ language), encloses the initial value between parentheses (()): `type identifier (initial_value);` For example: `int x (0);`

- A third method, known as **uniform initialization**, similar to the above, but using curly braces ({}) instead of parentheses (this was introduced by the revision of the C++ standard, in 2011): `type identifier {initial_value};` For example: `int x {0};`

#### Type deduction: auto and decltype

When a new variable is initialized, the compiler can figure out what the type of the variable is automatically by the initializer. For this, it suffices to use `auto` as the type specifier for the variable:
```
int foo = 0;
auto bar = foo;  // the same as: int bar = foo;
```

Variables that are not initialized can also make use of type deduction with the `decltype` specifier:

```
int foo = 0;
decltype(foo) bar;  // the same as: int bar;
```

### Constants

#### Literals

Literal constants can be classified into: integer, floating-point, characters, strings, Boolean, pointers, and user-defined literals.

- **Integer Numerals**
These literal constants have a type, just like variables. By default, integer literals are of type `int`. However, certain suffixes may be appended to an integer literal to specify a different integer type:

| Suffix | Type |
| :---: | :---: |
| `u` or `U` | `unsigned` |
| `l` or `L` | `long` |
| `ll` or `LL` | `long long` |

Unsigned may be combined with any of the other two in any order to form `unsigned long` or `unsigned long long`. For example:

```
75         // int
75u        // unsigned int
75l        // long
75ul       // unsigned long 
75lu       // unsigned long
```

- **Floating Point Numerals**

The default type for floating-point literals is `double`. Floating-point literals of type `float` or `long double` can be specified by adding one of the following suffixes:

| Suffix | Type |
| :---: | :---: |
| `f` or `F` | `float` |
| `l` or `L` | `long double` |

- **Character and string literals**

In C++, a backslash (`\`) at the end of line is considered a **line-continuation** character that merges both that line and the next into a single line. Therefore the following code:

```
x = "string expressed in \
two lines"
```

is equivalent to:

```x = "string expressed in two lines"```

The character literals and string literals are made of characters of type `char` by default. A different character type can be specified by using one of the following prefixes:

| Prefix | Character Type |
| :---: | :---: |
| `u` | `char16_t` |
| `U` | `char32_t` |
| `L` | `wchar_t` |

For string literals, apart from the above `u`, `U`, and `L`, two additional prefixes exist:

| Prefix | Description |
| :---: | :---: |
| `u8` | The string literal is encoded in the executable using UTF-8 |
| `R` | The string literal is a raw string |

- **Other literals**

Three keyword literals exist in C++: `true`, `false` and `nullptr`.

#### Typed constant expressions

Sometimes, it is just convenient to give a name to a constant value: `const double pi = 3.1415926;`

#### Preprocessor definitions (#define)

Another mechanism to name constant values is the use of preprocessor definitions. They have the following form:
`#define identifier replacement`
This replacement is performed by the preprocessor, and happens before the program is compiled, thus causing a sort of blind replacement: the validity of the types or syntax involved is not checked in any way. For example:

 ```
 #define PI 3.14159
 #define NEWLINE '\n'
 ```

Note that the `#define` lines are preprocessor directives, and as such are single-line instructions that *unlike C++ statements* do not require semicolons (`;`) at the end; the directive extends automatically until the end of the line. If a semicolon is included in the line, it is part of the replacement sequence and is also included in all replaced occurrences.

### Operators

#### Assignment Operator (=)

The assignment operation always takes place from right to left.

Assignment operations are expressions that can be evaluated. That means that the assignment itself has a value, and *for fundamental types* this value is the one assigned in the operation. For example:

`y = 2 + (x = 5);    // x=5, y=7`

The following expression is also valid in C++: `x = y = z = 5;`

#### Arithmetic operators ( +, -, *, /, % )

#### Compound assignment (+=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=)

Compound assignment operators modify the current value of a variable by performing an operation on it. They are equivalent to assigning the result of an operation to the first operand: