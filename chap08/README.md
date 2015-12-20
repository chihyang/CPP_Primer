##Exercise 8.1

> Write a function that takes and returns an istream&. The
function should read the stream until it hits end-of-file. The function should
print what it reads to the standard output. Reset the stream so that it is valid
before returning the stream.

##Exercise 8.2

> Test your function by calling it, passing cin as an argument.

##Exercise 8.3

> What causes the following while to terminate?
```cpp
while (cin >> i) /* ... */
```

##Exercise 8.4

> Write a function to open a file for input and read its contents
into a vector of strings, storing each line as a separate element in the
vector.

##Exercise 8.5

> Rewrite the previous program to store each word in a
separate element.

##Exercise 8.6

> Rewrite the bookstore program from § 7.1.1 (p. 256) to read
its transactions from a file. Pass the name of the file as an argument to main
(§ 6.2.5, p. 218).

##Exercise 8.4

> Write a function to open a file for input and read its contents
into a vector of strings, storing each line as a separate element in the
vector.

##Exercise 8.5

> Rewrite the previous program to store each word in a
separate element.

##Exercise 8.6

> Rewrite the bookstore program from § 7.1.1 (p. 256) to read
its transactions from a file. Pass the name of the file as an argument to main
(§ 6.2.5, p. 218).

##Exercise 8.9

> Use the function you wrote for the first exercise in § 8.1.2 (p.
314) to print the contents of an istringstream object.

##Exercise 8.10

> Write a program to store each line from a file in a
vector<string>. Now use an istringstream to read each element from
the vector a word at a time.

##Exercise 8.11

> The program in this section defined its istringstream
object inside the outer while loop. What changes would you need to make if
record were defined outside that loop? Rewrite the program, moving the
definition of record outside the while, and see whether you thought of all
the changes that are needed.

##Exercise 8.12

> Why didn’t we use in-class initializers in PersonInfo?

##Exercise 8.13

> Rewrite the phone number program from this section to read
from a named file rather than from cin.

##Exercise 8.14

> Why did we declare entry and nums as const auto &?
