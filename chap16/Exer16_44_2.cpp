// Warning: this is for verification. Template declarations and definitions should be put into header files.
#include <iostream>
using std::cout;
using std::endl;
template <typename T>
void g(const T& val) { T t; t = 42; }
int main()
{
	int i = 0;
	const int ci = i;
	g(i);      // ok: T is int; val is const int&
	g(ci);     // ok: T is int(const won't overlap); val is const int&;
	g(i * ci); // ok: T is int(although i * ci yields an rvalue, see page 687); val is const int&
	return 0;
}