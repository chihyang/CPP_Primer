##Exercise 18.1

> What is the type of the exception object in the following
throws?
```cpp
(a) range_error r("error");
    throw r;
(b) exception *p = &r;
    throw *p;
```
What would happen if the throw in (b) were written as throw p?

##Exercise 18.2

> Explain what happens if an exception occurs at the indicated
point:
```cpp
void exercise(int *b, int *e)
{
    vector<int> v(b, e);
    int *p = new int[v.size()];
    ifstream in("ints");
    // exception occurs here
}
```

##Exercise 18.3

> There are two ways to make the previous code work
correctly if an exception is thrown. Describe them and implement them.

[Exer18_03_1.cpp](Exer18_03_1.cpp) | [Exer18_03_2.cpp](Exer18_03_2.cpp) | [Exer18_03_3.cpp](Exer18_03_3.cpp) 

##Exercise 18.4

> Looking ahead to the inheritance hierarchy in Figure 18.1 (p.
783), explain what’s wrong with the following try block. Correct it.
```cpp
try {
    // use of the C++ standard library
} catch(exception) {
    // ...
} catch(const runtime_error &re) {
    // ...
} catch(overflow_error eobj) { /* ... */ }
```

##Exercise 18.5

> Modify the following main function to catch any of the
exception types shown in Figure 18.1 (p. 783):
```cpp
int main() {
    // use of the C++ standard library
}
```
The handlers should print the error message associated with the exception before
calling abort (defined in the header cstdlib) to terminate main.

[Exer18_05.cpp](Exer18_05.cpp) 

##Exercise 18.6

> Given the following exception types and catch clauses,
write a throw expression that creates an exception object that can be caught
by each catch clause:
```cpp
(a) class exceptionType { };
    catch(exceptionType *pet) { }
(b) catch(...) { }
(c) typedef int EXCPTYPE;
    catch(EXCPTYPE) { }
```

##Exercise 18.7

> Define your Blob and BlobPtr classes from Chapter 16 to
use function try blocks for their constructors.

[Exer18_07.cpp](Exer18_07.cpp) | [Exer18_07_Blob.h](Exer18_07_Blob.h) 

##Exercise 18.8

> Review the classes you’ve written and add appropriate
exception specifications to their constructors and destructors. If you think one
of your destructors might throw, change the code so that it cannot throw.

##Exercise 18.9

> Define the bookstore exception classes described in this
section and rewrite your Sales_data compound assigment operator to
throw an exception.

[Exer18_09_Sales_data.h](Exer18_09_Sales_data.h) 

##Exercise 18.10

> Write a program that uses the Sales_data addition
operator on objects that have differing ISBNs. Write two versions of the
program: one that handles the exception and one that does not. Compare the
behavior of the programs so that you become familiar with what happens
when an uncaught exception occurs.

[Exer18_10_1.cpp](Exer18_10_1.cpp) | [Exer18_10_2.cpp](Exer18_10_2.cpp) 

##Exercise 18.11

> Why is it important that the what function doesn’t throw?

##Exercise 18.12

> Organize the programs you have written to answer the
questions in each chapter into their own namespaces. That is, namespace
chapter15 would contain code for the Query programs and chapter10
would contain the TextQuery code. Using this structure, compile the Query
code examples.

##Exercise 18.13

> When might you use an unnamed namespace?

##Exercise 18.14

> Suppose we have the following declaration of the
operator* that is a member of the nested namespace
mathLib::MatrixLib:
```cpp
namespace mathLib {
    namespace MatrixLib {
        class matrix { /* ... */ };
        matrix operator*
        (const matrix &, const matrix &);
        // ...
    }
}
```
How would you declare this operator in global scope?

##Exercise 18.15

> Explain the differences between using declarations and
directives.

##Exercise 18.16

> Explain the following code assuming using declarations for
all the members of namespace Exercise are located at the location labeled
position 1. What if they appear at position 2 instead? Now answer the same
question but replace the using declarations with a using directive for
namespace Exercise.
```cpp
namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}
int ivar = 0;
// position 1
void manip() {
    // position 2
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
}
```

##Exercise 18.17

> Write code to test your answers to the previous question.

[Exer18_17_1.cpp](Exer18_17_1.cpp) | [Exer18_17_2.cpp](Exer18_17_2.cpp) | [Exer18_17_3.cpp](Exer18_17_3.cpp) | [Exer18_17_4.cpp](Exer18_17_4.cpp) 

##Exercise 18.18

> Given the following typical definition of swap § 13.3 (p.
517), determine which version of swap is used if mem1 is a string. What if
mem1 is an int? Explain how name lookup works in both cases.
```cpp
void swap(T v1, T v2)
{
    using std::swap;
    swap(v1.mem1, v2.mem1);
    // swap remaining members of type T
}
```

##Exercise 18.19

> What if the call to swap was std::swap(v1.mem1, v2.mem1)?

##Exercise 18.20

> In the following code, determine which function, if any,
matches the call to compute. List the candidate and viable functions. What
type conversions, if any, are applied to the argument to match the parameter
in each viable function?
```cpp
namespace primerLib {
    void compute();
    void compute(const void *);
}
using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char*, char* = 0);
void f()
{
    compute(0);
}
```
What would happen if the using declaration were located in main before the call
to compute? Answer the same questions as before.

[Exer18_20_1.cpp](Exer18_20_1.cpp) | [Exer18_20_2.cpp](Exer18_20_2.cpp) 

##Exercise 18.21

> Explain the following declarations. Identify any that are in
error and explain why they are incorrect:
```cpp
(a) class CADVehicle : public CAD, Vehicle { ... };
(b) class DblList: public List, public List { ... };
(c) class iostream: public istream, public ostream { ... };
```

##Exercise 18.22

> Given the following class hierarchy, in which each class
defines a default constructor:
```cpp
class A { ... };
class B : public A { ... };
class C : public B { ... };
class X { ... };
class Y { ... };
class Z : public X, public Y { ... };
class MI : public C, public Z { ... };
```
what is the order of constructor execution for the following definition?
```cpp
MI mi;
```

[Exer18_22.cpp](Exer18_22.cpp) 

##Exercise 18.23

> Using the hierarchy in exercise 18.22 along with class D
defined below, and assuming each class defines a default constructor, which,
if any, of the following conversions are not permitted?
```cpp
class D : public X, public C { ... };
D *pd = new D;
```
```cpp
(a) X *px = pd;
(b) A *pa = pd;
(c) B *pb = pd;
(d) C *pc = pd;
```

[Exer18_23.cpp](Exer18_23.cpp) 

##Exercise 18.24

> On page 807 we presented a series of calls made through
a Bear pointer that pointed to a Panda object. Explain each call assuming
we used a ZooAnimal pointer pointing to a Panda object instead.

##Exercise 18.25

> Assume we have two base classes, Base1 and Base2,
each of which defines a virtual member named print and a virtual
destructor. From these base classes we derive the following classes, each of
which redefines the print function:
```cpp
class D1 : public Base1 { /* ... */ };
class D2 : public Base2 { /* ... */ };
class MI : public D1, public D2 { /* ... */ };
Using the following pointers, determine which function is used in each call:
Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1 *pd1 = new MI;
D2 *pd2 = new MI;
```
```cpp
(a) pb1->print();
(b) pd1->print();
(c) pd2->print();
(d) delete pb2;
(e) delete pd1;
(f) delete pd2;
```

##Exercise 18.26

> Given the hierarchy in the box on page 810, why is the
following call to print an error? Revise MI to allow this call to print to
compile and execute correctly.
```cpp
MI mi;
mi.print(42);
```

[Exer18_26.cpp](Exer18_26.cpp) 

##Exercise 18.27

> Given the class hierarchy in the box on page 810 and
assuming we add a function named foo to MI as follows:
```cpp
int ival;
double dval;
void MI::foo(double cval)
{
    int dval;
    // exercise questions occur here
}
```
+ (a) List all the names visible from within MI::foo.
+ (b) Are any names visible from more than one base class?
+ (c) Assign to the local instance of dval the sum of the dval member of Base1 and the dval member of Derived.
+ (d) Assign the value of the last element in MI::dvec to Base2::fval.
+ (e) Assign cval from Base1 to the first character in sval from Derived.
```cpp
struct Base1 {
    void print(int) const; // public by default
    protected:
    int ival;
    double dval;
    char cval;
    private:
    int *id;
};
struct Base2 {
    void print(double) const; // public by default
    protected:
    double fval;
    private:
    double dval;
};
struct Derived : public Base1 {
    void print(std::string) const; // public by default
    protected:
    std::string sval;
    double dval;
};
struct MI : public Derived, public Base2 {
    void print(std::vector<double>); // public by default
    protected:
    int *ival;
    std::vector<double> dvec;
};
```

[Exer18_27.cpp](Exer18_27.cpp) 

##Exercise 18.28

> Given the following class hierarchy, which inherited
members can be accessed without qualification from within the VMI class?
Which require qualification? Explain your reasoning.
```cpp
struct Base {
    void bar(int); // public by default
    protected:
    int ival;
};
struct Derived1 : virtual public Base {
    void bar(char); // public by default
    void foo(char);
    protected:
    char cval;
};
struct Derived2 : virtual public Base {
    void foo(int); // public by default
    protected:
    int ival;
    char cval;
};
class VMI : public Derived1, public Derived2 { };
```

[Exer18_28.cpp](Exer18_28.cpp) 

##Exercise 18.29

> Given the following class hierarchy:
```cpp
class Class { ... };
class Base : public Class { ... };
class D1 : virtual public Base { ... };
class D2 : virtual public Base { ... };
class MI : public D1, public D2 { ... };
class Final : public MI, public Class { ... };
```
+ (a) In what order are constructors and destructors run on a Final object?
+ (b) A Final object has how many Base parts? How many Class parts?
+ (c) Which of the following assignments is a compile-time error?
```cpp
Base *pb; Class *pc; MI *pmi; D2 *pd2;
(a) pb = new Class;
(b) pc = new Final;
(c) pmi = pb;
(d) pd2 = pmi;
```

[Exer18_29_1.cpp](Exer18_29_1.cpp) | [Exer18_29_2.cpp](Exer18_29_2.cpp) 

##Exercise 18.30

> Define a default constructor, a copy constructor, and a
constructor that has an int parameter in Base. Define the same three
constructors in each derived class. Each constructor should use its argument
to initialize its Base part.

[Exer18_30.cpp](Exer18_30.cpp) 

