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
	// As long as we cast away const, we can assign a pointer to void*.
	pv = const_cast<string*>(ps);
	// Implicit conversion gets the same result as below.
	i = static_cast<int>(*pc);
	// Assigning a pointer to void* directly is okay.
	pv = &d;
	// Getting original pointer type can be performed by static_cast.
	pc = static_cast<char*>(pv);
	return 0;
}