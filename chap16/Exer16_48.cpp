#include <iostream>
#include <string>
#include "Exer16_48_debug_ret.h"
using std::cout;
using std::endl;
using std::string;
int main()
{
	string s("hi");
	const string *sp = &s;
	char a[] = "How are you?";
	char *p = a;
	cout << debug_ret(s) << "\n" << endl;  // call debug_ret(const string&)
	cout << debug_ret(sp) << "\n" << endl; // call debug_ret(T*), instantiated to debug_ret(const string*)
	cout << debug_ret("hi world!") << "\n" << endl; // call debug_ret(const char*)
	cout << debug_ret(p) << endl; // call debug_ret(char*)
	return 0;
}