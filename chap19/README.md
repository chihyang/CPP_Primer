##Exercise 19.1

> Write your own operator new(size_t) function using
malloc and use free to write the operator delete(void*) function.

[Exer19_01_new_delete.h](Exer19_01_new_delete.h) 

##Exercise 19.2

> By default, the allocator class uses operator new to
obtain storage and operator delete to free it. Recompile and rerun your
StrVec programs (§ 13.5, p. 526) using your versions of the functions from
the previous exercise.

[Exer19_02.cpp](Exer19_02.cpp) | [Exer19_02_StrVec.h](Exer19_02_StrVec.h) 

##Exercise 19.3

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

[Exer19_03_04.cpp](Exer19_03_04.cpp) 

##Exercise 19.4

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

##Exercise 19.5

> When should you use a dynamic_cast instead of a virtual
function?

##Exercise 19.6

> Write an expression to dynamically cast a pointer to a
Query_base to a pointer to an AndQuery (§ 15.9.1, p. 636). Test the cast
by using objects of AndQuery and of another query type. Print a statement
indicating whether the cast works and be sure that the output matches your
expectations.

[Exer19_06_07_08.cpp](Exer19_06_07_08.cpp) | [Exer19_06_07_08_Query.cpp](Exer19_06_07_08_Query.cpp) | [Exer19_06_07_08_Query.h](Exer19_06_07_08_Query.h) | [Exer19_06_07_08_TextQuery.cpp](Exer19_06_07_08_TextQuery.cpp) | [Exer19_06_07_08_TextQuery.h](Exer19_06_07_08_TextQuery.h) 

##Exercise 19.7

> Write the same cast, but cast a Query_base object to a
reference to AndQuery. Repeat the test to ensure that your cast works
correctly.

[Exer19_06_07_08.cpp](Exer19_06_07_08.cpp) | [Exer19_06_07_08_Query.cpp](Exer19_06_07_08_Query.cpp) | [Exer19_06_07_08_Query.h](Exer19_06_07_08_Query.h) | [Exer19_06_07_08_TextQuery.cpp](Exer19_06_07_08_TextQuery.cpp) | [Exer19_06_07_08_TextQuery.h](Exer19_06_07_08_TextQuery.h) 

##Exercise 19.8

> Write a typeid expression to see whether two
Query_base pointers point to the same type. Now check whether that type
is an AndQuery.

[Exer19_06_07_08.cpp](Exer19_06_07_08.cpp) | [Exer19_06_07_08_Query.cpp](Exer19_06_07_08_Query.cpp) | [Exer19_06_07_08_Query.h](Exer19_06_07_08_Query.h) | [Exer19_06_07_08_TextQuery.cpp](Exer19_06_07_08_TextQuery.cpp) | [Exer19_06_07_08_TextQuery.h](Exer19_06_07_08_TextQuery.h) 

##Exercise 19.9

> Write a program similar to the last one in this section to
print the names your compiler uses for common type names. If your compiler
gives output similar to ours, write a function that will translate those strings
to more human-friendly form.

[Exer19_09.cpp](Exer19_09.cpp) 

##Exercise 19.10

> Given the following class hierarchy in which each class
defines a public default constructor and virtual destructor, which type name
do the following statements print?

[Exer19_10.cpp](Exer19_10.cpp) 

##Exercise 19.11

> What is the difference between an ordinary data pointer
and a pointer to a data member?

##Exercise 19.12

> Define a pointer to member that can point to the cursor
member of class Screen. Fetch the value of Screen::cursor through that
pointer.

[Exer19_12.cpp](Exer19_12.cpp) | [Exer19_12_Screen.h](Exer19_12_Screen.h) 

##Exercise 19.13

> Define the type that can represent a pointer to the bookNo
member of the Sales_data class.

[Exer19_13.cpp](Exer19_13.cpp) 

##Exercise 19.14

> Is the following code legal? If so, what does it do? If not,
why?
```cpp
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```

[Exer19_14.cpp](Exer19_14.cpp) 

##Exercise 19.15

> What is the difference between an ordinary function pointer
and a pointer to a member function?

##Exercise 19.16

> Write a type alias that is a synonym for a pointer that can
point to the avg_price member of Sales_data.

[Exer19_16.cpp](Exer19_16.cpp) 

##Exercise 19.17

> Define a type alias for each distinct Screen member
function type.

[Exer19_17.cpp](Exer19_17.cpp) | [Exer19_17_Screen.h](Exer19_17_Screen.h) 

##Exercise 19.18

> Write a function that uses count_if to count how many
empty strings there are in a given vector.

[Exer19_18.cpp](Exer19_18.cpp) | [Exer19_18_ADL.cpp](Exer19_18_ADL.cpp) 

##Exercise 19.19

> Write a function that takes a vector<Sales_data> and
finds the first element whose average price is greater than some given
amount.

[Exer19_19.cpp](Exer19_19.cpp) 

##Exercise 19.20

> Nest your QueryResult class inside TextQuery and
rerun the programs you wrote to use TextQuery in § 12.3.2 (p. 490).

[Exer19_20.cpp](Exer19_20.cpp) | [Exer19_20_TextQuery.cpp](Exer19_20_TextQuery.cpp) | [Exer19_20_TextQuery.h](Exer19_20_TextQuery.h) 

##Exercise 19.21

> Write your own version of the Token class.

[Exer19_21_25.cpp](Exer19_21_25.cpp) | [Exer19_21_25_Token.cpp](Exer19_21_25_Token.cpp) | [Exer19_21_25_Token.h](Exer19_21_25_Token.h) 

##Exercise 19.22

> Add a member of type Sales_data to your Token class.

##Exercise 19.23

> Add a move constructor and move assignment to Token.

##Exercise 19.24

> Explain what happens if we assign a Token object to itself.

##Exercise 19.25

> Write assignment operators that take values of each type in
the union.

[Exer19_21_25.cpp](Exer19_21_25.cpp) | [Exer19_21_25_Token.cpp](Exer19_21_25_Token.cpp) | [Exer19_21_25_Token.h](Exer19_21_25_Token.h) 

##Exercise 19.26

> Explain these declarations and indicate whether they are
legal:
```cpp
extern "C" int compute(int *, int);
extern "C" double compute(double *, double);
```

[Exer19_26.c](Exer19_26.c) | [Exer19_26.cpp](Exer19_26.cpp) | [Exer19_26.h](Exer19_26.h) 

