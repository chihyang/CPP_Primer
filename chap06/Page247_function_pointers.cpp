#include <iostream>
void foo() { std::cout << "foo" << std::endl; }
int main()
{
	void (&f) () = foo;
	void (*fp) () = foo;
	f();
	fp();
	return 0;
}
// Note: as the example above shows, we can also declare a function reference. 
// See the link below.
// https://stackoverflow.com/questions/480248/function-references