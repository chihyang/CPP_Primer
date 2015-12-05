// Warning: this is for verification. Template declarations and definitions should be put into header files.
// Warning: this program cannot compile. The problem lies in line 25.
#include <iostream>
#include "Exer16_29_Blob.h"
using std::cout;
using std::endl;
using std::ostream;
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
	Blob<int> blob1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print(cout, blob1) << endl; // error: Blob doesn't overload << operator
	return 0;
}