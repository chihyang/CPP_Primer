// Warning: This is for verifying. It cannot be compiled successfully.
// The problem lies in line 12.
#include<iostream>
int main()
{
	int i = 42;
	const int &r1 = i;
	const int &r2 = 42;
	const int &r3 = r1 * 2;
	// illegal, r4 is not const, so it cannot be initialized by an expression
	int &r4 = i * 2;
	
	double dval = 3.14;
	//legal even if type doesn't match, because ri is actually bond to a temporary variable created by compiler.
	const int &ri = dval;
	return 0;
}