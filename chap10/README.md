## Contents
- [Exercise 10.1](#exercise-101)
- [Exercise 10.2](#exercise-102)
- [Exercise 10.3](#exercise-103)
- [Exercise 10.4](#exercise-104)
- [Exercise 10.5](#exercise-105)
- [Exercise 10.6](#exercise-106)
- [Exercise 10.7](#exercise-107)
- [Exercise 10.8](#exercise-108)
- [Exercise 10.9](#exercise-109)
- [Exercise 10.10](#exercise-1010)
- [Exercise 10.11](#exercise-1011)
- [Exercise 10.12](#exercise-1012)
- [Exercise 10.13](#exercise-1013)
- [Exercise 10.14](#exercise-1014)
- [Exercise 10.15](#exercise-1015)
- [Exercise 10.16](#exercise-1016)
- [Exercise 10.17](#exercise-1017)
- [Exercise 10.18](#exercise-1018)
- [Exercise 10.19](#exercise-1019)
- [Exercise 10.20](#exercise-1020)
- [Exercise 10.21](#exercise-1021)
- [Exercise 10.22](#exercise-1022)
- [Exercise 10.23](#exercise-1023)
- [Exercise 10.24](#exercise-1024)
- [Exercise 10.25](#exercise-1025)
- [Exercise 10.26](#exercise-1026)
- [Exercise 10.27](#exercise-1027)
- [Exercise 10.28](#exercise-1028)
- [Exercise 10.29](#exercise-1029)
- [Exercise 10.30](#exercise-1030)
- [Exercise 10.31](#exercise-1031)
- [Exercise 10.32](#exercise-1032)
- [Exercise 10.33](#exercise-1033)
- [Exercise 10.34](#exercise-1034)
- [Exercise 10.35](#exercise-1035)
- [Exercise 10.36](#exercise-1036)
- [Exercise 10.37](#exercise-1037)
- [Exercise 10.38](#exercise-1038)
- [Exercise 10.39](#exercise-1039)
- [Exercise 10.40](#exercise-1040)
- [Exercise 10.41](#exercise-1041)
- [Exercise 10.42](#exercise-1042)

## Exercise 10.1

> The algorithm header defines a function named count
that, like find, takes a pair of iterators and a value. count returns a count
of how often that value appears. Read a sequence of ints into a vector
and print the count of how many elements have a given value.

[Exer10_01.cpp](Exer10_01.cpp) 

## Exercise 10.2

> Repeat the previous program, but read values into a list of
strings.

[Exer10_02.cpp](Exer10_02.cpp) 

## Exercise 10.3

> Use accumulate to sum the elements in a vector<int>.

[Exer10_03.cpp](Exer10_03.cpp) 

## Exercise 10.4

> Assuming v is a vector<double>, what, if anything, is
wrong with calling accumulate(v.cbegin(), v.cend(), 0)?

[Exer10_04.cpp](Exer10_04.cpp) 

## Exercise 10.5

> In the call to equal on rosters, what would happen if both
rosters held C-style strings, rather than library strings?

[Exer10_05.cpp](Exer10_05.cpp) 

## Exercise 10.6

> Using fill_n, write a program to set a sequence of int
values to 0.

[Exer10_06.cpp](Exer10_06.cpp) 

## Exercise 10.7

> Determine if there are any errors in the following programs
and, if so, correct the error(s):
```cpp
(a)
vector<int> vec; list<int> lst; int i;
while (cin >> i)
lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
(b)
vector<int> vec;
vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
fill_n(vec.begin(), 10, 0);
```

## Exercise 10.8

> We said that algorithms do not change the size of the
containers over which they operate. Why doesn’t the use of back_inserter
invalidate this claim?

## Exercise 10.9

> Implement your own version of elimDups. Test your
program by printing the vector after you read the input, after the call to
unique, and after the call to erase.

[Exer10_09.cpp](Exer10_09.cpp) 

## Exercise 10.10

> Why do you think the algorithms don’t change the size of
containers?

## Exercise 10.11

> Write a program that uses stable_sort and isShorter
to sort a vector passed to your version of elimDups. Print the vector to
verify that your program is correct.

[Exer10_11.cpp](Exer10_11.cpp) 

## Exercise 10.12

> Write a function named compareIsbn that compares the
isbn() members of two Sales_data objects. Use that function to sort a
vector that holds Sales_data objects.

[Exer10_12.cpp](Exer10_12.cpp) 

## Exercise 10.13

> The library defines an algorithm named partition that
takes a predicate and partitions the container so that values for which the
predicate is true appear in the first part and those for which the predicate is
false appear in the second part. The algorithm returns an iterator just past
the last element for which the predicate returned true. Write a function that
takes a string and returns a bool indicating whether the string has five
characters or more. Use that function to partition words. Print the elements
that have five or more characters.

[Exer10_13.cpp](Exer10_13.cpp) 

## Exercise 10.14

> Write a lambda that takes two ints and returns their sum.

## Exercise 10.15

> Write a lambda that captures an int from its enclosing
function and takes an int parameter. The lambda should return the sum of
the captured int and the int parameter.

## Exercise 10.16

> Write your own version of the biggies function using
lambdas.

[Exer10_16.cpp](Exer10_16.cpp) 

## Exercise 10.17

> Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a
lambda in the call to sort instead of the compareIsbn function.

[Exer10_17.cpp](Exer10_17.cpp) 

## Exercise 10.18

> Rewrite biggies to use partition instead of find_if.
We described the partition algorithm in exercise 10.13 in § 10.3.1 (p.
387).

[Exer10_18.cpp](Exer10_18.cpp) 

## Exercise 10.19

> Rewrite the previous exercise to use stable_partition,
which like stable_sort maintains the original element order in the
paritioned sequence.

[Exer10_19.cpp](Exer10_19.cpp) 

## Exercise 10.20

> The library defines an algorithm named count_if. Like
find_if, this function takes a pair of iterators denoting an input range and
a predicate that it applies to each element in the given range. count_if
returns a count of how often the predicate is true. Use count_if to rewrite
the portion of our program that counted how many words are greater than
length 6.

[Exer10_20.cpp](Exer10_20.cpp) 

## Exercise 10.21

> Write a lambda that captures a local int variable and
decrements that variable until it reaches 0. Once the variable is 0 additional
calls should no longer decrement the variable. The lambda should return a
bool that indicates whether the captured variable is 0.

[Exer10_21.cpp](Exer10_21.cpp) 

## Exercise 10.22

> Rewrite the program to count words of size 6 or less using
functions in place of the lambdas.

[Exer10_22.cpp](Exer10_22.cpp) 

## Exercise 10.23

> How many arguments does bind take?

## Exercise 10.24

> Use bind and check_size to find the first element in a
vector of ints that has a value greater than the length of a specified
string value.

[Exer10_24.cpp](Exer10_24.cpp) 

## Exercise 10.25

> In the exercises for § 10.3.2 (p. 392) you wrote a version
of biggies that uses partition. Rewrite that function to use
check_size and bind.

[Exer10_25.cpp](Exer10_25.cpp) 

## Exercise 10.26

> Explain the differences among the three kinds of insert
iterators.

## Exercise 10.27

> In addition to unique (§ 10.2.3, p. 384), the library
defines function named unique_copy that takes a third iterator denoting a
destination into which to copy the unique elements. Write a program that
uses unique_copy to copy the unique elements from a vector into an
initially empty list.

[Exer10_27.cpp](Exer10_27.cpp) 

## Exercise 10.28

> Copy a vector that holds the values from 1 to 9 inclusive,
into three other containers. Use an inserter, a back_inserter, and a
front_inserter, respectivly to add elements to these containers. Predict
how the output sequence varies by the kind of inserter and verify your
predictions by running your programs.

[Exer10_28.cpp](Exer10_28.cpp) 

## Exercise 10.29

> Write a program using stream iterators to read a text file
into a vector of strings.

[Exer10_29.cpp](Exer10_29.cpp) 

## Exercise 10.30

> Use stream iterators, sort, and copy to read a sequence
of integers from the standard input, sort them, and then write them back to
the standard output.

[Exer10_30.cpp](Exer10_30.cpp) 

## Exercise 10.31

> Update the program from the previous exercise so that it
prints only the unique elements. Your program should use unqiue_copy (§
10.4.1, p. 403).

[Exer10_31.cpp](Exer10_31.cpp) 

## Exercise 10.32

> Rewrite the bookstore problem from § 1.6 (p. 24) using a
vector to hold the transactions and various algorithms to do the processing.
Use sort with your compareIsbn function from § 10.3.1 (p. 387) to
arrange the transactions in order, and then use find and accumulate to
do the sum.

[Exer10_32.cpp](Exer10_32.cpp) | [Exer10_32_Sales_item.h](Exer10_32_Sales_item.h) 

## Exercise 10.33

> Write a program that takes the names of an input file and
two output files. The input file should hold integers. Using an
istream_iterator read the input file. Using ostream_iterators, write
the odd numbers into the first output file. Each value should be followed by a
space. Write the even numbers into the second file. Each of these values
should be placed on a separate line.

[Exer10_33.cpp](Exer10_33.cpp) 

## Exercise 10.34

> Use reverse_iterators to print a vector in reverse
order.

[Exer10_34.cpp](Exer10_34.cpp) 

## Exercise 10.35

> Now print the elements in reverse order using ordinary
iterators.

[Exer10_35.cpp](Exer10_35.cpp) 

## Exercise 10.36

> Use find to find the last element in a list of ints with
value 0.

[Exer10_36.cpp](Exer10_36.cpp) 

## Exercise 10.37

> Given a vector that has ten elements, copy the elements
from positions 3 through 7 in reverse order to a list.

[Exer10_37.cpp](Exer10_37.cpp) 

## Exercise 10.38

> List the five iterator categories and the operations that each
supports.

## Exercise 10.39

> What kind of iterator does a list have? What about a
vector?

## Exercise 10.40

> What kinds of iterators do you think copy requires? What
about reverse or unique?

[Exer10_40.cpp](Exer10_40.cpp) 

## Exercise 10.41

> Based only on the algorithm and argument names, describe
the operation that the each of the following library algorithms performs:
```cpp
replace(beg, end, old_val, new_val);
replace_if(beg, end, pred, new_val);
replace_copy(beg, end, dest, old_val, new_val);
replace_copy_if(beg, end, dest, pred, new_val);
```

## Exercise 10.42

> Reimplement the program that eliminated duplicate words
that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.

[Exer10_42.cpp](Exer10_42.cpp) 

