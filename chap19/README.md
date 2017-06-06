## Contents
- [Exercise 19.1](#exercise-191)
- [Exercise 19.2](#exercise-192)
- [Exercise 19.3](#exercise-193)
- [Exercise 19.4](#exercise-194)
- [Exercise 19.5](#exercise-195)
- [Exercise 19.6](#exercise-196)
- [Exercise 19.7](#exercise-197)
- [Exercise 19.8](#exercise-198)
- [Exercise 19.9](#exercise-199)
- [Exercise 19.10](#exercise-1910)
- [Exercise 19.11](#exercise-1911)
- [Exercise 19.12](#exercise-1912)
- [Exercise 19.13](#exercise-1913)
- [Exercise 19.14](#exercise-1914)
- [Exercise 19.15](#exercise-1915)
- [Exercise 19.16](#exercise-1916)
- [Exercise 19.17](#exercise-1917)
- [Exercise 19.18](#exercise-1918)
- [Exercise 19.19](#exercise-1919)
- [Exercise 19.20](#exercise-1920)
- [Exercise 19.21](#exercise-1921)
- [Exercise 19.22](#exercise-1922)
- [Exercise 19.23](#exercise-1923)
- [Exercise 19.24](#exercise-1924)
- [Exercise 19.25](#exercise-1925)
- [Exercise 19.26](#exercise-1926)

## Exercise 19.1

> Write your own operator new(size_t) function using
malloc and use free to write the operator delete(void*) function.

[Exer19_01_new_delete.h](Exer19_01_new_delete.h) 

## Exercise 19.2

> By default, the allocator class uses operator new to
obtain storage and operator delete to free it. Recompile and rerun your
StrVec programs (§ 13.5, p. 526) using your versions of the functions from
the previous exercise.

[Exer19_02.cpp](Exer19_02.cpp) | [Exer19_02_StrVec.h](Exer19_02_StrVec.h) 

## Exercise 19.3

> Given the following class hierarchy in which each class
defines a public default constructor and virtual destructor:
```cpp
class A { /* . . . */ };
class B : public A { /* . . . */ };
class C : public B { /* . . . */ };
class D : public B, public A { /* . . . */ };
```
which, if any, of the following dynamic_casts fail?
```cpp
(a) A *pa = new C;
    B *pb = dynamic_cast< B* >(pa);
(b) B *pb = new B;
    C *pc = dynamic_cast< C* >(pb);
(c) A *pa = new D;
    B *pb = dynamic_cast< B* >(pa);
```

```
    A
    |\
    | \
    |  B
    | / \
    |/   \
    D     C
```
(b) will fail. Because the dynamic type of _pb_ is _B_, which is the base class of
_C_. We can't use a pointer of derived class to point to a base class object.

[Exer19_03_04.cpp](Exer19_03_04.cpp) 

## Exercise 19.4

> Using the classes defined in the first exercise, rewrite the
following code to convert the expression *pa to the type C&:
```cpp
if (C *pc = dynamic_cast< C* >(pa))
    // use C's members
} else {
    // use A's members
}
```

[Exer19_03_04.cpp](Exer19_03_04.cpp) 

## Exercise 19.5

> When should you use a dynamic_cast instead of a virtual
function?

If we use a base class pointer to point to a derived class object, and derived 
class defines its own functions, and we want to use these functions of the object, 
we can use dynamic_cast to cast it to a derived class pointer or reference.

## Exercise 19.6

> Write an expression to dynamically cast a pointer to a
Query_base to a pointer to an AndQuery (§ 15.9.1, p. 636). Test the cast
by using objects of AndQuery and of another query type. Print a statement
indicating whether the cast works and be sure that the output matches your
expectations.

[Exer19_06_07_08.cpp](Exer19_06_07_08.cpp) | [Exer19_06_07_08_Query.cpp](Exer19_06_07_08_Query.cpp) | [Exer19_06_07_08_Query.h](Exer19_06_07_08_Query.h) | [Exer19_06_07_08_TextQuery.cpp](Exer19_06_07_08_TextQuery.cpp) | [Exer19_06_07_08_TextQuery.h](Exer19_06_07_08_TextQuery.h) 

## Exercise 19.7

> Write the same cast, but cast a Query_base object to a
reference to AndQuery. Repeat the test to ensure that your cast works
correctly.

[Exer19_06_07_08.cpp](Exer19_06_07_08.cpp) | [Exer19_06_07_08_Query.cpp](Exer19_06_07_08_Query.cpp) | [Exer19_06_07_08_Query.h](Exer19_06_07_08_Query.h) | [Exer19_06_07_08_TextQuery.cpp](Exer19_06_07_08_TextQuery.cpp) | [Exer19_06_07_08_TextQuery.h](Exer19_06_07_08_TextQuery.h) 

## Exercise 19.8

> Write a typeid expression to see whether two
Query_base pointers point to the same type. Now check whether that type
is an AndQuery.

[Exer19_06_07_08.cpp](Exer19_06_07_08.cpp) | [Exer19_06_07_08_Query.cpp](Exer19_06_07_08_Query.cpp) | [Exer19_06_07_08_Query.h](Exer19_06_07_08_Query.h) | [Exer19_06_07_08_TextQuery.cpp](Exer19_06_07_08_TextQuery.cpp) | [Exer19_06_07_08_TextQuery.h](Exer19_06_07_08_TextQuery.h) 

## Exercise 19.9

> Write a program similar to the last one in this section to
print the names your compiler uses for common type names. If your compiler
gives output similar to ours, write a function that will translate those strings
to more human-friendly form.

[Exer19_09.cpp](Exer19_09.cpp) 

## Exercise 19.10

> Given the following class hierarchy in which each class
defines a public default constructor and virtual destructor, which type name
do the following statements print?

```cpp
class A { /* . . . */ };
class B : public A { /* . . . */ };
class C : public B { /* . . . */ };

(a) A *pa = new C;
    cout << typeid(pa).name() << endl;
(b) C cobj;
    A& ra = cobj;
    cout << typeid(&ra).name() << endl;
(c) B *px = new B;
    A& ra = *px;
    cout << typeid(ra).name() << endl;
```

[Exer19_10.cpp](Exer19_10.cpp) 

## Exercise 19.11

> What is the difference between an ordinary data pointer
and a pointer to a data member?

- The type of a pointer to member embodies both the type of a class and the type of a 
member of that class;
- We initialize such a pointer to point to a specific member of a class without
identifying an object to which that member belongs;
- We use .* and ->* to dereference a pointer to data member.

## Exercise 19.12

> Define a pointer to member that can point to the cursor
member of class Screen. Fetch the value of Screen::cursor through that
pointer.

[Exer19_12.cpp](Exer19_12.cpp) | [Exer19_12_Screen.h](Exer19_12_Screen.h) 

## Exercise 19.13

> Define the type that can represent a pointer to the bookNo
member of the Sales_data class.

[Exer19_13.cpp](Exer19_13.cpp) 

## Exercise 19.14

> Is the following code legal? If so, what does it do? If not,
why?
```cpp
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```

The type of _pmf_ is `char(Screen::*)() const`, the type of _get_ is `char() const`,
so we could use _pmf_ to point to the member function _get_ of _Screen_.

[Exer19_14.cpp](Exer19_14.cpp) 

## Exercise 19.15

> What is the difference between an ordinary function pointer
and a pointer to a member function?

- A pointer to a member function is declared using _classname_::*;
- there is no automatic conversion between a member function and a pointer to that
member.

## Exercise 19.16

> Write a type alias that is a synonym for a pointer that can
point to the avg_price member of Sales_data.

[Exer19_16.cpp](Exer19_16.cpp) 

## Exercise 19.17

> Define a type alias for each distinct Screen member
function type.

[Exer19_17.cpp](Exer19_17.cpp) | [Exer19_17_Screen.h](Exer19_17_Screen.h) 

## Exercise 19.18

> Write a function that uses count_if to count how many
empty strings there are in a given vector.

[Exer19_18.cpp](Exer19_18.cpp) | [Exer19_18_ADL.cpp](Exer19_18_ADL.cpp) 

## Exercise 19.19

> Write a function that takes a vector<Sales_data> and
finds the first element whose average price is greater than some given
amount.

[Exer19_19.cpp](Exer19_19.cpp) 

## Exercise 19.20

> Nest your QueryResult class inside TextQuery and
rerun the programs you wrote to use TextQuery in § 12.3.2 (p. 490).

[Exer19_20.cpp](Exer19_20.cpp) | [Exer19_20_TextQuery.cpp](Exer19_20_TextQuery.cpp) | [Exer19_20_TextQuery.h](Exer19_20_TextQuery.h) 

## Exercise 19.21

> Write your own version of the Token class.

[Exer19_21_25.cpp](Exer19_21_25.cpp) | [Exer19_21_25_Token.cpp](Exer19_21_25_Token.cpp) | [Exer19_21_25_Token.h](Exer19_21_25_Token.h) 

## Exercise 19.22

> Add a member of type Sales_data to your Token class.

[Exer19_21_25.cpp](Exer19_21_25.cpp) | [Exer19_21_25_Token.cpp](Exer19_21_25_Token.cpp) | [Exer19_21_25_Token.h](Exer19_21_25_Token.h) 

## Exercise 19.23

> Add a move constructor and move assignment to Token.

[Exer19_21_25.cpp](Exer19_21_25.cpp) | [Exer19_21_25_Token.cpp](Exer19_21_25_Token.cpp) | [Exer19_21_25_Token.h](Exer19_21_25_Token.h) 

## Exercise 19.24

> Explain what happens if we assign a Token object to itself.

If we assign a Token object to itself, the first condition 
`tok == STR && t.tok != STR` is false. Then if the object holds a string, the second 
condition is true. Assigning a string to it self is okay. Because a string has its 
own assignment operator. If the object doesn't hold a string, else condition is true.
_CopyUnion_ is called. In this case the object holds a built-in type object. Assigning
to itself is okay.

## Exercise 19.25

> Write assignment operators that take values of each type in
the union.

[Exer19_21_25.cpp](Exer19_21_25.cpp) | [Exer19_21_25_Token.cpp](Exer19_21_25_Token.cpp) | [Exer19_21_25_Token.h](Exer19_21_25_Token.h) 

## Exercise 19.26

> Explain these declarations and indicate whether they are
legal:
```cpp
extern "C" int compute(int *, int);
extern "C" double compute(double *, double);
```

The first declaration uses linkage directive to declare a function _compute_ that's
written in C and can be called by C++ programs. So does the second. The problem is C 
doesn't permit function overloading. So two declarations with the same name are illegal.

[Exer19_26.c](Exer19_26.c) | [Exer19_26.cpp](Exer19_26.cpp) | [Exer19_26.h](Exer19_26.h) 
