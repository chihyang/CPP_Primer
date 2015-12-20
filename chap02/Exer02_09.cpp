// Warning: This is for verification. It cannot be compiled successfully.
#include<iostream>
int main()
{
	// (a), it's illegal. 'Cause input_value isn't defined when the program tries to wite to it.
	std::cin >> int input_value;
	// (b), illegal, precision lost
	int i1 = { 3.14 };
	// (c), illegal, wage not defined
	double salary = wage = 9999.9;
	// (d), legal
	int i2 = 3.14;
	return 0;
}