// Warning: this is for verification. Template declarations and definitions should be put into header files.
// Warning: this program cannot be compiled by each compiler. See note below.
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest)
{
	cout << "ostream& print(ostream&, const T&, const Args&...)" << endl;
	os << t << ", ";           // print the first argument
	return print(os, rest...); //recursive call; print the other arguments
}
// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template <typename T>
ostream& print(ostream &os, const T &t)
{
	cout << "ostream& print(ostream&, const T&)" << endl;
	return os << t; // no separator after the last element in the pack
}
int main()
{
	int i = 0; double d = 3.14; string s = "how now brow cow";
	print(cout, i, d, s) << endl;
	return 0;
}
// ******compile info of g++******
// (the compile info of g++ is very tedious and hard to understand, but its meaning
// is the same as clang++: no match for call print(os, rest...))

// ******compile info of clang++******
// F:\Programming\CPP\cpp_primer\chap16\Exer16_55.cpp:15:9: error: no matching
//       function for call to 'print'
//         return print(os, rest...); //recursive call; print the other arguments
//                ^~~~~
// F:\Programming\CPP\cpp_primer\chap16\Exer16_55.cpp:15:9: note: in instantiation
//       of function template specialization
//       'print<std::__cxx11::basic_string<char>>' requested here
//         return print(os, rest...); //recursive call; print the other arguments
//                ^
// F:\Programming\CPP\cpp_primer\chap16\Exer16_55.cpp:15:9: note: in instantiation
//       of function template specialization 'print<double,
//       std::__cxx11::basic_string<char> >' requested here
//         return print(os, rest...); //recursive call; print the other arguments
//                ^
// F:\Programming\CPP\cpp_primer\chap16\Exer16_55.cpp:28:2: note: in instantiation
//       of function template specialization 'print<int, double,
//       std::__cxx11::basic_string<char> >' requested here
//         print(cout, i, d, s) << endl;
//         ^
// F:\Programming\CPP\cpp_primer\chap16\Exer16_55.cpp:11:10: note: candidate
//       function template not viable: requires at least 2 arguments, but 1 was
//       provided
// ostream& print(ostream &os, const T &t, const Args&... rest)
//          ^
// 1 error generated.

// ******compile info of cl******
// (compile passed, execution successful)

// ******result compiled by cl******
// ostream& print(ostream&, const T&, const Args&...)
// 0, ostream& print(ostream&, const T&, const Args&...)
// 3.14, ostream& print(ostream&, const T&)
// how now brow cow

// Note: as the compile info and result above show, if print(ostream&, const T&)
// is not declared at first, the program cannot be compiled by every compiler. 
// The problem is the call print(os, rest...). This call should match variadic
// version for the first iteration, but it seems that every compiler matches it 
// to print(ostream&, const T&) at compile time; only when the program is run, 
// this call matches to print(ostream&, const T&, const Args&...) for the call
// print(cout, i, d, s). This program can be compiled by cl because cl doesn't 
// require forward declaration, not because it matches print(os, rest...) to 
// print(ostream&, const T&, const Args&...) at compile time. But to make the 
// program work properly under any condition, we should declare names that are
// used by following code at first, rather than write such machine-dependent 
// codes.
// 
// Besides, it says on page 702 that the variadic function will recurse indefinitely
// if print(ostream&, const T&) is not declared before the variadic version is
// defined. This does not agree with the result above.