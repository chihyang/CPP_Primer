# Answers Of Non-programming Exercises

## Contents
- [Exercise 6.1](#exercise-61)
- [Exercise 6.2](#exercise-62)
- [Exercise 6.3](#exercise-63)
- [Exercise 6.4](#exercise-64)
- [Exercise 6.5](#exercise-65)
- [Exercise 6.6](#exercise-66)
- [Exercise 6.7](#exercise-67)
- [Exercise 6.8](#exercise-68)
- [Exercise 6.9](#exercise-69)
- [Exercise 6.10](#exercise-610)
- [Exercise 6.11](#exercise-611)
- [Exercise 6.12](#exercise-612)
- [Exercise 6.13](#exercise-613)
- [Exercise 6.14](#exercise-614)
- [Exercise 6.15](#exercise-615)
- [Exercise 6.16](#exercise-616)
- [Exercise 6.17](#exercise-617)
- [Exercise 6.18](#exercise-618)
- [Exercise 6.19](#exercise-619)
- [Exercise 6.20](#exercise-620)
- [Exercise 6.21](#exercise-621)
- [Exercise 6.22](#exercise-622)
- [Exercise 6.23](#exercise-623)
- [Exercise 6.24](#exercise-624)
- [Exercise 6.25](#exercise-625)
- [Exercise 6.26](#exercise-626)
- [Exercise 6.27](#exercise-627)
- [Exercise 6.28](#exercise-628)
- [Exercise 6.29](#exercise-629)
- [Exercise 6.30](#exercise-630)
- [Exercise 6.31](#exercise-631)
- [Exercise 6.32](#exercise-632)
- [Exercise 6.33](#exercise-633)
- [Exercise 6.34](#exercise-634)
- [Exercise 6.35](#exercise-635)
- [Exercise 6.36](#exercise-636)
- [Exercise 6.37](#exercise-637)
- [Exercise 6.38](#exercise-638)
- [Exercise 6.39](#exercise-639)
- [Exercise 6.40](#exercise-640)
- [Exercise 6.41](#exercise-641)
- [Exercise 6.42](#exercise-642)
- [Exercise 6.43](#exercise-643)
- [Exercise 6.44](#exercise-644)
- [Exercise 6.45](#exercise-645)
- [Exercise 6.46](#exercise-646)
- [Exercise 6.47](#exercise-647)
- [Exercise 6.48](#exercise-648)
- [Exercise 6.49](#exercise-649)
- [Exercise 6.50](#exercise-650)
- [Exercise 6.51](#exercise-651)
- [Exercise 6.52](#exercise-652)
- [Exercise 6.53](#exercise-653)
- [Exercise 6.54](#exercise-654)
- [Exercise 6.55](#exercise-655)
- [Exercise 6.56](#exercise-656)

## Exercise 6.1

> What is the difference between a parameter and an argument?

Arguments are the initializers for a function's parameters. We define a function
with parameter(s), while we call a function with argument(s). If the number of 
parameters are zero, so is arguments'.

## Exercise 6.2

> Indicate which of the following functions are in error and why.
Suggest how you might correct the problems.
```cpp
(a) int f() { // return type should be string
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ } // return type is essential
(c) int calc(int v1, int v1) { /* ... */ } // parameters must have different identifiers
(d) double square (double x) return x * x; // function body must be closed by curly braces
```

## Exercise 6.3

> Write and test your own version of fact.

[Exer06_03.cpp](Exer06_03.cpp) 

## Exercise 6.4

> Write a function that interacts with the user, asking for a
number and generating the factorial of that number. Call this function from
main.

[Exer06_04.cpp](Exer06_04.cpp) 

## Exercise 6.5

> Write a function to return the absolute value of its argument.

[Exer06_05.cpp](Exer06_05.cpp) 

## Exercise 6.6

> Explain the differences between a parameter, a local variable,
and a local static variable. Give an example of a function in which each
might be useful.

- differences
    - parameter: local variables declared inside the function parameter list. Parameters are initialized
by arguments provided in each function call. So parameter is a kind of local variable.

    - local variable: variables defined in a function body, only accessible to that function and hiding
declarations of the same name made in an outer scope. Parameter is a kind of special
local variable. They are automatic objects.

    - local static variable: local variables whose lifetime continues across calls to the function.

- example
    - parameter: for many function calls we need pass info from outside the function. Such as 
	`val` in `int fact(int val)`

    - local variable: we don't want those variables only useful to the execution of a function
    to exist through the execution of the program. So we define those as local variables. Such 
	as `ret` in `int fact(int val)`
	
	- local static variable: some variables are necessary if we want to know the status
	of calls to a function. For example, we have a function to turn on/off lights.
	We can define a static variable to represent the status of lights. Every time we call it,
	we turn on/off lights, depending on we turned off/on lights last time.
    
## Exercise 6.7

> Write a function that returns 0 when it is first called and then
generates numbers in sequence each time it is called again.

[Exer06_07.cpp](Exer06_07.cpp) 

## Exercise 6.8

> Write a header file named Chapter6.h that contains
declarations for the functions you wrote for the exercises in § 6.1 (p. 205).

[Chapter6.h](Chapter6.h)

## Exercise 6.9

> Write your own versions of the fact.cc and factMain.cc
files. These files should include your Chapter6.h from the exercises in the
previous section. Use these files to understand how your compiler supports
separate compilation.

[Exer06_09.cpp](Exer06_09.cpp) 

## Exercise 6.10

> Using pointers, write a function to swap the values of two
ints. Test the function by calling it and printing the swapped values.

[Exer06_10.cpp](Exer06_10.cpp) 

## Exercise 6.11

> Write and test your own version of reset that takes a
reference.

[Exer06_11.cpp](Exer06_11.cpp) 

## Exercise 6.12

> Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
to use references instead of pointers to swap the value of two ints. Which
version do you think would be easier to use and why?

Here reference is better than pointer. If we use pointer, we have to copy value,
we have to write address-of operator before every argument. Once we omit anything,
our program won't work.

Using reference, on the other hand, is more convenient. Except special declarations
of the parameter list, we can use every parameter a plain variable. In addition, when
we pass argument, we don't have to worry about omitting anything.

[Exer06_12.cpp](Exer06_12.cpp) 

## Exercise 6.13

> Assuming T is the name of a type, explain the difference
between a function declared as void f(T) and void f(T&).

We call the function _f(T)_ by passing value; we call _f(T&)_ by passing reference.
When we change the parameter of _f(T)_, the argument isn't effected. When we change the 
parameter of _f(T&)_, the argument is changed.


## Exercise 6.14

> Give an example of when a parameter should be a reference
type. Give an example of when a parameter should not be a reference.

If we want to swap two arguments, we must use reference:
```cpp
void swap(int &a, int &b);
```

If we want to return the bigger one of two variables, we have to use non reference:
```cpp
int max(int a, int b)
{
    return ((a > b) ? a : b));
}
```

## Exercise 6.15

> Explain the rationale for the type of each of _find_char_’s
parameters In particular, why is _s_ a reference to const but _occurs_ is a
plain reference? Why are these parameters references, but the _char_
parameter _c_ is not? What would happen if we made _s_ a plain reference?
What if we made _occurs_ a reference to const?

1. _s_ is a reference to const because we don't want to change contents of argument passed
to _s_ incidentally. Reference parameters that are not changed in a function should be
references to const. We use references because we don't want to copy objects, which
is not efficient and sometimes not allowed.

2. _occurs_ is a plain reference because we want and need to change its value. We use
reference as to return the results. If we don't use reference, we don't know the results,
because _find_char_ doesn't return it. If we use reference to const, we can't change the
value of the argument, thus we cannot get intended result.

3. We don't use reference but _char_ because neither do we need to change the argument
passed to _c_ nor keep the value of the argument. We just need a copy of the argument.
And for built-in type, copy is efficient enough(Please refer to Effective C++).

4. If we made _s_ a plain reference, we might change the value of the argument by accident.

5. If we made _occurs_ a reference to const, we would not be able to change the 
argument's value.

## Exercise 6.16

> The following function, although legal, is less useful than it
might be. Identify and correct the limitation on this function:
```cpp
bool is_empty(string& s) { return s.empty(); }
```

The parameter is a plain reference, thus we can not pass string literal. Correction:
```cpp
bool is_empty(const string& s) { return s.empty(); }
```

## Exercise 6.17

> Write a function to determine whether a string contains
any capital letters. Write a function to change a string to all lowercase. Do
the parameters you used in these functions have the same type? If so, why?
If not, why not?

- Function:
```cpp
bool contain_upper(const string &s)
{
    for (auto c: s) {
	    if (isupper(c))
		    return true;
	}
    return false;
}
```

```cpp
void to_lower_str(string &s)
{
    for (auto &c: s) {
        c = tolower(c);
	}
}
```

- Difference:
    - The former takes a reference to const string because we know we won't change the 
	argument.
	- The latter takes a plain reference to string because we need to change the
	argument.

## Exercise 6.18

> Write declarations for each of the following functions. When
you write these declarations, use the name of the function to indicate what
the function does.
(a) A function named compare that returns a bool and has two parameters
that are references to a class named matrix.
(b) A function named change_val that returns a vector<int> iterator
and takes two parameters: One is an int and the other is an iterator for a
vector<int>.

```cpp
(a) bool compare(const matrix&, const matrix&);
(b) vector<int>::iterator change_val(int, vector<int>::iterator);
```

## Exercise 6.19

> Given the following declarations, determine which calls are
legal and which are illegal. For those that are illegal, explain why.
```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```

- (a) illegal, offer two arguments but only requires one.
- (b) legal.
- (c) legal, 66 is converted to double.
- (d) legal, 3.8 is truncated to 3.

## Exercise 6.20

> When should reference parameters be references to const?
What happens if we make a parameter a plain reference when it could be a
reference to const?

## Exercise 6.21

> Write a function that takes an int and a pointer to an int
and returns the larger of the int value or the value to which the pointer
points. What type should you use for the pointer?

## Exercise 6.22

> Write a function to swap two int pointers.

[Exer06_22.cpp](Exer06_22.cpp) 

## Exercise 6.23

> Write your own versions of each of the print functions
presented in this section. Call each of these functions to print i and j
defined as follows:
```cpp
int i = 0, j[2] = {0, 1};
```

[Exer06_23.cpp](Exer06_23.cpp) 

## Exercise 6.24

> Explain the behavior of the following function. If there are
problems in the code, explain what they are and how you might fix them.
```cpp
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
    cout << ia[i] << endl;
}
```

## Exercise 6.25

> Write a main function that takes two arguments.
Concatenate the supplied arguments and print the resulting string.

[Exer06_25.cpp](Exer06_25.cpp) 

## Exercise 6.26

> Write a program that accepts the options presented in this
section. Print the values of the arguments passed to main.

[Exer06_26.cpp](Exer06_26.cpp) 

## Exercise 6.27

> Write a function that takes an initializer_list<int>
and produces the sum of the elements in the list.

[Exer06_27.cpp](Exer06_27.cpp) 

## Exercise 6.28

> In the second version of error_msg that has an ErrCode
parameter, what is the type of elem in the for loop?

## Exercise 6.29

> When you use an initializer_list in a range for
would you ever use a reference as the loop control variable? If so, why? If
not, why not?

## Exercise 6.30

> Compile the version of str_subrange as presented on
page 223 to see what your compiler does with the indicated errors.

[Exer06_30.cpp](Exer06_30.cpp) 

## Exercise 6.31

> When is it valid to return a reference? A reference to
const?

## Exercise 6.32

> Indicate whether the following function is legal. If so, explain
what it does; if not, correct any errors and then explain it.
```cpp
int &get(int *arry, int index) { return arry[index]; }
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
    get(ia, i) = i;
}
```
[Exer06_32.cpp](Exer06_32.cpp) 

## Exercise 6.33

> Write a recursive function to print the contents of a vector.

[Exer06_33.cpp](Exer06_33.cpp) 

## Exercise 6.34

> What would happen if the stopping condition in factorial
were
```cpp
if (val != 0)
```

## Exercise 6.35

> the recursive function will always use `val` as the parameter. *a recursion loop* would happen.

## Exercise 6.36

> Write the declaration for a function that returns a reference
to an array of ten strings, without using either a trailing return,
decltype, or a type alias.

## Exercise 6.37

> Write three additional declarations for the function in the
previous exercise. One should use a type alias, one should use a trailing
return, and the third should use decltype. Which form do you prefer and
why?

## Exercise 6.38

> Revise the _arrPtr_ function on to return a reference to the
array.

## Exercise 6.39

> Explain the effect of the second declaration in each one of
the following sets of declarations. Indicate which, if any, are illegal.
```cpp
(a) int calc(int, int);
int calc(const int, const int);
(b) int get();
double get();
(c) int *reset(int *);
double *reset(double *);
```

## Exercise 6.40

> Which, if either, of the following declarations are errors?
Why?
```cpp
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);
```

## Exercise 6.41

> Which, if any, of the following calls are illegal? Why? Which,
if any, are legal but unlikely to match the programmer’s intent? Why?
```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24,10);
(c) init(14, '*');
```

## Exercise 6.42

> Give the second parameter of make_plural (§ 6.3.2, p.
224) a default argument of 's'. Test your program by printing singular and
plural versions of the words success and failure.

[Exer06_42.cpp](Exer06_42.cpp) 

## Exercise 6.43

> Which one of the following declarations and definitions would
you put in a header? In a source file? Explain why.
```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```

[Exer06_43.cpp](Exer06_43.cpp) 

## Exercise 6.44

> Rewrite the isShorter function from § 6.2.2 (p. 211) to be
inline.

## Exercise 6.45

> Review the programs you’ve written for the earlier exercises
and decide whether they should be defined as inline. If so, do so. If not,
explain why they should not be inline.

## Exercise 6.46

> Would it be possible to define isShorter as a constexpr?
If so, do so. If not, explain why not.

[Exer06_46.cpp](Exer06_46.cpp) 

## Exercise 6.47

> Revise the program you wrote in the exercises in § 6.3.2 (p.
228) that used recursion to print the contents of a vector to conditionally
print information about its execution. For example, you might print the size of
the vector on each call. Compile and run the program with debugging
turned on and again with it turned off.

[Exer06_47.cpp](Exer06_47.cpp) 

## Exercise 6.48

> Explain what this loop does and whether it is a good use of
assert:
```cpp
string s;
while (cin >> s && s != sought) { } // empty body
assert(cin);
```

## Exercise 6.49

> What is a candidate function? What is a viable function?

## Exercise 6.50

> Given the declarations for f from page 242, list the viable
functions, if any for each of the following calls. Indicate which function is the
best match, or if the call is illegal whether there is no match or why the call
is ambiguous.
```cpp
(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
```

## Exercise 6.51

> Write all four versions of f. Each function should print a
distinguishing message. Check your answers for the previous exercise. If your
answers were incorrect, study this section until you understand why your
answers were wrong.

[Exer06_51.cpp](Exer06_51.cpp) 

## Exercise 6.52

> Given the following declarations,
```cpp
void manip(int, int);
double dobj;
```
what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?
```
(a) manip('a', 'z');
(b) manip(55.4, dobj);
```

## Exercise 6.53

> Explain the effect of the second declaration in each one of
the following sets of declarations. Indicate which, if any, are illegal.
```cpp
(a) int calc(int&, int&);
int calc(const int&, const int&);
(b) int calc(char*, char*);
int calc(const char*, const char*);
(c) int calc(char*, char*);
int calc(char* const, char* const);
```

## Exercise 6.54

> Write a declaration for a function that takes two _int_
parameters and returns an _int_, and declare a _vector_ whose elements have
this function pointer type.

```cpp
int fun(int, int);
```

Way 1:
```cpp
vector<int(*)(int, int)> vec;
```

Way 2:
```cpp
using fp = int(*)(int, int);
vector<fp> vec;
```

Way 3:
```cpp
using fp = int(int, int);
vector<fp*> vec;
```


## Exercise 6.55

> Write four functions that add, subtract, multiply, and divide
two int values. Store pointers to these values in your vector from the
previous exercise.

[Exer06_55_56.cpp](Exer06_55_56.cpp) 

## Exercise 6.56

> Call each element in the vector and print their result.

[Exer06_55_56.cpp](Exer06_55_56.cpp) 

