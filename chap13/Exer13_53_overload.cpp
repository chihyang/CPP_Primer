// Warning: this is for explanation. It cannot compile.
// The problem lies in ambiguous call.
#include <iostream>
void foo(const int&) {std::cout << "const int&" << std::endl;}
void foo(int) {std::cout << "int&" << std::endl;}
int main()
{
	int i = 0;
	foo(i);
	return 0;
}
// ******compile info of clang++******
// Exer13_53_overload.cpp:9:2: error: call to 'foo' is ambiguous
//         foo(i);
//         ^~~
// Exer13_53_overload.cpp:4:6: note: candidate function
// void foo(const int&) {std::cout << "const int&" << std::endl;}
//      ^
// Exer13_53_overload.cpp:5:6: note: candidate function
// void foo(int) {std::cout << "int&" << std::endl;}
//      ^
// 1 error generated.

// Note: why is this an ambiguous call? First let's see line 9. i is an int. 
// When we pass it to foo, it can be used to initialize an int or a const reference
// to int. So both foo(const int&) and foo(int) are viable. The problem is which
// matches better. Strictly speaking, calling foo(const int&) by i requires 
// conversion to const(page 162). Thus foo(const int&) should be ranked lower 
// than foo(int), which is exact match. On the other hand, however, we can pass
// a plain variable, a const object, a literal or an object that requires conversion
// to both const reference and plain parameter. As a result, there is no way to 
// differentiate them. Maybe that's the reason why const reference and plain 
// type cannot be used to overload a function. Furthermore, whether an int has 
// (top-level) const qualifier or not can not be used to differentiate overload 
// function. But foo(int) is actually using top-level const to differentiate 
// itself from foo(const int&). This might be a better explanation for ambiguity.