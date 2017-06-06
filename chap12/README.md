# Answers To Non-programming Exercises

## Contents
- [Exercise 12.1](#exercise-121)
- [Exercise 12.2](#exercise-122)
- [Exercise 12.3](#exercise-123)
- [Exercise 12.4](#exercise-124)
- [Exercise 12.5](#exercise-125)
- [Exercise 12.6](#exercise-126)
- [Exercise 12.7](#exercise-127)
- [Exercise 12.8](#exercise-128)
- [Exercise 12.9](#exercise-129)
- [Exercise 12.10](#exercise-1210)
- [Exercise 12.11](#exercise-1211)
- [Exercise 12.12](#exercise-1212)
- [Exercise 12.13](#exercise-1213)
- [Exercise 12.14](#exercise-1214)
- [Exercise 12.15](#exercise-1215)
- [Exercise 12.16](#exercise-1216)
- [Exercise 12.17](#exercise-1217)
- [Exercise 12.18](#exercise-1218)
- [Exercise 12.19](#exercise-1219)
- [Exercise 12.20](#exercise-1220)
- [Exercise 12.21](#exercise-1221)
- [Exercise 12.22](#exercise-1222)
- [Exercise 12.23](#exercise-1223)
- [Exercise 12.24](#exercise-1224)
- [Exercise 12.25](#exercise-1225)
- [Exercise 12.26](#exercise-1226)
- [Exercise 12.27](#exercise-1227)
- [Exercise 12.28](#exercise-1228)
- [Exercise 12.29](#exercise-1229)
- [Exercise 12.30](#exercise-1230)
- [Exercise 12.31](#exercise-1231)
- [Exercise 12.32](#exercise-1232)
- [Exercise 12.33](#exercise-1233)

## Exercise 12.1

> How many elements do b1 and b2 have at the end of this
code?
```cpp
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```

## Exercise 12.2

> Write your own version of the StrBlob class including the
const versions of front and back.

[Exer12_02.cpp](Exer12_02.cpp) 

## Exercise 12.3

> Does this class need const versions of push_back and
pop_back? If so, add them. If not, why aren’t they needed?

## Exercise 12.4

> In our check function we didn’t check whether i was
greater than zero. Why is it okay to omit that check?

## Exercise 12.5

> We did not make the constructor that takes an
initializer_list explicit (§ 7.5.4, p. 296). Discuss the pros and
cons of this design choice.

## Exercise 12.6

> Write a function that returns a dynamically allocated vector
of ints. Pass that vector to another function that reads the standard input
to give values to the elements. Pass the vector to another function to print
the values that were read. Remember to delete the vector at the
appropriate time.

[Exer12_06.cpp](Exer12_06.cpp) 

## Exercise 12.7

> Redo the previous exercise, this time using shared_ptr.

[Exer12_07.cpp](Exer12_07.cpp) 

## Exercise 12.8

> Explain what if anything is wrong with the following function.
```cpp
bool b() {
    int* p = new int;
    // ...
    return p;
}
```

## Exercise 12.9

> Explain what happens in the following code:
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

## Exercise 12.10

> Explain whether the following call to the process function
defined on page 464 is correct. If not, how would you correct the call?
```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

[Exer12_10.cpp](Exer12_10.cpp) 

## Exercise 12.11

> What would happen if we called process as follows?
```cpp
process(shared_ptr<int>(p.get()));
```

## Exercise 12.12

> Using the declarations of p and sp explain each of the
following calls to process. If the call is legal, explain what it does. If the call
is illegal, explain why:
```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```

## Exercise 12.13

> What happens if we execute the following code?
```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

[Exer12_13.cpp](Exer12_13.cpp) 

## Exercise 12.14

> Write your own version of a function that uses a
shared_ptr to manage a connection.

[Exer12_14.cpp](Exer12_14.cpp) 

## Exercise 12.15

> Rewrite the first exercise to use a lambda (§ 10.3.2, p.
388) in place of the end_connection function.

[Exer12_15.cpp](Exer12_15.cpp) 

## Exercise 12.16

> Compilers don’t always give easy-to-understand error
messages if we attempt to copy or assign a unique_ptr. Write a program
that contains these errors to see how your compiler diagnoses them.

[Exer12_16.cpp](Exer12_16.cpp) 

## Exercise 12.17

> Which of the following unique_ptr declarations are illegal
or likely to result in subsequent program error? Explain what the problem is
with each one.
```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());
```

[Exer12_17.cpp](Exer12_17.cpp) 

## Exercise 12.18

> Why doesn’t shared_ptr have a release member?

## Exercise 12.19

> Define your own version of StrBlobPtr and update your
StrBlob class with the appropriate friend declaration and begin and end
members.

[Exer12_19_StrBlob.h](Exer12_19_StrBlob.h) 

## Exercise 12.20

> Write a program that reads an input file a line at a time
into a StrBlob and uses a StrBlobPtr to print each element in that
StrBlob.

[Exer12_20.cpp](Exer12_20.cpp) 

## Exercise 12.21

> We could have written StrBlobPtr’s deref member as
follows:
```cpp
std::string& deref() const
{ return (*check(curr, "dereference past end"))[curr]; }
```
Which version do you think is better and why?

## Exercise 12.22

> What changes would need to be made to StrBlobPtr to
create a class that can be used with a const StrBlob? Define a class
named ConstStrBlobPtr that can point to a const StrBlob.

[Exer12_22.cpp](Exer12_22.cpp) | [Exer12_22_StrBlob.h](Exer12_22_StrBlob.h) 

## Exercise 12.23

> Write a program to concatenate two string literals, putting
the result in a dynamically allocated array of char. Write a program to
concatenate two library strings that have the same value as the literals
used in the first program.

[Exer12_23.cpp](Exer12_23.cpp) 

## Exercise 12.24

> Write a program that reads a string from the standard input
into a dynamically allocated character array. Describe how your program
handles varying size inputs. Test your program by giving it a string of data
that is longer than the array size you’ve allocated.

[Exer12_24.cpp](Exer12_24.cpp) 

## Exercise 12.25

> Given the following new expression, how would you
delete pa?
```cpp
int *pa = new int[10];
```

## Exercise 12.26

> Rewrite the program on page 481 using an allocator.

[Exer12_26.cpp](Exer12_26.cpp) 

## Exercise 12.27

> The TextQuery and QueryResult classes use only
capabilities that we have already covered. Without looking ahead, write your
own versions of these classes.

[Exer12_27.cpp](Exer12_27.cpp) | [Exer12_27_TextQuery.h](Exer12_27_TextQuery.h) 

## Exercise 12.28

> Write a program to implement text queries without defining
classes to manage the data. Your program should take a file and interact
with a user to query for words in that file. Use vector, map, and set
containers to hold the data for the file and to generate the results for the
queries.

[Exer12_28.cpp](Exer12_28.cpp) 

## Exercise 12.29

> We could have written the loop to manage the interaction
with the user as a do while (§ 5.4.4, p. 189) loop. Rewrite the loop to use
a do while. Explain which version you prefer and why.

[Exer12_29.cpp](Exer12_29.cpp) 

## Exercise 12.30

> Define your own versions of the TextQuery and
QueryResult classes and execute the runQueries function from § 12.3.1
(p. 486).

[Exer12_30.cpp](Exer12_30.cpp) | [Exer12_30_33_TextQuery.h](Exer12_30_33_TextQuery.h) 

## Exercise 12.31

> What difference(s) would it make if we used a vector
instead of a set to hold the line numbers? Which approach is better? Why?

## Exercise 12.32

> Rewrite the TextQuery and QueryResult classes to use
a StrBlob instead of a vector<string> to hold the input file.

[Exer12_32.cpp](Exer12_32.cpp) | [Exer12_32_TextQuery_StrBlob.h](Exer12_32_TextQuery_StrBlob.h) 

## Exercise 12.33

> In Chapter 15 we’ll extend our query system and will need
some additional members in the QueryResult class. Add members named
begin and end that return iterators into the set of line numbers returned
by a given query, and a member named get_file that returns a
shared_ptr to the file in the QueryResult object.

[Exer12_30_33_TextQuery.h](Exer12_30_33_TextQuery.h) 

