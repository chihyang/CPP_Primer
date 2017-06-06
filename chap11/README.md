# Answers To Non-programming Exercises

## Contents
- [Exercise 11.1](#exercise-111)
- [Exercise 11.2](#exercise-112)
- [Exercise 11.3](#exercise-113)
- [Exercise 11.4](#exercise-114)
- [Exercise 11.5](#exercise-115)
- [Exercise 11.6](#exercise-116)
- [Exercise 11.7](#exercise-117)
- [Exercise 11.8](#exercise-118)
- [Exercise 11.9](#exercise-119)
- [Exercise 11.10](#exercise-1110)
- [Exercise 11.11](#exercise-1111)
- [Exercise 11.12](#exercise-1112)
- [Exercise 11.13](#exercise-1113)
- [Exercise 11.14](#exercise-1114)
- [Exercise 11.15](#exercise-1115)
- [Exercise 11.16](#exercise-1116)
- [Exercise 11.17](#exercise-1117)
- [Exercise 11.20](#exercise-1120)
- [Exercise 11.21](#exercise-1121)
- [Exercise 11.22](#exercise-1122)
- [Exercise 11.23](#exercise-1123)
- [Exercise 11.24](#exercise-1124)
- [Exercise 11.25](#exercise-1125)
- [Exercise 11.26](#exercise-1126)
- [Exercise 11.27](#exercise-1127)
- [Exercise 11.28](#exercise-1128)
- [Exercise 11.29](#exercise-1129)
- [Exercise 11.30](#exercise-1130)
- [Exercise 11.31](#exercise-1131)
- [Exercise 11.32](#exercise-1132)
- [Exercise 11.33](#exercise-1133)
- [Exercise 11.34](#exercise-1134)
- [Exercise 11.35](#exercise-1135)
- [Exercise 11.36](#exercise-1136)
- [Exercise 11.37](#exercise-1137)
- [Exercise 11.38](#exercise-1138)

## Exercise 11.1

> Describe the differences between a map and a vector.

## Exercise 11.2

> Give an example of when each of list, vector, deque,
map, and set might be most useful.

## Exercise 11.3

> Write your own version of the word-counting program.

[Exer11_03_04.cpp](Exer11_03_04.cpp) 

## Exercise 11.4

> Extend your program to ignore case and punctuation. For
example, “example.” “example,” and “Example” should all increment the same
counter.

[Exer11_03_04.cpp](Exer11_03_04.cpp) 

## Exercise 11.5

> Explain the difference between a map and a set. When
might you use one or the other?

## Exercise 11.6

> Explain the difference between a set and a list. When
might you use one or the other?

## Exercise 11.7

> Define a map for which the key is the family’s last name and
the value is a vector of the children’s names. Write code to add new
families and to add new children to an existing family.

[Exer11_07.cpp](Exer11_07.cpp) 

## Exercise 11.8

> Write a program that stores the excluded words in a vector
instead of in a set. What are the advantages to using a set?

[Exer11_08.cpp](Exer11_08.cpp) 

## Exercise 11.9

> Define a map that associates words with a list of line
numbers on which the word might occur.

## Exercise 11.10

> Could we define a map from vector<int>::iterator to
int? What about from list<int>::iterator to int? In each case, if
not, why not?

## Exercise 11.11

> Redefine bookstore without using decltype.

## Exercise 11.12

> Write a program to read a sequence of strings and ints,
storing each into a pair. Store the pairs in a vector.

[Exer11_12.cpp](Exer11_12.cpp) 

## Exercise 11.13

> There are at least three ways to create the pairs in the
program for the previous exercise. Write three versions of that program,
creating the pairs in each way. Explain which form you think is easiest to
write and understand, and why.

[Exer11_13.cpp](Exer11_13.cpp) 

## Exercise 11.14

> Extend the map of children to their family name that you
wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
pair that holds a child’s name and birthday.

[Exer11_14.cpp](Exer11_14.cpp) 

## Exercise 11.15

> What are the mapped_type, key_type, and
value_type of a map from int to vector<int>?

[Exer11_15.cpp](Exer11_15.cpp) 

## Exercise 11.16

> Using a map iterator write an expression that assigns a
value to an element.

## Exercise 11.17

> Assuming c is a multiset of strings and v is a vector
of strings, explain the following calls. Indicate whether each call is legal:

## Exercise 11.20

> Rewrite the word-counting program from § 11.1 (p. 421) to
use insert instead of subscripting. Which program do you think is easier to
write and read? Explain your reasoning.

## Exercise 11.21

> Assuming word_count is a map from string to size_t
and word is a string, explain the following loop:
```cpp
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```

[Exer11_19.cpp](Exer11_19.cpp) 

## Exercise 11.22

> Given a map<string, vector<int>>, write the types
used as an argument and as the return value for the version of insert that
inserts one element.

[Exer11_20.cpp](Exer11_20.cpp) 

## Exercise 11.23

> Rewrite the map that stored vectors of children’s names
with a key that is the family last name for the exercises in § 11.2.1 (p. 424)
to use a multimap.

## Exercise 11.24

> What does the following program do?
```cpp
map<int, int> m;
m[0] = 1;
```

## Exercise 11.25

> Contrast the following program with the one in the previous
exercise
```cpp
vector<int> v;
v[0] = 1;
```

[Exer11_23.cpp](Exer11_23.cpp) 

## Exercise 11.26

> What type can be used to subscript a map? What type does
the subscript operator return? Give a concrete example—that is, define a map
and then write the types that can be used to subscript the map and the type
that would be returned from the subscript operator.

## Exercise 11.27

> What kinds of problems would you use count to solve?
When might you use find instead?

## Exercise 11.28

> Define and initialize a variable to hold the result of calling
find on a map from string to vector of int.

[Exer11_26.cpp](Exer11_26.cpp) 

## Exercise 11.29

> What do upper_bound, lower_bound, and
equal_range return when you pass them a key that is not in the container?

## Exercise 11.30

> Explain the meaning of the operand pos.first->second
used in the output expression of the final program in this section.

## Exercise 11.31

> Write a program that defines a multimap of authors and
their works. Use find to find an element in the multimap and erase that
element. Be sure your program works correctly if the element you look for is
not in the map.

## Exercise 11.32

> Using the multimap from the previous exercise, write a
program to print the list of authors and their works alphabetically.

## Exercise 11.33

> Implement your own version of the word-transformation
program.

[Exer11_31.cpp](Exer11_31.cpp) 

## Exercise 11.34

> What would happen if we used the subscript operator
instead of find in the transform function?

[Exer11_32.cpp](Exer11_32.cpp) 

## Exercise 11.35

> In buildMap, what effect, if any, would there be from
rewriting
```cpp
trans_map[key] = value.substr(1);
as trans_map.insert({key, value.substr(1)})?
```

[Exer11_33.cpp](Exer11_33.cpp) 

## Exercise 11.36

> Our program does no checking on the validity of either
input file. In particular, it assumes that the rules in the transformation file are
all sensible. What would happen if a line in that file has a key, one space,
and then the end of the line? Predict the behavior and then check it against
your version of the program.

## Exercise 11.37

> What are the advantages of an unordered container as
compared to the ordered version of that container? What are the advantages
of the ordered version?

## Exercise 11.38

> Rewrite the word-counting (§ 11.1, p. 421) and wordtransformation
(§ 11.3.6, p. 440) programs to use an unordered_map.
