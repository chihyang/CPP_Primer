# Answers Of Non-programming Exercises

## Contents
- [Exercise 3.1](#exercise-31)
- [Exercise 3.2](#exercise-32)
- [Exercise 3.3](#exercise-33)
- [Exercise 3.4](#exercise-34)
- [Exercise 3.5](#exercise-35)
- [Exercise 3.6](#exercise-36)
- [Exercise 3.7](#exercise-37)
- [Exercise 3.8](#exercise-38)
- [Exercise 3.9](#exercise-39)
- [Exercise 3.10](#exercise-310)
- [Exercise 3.11](#exercise-311)
- [Exercise 3.12](#exercise-312)
- [Exercise 3.13](#exercise-313)
- [Exercise 3.14](#exercise-314)
- [Exercise 3.15](#exercise-315)
- [Exercise 3.16](#exercise-316)
- [Exercise 3.17](#exercise-317)
- [Exercise 3.18](#exercise-318)
- [Exercise 3.19](#exercise-319)
- [Exercise 3.20](#exercise-320)
- [Exercise 3.21](#exercise-321)
- [Exercise 3.22](#exercise-322)
- [Exercise 3.23](#exercise-323)
- [Exercise 3.24](#exercise-324)
- [Exercise 3.25](#exercise-325)
- [Exercise 3.26](#exercise-326)
- [Exercise 3.27](#exercise-327)
- [Exercise 3.28](#exercise-328)
- [Exercise 3.29:](#exercise-329:)
- [Exercise 3.30](#exercise-330)
- [Exercise 3.31](#exercise-331)
- [Exercise 3.32](#exercise-332)
- [Exercise 3.33](#exercise-333)
- [Exercise 3.34](#exercise-334)
- [Exercise 3.35](#exercise-335)
- [Exercise 3.36](#exercise-336)
- [Exercise 3.37](#exercise-337)
- [Exercise 3.38](#exercise-338)
- [Exercise 3.39](#exercise-339)
- [Exercise 3.40](#exercise-340)
- [Exercise 3.41](#exercise-341)
- [Exercise 3.42](#exercise-342)
- [Exercise 3.43](#exercise-343)
- [Exercise 3.44](#exercise-344)
- [Exercise 3.45](#exercise-345)

## Exercise 3.1

> Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
with appropriate _using_ declarations.

[Exer03_01_1.cpp](Exer03_01_1.cpp) | [Exer03_01_2.cpp](Exer03_01_2.cpp) | [Exer03_01_3.cpp](Exer03_01_3.cpp)

## Exercise 3.2

> Write a program to read the standard input a line at a time.
Modify your program to read a word at a time.

[Exer03_02_1.cpp](Exer03_02_1.cpp) | [Exer03_02_2.cpp](Exer03_02_2.cpp)

## Exercise 3.3

> Explain how whitespace characters are handled in the _string_
input operator and in the _getline_ function.

- The _string_ input operator reads and discards any leading whitespace(e.g., spaces, newlinew, tabs).
It then read characters until the next whitespace character is encountered.
- The _getline_ function reads the given stream up to and including the first newline and stores what is
read--not including the newline--in its _string_ argument. After _getline_ sees a newline, even if it is 
the first character in the input, it stops reading and returns. If the first character in the input is a 
newline, then the resulting _string_ is the empty _string_.

## Exercise 3.4

> Write a program to read two _strings_ and report whether the
_strings_ are equal. If not, report which of the two is larger. Now, change
the program to report whether the _strings_ have the same length, and if
not, report which is longer.

[Exer03_04.cpp](Exer03_04.cpp)

## Exercise 3.5

> Write a program to read _strings_ from the standard input,
concatenating what is read into one large _string_. Print the concatenated
_string_. Next, change the program to separate adjacent input _strings_ by a
space.

[Exer03_05.cpp](Exer03_05.cpp)

## Exercise 3.6

> Use a range _for_ to change all the characters in a _string_ to
_X_.

[Exer03_06.cpp](Exer03_06.cpp)

## Exercise 3.7

> What would happen if you define the loop control variable in the previous
exercise as type _char_? Predict the results and then change your program
to use a char to see if you were right.

[Exer03_07.cpp](Exer03_07.cpp)

If we use _char_ rather than _char&_, we just get a copy of every character in the _string_, when we 
assign to the loop variable, we are changing the copy rather than the original character.

## Exercise 3.8

> Rewrite the program in the first exercise, first using a _while_
and again using a traditional _for_ loop. Which of the three approaches do
you prefer and why?

[Exer03_08.cpp](Exer03_08.cpp)

Apparently, range for is simpler to use here.

## Exercise 3.9

> What does the following program do? Is it valid? If not, why not?
```cpp
string s;
cout << s[0] << endl;
```

No, it's not valid. Because _string_ is default initialized as empty. Subscripting an empty _string_ 
is undefined.

## Exercise 3.10

> Write a program that reads a _string_ of characters including
punctuation and writes what was read but with the punctuation removed.

[Exer03_10.cpp](Exer03_10.cpp)

## Exercise 3.11

> Is the following range _for_ legal? If so, what is the type of _c_?
```cpp
const string s = "Keep out!";
for (auto &c : s){ /*... */ }
```

The type of _c_ is const _char&_. If there is no operation that tries to change the value of _c_, it's 
legal, otherwise illegal.

[Exer03_11.cpp](Exer03_11.cpp)

## Exercise 3.12

> Which, if any, of the following _vector_ definitions are in error?
For those that are legal, explain what the definition does.
For those that are not legal, explain why they are illegal.
```cpp
(a) vector<vector<int>> ivec;
(b) vector<string> svec = ivec;
(c) vector<string> svec(10, "null");
```

(a) legal: define and value initialize a _vector_ whose elements are _vector_ of _int_.

(b) illegal: types of _svec_ and _ivec_ are different, we can't initialize a _vector_ with another of 
different types.

(c) legal: define and initialize a _vector_ of _string_ which has 10 elements with the same initial value
"null".

[Exer03_12.cpp](Exer03_12.cpp)

## Exercise 3.13

> How many elements are there in each of the following
_vectors_? What are the values of the elements?
```cpp
(a) vector<int> v1;        
(b) vector<int> v2(10);    
(c) vector<int> v3(10, 42);
(d) vector<int> v4{ 10 };    
(e) vector<int> v5{ 10, 42 };
(f) vector<string> v6{ 10 }; 
(g) vector<string> v7{ 10, "hi" };
```

(a) 0 element.

(b) 10 elements, each has value 0.

(c) 10 elements, each has value 42.

(d) 1 element, the value is 10.

(e) 2 elements, the values of them are 10 and 42 respectively.

(f) 10 elements, each is an empty _string_.

(g) 10 elements, eahc has value "hi".

[Exer03_13.cpp](Exer03_13.cpp)

## Exercise 3.14

> Write a program to read a sequence of _ints_ from _cin_ and
store those values in a _vector_.

[Exer03_14.cpp](Exer03_14.cpp)

## Exercise 3.15

> Repeat the previous program but read _strings_ this time.

[Exer03_15.cpp](Exer03_15.cpp)

## Exercise 3.16

> Write a program to print the size and contents of the
vectors from exercise 3.13. Check whether your answers to that exercise
were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you
were wrong.

[Exer03_16.cpp](Exer03_16.cpp)

## Exercise 3.17

> Read a sequence of words from cin and store the values a
_vector_. After you’ve read all the words, process the _vector_ and change
each word to uppercase. Print the transformed elements, eight words to a
line.

[Exer03_17.cpp](Exer03_17.cpp)

## Exercise 3.18

> Is the following program legal? If not, how might you fix it?
```cpp
vector<int> ivec;
ivec[0] = 42;
```

Illegal, subscripting an empty vector is undefined, we should use _push_back_:
```cpp
vector<int> ivec;
ivec.push_back(42);
```


## Exercise 3.19

> List three ways to define a _vector_ and give it ten elements,
each with the value 42. Indicate whether there is a preferred way to do so
and why.

way 1:
```cpp
vector<int> ivec(10, 42);
```
way 2:
```cpp
vector<int> ivec{42, 42, 42, 42, 42, 42, 42, 42, 42, 42,};
```
way 3:
```cpp
vector<int> ivec(10);
for (auto &i : ivec) {
    i = 42;
}
```
Apparently, the first way is the best.

## Exercise 3.20

> Read a set of integers into a _vector_. Print the sum of each
pair of adjacent elements. Change your program so that it prints the sum of
the first and last elements, followed by the sum of the second and second-tolast,
and so on.

[Exer03_20.cpp](Exer03_20.cpp)

## Exercise 3.21

> Redo the first exercise from § 3.3.3 (p. 105) using iterators.

[Exer03_21_1.cpp](Exer03_21_1.cpp) | [Exer03_21_2.cpp](Exer03_21_2.cpp)

## Exercise 3.22

> Revise the loop that printed the first paragraph in _text_ to
instead change the elements in _text_ that correspond to the first paragraph
to all uppercase. After you’ve updated _text_, print its contents.

[Exer03_22.cpp](Exer03_22.cpp)

## Exercise 3.23

> Write a program to create a _vector_ with ten _int_ elements.
Using an iterator, assign each element a value that is twice its current value.
Test your program by printing the _vector_.

[Exer03_23.cpp](Exer03_23.cpp)

## Exercise 3.24

> Redo the last exercise from § 3.3.3 (p. 105) using iterators.

[Exer03_24.cpp](Exer03_24.cpp)

## Exercise 3.25

> Rewrite the grade clustering program from § 3.3.3 (p. 104)
using iterators instead of subscripts.

[Exer03_25.cpp](Exer03_25.cpp)

## Exercise 3.26

> In the binary search program on page 112,
why did we write `mid=beg+(end-beg)/2;` instead of `mid=(beg+end) /2;`?

We use `mid=beg+(end-beg)/2;` instead of `mid=(beg+end) /2;` because there is no definition of adding 
two iterators.

## Exercise 3.27

> Assuming _txt_size_ is a function that takes no arguments
and returns an _int_ value, which of the following definitions are illegal?
Explain why.
```cpp
unsigned buf_size = 1024;
(a) int ia[buf_size];  
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";
```

(a) illegal, we cannot use non-const value as the size of an array. 

(b) legal, 4 * 7 - 14 is a const expression and can be evaluated at compile time.

(c) illegal, the return value of _txt_size_ is not a const expression.

(d) illegal, there is a null terminator at the end of the string literal, thus its size is 12 rather 
than 11.

[Exer03_27.cpp](Exer03_27.cpp)

## Exercise 3.28

> What are the values in the following arrays?
```cpp
string sa[10];
int ia[10];
int main() 
{
    string sa2[10];
    int ia2[10];
}
```

_sa_: ten empty _strings_.

_ia_: ten _ints_ whose values are all 0.

_sa2_: ten empty _strings_.

_ia2_: ten uninitialized _ints_.

## Exercise 3.29:

> List some of the drawbacks of using an array instead of a _vector_.

- Size of an array is fixed at the time of declaration, while the length of a _vector_ is changeable.
- An array defined in a block is not initialized, while a _vector_ is value initialized.

## Exercise 3.30

> Identify the indexing errors in the following code:
```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
    ia[ix] = ix;
```

The maximum index of _ia_ is 9 rather than 10. When _ix_ grows to 10, it will be out of range.

## Exercise 3.31

> Write a program to define an array of ten _ints_. Give each
element the same value as its position in the array.

[Exer03_31.cpp](Exer03_31.cpp)

## Exercise 3.32

> Copy the array you defined in the previous exercise into
another array. Rewrite your program to use vectors.

[Exer03_32_1.cpp](Exer03_32_1.cpp) | [Exer03_32_2.cpp](Exer03_32_2.cpp)

## Exercise 3.33

> What would happen if we did not initialize the _scores_ array in the program
on page 116?

If we don't initialize _scores_, the value of every element in it is undefined. When we access them, 
there might be unexpected results.

## Exercise 3.34

> Given that _p1_ and _p2_ point to elements in the same array, what does the following code do?
Are there values of _p1_ or _p2_ that make this code illegal?
```cpp
p1 += p2 - p1;
```

This code makes _p1_ points to the position of _p2_. If _p1_ or _p2_ per se is illegal, the result might
be illegal.

## Exercise 3.35

> Using pointers, write a program to set the elements in an
array to zero.

[Exer03_35.cpp](Exer03_35.cpp)

## Exercise 3.36

> Write a program to compare two arrays _for_ equality. Write a
similar program to compare two _vectors_.

[Exer03_36_1.cpp](Exer03_36_1.cpp) | [Exer03_36_2.cpp](Exer03_36_2.cpp)

## Exercise 3.37

> What does the following program do?
```cpp
const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

This code tries to output the const _char_ array _ca_. The problem is that _ca_ doesn't have null 
terminator. The loop might not end as expected.

## Exercise 3.38

> In this section, we noted that it was not only illegal but meaningless to try to add two pointers.
Why would adding two pointers be meaningless?

Because the value of a pointer in actually an address. There is no meaning to add two addresses: we 
can't know whether the result is a valid address or an address that stores a value of the same type. 

## Exercise 3.39

> Write a program to compare two _strings_. Now write a
program to compare the values of two C-style character _strings_.

[Exer03_39.cpp](Exer03_39.cpp)

## Exercise 3.40

> Write a program to define two character arrays initialized
from _string_ literals. Now define a third character array to hold the
concatenation of the two arrays. Use _strcpy_ and _strcat_ to copy the two
arrays into the third.

[Exer03_40.cpp](Exer03_40.cpp)

## Exercise 3.41

> Write a program to initialize a _vector_ from an array of
_ints_.

[Exer03_41.cpp](Exer03_41.cpp)

## Exercise 3.42

> Write a program to copy a _vector_ of _ints_ into an array of
_ints_.

[Exer03_42.cpp](Exer03_42.cpp)

## Exercise 3.43

> Write three different versions of a program to print the
elements of ia. One version should use a range _for_ to manage the
iteration, the other two should use an ordinary _for_ loop in one case using
subscripts and in the other using pointers. In all three programs write all the
types directly. That is, do not use a type alias, _auto_, or _decltype_ to
simplify the code.

[Exer03_43.cpp](Exer03_43.cpp)

## Exercise 3.44

> Rewrite the programs from the previous exercises using a type alias _for_ the type of the loop control variables.

[Exer03_44.cpp](Exer03_44.cpp)

## Exercise 3.45

> Rewrite the programs again, this time using _auto_.

[Exer03_45.cpp](Exer03_45.cpp)
