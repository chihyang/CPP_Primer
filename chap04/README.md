# Answers To Non-programming Exercises

## Contents
- [Exercise 4.1](#exercise-41)
- [Exercise 4.2](#exercise-42)
- [Exercise 4.3](#exercise-43)
- [Exercise 4.4](#exercise-44)
- [Exercise 4.5](#exercise-45)
- [Exercise 4.6](#exercise-46)
- [Exercise 4.7](#exercise-47)
- [Exercise 4.8](#exercise-48)
- [Exercise 4.9](#exercise-49)
- [Exercise 4.10](#exercise-410)
- [Exercise 4.11](#exercise-411)
- [Exercise 4.12](#exercise-412)
- [Exercise 4.13](#exercise-413)
- [Exercise 4.14](#exercise-414)
- [Exercise 4.15](#exercise-415)
- [Exercise 4.16](#exercise-416)
- [Exercise 4.17](#exercise-417)
- [Exercise 4.18](#exercise-418)
- [Exercise 4.19](#exercise-419)
- [Exercise 4.20](#exercise-420)
- [Exercise 4.21](#exercise-421)
- [Exercise 4.22](#exercise-422)
- [Exercise 4.23](#exercise-423)
- [Exercise 4.24](#exercise-424)
- [Exercise 4.25](#exercise-425)
- [Exercise 4.26](#exercise-426)
- [Exercise 4.27](#exercise-427)
- [Exercise 4.28](#exercise-428)
- [Exercise 4.29](#exercise-429)
- [Exercise 4.30](#exercise-430)
- [Exercise 4.31](#exercise-431)
- [Exercise 4.32](#exercise-432)
- [Exercise 4.33](#exercise-433)
- [Exercise 4.34](#exercise-434)
- [Exercise 4.35](#exercise-435)
- [Exercise 4.36](#exercise-436)
- [Exercise 4.37](#exercise-437)
- [Exercise 4.38](#exercise-438)

## Exercise 4.1

> What is the value returned by 5 + 10 * 20/2?

105

## Exercise 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to
indicate the order in which the operands are grouped:
```cpp
(a) * vec.begin()
(b) * vec.begin() + 1
```

(a) \*(vec.begin())

(b) (\*(vec.begin())) + 1

## Exercise 4.3

> Order of evaluation for most of the binary operators is left
undefined to give the compiler opportunities for optimization.
This strategy presents a trade-off between efficient code generation
and potential pitfalls in the use of the language by the programmer.
Do you consider that an acceptable trade-off? Why or why not?

If all the compilers just forbid such operations, it'll be troublesome under some 
circumstances when a programmer does need to refer and change the same object. As 
long as a programmer knows exactly how his compiler processes the operation, he can take
advantage of it. But such codes highly depend on environment. It's not recommended.

## Exercise 4.4

> Parenthesize the following expression to show how it is evaluated.
Test your answer by compiling the expression (without parentheses)
and printing its result.
```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```

[Exer04_04.cpp](Exer04_04.cpp) 

## Exercise 4.5

> Determine the result of the following expressions.
```cpp
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5 
(d) -30 / 3 * 21 % 4
```

[Exer04_05.cpp](Exer04_05.cpp) 

## Exercise 4.6

> Write an expression to determine whether an int value is even or odd.

```cpp
ival % 2 == 0
```

## Exercise 4.7

> What does overflow mean? Show three expressions that will overflow.

Overflow: a value is computed that is outside the range of values that its type
can represent. Such as:
```cpp
short si1 = 32767 + 1;
unsigned short si2 = 0xFFFF + 1;
unsigned char ch = 256;
```

[Exer04_07.cpp](Exer04_07.cpp) 

## Exercise 4.8

> Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.

- `AND`: right-hand operands are evaluated if and only if left-hand operands are true;
- `OR`: right-hand operands are evaluated if and only if left-hand operands are false;
- `EQALITY`: right-hand operands are always evaluated, but the order of evaluation is not guaranteed.

## Exercise 4.9

> Explain the behavior of the condition in the following if:
```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

The if first evaluates if the const pointer _cp_ is a null pointer. If _cp_ is a null pointer,
the value of the expression is false, otherwise the value of the object that _cp_ points to is
evaluated; if the value is true, the value of the expression is true, otherwise the result is
false.

## Exercise 4.10

> Write the condition for a while loop that would read ints from
the standard input and stop when the value read is equal to 42.

[Exer04_10.cpp](Exer04_10.cpp) 

## Exercise 4.11

> Write an expression that tests four values, _a_, _b_, _c_, and _d_,
and ensures that _a_ is greater than _b_, which is greater than _c_,
which is greater than _d_.

```cpp
a > b && b > c && c > d
```

## Exercise 4.12

> Assuming _i_, _j_, and _k_ are all _ints_, explain what `i != j < k` means.

`i != j < k` judges if the value of _i_ is equal to the value of `j < k`, i.e.:
- when _j_ is less than _k_, if _i_ is equal to 0, the result is _true_, otherwise the result is _false_;
- when _j_ is greater than or equal to _k_, if _i_ is equal to 0, the result is _false_, otherwise the result is _true_.

## Exercise 4.13

> What are the values of _i_ and _d_ after each assignment?
```cpp
int i;   double d;
(a) d = i = 3.5;
(b) i = d = 3.5;
```

(a) _i_ = 3, _d_ = 3.0

(b) _i_ = 3, _d_ = 3.5

## Exercise 4.14

> Explain what happens in each of the if tests:
```cpp
if (42 = i)
if (i = 42)
```

- The first if test tries to assign _i_ to an _int_ literal, which is an error.

- The second if test assigns 42 to _i_, thus the expression `i = 42` returns _i_, 
whose value is 42. The result of if tests is always true.
 
## Exercise 4.15

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

## Exercise 4.16

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

## Exercise 4.17

> Explain the difference between prefix and postfix increment.

- prefix increment: increment its operand and yields the changed object as its result;
- postfix increment: increment its operand but yields a copy of the original, unchanged values as its 
result.

## Exercise 4.18

> What would happen if the while loop on page 148 that prints
the elements from a vector used the prefix increment operator?

```cpp
cout << *++pbeg << endl;
```
If we used prefix increment as above, first _pbeg_ increments and then its value is
returned. Thus _*++pbeg_ is equivalent to *(pbeg + 1). The problem is this expression
will ignore the first element in the vector.

## Exercise 4.19

> Given that _ptr_ points to an _int_, that _vec_ is a _vector<int>_,
and that _ival_ is an _int_, explain the behaviour of each of these expressions.
Which, if any, are likely to be incorrect? Why? How might each be corrected?
```cpp
(a) ptr != 0 && *ptr++ 
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]
```

(a) If _ptr_ is not a null pointer, and the value of the object that _ptr_ points to is
not 0, the result is true, otherwise the result is false.

(b) If the original value of _ival_ and the value of (_ival_ + 1) are not 0, the result is
true, otherwise the result is false.

(c) If evaluation order is from left to right, the expression judges if _vec[ival]_ is less than or
equal to _vec[ival + 1]_.
If the evaluation order is from right to left, the expression
is eqivalent to:
```cpp
vec[ival]_ <= vec[ival];
++ival;
```
which is always true.

## Exercise 4.20

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

(a) Legal. return value of *_iter_, then move _iter_ to next position;

(b) Legal. return value of *_iter_, the increment the return value of *_iter_;

(c) Illegal, this is equivalent to:
```cpp
*(iter.empty())
```
But the result of iter.empty() is a _bool_ cannot be dereferenced.

(d) Legal. It's equivalent to:
```cpp
(*iter).empty();
```

(e) Legal. It's equal to:
```cpp
++(*iter);
```

(f) First increment _iter_, then return a copy of the original _iter_, then access
member function _empty_ to judge if the _string_ that the original _iter_ points
is empty.

## Exercise 4.21

> Write a program to use a conditional operator to find the
elements in a _vector<int>_ that have odd value and double the value of
each such element.

[Exer04_21.cpp](Exer04_21.cpp) 

## Exercise 4.22

> Extend the program that assigned high pass, pass, and fail
grades to also assign low pass for grades between 60 and 75 inclusive. Write
two versions: One version that uses only conditional operators; the other
should use one or more if statements. Which version do you think is easier
to understand and why?

_If_ version is much easier to understand, while conditional operators version is simpler and 
somewhat error-prone.

[Exer04_22_1.cpp](Exer04_22_1.cpp) | [Exer04_22_2.cpp](Exer04_22_2.cpp) 

## Exercise 4.23

> The following expression fails to compile due to operator precedence.
Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s";
```

The precedence of +, ==, ?: and = is(from high to low):
+ == ?: =
This is equivalent to:
```cpp
string p1 = (((s + s[s.size() - 1]) == 's') ? "" : "s");
```
The value of _p1_ is either empty string or "s".

It should be:
```cpp
string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
```

## Exercise 4.24

> Our program that distinguished between high pass, pass,
and fail depended on the fact that
the conditional operator is right associative.
Describe how that operator would be evaluated
if the operator were left associative.

if ? : is left associative, result is something like below
```cpp
string finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```
It's a wrong expression for type of two expressions of the first 
conditional operator is neither the same type nor able to be converted to
the same type.

[Exer04_24.cpp](Exer04_24.cpp)

## Exercise 4.25

> What is the value of ~'q' << 6 on a machine with 32-bit _ints_ and 8 bit _chars_, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?

The expression is equivalent to:
```cpp
(~'q') << 6
```

The result is:
```cpp
11111111 11111111 11100011 10000000
```

## Exercise 4.26

> In our grading example in this section, what would happen if we used _unsigned_ _int_ as the type for _quiz1_?

On machine where _int_ is 16-bit wise, we may get unexpected result.

## Exercise 4.27

> What is the result of each of these expressions?
```cpp
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2
(b) ul1 | ul2
(c) ul1 && ul2
(d) ul1 || ul2
```

(a) 3;

(b) 7;

(c) true;

(d) true.

## Exercise 4.28

> Write a program to print the size of each of the built-in
types.

[Exer04_28.cpp](Exer04_28.cpp) 

## Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
```cpp
int x[10];   int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;
```

```cpp
cout << sizeof(x)/sizeof(*x) << endl;
```
The result is 10, because the array won't be converted to pointer when we use _sizeof_.

```cpp
cout << sizeof(p)/sizeof(*p) << endl;
```
The result is machine dependent. See the source file below.

[Exer04_29.cpp](Exer04_29.cpp) 

## Exercise 4.30

> Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
```cpp
(a) sizeof x + y     
(b) sizeof p-> mem[i]
(c) sizeof a < b     
(d) sizeof f()
```

(a) (sizeof x) + y

(b) (sizeof((p->mem)[i]))

(c) (sizeof a) < b

(d) sizeof(f())

## Exercise 4.31

> The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

In this program there is no difference, we can use both prefix and postfix increment or decrement. But postfix version requires extra steps, so it's not recommended.

[Exer04_31.cpp](Exer04_31.cpp) 

## Exercise 4.32

> Explain the following loop.
```cpp
constexpr int size = 5;
int ia[size] = { 1, 2, 3, 4, 5 };
for (int *ptr = ia, ix = 0;
    ix != size && ptr != ia+size;
    ++ix, ++ptr) { /* ... */ }
```

The loop above accesses every element in _ia_. The first comma expression:
```cpp
int *ptr = ia, ix = 0
```
initializes an _int_ pointer with _ia_, and an _int_ with 0.

The last comma expression:
```cpp
++ix, ++ptr
```
increment _ix_ and _ptr_ to access to next element in _ia_

## Exercise 4.33

> Using Table 4.12 (p. 166) explain what the following expression does:
```cpp
someValue ? ++x, ++y : --x, --y
```

Conditional operator will regard the expression between ? and : as a whole. So even
if comma has a lower precedence than ?:, ++x, ++y is grouped together. Not that
++x is grouped with ? and ++ y with :. Thus the expression is equivalent to:

```cpp
(someValue ? (++x, ++y) : --x) , --y
```

Rather than:

```cpp
(someValue ? ++x), (++y : --x , --y)
```

The language tries to make the expression meaningful.

[Exer04_33.cpp](Exer04_33.cpp) 

Please refer to [the answer](https://github.com/Mooophy/Cpp-Primer/tree/master/ch04) from
[Mooophy](https://github.com/Mooophy).

## Exercise 4.34

> Given the variable definitions in this section, explain what conversions take place in the following expressions:
```cpp
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
```
Remember that you may need to consider the associativity of the operators.

(a) _fval_ is converted to _bool_.

(b) _ival_ is converted to _float_, then the result is converted to _double_.

(c) _cval_ is promoted to _int_, then _ival_ * _cval_ is converted to _double_.

## Exercise 4.35

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

(a) 'a' is converted to _int_, then the result is converted to _char_.

(b) _ival_ is converted to _double_, _ui_ is converted to _double_, the result is 
converted to _float_.

(c) _ui_ is converted to _float_, then the result is converted to _double_.

(d) _ival_ is converted to _float_, then the result of `ival + fval` is converted to _double_, then 
the result of `ival + fval + dval` is converted to _char_.

## Exercise 4.36

> Assuming _i_ is an _int_ and _d_ is a _double_ write the expression `i *= d` so that it does integral, rather than floating-point, multiplication.

```cpp
i *= static_cast<int>(d);
```

## Exercise 4.37

> Rewrite each of the following old-style casts to use a named cast:
```cpp
int i;    double d;    const string *ps;    char *pc; void *pv;
(a) pv = (void*)ps;
(b) i = int(*pc);  
(c) pv = &d;       
(d) pc = (char*)pv;
```

[Exer04_37.cpp](Exer04_37.cpp) 

## Exercise 4.38

> Explain the following expression:
```cpp
double slope = static_cast<double>(j/i);
```

First `j/i` is evaluated, then the result is converted to a double, and _slope_
is initialized with it.
