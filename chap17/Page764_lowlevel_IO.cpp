// Warning: this is for illustration. It has run time error.
// See page 764 for illustration.
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
int main()
{
	unsigned char ch; // using an unsigned char here invites disaster!
	// the return from cin.get is converted to char and then compared to an int
	// ch is 0 or has a positive value, which is never equal to EOF
	while ((ch = cin.get()) != EOF)
		cout.put(ch);
	return 0;
}
// Note: because the result of get is ALWAYS non-negative, when we assign it to 
// an unsigned char, it will never be equal to EOF. On the other hand, if we 
// assign it to a signed char, the result would be hard to say. If the value of
// cin.get() is out of range of a signed char, the result would depend on compiler.