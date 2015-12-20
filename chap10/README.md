##Exercise 10.1

> The algorithm header defines a function named count
that, like find, takes a pair of iterators and a value. count returns a count
of how often that value appears. Read a sequence of ints into a vector
and print the count of how many elements have a given value.

##Exercise 10.2

> Repeat the previous program, but read values into a list of
strings.

##Exercise 10.3

> Use accumulate to sum the elements in a vector<int>.

##Exercise 10.4

> Assuming v is a vector<double>, what, if anything, is
wrong with calling accumulate(v.cbegin(), v.cend(), 0)?

##Exercise 10.5

> In the call to equal on rosters, what would happen if both
rosters held C-style strings, rather than library strings?

##Exercise 10.6

> Using fill_n, write a program to set a sequence of int
values to 0.

##Exercise 10.7

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

##Exercise 10.8

> We said that algorithms do not change the size of the
containers over which they operate. Why doesn’t the use of back_inserter
invalidate this claim?

##Exercise 10.9

> Implement your own version of elimDups. Test your
program by printing the vector after you read the input, after the call to
unique, and after the call to erase.

##Exercise 10.10

> Why do you think the algorithms don’t change the size of
containers?

##Exercise 10.11

> Write a program that uses stable_sort and isShorter
to sort a vector passed to your version of elimDups. Print the vector to
verify that your program is correct.

##Exercise 10.12

> Write a function named compareIsbn that compares the
isbn() members of two Sales_data objects. Use that function to sort a
vector that holds Sales_data objects.

##Exercise 10.13

> The library defines an algorithm named partition that
takes a predicate and partitions the container so that values for which the
predicate is true appear in the first part and those for which the predicate is
false appear in the second part. The algorithm returns an iterator just past
the last element for which the predicate returned true. Write a function that
takes a string and returns a bool indicating whether the string has five
characters or more. Use that function to partition words. Print the elements
that have five or more characters.

##Exercise 10.14

> Write a lambda that takes two ints and returns their sum.

##Exercise 10.15

> Write a lambda that captures an int from its enclosing
function and takes an int parameter. The lambda should return the sum of
the captured int and the int parameter.

##Exercise 10.16

> Write your own version of the biggies function using
lambdas.

##Exercise 10.17

> Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a
lambda in the call to sort instead of the compareIsbn function.

##Exercise 10.18

> Rewrite biggies to use partition instead of find_if.
We described the partition algorithm in exercise 10.13 in § 10.3.1 (p.
387).

##Exercise 10.19

> Rewrite the previous exercise to use stable_partition,
which like stable_sort maintains the original element order in the
paritioned sequence.

##Exercise 10.20

> The library defines an algorithm named count_if. Like
find_if, this function takes a pair of iterators denoting an input range and
a predicate that it applies to each element in the given range. count_if
returns a count of how often the predicate is true. Use count_if to rewrite
the portion of our program that counted how many words are greater than
length 6.

##Exercise 10.21

> Write a lambda that captures a local int variable and
decrements that variable until it reaches 0. Once the variable is 0 additional
calls should no longer decrement the variable. The lambda should return a
bool that indicates whether the captured variable is 0.

##Exercise 10.22

> Rewrite the program to count words of size 6 or less using
functions in place of the lambdas.

##Exercise 10.23

> How many arguments does bind take?

##Exercise 10.24

> Use bind and check_size to find the first element in a
vector of ints that has a value greater than the length of a specified
string value.

##Exercise 10.25

> In the exercises for § 10.3.2 (p. 392) you wrote a version
of biggies that uses partition. Rewrite that function to use
check_size and bind.

##Exercise 10.26

> Explain the differences among the three kinds of insert
iterators.

##Exercise 10.27

> In addition to unique (§ 10.2.3, p. 384), the library
defines function named unique_copy that takes a third iterator denoting a
destination into which to copy the unique elements. Write a program that
uses unique_copy to copy the unique elements from a vector into an
initially empty list.

##Exercise 10.28

> Copy a vector that holds the values from 1 to 9 inclusive,
into three other containers. Use an inserter, a back_inserter, and a
front_inserter, respectivly to add elements to these containers. Predict
how the output sequence varies by the kind of inserter and verify your
predictions by running your programs.

##Exercise 10.29

> Write a program using stream iterators to read a text file
into a vector of strings.

##Exercise 10.30

> Use stream iterators, sort, and copy to read a sequence
of integers from the standard input, sort them, and then write them back to
the standard output.

##Exercise 10.31

> Update the program from the previous exercise so that it
prints only the unique elements. Your program should use unqiue_copy (§
10.4.1, p. 403).

##Exercise 10.32

> Rewrite the bookstore problem from § 1.6 (p. 24) using a
vector to hold the transactions and various algorithms to do the processing.
Use sort with your compareIsbn function from § 10.3.1 (p. 387) to
arrange the transactions in order, and then use find and accumulate to
do the sum.

##Exercise 10.33

> Write a program that takes the names of an input file and
two output files. The input file should hold integers. Using an
istream_iterator read the input file. Using ostream_iterators, write
the odd numbers into the first output file. Each value should be followed by a
space. Write the even numbers into the second file. Each of these values
should be placed on a separate line.

##Exercise 10.34

> Use reverse_iterators to print a vector in reverse
order.

##Exercise 10.35

> Now print the elements in reverse order using ordinary
iterators.

##Exercise 10.36

> Use find to find the last element in a list of ints with
value 0.

##Exercise 10.37

> Given a vector that has ten elements, copy the elements
from positions 3 through 7 in reverse order to a list.

##Exercise 10.38

> List the five iterator categories and the operations that each
supports.

##Exercise 10.39

> What kind of iterator does a list have? What about a
vector?

##Exercise 10.40

> What kinds of iterators do you think copy requires? What
about reverse or unique?

##Exercise 10.41

> Based only on the algorithm and argument names, describe
the operation that the each of the following library algorithms performs:
```cpp
replace(beg, end, old_val, new_val);
replace_if(beg, end, pred, new_val);
replace_copy(beg, end, dest, old_val, new_val);
replace_copy_if(beg, end, dest, pred, new_val);
```

##Exercise 10.42

> Reimplement the program that eliminated duplicate words
that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.