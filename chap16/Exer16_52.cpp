// Warning: this is for verification. Template declarations and definitions should be put into header files.
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
// Args is a template parameter pack; args is a function parameter pack
// Args represents zero or more template type parameters
// args represents zero or more function parameters
template <typename T, typename... Args>
void foo(const T &t, const Args& ... args)
{
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
}
int main()
{
	int i = 0; double d = 3.14; string s = "how now brow cow";
	// call void foo(const int&, const string&, const int&, const double&)
	foo(i, s, 42, d); // three parameters in the pack
	// call void foo(const string&, const int&, const char[3]&)
	foo(s, 42, "hi"); // two parameters in the pack
	// call void foo(const double&, const string&)
	foo(d, s);        // one parameter in the pack
	// call void foo(const char[3]&)
	foo("hi");        // empty pack
	return 0;
}