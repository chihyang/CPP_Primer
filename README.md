# C++ Primer Solutions

My solutions to C++ Primer(5th edition) exercises, including problems that perplex me. ```Makefile``` for visual studio compiler and ```gcc``` will be added later.

## Contents
- [Chapter 1. Getting Started](chap01)
- Part I: The Basics
  - [Chapter 2. Variables and Basic Types](chap02)
  - [Chapter 3. Strings, Vectors, and Arrays](chap03)
  - [Chapter 4. Expressions](chap04)
  - [Chapter 5. Statements](chap05)
  - [Chapter 6. Functions](chap06)
  - [Chapter 7. Classes](chap07)
- Part II: The C++ Library
  - [Chapter 8. The IO Library](chap08)
  - [Chapter 9. Sequential Containers](chap09)
  - [Chapter 10. Generic Algorithms](chap10)
  - [Chapter 11. Associative Containers](chap11)
  - [Chapter 12. Dynamic Memory](chap12)
- Part III: Tools for Class Authors
  - [Chapter 13. Copy Control](chap13)
  - [Chapter 14. Overloaded Operations and Conversions](chap14)
  - [Chapter 15. Object-Oriented Programming](chap15)
  - [Chapter 16. Templates and Generic Programming](chap16)
- Part IV:  Advanced Topics
  - [Chapter 17. Specialized Library Facilities](chap17)
  - [Chapter 18. Tools for Large Programs](chap18)
  - [Chapter 19. Specialized Tools and Techniques](chap19)

## Compiler version

* ```gcc```: (tdm64-1) 5.1.0
* ```clang```: 3.7.0 (tags/RELEASE_370/final)
* ```cl```: Visual Studio 2013, version 18.00.40629

## File Format

### Solutions to exercises

* Header files

> Exer07_26_Sales_data.h

Where ```Exer07_26``` corresponds to ```exercise 7.26```, ```_Sales_data``` corresponds to the (primary) class defined in the header.

* Source files

> Exer01_13_1.cpp

Where ```Exer01_13``` corresponds to ```exercise 1.13```, ```_1``` corresponds to the first question in the exercise. Whether ```_1``` (```_2```, ```_3``` and so on) appears depends on the number of questions of the exercise.

### Illustrations or verifications of key points

> Page046_underline.cpp

Where ```Page046``` corresponds to the page number of the key point, and ```underline``` is the key point to be illustrated or verified.

## Comments

### Warning

Not every file could compile. Some programs are intended for repeating an error so that I can know definitely what is correct and what is not. Every program that cannot be compiled successfully begins with a ```WARNING``` comment as below:

```cpp
// Warning: This is for verification. It CANNOT be compiled successfully by both compiler.
// The problem lies in line XX.
```

Generally, compile info will be added to the end of such files.

Before or after ```line XX```, there are comments for concrete explanation of the error. 

### Notes
