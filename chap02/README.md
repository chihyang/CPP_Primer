# Answers To Non-programming Exercises

## Contents
- [Exercise 2.1](#exercise-21)
- [Exercise 2.2](#exercise-22)
- [Exercise 2.3](#exercise-23)
- [Exercise 2.4](#exercise-24)
- [Exercise 2.5](#exercise-25)
- [Exercise 2.6](#exercise-26)
- [Exercise 2.7](#exercise-27)
- [Exercise 2.8](#exercise-28)
- [Exercise 2.9](#exercise-29)
- [Exercise 2.10](#exercise-210)
- [Exercise 2.11](#exercise-211)
- [Exercise 2.12](#exercise-212)
- [Exercise 2.13](#exercise-213)
- [Exercise 2.14](#exercise-214)
- [Exercise 2.15](#exercise-215)
- [Exercise 2.16](#exercise-216)
- [Exercise 2.17](#exercise-217)
- [Exercise 2.18](#exercise-218)
- [Exercise 2.19](#exercise-219)
- [Exercise 2.20](#exercise-220)
- [Exercise 2.21](#exercise-221)
- [Exercise 2.22](#exercise-222)
- [Exercise 2.23](#exercise-223)
- [Exercise 2.24](#exercise-224)
- [Exercise 2.25](#exercise-225)
- [Exercise 2.26](#exercise-226)
- [Exercise 2.27](#exercise-227)
- [Exercise 2.28](#exercise-228)
- [Exercise 2.29](#exercise-229)
- [Exercise 2.30](#exercise-230)
- [Exercise 2.31](#exercise-231)
- [Exercise 2.32](#exercise-232)
- [Exercise 2.33](#exercise-233)
- [Exercise 2.34](#exercise-234)
- [Exercise 2.35](#exercise-235)
- [Exercise 2.36](#exercise-236)
- [Exercise 2.37](#exercise-237)
- [Exercise 2.38](#exercise-238)
- [Exercise 2.39](#exercise-239)
- [Exercise 2.40](#exercise-240)
- [Exercise 2.41](#exercise-241)
- [Exercise 2.42](#exercise-242)

## Exercise 2.1

> What are the differences between _int_, _long_, _long_ _long_,
and _short_? Between an unsigned and a signed type? Between a _float_ and
a _double_?

* (a)

    _short_, _int_, _long_, _long_ _long_ have differenct sizes:

    _short_: at least 16bits;

    _int_: at least as large as _short_;

    _long_: at least 32bits, and at least as large as _int_;

    _long_ _long_: at least 64bits, and at least as large as _long_, introduced by new standard.

* (b)

    A signed type represents negative or positive numbers(including zero);

    An unsigned type represents only values greater than or equal to zero.

* (c) 

    _float_: single-precision floating-point value, at least yields 6 significant digits;

    _double_: double-precision floating-point value, at least yields 10 significant digits.

## Exercise 2.2

> To calculate a mortgage payment, what types would you use
for the rate, principal, and payment? Explain why you selected each type.

rate: _double_

principal: _double_

payment: _double_

Reason: 
* none of the above can be represented only by integer in real world, so we should use 
floating point types.
* _double_ provides higher precision than _float_.


## Exercise 2.3

> What output will the following code produce?
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

The output(compiled by g++):
```cpp
32
4294967264 // 2^32 - (42 - 10)
32
-32
0
0
```

## Exercise 2.4

> Write a program to check whether your predictions were
correct. If not, study this section until you understand what the problem is.

[Exer02_04.cpp](Exer02_04.cpp)

## Exercise 2.5

> Determine the type of each of the following literals. Explain
the differences among the literals in each of the four examples:
```cpp
(a) 'a', L'a', "a", L"a"
(b) 10, 10u, 10L, 10uL, 012, 0xC
(c) 3.14, 3.14f, 3.14L
(d) 10, 10u, 10., 10e-2
```

(a)
```cpp
'a'  - char
L'a' - wchar_t
"a"  - const char[2]
L"a" - const wchar_t[2]
```
(b)
```cpp
10   - int
10u  - unsigned int
10L  - long
10uL - unsigned long
012  - octal int
0xC  - hexadecimal int
```
(c)
```cpp
3.14  - double
3.14f - float
3.14L - long double
```
(d)
```cpp
10    - int
10u   - unsigned int
10.   - double
10e-2 - double
```
   
## Exercise 2.6

> What, if any, are the differences between the following
definitions:
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

The first line uses decimal numbers as initializers, while the second line uses octal numbers as
initializers. But 9 is not a octal number, so it's an error.

## Exercise 2.7

> What values do these literals represent? What type does each
have?
```cpp
(a) "Who goes with F\145rgus?\012"
(b) 3.14e1L
(c) 1024f
(d) 3.14L
```

(a) "Who goes with Fergus?", string literal

(b) 31.4, double

(c) error, 1024 is not a floating-point number, thus cannot be appended with f

(d) 3.14, long double

## Exercise 2.8

> Using escape sequences, write a program to print _2M_ followed
by a newline. Modify the program to print _2_, then a tab, then an _M_, followed
by a newline.

[Exer02_08.cpp](Exer02_08.cpp)

## Exercise 2.9

> Explain the following definitions. For those that are illegal,
explain what’s wrong and how to correct it.
```cpp
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;
```

See [Exer02_09.cpp](Exer02_09.cpp).

## Exercise 2.10

> What are the initial values, if any, of each of the following variables?
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```

global_str: empty string

global_int: 0

local_int: undefined value

local_str: empty string

## Exercise 2.11

> Explain whether each of the following is a declaration or a
definition:
```cpp
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;
```

(a) definition

(b) definition

(c) declaration

## Exercise 2.12

> Which, if any, of the following names are invalid?
```cpp
(a) int double = 3.14;
(b) int _;
(c) int catch-22;
(d) int 1_or_2 = 1;
(e) double Double = 3.14;
```

(a) invalid, C++ keywords cannot be used as identifiers.

(b) valid, see [Page046_underline.cpp](Page046_underline.cpp) for more details.

(c) invalid, only underscore, digits and letters are permitted.

(d) invalid, identifiers cannot begin with a digit.

(e) valid, upper case and lower case letters are dinstinct.

[Exer02_12.cpp](Exer02_12.cpp)

## Exercise 2.13

> What is the value of _j_ in the following program?
```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

_j_ = 100, local variable _i_ hides global variable with the same name.

## Exercise 2.14

> Is the following program legal? If so, what values are printed?
```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

legal, output is 
```cpp
45 100
```

## Exercise 2.15

> Which of the following definitions, if any, are invalid? Why?
```cpp
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;
```

(a) valid.

(b) invalid, non-const reference cannot be initialized with a literal.

(c) valid.

(d) invalid, reference must be initialized.

## Exercise 2.16

> Which, if any, of the following assignments are invalid? If they are valid, explain what they do.
```cpp
int i = 0, &r1 = i; double d = 0, &r2 = d;
```
```cpp
(a) r2 = 3.14159;
(b) r2 = r1;
(c) i = r2;
(d) r1 = d;
```

(a) valid.

(b) valid.

(c) valid.

(d) valid.

All of the assignments above are not initializations. Plain references cannot be bound 
to another type, but could be assigned with another compatible type.

[Exer02_16.cpp](Exer02_16.cpp)

## Exercise 2.17

> What does the following code print?
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

```cpp
10 10
```

## Exercise 2.18

> Write code to change the value of a pointer. Write code to
change the value to which the pointer points.

```cpp
int *p = 0;
int val1 = 0, val2 = 2;
p = &val1;
*p = val2;
```

## Exercise 2.19

> Explain the key differences between pointers and references.

Key differences:
- references are not objects; pointers are objects.
- references must be initialized and can only be bound to one object, but pointers can be
bound to different objects and don't have to be initialized.

## Exercise 2.20

> What does the following program do?
```cpp
int i = 42;
int *p1 = &i; *p1 = *p1 * *p1;
```

The program initializes pointer _p1_ with _i_ and changes the value of _i_ to its 
square by dereferencing the pointer _p1_.

## Exercise 2.21

> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
```cpp
int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```

(a) illegal, plain pointers and the object they point to must have the same type.

(b) illegal, cannot initialize a pointer with an _int_, even the value the the _int_ is 0.

(c) legal.

## Exercise 2.22

> Assuming _p_ is a pointer to _int_, explain the following code:
```cpp
if (p) // ...
if (*p) // ...
```

```if (p)``` judges if the value of pointer _p_ is 0.

```if (*p)``` judges if the value of the object that _p_ points to is 0.

## Exercise 2.23

> Given a pointer _p_, can you determine whether _p_ points to a valid object? If so, how? If not, why not?

No, we cannot determine if _p_ points to a valid object. Because we cannot distinguish 
a valid address from an invalid one. 

## Exercise 2.24

> Why is the initialization of _p_ legal but that of _lp_ illegal?
```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

Because we can use a _void_ pointer to point to object of any type, otherwise the type of the pointer
and the object it points to must match.

## Exercise 2.25

> Determine the types and values of each of the following
variables.
```cpp
(a) int* ip, i, &r = i;
(b) int i, *ip = 0;
(c) int* ip, ip2;
```

(a)

_ip_: _int_ pointer, uninitialized

_i_: _int_, uninitialized

_r_: _int_ reference, bound to _i_

(b)

_i_: _int_, uninitialized

_ip_: _int_ pointer, initialized to 0

(c)

_ip_: _int_ pointer, uninitialized

_ip2_: _int_, uninitialized

## Exercise 2.26

> Which of the following are legal? For those that are illegal,
explain why.
```cpp
(a) const int buf; 
(b) int cnt = 0;     
(c) const int sz = cnt;
(d) ++cnt; ++sz;
```

(a) illegal, const object must be initialized.

(b) legal.

(c) legal.

(d) illegal, _sz_ is a const and thus its value cannot be changed.

## Exercise 2.27

> Which of the following initializations are legal? Explain why.
```cpp
(a) int i = -1, &r = 0;         
(b) int *const p2 = &i2;        
(c) const int i = -1, &r = 0;   
(d) const int *const p3 = &i2;  
(e) const int *p1 = &i2;   
(f) const int &const r2;        
(g) const int i2 = i, &r = i;
```

(a) illegal; we can not initialize a plain reference with a literal.

(b) legal.

(c) legal; we can initialize a const reference with a literal.

(d) legal; define a const pointer to a const _int_ and initialize it with _&i2_.

(e) legal.

(f) illegal; reference must be initialized.

(g) legal; const reference can be bound to a plain variable.

[Exer02_27.cpp](Exer02_27.cpp)

## Exercise 2.28

> Explain the following definitions. Identify any that are illegal.
```cpp
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;
```

(a) illegal; define a _int_ variable and a const pointer of _int_, const pointers must be initialized.

(b) illegal; define a plain pointer to _int_ and a const pointer to _int_, const pointers must be 
 initialized.

(c) illegal; const variable must be initialized.

(d) illegal; pointer to const must be initialized.

(e) legal; define a pointer to const _int_.

## Exercise 2.29

> Uing the variables in the previous exercise, which of the
following assignments are legal? Explain why.
```cpp
(a) i = ic;  
(b) p1 = p3; 
(c) p1 = &ic;
(d) p3 = &ic;
(e) p2 = p1; 
(f) ic = *p3;
```

(a) legal; we can assign to a plain variable with a const or non-const variable; top-level const are ignored.

(b) illegal; we cannot assign to a plain pointer with a  pointer to const; low-level const won't be ignored.

(c) illegal; plain pointer cannot point to const variable.

(d) illegal; const pointers cannot be assigned.

(e) illegal; const pointers cannot be assigned.

(f) illegal; const variables cannot be assigned.

## Exercise 2.30

> For each of the following declarations indicate whether the
object being declared has top-level or low-level _const_.
```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

_v2_: top-level const.

_v1_: non-const.

_p1_: non-const.

_r1_: non-const.

_p2_: low-level const.

_p3_: top-level and low-level const.

_r2_: low-level const.

## Exercise 2.31

> Given the declarations in the previous exercise determine
whether the following assignments are legal. Explain how the top-level or
low-level _const_ applies in each case.
```cpp
r1 = v2;
p1 = p2;
p2 = p1;
p1 = p3;
p2 = p3;
```

(a) legal; top-level const are ignored.

(b) illegal; low-level const won't be ignored, thus a non-const pointer cannot be assigned with a low-level const pointer.

(c) legal; a pointer to const can be assigned with another variable.

(d) illegal; the reason is the same as in (b).

(e) legal; top-level const are ignored, both _p2_ and _p3_ are low-level const.

## Exercise 2.32

> Is the following code legal or not? If not, how might you
make it legal?
```cpp
int null = 0, *p = null;
```

Illegal. It's illegal to assign a _int_ variable to a pointer, even if the variable's value is 0.(page 54)

## Exercise 2.33

> Using the variable definitions from this section, determine
what happens in each of these assignments:
```cpp
a=42;    b=42;    c=42;
d=42;    e=42;    g=42;
```

```cpp
a=42; // legal; a is a plain int
b=42; // legal; b is a plain int
c=42; // legal; c is a plain int
d=42; // illegal; d is a plain pointer
e=42; // illegal; e is a pointer to const
g=42; // illegal; g is a const int
```

## Exercise 2.34

> Write a program containing the variables and assignments from the
previous exercise.
Print the variables before and after the assignments to check
whether your predictions in the previous exercise were correct.
If not, study the examples until you can convince yourself you know
what led you to the wrong conclusion.

[Exer02_34.cpp](Exer02_34.cpp)

## Exercise 2.35

> Determine the types deduced in each of the following definitions.
Once you’ve figured out the types,
write a program to see whether you were correct.
```cpp
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i; const auto j2 = i, &k2 = i;
```

_j_: _int_; top-level const is ignored.

_k_: const reference to _int_.

_p_: pointer to const _int_.

_j2_: const _int_.

_k2_: const reference to _int_.

[Exer02_35.cpp](Exer02_35.cpp)

## Exercise 2.36

> In the following code, determine the type of each variable
and the value each variable has when the code finishes:
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

_c_: _int_;

_d_: reference to _int_.

When the code finishes:
```cpp
a = 4;
b = 4;
c = 4;
b = 4;
```

## Exercise 2.37

> Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if _i_ is an _int_, then the type of the expression _i_ = _x_ is _int&_. Using that knowledge, determine the type and value of each variable in this code:
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

_c_: _int_;

_d_: reference to _int_.

## Exercise 2.38

> Describe the differences in type deduction between _decltype_ and _auto_. Give an example of an expression where _auto_ and _decltype_ will deduce the same type and an example where they will deduce differing types.

Difference:

- _auto_ would ignore top-level const, _decltype_ won't:
```cpp
const int a = 42;
auto b = a;        // b is int
decltype(a) c = a; // c is const int
```

- _auto_ regards references as the types they refer to, _decltype_ regards reference as reference:
```cpp
const int a = 42, &ri = a;
auto b = ri;        // b is const int
decltype(ri) c = a; // c is const reference to int
```

- _auto_ doesn't differentiate rvalue from lvalue, _decltype_ does: 
```cpp
int a = 42;
auto b = (a);        // b is int
decltype((a)) c = a; // c is reference to int
```

## Exercise 2.39

> Compile the following program to see what happens when
you forget the semicolon after a class definition. Remember the message for
future reference.
```cpp
struct Foo { /* empty  */ } // Note: no semicolon
int main()
{
    return 0;
}
```

[Exer02_39.cpp](Exer02_39.cpp)

## Exercise 2.40

> Write your own version of the _Sales_data_ class.

[Sales_data.h](Sales_data.h)

## Exercise 2.41

> Use your _Sales_data_ class to rewrite the exercises in §
1.5.1(p. 22), § 1.5.2(p. 24), and § 1.6(p. 25). For now, you should define
your _Sales_data_ class in the same file as your _main_ function.

[Exer02_41_1.cpp](Exer02_41_1.cpp) | [Exer02_41_2.cpp](Exer02_41_2.cpp) | [Exer02_41_3.cpp](Exer02_41_3.cpp)

## Exercise 2.42

> Write your own version of the _Sales_data.h_ header and use it to rewrite the exercise from § 2.6.2(p. 76)

[Exer02_42_1.cpp](Exer02_42_1.cpp) | [Exer02_42_2.cpp](Exer02_42_2.cpp) | [Exer02_42_3.cpp](Exer02_42_3.cpp)