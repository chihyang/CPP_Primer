// Warning: This is for verification. It CANNOT be compiled successfully by both compilers.
// The problems lie in line 14.
#include <iostream>
void fun() // overloaded #1
{
	std::cout << "This is a function without any parameter" << std::endl;
}
void fun(int a = 0, int b = 0) // overloaded #2
{
	std::cout << a << " " << b << std::endl;
}
int main()
{
	fun(); // ambiguous call
	fun(2);
	fun(2, 3);
	return 0;
}
// Note: why is this an ambiguous call? First, this call takes no arguments.
// Overloaded function #1 has zero parameter, while #2 has two parameters with 
// default argument initializers. Compiler checks arguments one by one, only to 
// find that both #1 and #2 are viable. Because there is no const conversion, 
// promotion, arithmetic conversion or class-type conversion, both are exact 
// match! So the poor compiler gets perplexing. It can do nothing but complain 
// to us about it.
