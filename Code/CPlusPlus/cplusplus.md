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

A valid identifier is a sequence of one or more letters, digits, or underscore characters (`_`). In addition, identifiers shall always begin with a letter. They can also begin with an underline character (`_`), but such identifiers are -on most cases- considered reserved for compiler-specific keywords or external identifiers, as well as identifiers containing two successive underscore characters anywhere. In no case can they begin with a digit.

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

