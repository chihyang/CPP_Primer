#include <iostream>
void foo(int&&) {std::cout << "void foo(int&&)" << std::endl;}
void foo(int&) {std::cout << "void foo(int&)" << std::endl;}
int main()
{
	int i = 0;
	foo(2);
	foo(i);
	foo(std::move(i));
	return 0;
}
// Note: lvalue and rvalue reference can be used to overload function. Because 
// they DO match different arguments. Compare this with Exer13_53_overload.cpp, 
// we can find that overloaded functions must be able to be passed different 
// arguments. If two functions with the same name can be passed completely 
// identical arguments, they will cause ambiguous call. Thus match rules on page
// 245 won't work.