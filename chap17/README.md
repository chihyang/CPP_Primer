# Answers To Non-programming Exercises

## Contents
- [Exercise 17.1](#exercise-171)
- [Exercise 17.2](#exercise-172)
- [Exercise 17.3](#exercise-173)
- [Exercise 17.4](#exercise-174)
- [Exercise 17.5](#exercise-175)
- [Exercise 17.6](#exercise-176)
- [Exercise 17.7](#exercise-177)
- [Exercise 17.8](#exercise-178)
- [Exercise 17.9](#exercise-179)
- [Exercise 17.10](#exercise-1710)
- [Exercise 17.11](#exercise-1711)
- [Exercise 17.12](#exercise-1712)
- [Exercise 17.13](#exercise-1713)
- [Exercise 17.14](#exercise-1714)
- [Exercise 17.15](#exercise-1715)
- [Exercise 17.16](#exercise-1716)
- [Exercise 17.17](#exercise-1717)
- [Exercise 17.18](#exercise-1718)
- [Exercise 17.19](#exercise-1719)
- [Exercise 17.20](#exercise-1720)
- [Exercise 17.21](#exercise-1721)
- [Exercise 17.22](#exercise-1722)
- [Exercise 17.23](#exercise-1723)
- [Exercise 17.24](#exercise-1724)
- [Exercise 17.25](#exercise-1725)
- [Exercise 17.26](#exercise-1726)
- [Exercise 17.27](#exercise-1727)
- [Exercise 17.28](#exercise-1728)
- [Exercise 17.29](#exercise-1729)
- [Exercise 17.30](#exercise-1730)
- [Exercise 17.31](#exercise-1731)
- [Exercise 17.32](#exercise-1732)
- [Exercise 17.33](#exercise-1733)
- [Exercise 17.34](#exercise-1734)
- [Exercise 17.35](#exercise-1735)
- [Exercise 17.36](#exercise-1736)
- [Exercise 17.37](#exercise-1737)
- [Exercise 17.38](#exercise-1738)
- [Exercise 17.39](#exercise-1739)

## Exercise 17.1

> Define a tuple that holds three int values and initialize the
members to 10, 20, and 30.

[Exer17_01_02.cpp](Exer17_01_02.cpp) 

## Exercise 17.2

> Define a tuple that holds a string, a vector<string>,
and a pair<string, int>.

[Exer17_01_02.cpp](Exer17_01_02.cpp) 

## Exercise 17.3

> Rewrite the TextQuery programs from § 12.3 (p. 484) to
use a tuple instead of the QueryResult class. Explain which design you
think is better and why.

[Exer17_03.cpp](Exer17_03.cpp) | [Exer17_03_TextQuery.cpp](Exer17_03_TextQuery.cpp) | [Exer17_03_TextQuery.h](Exer17_03_TextQuery.h) 

## Exercise 17.4

> Write and test your own version of the findBook function.

[Exer17_04.cpp](Exer17_04.cpp) 

## Exercise 17.5

> Rewrite findBook to return a pair that holds an index and
a pair of iterators.

[Exer17_05.cpp](Exer17_05.cpp) 

## Exercise 17.6

> Rewrite findBook so that it does not use tuple or pair.

[Exer17_06.cpp](Exer17_06.cpp) 

## Exercise 17.7

> Explain which version of findBook you prefer and why.

In this example _tuple_ is okay. We don't need to define a new class or use nested
pair. Everything is clear.

## Exercise 17.8

> What would happen if we passed _Sales_data()_ as the
third parameter to accumulate in the last code example in this section?

If we pass _Sales_data()_, the _isbn_ of the result is an empty string. Thus the
output result would not be correct.

## Exercise 17.9

> Explain the bit pattern each of the following bitset objects
contains:
```cpp
(a) bitset<64> bitvec(32);
(b) bitset<32> bv(1010101);
(c) string bstr; cin >> bstr; bitset<8>bv(bstr);
```

- (a) _bitvec_ has 64 bits. The positions from 0 to 5 are set as 100000, the rest are
0.
- (b) _bv_ has 32 bits, the binary representation of 1010101 is `1111 0110 1001 1011 0101`.
So the bits of _bv_ are `0000 0000 0000 1111 0110 1001 1011 0101`.
- (c) _bv_ has 8 bits and is initialized by _bstr_.If _bstr_ is shorter than 8,
the rest high-order part of _bv_ is set to 0. If _bstr_ contains any character 
except '0' or '1', the constructor throws `invalid_argument` exception.

[Exer17_09.cpp](Exer17_09.cpp) 

## Exercise 17.10

> Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a
bitset that has a 1 bit in each position corresponding to a number in this
sequence. Default initialize another bitset and write a small program to
turn on each of the appropriate bits.

[Exer17_10.cpp](Exer17_10.cpp) 

## Exercise 17.11

> Define a data structure that contains an integral object to
track responses to a true/false quiz containing 10 questions. What changes, if
any, would you need to make in your data structure if the quiz had 100
questions?

[Exer17_11_12_13.cpp](Exer17_11_12_13.cpp) | [Exer17_11_quiz.h](Exer17_11_quiz.h) 

## Exercise 17.12

> Using the data structure from the previous question, write a
function that takes a question number and a value to indicate a true/false
answer and updates the quiz results accordingly.

[Exer17_11_12_13.cpp](Exer17_11_12_13.cpp) 

## Exercise 17.13

> Write an integral object that contains the correct answers
for the true/false quiz. Use it to generate grades on the quiz for the data
structure from the previous two exercises.

[Exer17_11_12_13.cpp](Exer17_11_12_13.cpp) 

## Exercise 17.14

> Write several regular expressions designed to trigger
various errors. Run your program to see what output your compiler generates
for each error.

[Exer17_14.cpp](Exer17_14.cpp) 

## Exercise 17.15

> Write a program using the pattern that finds words that
violate the “i before e except after c” rule. Have your program prompt the
user to supply a word and indicate whether the word is okay or not. Test
your program with words that do and do not violate the rule.

[Exer17_15.cpp](Exer17_15.cpp) 

## Exercise 17.16

> What would happen if your regex object in the previous
program were initialized with "[^c]ei"? Test your program using that
pattern to see whether your expectations were correct.

If we use "[^c]ei" to initialize regex, only words made up of 3 characters would be checked.

[Exer17_16.cpp](Exer17_16.cpp) 

## Exercise 17.17

> Update your program so that it finds all the words in an
input sequence that violiate the “ei” grammar rule.

[Exer17_17.cpp](Exer17_17.cpp) 

## Exercise 17.18

> Revise your program to ignore words that contain “ei” but
are not misspellings, such as “albeit” and “neighbor.”

[Exer17_18.cpp](Exer17_18.cpp) 

## Exercise 17.19

> Why is it okay to call m[4].str() without first checking
whether m[4] was matched?

Because `||` uses short circuit evaluation. If _m[4].str()_ is evaluated, that means
`m[4].str() == 0` is false, which means `m[4].matched` is true. Thus we can use _m[4].str()_
directly.

## Exercise 17.20

> Write your own version of the program to validate phone
numbers.

[Exer17_20.cpp](Exer17_20.cpp) 

## Exercise 17.21

> Rewrite your phone number program from § 8.3.2 (p. 323)
to use the valid function defined in this section.

[Exer17_21.cpp](Exer17_21.cpp) 

## Exercise 17.22

> Rewrite your phone program so that it allows any number
of whitespace characters to separate the three parts of a phone number.

[Exer17_22.cpp](Exer17_22.cpp) 

## Exercise 17.23

> Write a regular expression to find zip codes. A zip code can
have five or nine digits. The first five digits can be separated from the
remaining four by a dash.

[Exer17_23.cpp](Exer17_23.cpp) 

## Exercise 17.24

> Write your own version of the program to reformat phone
numbers.

[Exer17_24.cpp](Exer17_24.cpp) 

## Exercise 17.25

> Rewrite your phone program so that it writes only the first
phone number for each person.

[Exer17_25.cpp](Exer17_25.cpp) 

## Exercise 17.26

> Rewrite your phone program so that it writes only the
second and subsequent phone numbers for people with more than one phone
number.

[Exer17_26.cpp](Exer17_26.cpp) 

## Exercise 17.27

> Write a program that reformats a nine-digit zip code as
ddddd-dddd.

[Exer17_27.cpp](Exer17_27.cpp) 

## Exercise 17.28

> Write a function that generates and returns a uniformly
distributed random unsigned int each time it is called.

[Exer17_28.cpp](Exer17_28.cpp) 

## Exercise 17.29

> Allow the user to supply a seed as an optional argument to
the function you wrote in the previous exercise.

[Exer17_29.cpp](Exer17_29.cpp) 

## Exercise 17.30

> Revise your function again this time to take a minimum and
maximum value for the numbers that the function should return.

[Exer17_30.cpp](Exer17_30.cpp) 

## Exercise 17.31

> What would happen if we defined _b_ and _e_ inside the _do_
loop of the game-playing program from this section?

If we defined _b_ and _e_ inside the _do_ loop, every iteration would generate the 
same number.

## Exercise 17.32

> What would happen if we defined _resp_ inside the loop?

If we defined _resp_ inside the loop, we couldn't use _resp_ in a condition of _while_,
where it is out of scope.

## Exercise 17.33

> Write a version of the word transformation program from §
11.3.6 (p. 440) that allows multiple transformations for a given word and
randomly selects which transformation to apply.

[Exer17_33.cpp](Exer17_33.cpp) 

## Exercise 17.34

> Write a program that illustrates the use of each
manipulator in Tables 17.17 (p. 757) and 17.18.

[Exer17_34.cpp](Exer17_34.cpp) 

## Exercise 17.35

> Write a version of the program from page 758, that printed
the square root of 2 but this time print hexadecimal digits in uppercase.

[Exer17_35.cpp](Exer17_35.cpp) 

## Exercise 17.36

> Modify the program from the previous exercise to print the
various floating-point values so that they line up in a column.

[Exer17_36.cpp](Exer17_36.cpp) 

## Exercise 17.37

> Use the unformatted version of getline to read a file a
line at a time. Test your program by giving it a file that contains empty lines
as well as lines that are longer than the character array that you pass to
getline.

[Exer17_37.cpp](Exer17_37.cpp) 

## Exercise 17.38

> Extend your program from the previous exercise to print
each word you read onto its own line.

[Exer17_38.cpp](Exer17_38.cpp) 

## Exercise 17.39

> Write your own version of the seek program presented in
this section.

[Exer17_39.cpp](Exer17_39.cpp) 

