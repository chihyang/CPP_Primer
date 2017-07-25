// Warning: this is for illustration. Template declarations and definitions should be put into header files.
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
template <typename T> void debug_test1(const T &t)
{
    int i = 2;
    // test for passing const int
    T t2 = 3;
    cout << t2 << endl;
    t2 = 5;
    cout << t2 << endl;
}
template <typename T> void debug_test2(const T &t)
{
    int i = 2;
    // test for passing const int*
    T t2 = &i;
    cout << *t2 << endl;
    *t2 = 7;
    cout << *t2 << endl;
}
template <typename T> void debug_test3(const T &t)
{
    string str = "s";
    // test for passing const string*
    T t2 = &str;
    cout << *t2 << endl;
    *t2 = "this";
    cout << *t2 << endl;
}
int main()
{
    string s = "this", *sp = &s;
    const string *scp = &s;
    int j = 42, &lr = j, &&rr = 2, *p = &j;
    const int cj = 20;
    const int &clr = j, &&crr = 41, *ip = &j;
    // passing int and const int, lvalue reference and rvalue reference and const reference, T is int,
    debug_test1(j);
    debug_test1(cj);
    debug_test1(clr);
    debug_test1(clr);
    debug_test1(lr);
    debug_test1(rr);
    // passing int* and const int*
    debug_test2(p);   // T is int*, can assign and initialize
    debug_test2(ip);  // T is const int*, cannot assign, can only initialize
    // passing const string*
    debug_test3(sp);  // T is string*, can assign and initialize
    debug_test3(scp); // T is const string*, cannot assign, can only initialize
    return 0;
}
// Note: on page 687 it says:
// When a function parameter is an ordinary (lvalue) reference to a template type
// parameter, ..., if the argument is const, then T will be deduced as a const
// type;
// If a function parameter has type const T&, when the function parameter is
// itself const, the type deduced for T will not be a const type. The const is
// already part of the function parameter type.
// But pointer seems different disagrees with this rule. Even as the example
// above shows, even if function parameter is const T&, if a pointer to const
// argument is passed to function template, T is still deduced as a pointer to
// const. Maybe this is because a pointer to const has a low-level const.
