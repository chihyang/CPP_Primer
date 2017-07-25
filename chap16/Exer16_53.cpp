// Warning: this is for verification. Template declarations and definitions should be put into header files.
#include <iostream>
#include <string>
#include
#include "Exer16_29_Blob.h"
using std::cout;
using std::endl;
using std::ostream;
using std::string;
// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template <typename T>
ostream& print(ostream &os, const T &t)
{
    return os << t; // no separator after the last element in the pack
}
// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest)
{
    os << t << ", ";           // print the first argument
    return print(os, rest...); //recursive call; print the other arguments
}
int main()
{
    int i = 0; double d = 3.14; string s = "how now brow cow";
    print(cout, i) << endl; // calls the first version directly
    print(cout, i, d) << endl;
    print(cout, i, d, s) << endl;
    print(cout, i, d, s, 'a') << endl;
    print(cout, i, d, s, 'a', "hi") << endl;
    return 0;
}
