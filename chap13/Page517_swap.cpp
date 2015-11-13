#include <iostream>
#include <algorithm>
#include "HasPtr.h"
using std::cout;
using std::endl;
class Foo {
	friend void swap(Foo &lhs, Foo &rhs);
public:
	Foo(HasPtr p) : h(p) {}
private:
	HasPtr h;
};
void swap(Foo &lhs, Foo &rhs)
{
	using std::swap;
	swap(lhs.h, rhs.h); // this way, friend function swap of HasPtr will be called
}
int main()
{
	Foo f1(HasPtr("string1"));
	Foo f2(HasPtr("string2"));
	swap(f1, f2);
	return 0;
}