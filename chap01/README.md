# Answers Of Non-programming Exercises

## Contents
- [Exercise 1.1](#exercise-11)
- [Exercise 1.2](#exercise-12)
- [Exercise 1.3](#exercise-13)
- [Exercise 1.4](#exercise-14)
- [Exercise 1.5](#exercise-15)
- [Exercise 1.6](#exercise-16)
- [Exercise 1.7](#exercise-17)
- [Exercise 1.8](#exercise-18)
- [Exercise 1.9](#exercise-19)
- [Exercise 1.10](#exercise-110)
- [Exercise 1.11](#exercise-111)
- [Exercise 1.12](#exercise-112)
- [Exercise 1.13](#exercise-113)
- [Exercise 1.14](#exercise-114)
- [Exercise 1.15](#exercise-115)
- [Exercise 1.16](#exercise-116)
- [Exercise 1.17](#exercise-117)
- [Exercise 1.18](#exercise-118)
- [Exercise 1.19](#exercise-119)
- [Exercise 1.20](#exercise-120)
- [Exercise 1.21](#exercise-121)
- [Exercise 1.22](#exercise-122)
- [Exercise 1.23](#exercise-123)
- [Exercise 1.24](#exercise-124)
- [Exercise 1.25](#exercise-125)

## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the _main_ program from page 2.

[Exer01_01.cpp](Exer01_01.cpp)

## Exercise 1.2

> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from _main_.

[Exer01_02.cpp](Exer01_02.cpp)

## Exercise 1.3
> Write a program to print _Hello_, _World_ on the standard output.

[Exer01_03.cpp](Exer01_03.cpp)

## Exercise 1.4
> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

[Exer01_04.cpp](Exer01_04.cpp)

## Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

[Exer01_05.cpp](Exer01_05.cpp)

## Exercise 1.6
> Explain whether the following program fragment is legal.
```cpp
std::cout << "The sum of " << v1;
          << " and " << v2;
		  << " is " << v1 + v2 << std::endl;
```
If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

The program is illegal. It attempts to output the sum of _v1_ and _v2_, but appends surplus semicolons.
The correct way:

```cpp
std::cout << "The sum of " << v1
          << " and " << v2
		  << " is " << v1 + v2 << std::endl;
```

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

[Exer01_07.cpp](Exer01_07.cpp)

## Exercise 1.8

> Indicate which, if any, of the following output statements are legal:
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
After you’ve predicted what will happen, test your answers by compiling a
program with each of these statements. Correct any errors you encounter.

Legal statements:
```cpp
(a) std::cout << "/*";
(b) std::cout << "*/";
(d) std::cout << /* "*/" /* "/*" */;
```
Illegel statements:
```cpp
(c) std::cout << /* "*/" */;
```
We can correct it as below:
```cpp
(c) std::cout << /* "*/" */";
```
see [Exer01_08.cpp](Exer01_08.cpp)

## Exercise 1.9

> Write a program that uses a _while_ to sum the numbers from
50 to 100.

[Exer01_09.cpp](Exer01_09.cpp)

## Exercise 1.10

> In addition to the ++ operator that adds 1 to its operand,
there is a decrement operator (--) that subtracts 1. Use the decrement
operator to write a _while_ that prints the numbers from ten down to zero.

[Exer01_10.cpp](Exer01_10.cpp)

## Exercise 1.11

> Write a program that prompts the user for two integers.
Print each number in the range specified by those two integers.

[Exer01_11.cpp](Exer01_11.cpp)

## Exercise 1.12

> What does the following _for_ loop do? What is the final value
of _sum_?
```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

The _for_ loop evaluates the sum from -100 to 100. The final value of _sum_ is 
0.

See [Exer01_12.cpp](Exer01_12.cpp)

## Exercise 1.13

> Rewrite the exercises from § 1.4.1 (p. 13) using _for_ loops.

[Exer01_13_1.cpp](Exer01_13_1.cpp) | [Exer01_13_2.cpp](Exer01_13_2.cpp) | [Exer01_13_3.cpp](Exer01_13_3.cpp)

## Exercise 1.14

> Compare and contrast the loops that used a _for_ with those
using a _while_. Are there advantages or disadvantages to using either form?

- _for_ loop

    _for_ is more fit for loops that will execute known times. 

- _while_ loop

    _while_ is more fit for loops that will execute unknown times.

## Exercise 1.15

> Write programs that contain the common errors discussed in
the box on page 16. Familiarize yourself with the messages the compiler
generates.

(nothing)

## Exercise 1.16

> Write your own version of a program that prints the sum of
a set of integers read from _cin_.

[Exer01_16.cpp](Exer01_16.cpp)

## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If the input values are all equal, there will be only one line of output.

If there are no duplicated values, there will be as many lines of outputs as the number of input values.

See next exercise.

## Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

[Exer01_18.cpp](Exer01_18.cpp)

## Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

[Exer01_19.cpp](Exer01_19.cpp)

## Exercise 1.20

> http://www.informit.com/title/032174113 contains a copy of _Sales_item.h_ in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

[Exer01_20.cpp](Exer01_20.cpp)

## Exercise 1.21

> Write a program that reads two _Sales_item_ objects that have the same ISBN and produces their sum.

[Exer01_21.cpp](Exer01_21.cpp)

## Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

[Exer01_22.cpp](Exer01_22.cpp)

## Exercise 1.23

> Write a program that reads several transactions and counts
how many transactions occur for each ISBN.

[Exer01_24.cpp](Exer01_24.cpp)

## Exercise 1.24

> Test the previous program by giving multiple transactions
representing multiple ISBNs. The records for each ISBN should be grouped
together.

[Exer01_24.cpp](Exer01_24.cpp)

## Exercise 1.25

> Using the _Sales_item.h_ header from the Web site,
compile and execute the bookstore program presented in this section.

[Exer01_25.cpp](Exer01_25.cpp)
