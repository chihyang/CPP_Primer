#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
	char c = 'z';
	string s = "this is a string.";
	
	int i;
	double d;
	const string *ps = &s;
	char *pc = &c;
	void *pv;
	pv = const_cast<string*>(ps);
	// As long as we cast away const, we can assign a pointer to void*.
	i = static_cast<int>(*pc);
	// Implicit conversion is the same.
	pv = &d;
	// Assigning a pointer to void* directly is okay.
	pc = static_cast<char*>(pv);
	// Getting original pointer type could be performed by static_cast.
	return 0;
}