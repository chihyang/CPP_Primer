# Answers Of Non-programming Exercises

## Contents
- [Exercise 9.1](#exercise-91)
- [Exercise 9.2](#exercise-92)
- [Exercise 9.3](#exercise-93)
- [Exercise 9.4](#exercise-94)
- [Exercise 9.5](#exercise-95)
- [Exercise 9.6](#exercise-96)
- [Exercise 9.7](#exercise-97)
- [Exercise 9.8](#exercise-98)
- [Exercise 9.9](#exercise-99)
- [Exercise 9.10](#exercise-910)
- [Exercise 9.11](#exercise-911)
- [Exercise 9.12](#exercise-912)
- [Exercise 9.13](#exercise-913)
- [Exercise 9.14](#exercise-914)
- [Exercise 9.15](#exercise-915)
- [Exercise 9.16](#exercise-916)
- [Exercise 9.17](#exercise-917)
- [Exercise 9.18](#exercise-918)
- [Exercise 9.19](#exercise-919)
- [Exercise 9.20](#exercise-920)
- [Exercise 9.21](#exercise-921)
- [Exercise 9.22](#exercise-922)
- [Exercise 9.23](#exercise-923)
- [Exercise 9.24](#exercise-924)
- [Exercise 9.25](#exercise-925)
- [Exercise 9.26](#exercise-926)
- [Exercise 9.27](#exercise-927)
- [Exercise 9.28](#exercise-928)
- [Exercise 9.29](#exercise-929)
- [Exercise 9.30](#exercise-930)
- [Exercise 9.31](#exercise-931)
- [Exercise 9.32](#exercise-932)
- [Exercise 9.33](#exercise-933)
- [Exercise 9.34](#exercise-934)
- [Exercise 9.35](#exercise-935)
- [Exercise 9.36](#exercise-936)
- [Exercise 9.37](#exercise-937)
- [Exercise 9.38](#exercise-938)
- [Exercise 9.39](#exercise-939)
- [Exercise 9.40](#exercise-940)
- [Exercise 9.41](#exercise-941)
- [Exercise 9.42](#exercise-942)
- [Exercise 9.43](#exercise-943)
- [Exercise 9.44](#exercise-944)
- [Exercise 9.45](#exercise-945)
- [Exercise 9.46](#exercise-946)
- [Exercise 9.47](#exercise-947)
- [Exercise 9.48](#exercise-948)
- [Exercise 9.49](#exercise-949)
- [Exercise 9.50](#exercise-950)
- [Exercise 9.51](#exercise-951)
- [Exercise 9.52](#exercise-952)

## Exercise 9.1

> Which is the most appropriate—a vector, a deque, or a
list—for the following program tasks? Explain the rationale for your choice.
If there is no reason to prefer one or another container, explain why not.
(a) Read a fixed number of words, inserting them in the container
alphabetically as they are entered. We’ll see in the next chapter that
associative containers are better suited to this problem.
(b) Read an unknown number of words. Always insert new words at the
back. Remove the next value from the front.
(c) Read an unknown number of integers from a file. Sort the numbers and
then print them to standard output.

## Exercise 9.2

> Define a list that holds elements that are deques that hold
ints.

## Exercise 9.3

> What are the constraints on the iterators that form iterator
ranges?

## Exercise 9.4

> Write a function that takes a pair of iterators to a
vector<int> and an int value. Look for that value in the range and return
a bool indicating whether it was found.

[Exer09_04.cpp](Exer09_04.cpp) 

## Exercise 9.5

> Rewrite the previous program to return an iterator to the
requested element. Note that the program must handle the case where the
element is not found.

[Exer09_05.cpp](Exer09_05.cpp) 

## Exercise 9.6

> What is wrong with the following program? How might you
correct it?
```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

## Exercise 9.7

> What type should be used as the index into a vector of
ints?

## Exercise 9.8

> What type should be used to read elements in a list of
strings? To write them?

## Exercise 9.9

> What is the difference between the begin and cbegin
functions?

## Exercise 9.10

> What are the types of the following four objects?
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

## Exercise 9.11

> Show an example of each of the six ways to create and
initialize a vector. Explain what values each vector contains.

[Exer09_11.cpp](Exer09_11.cpp) 

## Exercise 9.12

> Explain the differences between the constructor that takes a
container to copy and the constructor that takes two iterators.

## Exercise 9.13

> How would you initialize a vector<double> from a
list<int>? From a vector<int>? Write code to check your answers.

## Exercise 9.14

> Write a program to assign the elements from a list of
char* pointers to C-style character strings to a vector of strings.

[Exer09_14.cpp](Exer09_14.cpp) 

## Exercise 9.15

> Write a program to determine whether two vector<int>s
are equal.

[Exer09_15.cpp](Exer09_15.cpp) 

## Exercise 9.16

> Repeat the previous program, but compare elements in a
list<int> to a vector<int>.

[Exer09_16.cpp](Exer09_16.cpp) 

## Exercise 9.17

> Assuming c1 and c2 are containers, what (if any)
constraints does the following usage place on the types of c1 and c2?
```cpp
if (c1 < c2)
```

## Exercise 9.18

> Write a program to read a sequence of strings from the
standard input into a deque. Use iterators to write a loop to print the
elements in the deque.

[Exer09_18.cpp](Exer09_18.cpp) 

## Exercise 9.19

> Rewrite the program from the previous exercise to use a
list. List the changes you needed to make.

[Exer09_19.cpp](Exer09_19.cpp) 

## Exercise 9.20

> Write a program to copy elements from a list<int> into
two deques. The even-valued elements should go into one deque and the
odd ones into the other.

[Exer09_20.cpp](Exer09_20.cpp) 

## Exercise 9.21

> Explain how the loop from page 345 that used the return
from insert to add elements to a list would work if we inserted into a
vector instead.

## Exercise 9.22

> Assuming iv is a vector of ints, what is wrong with the
following program? How might you correct the problem(s)?
```cpp
vector<int>::iterator iter = iv.begin(),
mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```

[Exer09_22.cpp](Exer09_22.cpp) 

## Exercise 9.23

> In the first program in this section on page 346, what would
the values of val, val2, val3, and val4 be if c.size() is 1?

## Exercise 9.24

> Write a program that fetches the first element in a vector
using at, the subscript operator, front, and begin. Test your program on
an empty vector.

[Exer09_24.cpp](Exer09_24.cpp) 

## Exercise 9.25

> In the program on page 349 that erased a range of
elements, what happens if elem1 and elem2 are equal? What if elem2 or
both elem1 and elem2 are the off-the-end iterator?

## Exercise 9.26

> Using the following definition of ia, copy ia into a vector
and into a list. Use the single-iterator form of erase to remove the
elements with odd values from your list and the even values from your
vector.
```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

[Exer09_26.cpp](Exer09_26.cpp) 

## Exercise 9.27

> Write a program to find and remove the odd-valued
elements in a forward_list<int>.

[Exer09_27.cpp](Exer09_27.cpp) 

## Exercise 9.28

> Write a function that takes a forward_list<string> and
two additional string arguments. The function should find the first string
and insert the second immediately following the first. If the first string is
not found, then insert the second string at the end of the list.

[Exer09_28.cpp](Exer09_28.cpp) 

## Exercise 9.29

> Given that vec holds 25 elements, what does
vec.resize(100) do? What if we next wrote vec.resize(10)?

## Exercise 9.30

> What, if any, restrictions does using the version of resize
that takes a single argument place on the element type?

## Exercise 9.31

> The program on page 354 to remove even-valued elements
and duplicate odd ones will not work on a list or forward_list. Why?
Revise the program so that it works on these types as well.

[Exer09_31.cpp](Exer09_31.cpp) 

## Exercise 9.32

> In the program onpage 354 would it be legal to write the call
to insert as follows? If not, why not?
```cpp
iter = vi.insert(iter, *iter++);
```

[Exer09_32.cpp](Exer09_32.cpp) 

## Exercise 9.33

> In the final example in this section what would happen if we
did not assign the result of insert to begin? Write a program that omits
this assignment to see if your expectation was correct.

[Exer09_33.cpp](Exer09_33.cpp) 

## Exercise 9.34

> Assuming vi is a container of ints that includes even and
odd values, predict the behavior of the following loop. After you’ve analyzed
this loop, write a program to test whether your expectations were correct.
```cpp
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2)
        iter = vi.insert(iter, *iter);
    ++iter;
```

[Exer09_34.cpp](Exer09_34.cpp) 

## Exercise 9.35

> Explain the difference between a vector’s capacity and
its size.

## Exercise 9.36

> Can a container have a capacity less than its size?

## Exercise 9.37

> Why don’t list or array have a capacity member?

## Exercise 9.38

> Write a program to explore how vectors grow in the library
you use.

[Exer09_38.cpp](Exer09_38.cpp) 

## Exercise 9.39

> Explain what the following program fragment does:
```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);
```

## Exercise 9.40

> If the program in the previous exercise reads 256 words,
what is its likely capacity after it is resized? What if it reads 512? 1,000?
1,048?

## Exercise 9.41

> Write a program that initializes a string from a
vector<char>.

[Exer09_41.cpp](Exer09_41.cpp) 

## Exercise 9.42

> Given that you want to read a character at a time into a
string, and you know that you need to read at least 100 characters, how
might you improve the performance of your program?

[Exer09_42.cpp](Exer09_42.cpp) 

## Exercise 9.43

> Write a function that takes three strings, s, oldVal, and
newVal. Using iterators, and the insert and erase functions replace all
instances of oldVal that appear in s by newVal. Test your function by
using it to replace common abbreviations, such as “tho” by “though” and
“thru” by “through”.

[Exer09_43.cpp](Exer09_43.cpp) 

## Exercise 9.44

> Rewrite the previous function using an index and replace.

[Exer09_44.cpp](Exer09_44.cpp) 

## Exercise 9.45

> Write a funtion that takes a string representing a name
and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
suffix, such as “Jr.” or “III”. Using iterators and the insert and append
functions, generate and return a new string with the suffix and prefix
added to the given name.

[Exer09_45.cpp](Exer09_45.cpp) 

## Exercise 9.46

> Rewrite the previous exercise using a position and length to
manage the strings. This time use only the insert function.

[Exer09_46.cpp](Exer09_46.cpp) 

## Exercise 9.47

> Write a program that finds each numeric character and then
each alphabetic character in the string "ab2c3d7R4E6". Write two
versions of the program. The first should use find_first_of, and the
second find_first_not_of.

[Exer09_47.cpp](Exer09_47.cpp) 

## Exercise 9.48

> Given the definitions of name and numbers on page 365,
what does numbers.find(name) return?

## Exercise 9.49

> A letter has an ascender if, as with d or f, part of the letter
extends above the middle of the line. A letter has a descender if, as with p or
g, part of the letter extends below the line. Write a program that reads a file
containing words and reports the longest word that contains neither
ascenders nor descenders.

[Exer09_49.cpp](Exer09_49.cpp) 

## Exercise 9.50

> Write a program to process a vector<string>s whose
elements represent integral values. Produce the sum of all the elements in
that vector. Change the program so that it sums of strings that represent
floating-point values.

[Exer09_50.cpp](Exer09_50.cpp) 

## Exercise 9.51

> Write a class that has three unsigned members
representing year, month, and day. Write a constructor that takes a string
representing a date. Your constructor should handle a variety of date
formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.

[Exer09_51.cpp](Exer09_51.cpp) | [Exer09_51.h](Exer09_51.h) 

## Exercise 9.52

> Use a stack to process parenthesized expressions. When
you see an open parenthesis, note that it was seen. When you see a close
parenthesis after an open parenthesis, pop elements down to and including
the open parenthesis off the stack. push a value onto the stack to
indicate that a parenthesized expression was replaced.

[Exer09_52.cpp](Exer09_52.cpp) 

