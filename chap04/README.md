##Exercise 4.1

> What is the value returned by 5 + 10 * 20/2?

105

##Exercise 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to
indicate the order in which the operands are grouped:
```cpp
(a) * vec.begin()
(b) * vec.begin() + 1
```

(a) \*(vec.begin())

(b) (\*(vec.begin())) + 1

##Exercise 4.3

> Order of evaluation for most of the binary operators is left
undefined to give the compiler opportunities for optimization.
This strategy presents a trade-off between efficient code generation
and potential pitfalls in the use of the language by the programmer.
Do you consider that an acceptable trade-off? Why or why not?

If all the compilers just forbid such operations, it'll be troublesome under some 
circumstances when a programmer does need to refer and change the same object. As 
long as a programmer knows exactly how his compiler processes the operation, he can take
advantage of it. But such codes highly depend on environment. It's not recommended.

##Exercise 4.4

> Parenthesize the following expression to show how it is evaluated.
Test your answer by compiling the expression (without parentheses)
and printing its result.
```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```

[Exer04_04.cpp](Exer04_04.cpp) 

##Exercise 4.5

> Determine the result of the following expressions.
```cpp
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5 
(d) -30 / 3 * 21 % 4
```

[Exer04_05.cpp](Exer04_05.cpp) 

##Exercise 4.6

> Write an expression to determine whether an int value is even or odd.

```cpp
ival % 2 == 0
```

##Exercise 4.7

> What does overflow mean? Show three expressions that will overflow.

Overflow: a value is computed that is outside the range of values that its type
can represent. Such as:
```cpp
short si1 = 32767 + 1;
unsigned short si2 = 0xFFFF + 1;
unsigned char ch = 256;
```

[Exer04_07.cpp](Exer04_07.cpp) 

##Exercise 4.8

> Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.

- `AND`: right-hand operands are evaluated if and only if left-hand operands are true;
- `OR`: right-hand operands are evaluated if and only if left-hand operands are false;
- `EQALITY`: right-hand operands are always evaluated, but the order of evaluation is not guaranteed.

##Exercise 4.9

> Explain the behavior of the condition in the following if:
```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

The if first evaluates if the const pointer _cp_ is a null pointer. If _cp_ is a null pointer,
the value of the expression is false, otherwise the value of the object that _cp_ points to is
evaluated; if the value is true, the value of the expression is true, otherwise the result is
false.

##Exercise 4.10

> Write the condition for a while loop that would read ints from
the standard input and stop when the value read is equal to 42.

[Exer04_10.cpp](Exer04_10.cpp) 

##Exercise 4.11

> Write an expression that tests four values, a, b, c, and d,
and ensures that a is greater than b, which is greater than c,
which is greater than d.

```cpp
a > b && b > c && c > d
```

##Exercise 4.12

> Assuming _i_, _j_, and _k_ are all _ints_, explain what `i != j < k` means.

`i != j < k` judges if the value of _i_ is equal to the value of `j < k`, i.e.:
- when _j_ is less than _k_, if _i_ is equal to 0, the result is _true_, otherwise the result is _false_;
- when _j_ is greater or equal to _k_, if _i_ is equal to 0, the result is _false_, otherwise the result is _true_.

##Exercise 4.13

> What are the values of _i_ and _d_ after each assignment?
```cpp
int i;   double d;
(a) d = i = 3.5;
(b) i = d = 3.5;
```

(a) i = 3, d = 3.0
(b) i = 3, d = 3.5

##Exercise 4.14

> Explain what happens in each of the if tests:
```cpp
if (42 = i)
if (i = 42)
```

- The first if test tries to assign _i_ to an _int_ literal, which is an error.

- The second if test assigns 42 to _i_, thus the expression `i = 42` returns _i_, whose value is 
42 and the result of if tests is always true.
 
##Exercise 4.15

> The following assignment is illegal. Why? How would you correct it?
```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

The assignment is equivalent to:
```cpp
dval = (ival = (pi = 0));
```
We cannot assign the value of a pointer to an _int_.

##Exercise 4.16

> Although the following are legal,
they probably do not behave as the programmer expects. Why?
Rewrite the expressions as you think they should be.
```cpp
(a) if (p = getPtr() != 0)
(b) if (i = 1024)
```

(a) the expression assigns the result of `(getPtr() != 0)` to _p_, rather than assigns `getPtr()` 
to _p_ and compares _p_ to 0. It should be:
```cpp
if ((p = getPtr()) != 0)
```

(b) the expression assigns 1024 to _i_ rather than compares _i_ to 1024. It should be:
```cpp
if (i == 1024)
```

##Exercise 4.17

> Explain the difference between prefix and postfix increment.

- prefix increment: increment its operand and yields the changed object as its result;
- postfix increment: increment its operand but yields a copy of the original, unchanged values as its 
result.

##Exercise 4.18

> What would happen if the while loop on page 148 that prints
the elements from a vector used the prefix increment operator?

```cpp
cout << *++pbeg << endl;
```
If we used prefix increment as above, first _pbeg_ increments and then its value is
returned. Thus _*++pbeg_ is equivalent to *(pbeg + 1). The problem is this expression
will ignore the first element in the vector.

##Exercise 4.19

> Given that _ptr_ points to an _int_, that _vec_ is a _vector<int>_,
and that _ival_ is an _int_, explain the behaviour of each of these expressions.
Which, if any, are likely to be incorrect? Why? How might each be corrected?
```cpp
(a) ptr != 0 && *ptr++ 
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]
```

(a) If _ptr_ is not a null pointer, and the value of the object 

##Exercise 4.20

> Assuming that _iter_ is a _vector<string>::iterator_,
indicate which, if any, of the following expressions are legal.
Explain the behaviour of the legal expressions and
why those that aren’t legal are in error.
```cpp
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty()
(d) iter-> empty();
(e) ++*iter;
(f) iter++-> empty();
```

##Exercise 4.21

> Write a program to use a conditional operator to find the
elements in a _vector<int>_ that have odd value and double the value of
each such element.

[Exer04_21.cpp](Exer04_21.cpp) 

##Exercise 4.22

> Extend the program that assigned high pass, pass, and fail
grades to also assign low pass for grades between 60 and 75 inclusive. Write
two versions: One version that uses only conditional operators; the other
should use one or more if statements. Which version do you think is easier
to understand and why?

[Exer04_22_1.cpp](Exer04_22_1.cpp) | [Exer04_22_2.cpp](Exer04_22_2.cpp) 

##Exercise 4.23

> The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

##Exercise 4.24

> Our program that distinguished between high pass, pass,
and fail depended on the fact that
the conditional operator is right associative.
Describe how that operator would be evaluated
if the operator were left associative.

[Exer04_24.cpp](Exer04_24.cpp) 

##Exercise 4.25

> What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?

##Exercise 4.26

> In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

##Exercise 4.27

> What is the result of each of these expressions?
```cpp
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2 // == 3
(b) ul1 | ul2 // == 7
(c) ul1 && ul2 // == true
(d) ul1 || ul2 // == ture
```

##Exercise 4.28

> Write a program to print the size of each of the built-in
types.

[Exer04_28.cpp](Exer04_28.cpp) 

##Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
```cpp
int x[10];   int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

[Exer04_29.cpp](Exer04_29.cpp) 

##Exercise 4.30

> Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
```cpp
(a) sizeof x + y     
(b) sizeof p-> mem[i]
(c) sizeof a < b     
(d) sizeof f()
```

##Exercise 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

[Exer04_31.cpp](Exer04_31.cpp) 

##Exercise 4.32

> Explain the following loop.
```cpp
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

##Exercise 4.33

> Using Table 4.12 (p. 166) explain what the following expression does:
```cpp
someValue ? ++x, ++y : --x, --y
```

[Exer04_33.cpp](Exer04_33.cpp) 

##Exercise 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions:
```cpp
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
```
Remember that you may need to consider the associativity of the operators.

##Exercise 4.35

> Given the following definitions,
```cpp
char cval; int ival; unsigned int ui; float fval; double dval;
```
identify the implicit type conversions, if any, taking place:
```cpp
(a) cval = 'a' + 3;
(b) fval = ui - ival * 1.0;
(c) dval = ui * fval;
(d) cval = ival + fval + dval;
```

##Exercise 4.36

> Assuming i is an int and d is a double write the expression i *= d so that it does integral, rather than floating-point, multiplication.

##Exercise 4.37

> Rewrite each of the following old-style casts to use a named cast:
```cpp
int i;    double d;    const string *ps;    char *pc; void *pv;
(a) pv = (void*)ps;
(b) i = int(*pc);  
(c) pv = &d;       
(d) pc = (char*)pv;
```

[Exer04_37.cpp](Exer04_37.cpp) 

##Exercise 4.38

> Explain the following expression:
```cpp
double slope = static_cast<double>(j/i);
```
