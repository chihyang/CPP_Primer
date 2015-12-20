
##Exercise 16.1

> Define instantiation.

##Exercise 16.2

> Write and test your own versions of the compare functions.

##Exercise 16.3

> Call your compare function on two Sales_data objects to
see how your compiler handles errors during instantiation.

##Exercise 16.4

> Write a template that acts like the library find algorithm.
The function will need two template type parameters, one to represent the
function’s iterator parameters and the other for the type of the value. Use
your function to find a given value in a vector<int> and in a
list<string>.

##Exercise 16.5

> Write a template version of the print function from § 6.2.4
(p. 217) that takes a reference to an array and can handle arrays of any size
and any element type.

##Exercise 16.6

> How do you think the library begin and end functions that
take an array argument work? Define your own versions of these functions.

##Exercise 16.7

> Write a constexpr template that returns the size of a given
array.

##Exercise 16.8

> In the “Key Concept” box on page 108, we noted that as a
matter of habit C++ programmers prefer using != to using <. Explain the
rationale for this habit.

##Exercise 16.9

> What is a function template? What is a class template?

##Exercise 16.10

> What happens when a class template is instantiated?

##Exercise 16.11

> The following definition of List is incorrect. How would
you fix it?
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem *front, *end;
};
```

##Exercise 16.12

> Write your own version of the Blob and BlobPtr
templates. including the various const members that were not shown in the
text.

##Exercise 16.13

> Explain which kind of friendship you chose for the equality
and relational operators for BlobPtr.

##Exercise 16.14

> Write a Screen class template that uses nontype
parameters to define the height and width of the Screen.

##Exercise 16.15

> Implement input and output operators for your Screen
template. Which, if any, friends are necessary in class Screen to make the
input and output operators work? Explain why each friend declaration, if any,
was needed.

##Exercise 16.16

> Rewrite the StrVec class (§ 13.5, p. 526) as a template
named Vec.

##Exercise 16.17

> What, if any, are the differences between a type parameter
that is declared as a typename and one that is declared as a class? When
must typename be used?

##Exercise 16.18

> Explain each of the following function template declarations
and identify whether any are illegal. Correct each error that you find.
```cpp
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int*);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
    template <typename Ctype> Ctype f5(Ctype a);
```

##Exercise 16.19

> Write a function that takes a reference to a container and
prints the elements in that container. Use the container’s size_type and
size members to control the loop that prints the elements.

##Exercise 16.20

> Rewrite the function from the previous exercise to use
iterators returned from begin and end to control the loop.

##Exercise 16.21

> Write your own version of DebugDelete.

##Exercise 16.22

> Revise your TextQuery programs from § 12.3 (p. 484) so
that the shared_ptr members use a DebugDelete as their deleter (§
12.1.4, p. 468).

##Exercise 16.23

> Predict when the call operator will be executed in your
main query program. If your expectations and what happens differ, be sure
you understand why.

##Exercise 16.24

> Add a constructor that takes two iterators to your Blob
template.

##Exercise 16.25

> Explain the meaning of these declarations:
```cpp
extern template class vector<string>;
template class vector<Sales_data>;
```

##Exercise 16.26

> Assuming NoDefault is a class that does not have a
default constructor, can we explicitly instantiate vector<NoDefault>? If
not, why not?

##Exercise 16.27

> For each labeled statement explain what, if any,
instantiations happen. If a template is instantiated, explain why; if not,
explain why not.
```cpp
template <typename T> class Stack { };
    void f1(Stack<char>); // (a)
    class Exercise {
    Stack<double> &rsd; // (b)
    Stack<int> si; // (c)
};
int main() {
    Stack<char> *sc; // (d)
    f1(*sc); // (e)
    int iObj = sizeof(Stack< string >); // (f)
}
```

##Exercise 16.28

> Write your own versions of shared_ptr and
unique_ptr.

##Exercise 16.29

> Revise your Blob class to use your version of
shared_ptr rather than the library version.

##Exercise 16.30

> Rerun some of your programs to verify your shared_ptr
and revised Blob classes. (Note: Implementing the weak_ptr type is
beyond the scope of this Primer, so you will not be able to use the BlobPtr
class with your revised Blob.)

##Exercise 16.31

> Explain how the compiler might inline the call to the deleter
if we used DebugDelete with unique_ptr.

##Exercise 16.32

> What happens during template argument deduction?

##Exercise 16.33

> Name two type conversions allowed on function arguments
involved in template argument deduction.

##Exercise 16.34

> Given only the following code, explain whether each of
these calls is legal. If so, what is the type of T? If not, why not?
template <class T> int compare(const T&, const T&);
```cpp
(a) compare("hi", "world");
(b) compare("bye", "dad");
```

##Exercise 16.35

> Which, if any, of the following calls are errors? If the call is
legal, what is the type of T? If the call is not legal, what is the problem?
```cpp
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d; float f; char c;
(a) calc(c, 'c');
(b) calc(d, f);
(c) fcn(c, 'c');
(d) fcn(d, f);
```

##Exercise 16.36

> What happens in the following calls:
```cpp
template <typename T> f1(T, T);
template <typename T1, typename T2) f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
(a) f1(p1, p2);
(b) f2(p1, p2);
(c) f1(cp1, cp2);
(d) f2(cp1, cp2);
(e) f1(p1, cp1);
(f) f2(p1, cp1);
```

##Exercise 16.37

> The library max function has two function parameters and
returns the larger of its arguments. This function has one template type
parameter. Could you call max passing it an int and a double? If so, how?
If not, why not?

##Exercise 16.38

> When we call make_shared (§ 12.1.1, p. 451), we have to
provide an explicit template argument. Explain why that argument is needed
and how it is used.

##Exercise 16.39

> Use an explicit template argument to make it sensible to
pass two string literals to the original version of compare from § 16.1.1 (p.
652).

##Exercise 16.40

> Is the following function legal? If not, why not? If it is
legal, what, if any, are the restrictions on the argument type(s) that can be
passed, and what is the return type?
```cpp
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    // process the range
    return *beg; // return a copy of an element from the range
}
```

##Exercise 16.41

> Write a version of sum with a return type that is
guaranteed to be large enough to hold the result of the addition.

##Exercise 16.42

> Determine the type of T and of val in each of the
following calls:
```cpp
template <typename T> void g(T&& val);
int i = 0; const int ci = i;
(a) g(i);
(b) g(ci);
(c) g(i * ci);
```

##Exercise 16.43

> Using the function defined in the previous exercise, what
would the template parameter of g be if we called g(i = ci)?

##Exercise 16.44

> Using the same three calls as in the first exercise,
determine the types for T if g’s function parameter is declared as T (not
T&&). What if g’s function parameter is const T&?

##Exercise 16.45

> Given the following template, explain what happens if we
call g on a literal value such as 42. What if we call g on a variable of type
int?
template <typename T> void g(T&& val) { vector<T> v; }

##Exercise 16.46

> Explain this loop from StrVec::reallocate in § 13.5 (p.
530):
```cpp
for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
```

##Exercise 16.47

> Write your own version of the flip function and test it by
calling functions that have lvalue and rvalue reference parameters.

##Exercise 16.48

> Write your own versions of the debug_rep functions.

##Exercise 16.49

> Explain what happens in each of the following calls:
```cpp
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;
g(42); g(p); g(ci); g(p2);
f(42); f(p); f(ci); f(p2);
```

##Exercise 16.50

> Define the functions from the previous exercise so that they
print an identifying message. Run the code from that exercise. If the calls
behave differently from what you expected, make sure you understand why.

##Exercise 16.51

> Determine what sizeof...(Args) and
sizeof...(rest) return for each call to foo in this section.

##Exercise 16.52

> Write a program to check your answer to the previous
question.

##Exercise 16.53

> Write your own version of the print functions and test
them by printing one, two, and five arguments, each of which should have
different types.

##Exercise 16.54

> What happens if we call print on a type that doesn’t have
an << operator?

##Exercise 16.55

> Explain how the variadic version of print would execute if
we declared the nonvariadic version of print after the definition of the
variadic version.

##Exercise 16.56

> Write and test a variadic version of errorMsg.

##Exercise 16.57

> Compare your variadic version of errorMsg to the
error_msg function in § 6.2.6 (p. 220). What are the advantages and
disadvantages of each approach?

##Exercise 16.58

> Write the emplace_back function for your StrVec class
and for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668).

##Exercise 16.59

> Assuming s is a string, explain
svec.emplace_back(s).

##Exercise 16.60

> Explain how make_shared (§ 12.1.1, p. 451) works.

##Exercise 16.61

> Define your own version of make_shared.

##Exercise 16.62

> Define your own version of hash<Sales_data> and
define an unordered_multiset of Sales_data objects. Put several
transactions into the container and print its contents.

##Exercise 16.63

> Define a function template to count the number of
occurrences of a given value in a vector. Test your program by passing it a
vector of doubles, a vector of ints, and a vector of strings.

##Exercise 16.64

> Write a specialized version of the template from the
previous exercise to handle vector<const char*> and a program that
uses this specialization.

##Exercise 16.65

> In § 16.3 (p. 698) we defined overloaded two versions of
debug_rep one had a const char* and the other a char* parameter.
Rewrite these functions as specializations.

##Exercise 16.66

> What are the advantages and disadvantages of overloading
these debug_rep functions as compared to defining specializations?

##Exercise 16.67

> Would defining these specializations affect function
matching for debug_rep? If so, how? If not, why not?
