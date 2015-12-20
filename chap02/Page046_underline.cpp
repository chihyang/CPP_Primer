#include<iostream>
int main()
{
	// a variable named as an underline is legal
	// !!!variable name only containing one or more underlines is legal , but it's never recommended!!!
	// variable name containing two consistent underlines belongs to standard library, if you define
	// a variable with the same name as that in standard library, unexpected things would happen. 
	int _ = 1;
	int __ = 2;
	int ___ = 3;
	std::cout << _ << __<< ___ << std::endl;
	// data type won't influence result because of a implicit type conversion. So use it freely as at home.
	int compareIntAndFloat = (10 == 10.0);
	std::cout << compareIntAndFloat << std::endl;
	return 0;
}