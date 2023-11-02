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
      - [Increment and decrement (++, --)](#increment-and-decrement----)
      - [Relational and comparison operators (==, !=, \>, \<, \>=, \<=)](#relational-and-comparison-operators------)
      - [Logical operators (!, \&\&, ||)](#logical-operators---)
      - [Conditional ternary operator (?)](#conditional-ternary-operator-)
      - [Comma operator (,)](#comma-operator-)
      - [Bitwise operators (\&, |, ^, ~, \<\<, \>\>)](#bitwise-operators------)
      - [Explicit type casting operator](#explicit-type-casting-operator)
      - [sizeof](#sizeof)
    - [Basic Input/Output](#basic-inputoutput)
      - [Standard output (cout)](#standard-output-cout)
      - [Standard input (cin)](#standard-input-cin)
      - [cin and strings](#cin-and-strings)
      - [stringstream](#stringstream)
  - [Program structure](#program-structure)
    - [Statements and flow control](#statements-and-flow-control)
      - [Selection statements: if and else](#selection-statements-if-and-else)
      - [Iteration statements (loops)](#iteration-statements-loops)
      - [Jump Statements](#jump-statements)
      - [Another selection statement: switch](#another-selection-statement-switch)
    - [Functions](#functions)
    - [Overloads and templates](#overloads-and-templates)
    - [Name visibility](#name-visibility)
  - [Compound data types](#compound-data-types)
    - [Arrays](#arrays)
    - [Character sequences](#character-sequences)
    - [Pointers](#pointers)
    - [Dynamic memory](#dynamic-memory)
    - [Data structures](#data-structures)
    - [Other data types](#other-data-types)
  - [Classes](#classes)
    - [Classes (I)](#classes-i)
    - [Classes (II)](#classes-ii)
    - [Special members](#special-members)
    - [Friendship and inheritance](#friendship-and-inheritance)
    - [Polymorphism](#polymorphism)
  - [Other language features](#other-language-features)
    - [Type conversions](#type-conversions)
    - [Exceptions](#exceptions)
    - [Preprocessor directives](#preprocessor-directives)
  - [Standard library](#standard-library)
    - [Input/output with files](#inputoutput-with-files)


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

```C++
#include <iostream>
```

Lines beginning with a hash sign (`#`) are directives read and interpreted by what is known as the preprocessor. They are special lines interpreted before the compilation of the program itself begins.

```C++
int main ()
```

The function named main is a special function in all C++ programs; it is the function called when the program is run. The execution of all C++ programs begins with the main function, regardless of where the function is actually located within the code.

#### Comments

C++ supports two ways of commenting code:

```C++
// line comment
/* block comment */
```

#### Using namespace std

In order to refer to the elements in the `std` namespace a program shall either qualify each and every use of elements of the library (as we have done by prefixing `cout` with `std::`), or introduce visibility of its components. The most typical way to introduce visibility of these components is by means of **using declarations**:

```C++
using namespace std;
```

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

```C++
int foo = 0;
auto bar = foo;  // the same as: int bar = foo;
```

Variables that are not initialized can also make use of type deduction with the `decltype` specifier:

```C++
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

```C++
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

```C++
x = "string expressed in \
two lines"
```

is equivalent to:

```C++
x = "string expressed in two lines"
```

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

Sometimes, it is just convenient to give a name to a constant value: 

```C++
const double pi = 3.1415926;
```

#### Preprocessor definitions (#define)

Another mechanism to name constant values is the use of preprocessor definitions. They have the following form:

```C++
#define identifier replacement
```

This replacement is performed by the preprocessor, and happens before the program is compiled, thus causing a sort of blind replacement: the validity of the types or syntax involved is not checked in any way. For example:

 ```C++
 #define PI 3.14159
 #define NEWLINE '\n'
 ```

Note that the `#define` lines are preprocessor directives, and as such are single-line instructions that *unlike C++ statements* do not require semicolons (`;`) at the end; the directive extends automatically until the end of the line. If a semicolon is included in the line, it is part of the replacement sequence and is also included in all replaced occurrences.

### Operators

#### Assignment Operator (=)

The assignment operation always takes place from right to left.

Assignment operations are expressions that can be evaluated. That means that the assignment itself has a value, and *for fundamental types* this value is the one assigned in the operation. For example:

```C++
y = 2 + (x = 5);    // x=5, y=7
```

The following expression is also valid in C++: `x = y = z = 5;`

#### Arithmetic operators ( +, -, *, /, % )

#### Compound assignment (+=, -=, *=, /=, %=, >>=, <<=, &=, ^=, |=)

Compound assignment operators modify the current value of a variable by performing an operation on it. They are equivalent to assigning the result of an operation to the first operand:

| expression | equivalent to... |
| :---: | :---: |
| `y += x` | `y = y + x` |
| `y /= x` | `y = y / x` |
| `y %= x` | `y = y % x` |

`>>`, `<<`, `&`, `^` and `|` are bitwise operators.

#### Increment and decrement (++, --)

Although in simple expressions like `x++` or `++x`, both have exactly the same meaning; in other expressions in which the result of the increment or decrement operation is evaluated, they may have an important difference in their meaning.

| Example 1 | Example 2 |
| :---: | :---: |
| `x = 3;` | `x = 3` |
| `y = ++x;` | `y = x++` |
| `// x contains 4, y contains 4` | `// x contains 4, y contains 3` |

#### Relational and comparison operators (==, !=, >, <, >=, <=)

#### Logical operators (!, &&, ||)

C++ supports **short-circuit evaluation**, and works like this for these operators:

| operator | short-circuit |
| :---: | :---: |
| `&&` | if the left-hand side expression is `false`, the combined result is `false` (the right-hand side expression is never evaluated). |
| `\|\|` | if the left-hand side expression is `true`, the combined result is `true` (the right-hand side expression is never evaluated). |

This is mostly important when the right-hand expression has side effects, such as altering values:

```C++
if ( (i<10) && (++i<n) ) { /*...*/ }   // note that the condition increments i
```

#### Conditional ternary operator (?)

The conditional operator evaluates an expression, returning one value if that expression evaluates to `true`, and a different one if the expression evaluates as `false`. Its syntax is:

```C++
condition ? result1 : result2
```

If `condition` is `true`, the entire expression evaluates to `result1`, and otherwise to `result2`.

#### Comma operator (,)

The comma operator (`,`) is used to separate two or more expressions that are included where only one expression is expected. When the set of expressions has to be evaluated for a value, only the right-most expression is considered. For example:

```C++
a = (b=3, b+2);    \\ a contains 5, b contains 3
```

#### Bitwise operators (&, |, ^, ~, <<, >>)

Bitwise operators modify variables considering the bit patterns that represent the values they store.

| operator | asm equivalent | description |
| :---: | :---: | :---: |
| `&` | `AND` | Bitwise AND |
| `\|` | `OR` | Bitwise inclusive OR |
| `^` | `XOR` | Bitwise exclusive OR |
| `~` | `NOT` | Unary complement (bit inversion) |
| `<<` | `SHL` | Shift bits left |
| `>>` | `SHR` | Shift bits right |

#### Explicit type casting operator

Type casting operators allow to convert a value of a given type to another type. There are several ways to do this in C++:

 ```C++
int a = 1;
float b = 3.14;
i = (int) f;    // inherite from the C language
i = int (f);    // C++ style
 ```

#### sizeof

This operator accepts one parameter, which can be either a type or a variable, and returns the size in bytes of that type or object:

```C++
x = sizeof (char);    // x contains 1
```

The value returned by `sizeof` is a compile-time constant, so it is always determined before program execution. For example:

 ```C++
int a = 7;
cout<<sizeof(++a)<<endl;    // 4
cout<<a<<endl;    // 7, ++a is not executed
 ```

 ### Basic Input/Output

 The standard library defines a handful of stream objects that can be used to access what are considered the standard sources and destinations of characters by the environment where the program runs:

 | stream | description |
| :---: | :---: |
| `cin` | standard input stream |
| `cout` | standard output stream |
| `cerr` | standard error (output) stream |
| `clog` | standard logging (output) stream |

#### Standard output (cout)

For formatted output operations, `cout` is used together with the **insertion operator**, which is written as `<<` (i.e., two "less than" signs).

 ```C++
cout << "Output sentence"; // prints Output sentence on screen
cout << 120;               // prints number 120 on screen
cout << x;                 // prints the value of x on screen
 ```

The `endl` manipulator produces a newline character, exactly as the insertion of `\n` does; but it also has an additional behavior: the stream's buffer (if any) is flushed, which means that the output is requested to be physically written to the device, if it wasn't already. This affects mainly **fully buffered** streams, and `cout` is (generally) not a fully buffered stream. Still, it is generally a good idea to use `endl` only when flushing the stream would be a feature and `\n` when it would not. Bear in mind that a flushing operation incurs a certain overhead, and on some devices it may produce a delay.

#### Standard input (cin)

For formatted input operations, `cin` is used together with the extraction operator, which is written as `>>` (i.e., two "greater than" signs). This operator is then followed by the variable where the extracted data is stored. For example:

 ```C++
int age;
cin >> age;
 ```

#### cin and strings

`cin` extraction always considers spaces (whitespaces, tabs, new-line...) as terminating the value being extracted, and thus extracting a string means to always extract a single word, not a phrase or an entire sentence. For example:

 ```C++
string mystring;
cin>>mystring;    // Hello World
cout<<mystring;    // Hello
 ```

To get an entire line from `cin`, there exists a function, called `getline`, that takes the stream (`cin`) as first argument, and the string variable as second. For example:

 ```C++
string mystring;
getline(cin, mystring);    // Hello World
cout<<mystring;    // Hello World
 ```

#### stringstream

The standard header `<sstream>` defines a type called `stringstream` that allows a string to be treated as a stream, and thus allowing extraction or insertion operations from/to strings in the same way as they are performed on `cin` and `cout`. This feature is most useful to convert strings to numerical values and vice versa. For example:

```C++
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
  string mystr;
  float price=0;
  int quantity=0;

  cout << "Enter price: ";
  getline (cin,mystr);
  stringstream(mystr) >> price;
  cout << "Enter quantity: ";
  getline (cin,mystr);
  stringstream(mystr) >> quantity;
  cout << "Total price: " << price*quantity << endl;
  return 0;
}
```

## Program structure

### Statements and flow control

Programs are not limited to a linear sequence of statements. During its process, a program may repeat segments of code, or take decisions and bifurcate. For that purpose, C++ provides flow control statements that serve to specify what has to be done by our program, when, and under which circumstances.

#### Selection statements: if and else

The `if` keyword is used to execute a statement or block, if, and only if, a condition is fulfilled. Its syntax is:

`if (condition) statement`

If you want to include more than a single statement to be executed when the condition is fulfilled, these statements shall be enclosed in braces (`{}`), forming a block:

```C++
if (x == 100)
{
   cout << "x is ";
   cout << x;
}
```

Selection statements with `if` can also specify what happens when the condition is not fulfilled, by using the `else` keyword to introduce an alternative statement. Its syntax is:

`if (condition) statement1 else statement2`

#### Iteration statements (loops)

- **The while loop**

The simplest kind of loop is the while-loop. Its syntax is:

`while (expression) statement`

- **The do-while loop**

Its syntax is:

`do statement while (condition);`

It behaves like a while-loop, except that `condition` is evaluated after the execution of `statement` instead of before, guaranteeing at least one execution of `statement`, even if `condition` is never fulfilled.

- **The for loop**

The `for` loop is designed to iterate a number of times. Its syntax is:

`for (initialization; condition; increase) statement;`

The `initialization` and `increase` expression, are executed before the loop begins the first time, and after each iteration, respectively.

The three fields in a for-loop are optional. They can be left empty, but in all cases the semicolon signs between them are required. For example, `for (;n<10;)` is a loop without `initialization` or `increase` (equivalent to a while-loop).

Because each of the fields is executed in a particular time in the life cycle of a loop, it may be useful to execute more than a single expression as any of `initialization`, `condition`, or `statement`. For example, it would be possible for a for loop to handle two counter variables, initializing and increasing both:

```C++
for ( n=0, i=100 ; n!=i ; ++n, --i )
{
   // whatever here...
}
```

This loop will execute 50 times if neither `n` or `i` are modified within the loop.

- **Range-based for loop**

The for-loop has another syntax, which is used exclusively with ranges:

`for ( declaration : range ) statement;`

This kind of `for` loop iterates over all the elements in `range`, where `declaration` declares some variable able to take the value of an element in this `range`. Ranges are sequences of elements, including arrays, containers, and any other type supporting the functions `begin` and `end`. An example of range-based for loop using strings:

```C++
string str {"Hello!"};
for (char c : str)
{
  cout << "[" << c << "]";
}
cout << '\n';
```

Range based loops usually also make use of type deduction for the type of the elements with `auto`. Typically, the range-based loop above can also be written as:

```C++
for (auto c : str)
  cout << "[" << c << "]";
```

#### Jump Statements

- **The break statement**

`break` leaves a loop, even if the condition for its end is not fulfilled.

- **The continue statement**

The `continue` statement causes the program to skip the rest of the loop in the current iteration, as if the end of the statement block had been reached, causing it to jump to the start of the following iteration.

- **The goto statement**

`goto` allows to make an absolute jump to another point in the program. This unconditional jump ignores nesting levels, and does not cause any automatic stack unwinding. Therefore, it is a feature to use with care, and preferably within the same block of statements, especially in the presence of local variables.

The destination point is identified by a **label**, which is then used as an argument for the `goto` statement. A **label** is made of a valid identifier followed by a colon (`:`).

```C++
int main ()
{
  int n=10;
mylabel:
  cout << n << ", ";
  n--;
  if (n>0) goto mylabel;
  cout << "liftoff!\n";
}
```

#### Another selection statement: switch

The purpose of `switch` statement is to check for a value among a number of possible constant expressions. Its most typical syntax is:

```C++
switch (expression)
{
  case constant1:
     group-of-statements-1;
     break;
  case constant2:
     group-of-statements-2;
     break;
  .
  .
  .
  default:
     default-group-of-statements
}
```

If `break` is not included, all statements following the case (including those under any other labels) are also executed, until the end of the switch block or a jump statement (such as `break`) is reached. For example:

```C++
switch (x) {
  case 1:
  case 2:
  case 3:
    cout << "x is 1, 2 or 3";
    break;
  default:
    cout << "x is not 1, 2 nor 3";
  };
```













### Functions

### Overloads and templates

### Name visibility

## Compound data types

### Arrays

### Character sequences

### Pointers

### Dynamic memory

### Data structures

### Other data types

## Classes

### Classes (I)

### Classes (II)

### Special members

### Friendship and inheritance

### Polymorphism

## Other language features

### Type conversions

### Exceptions

### Preprocessor directives

## Standard library

### Input/output with files