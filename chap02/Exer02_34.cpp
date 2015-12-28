// Warning: This is for verification. It cannot be compiled successfully by every compiler.
// The problem lies in line 29, 30, 31.
#include<iostream>
int main()
{
	int i = 0, &r = i;
	auto a = r;
	const int ci = i, &cr = ci;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	const auto f = ci;
	auto &g = ci;
	const auto &j = 42;
	std::cout << a << " " << 
	             b << " " <<
	             c << " " <<
	             d << " " <<
	             e << " " <<
	             g << " " << std::endl;
	// Try to assign
	// legal
	a = 42;
	b = 42;
	c = 42;
	// illegal
	d = 42; // pointer, can't be assigned an int value
	e = 42; // const pointer, here const is low-level because of &
	g = 42; // const reference, const won't be ignored in this situation
	std::cout << a << " " << 
	             b << " " <<
				 c << " " <<
				 d << " " <<
				 e << " " <<
				 g << " " << std::endl;
	return 0;
}