// see Exer07_04.h for function declarations and definitions.
#include <iostream>
#include <string>
#include "Exer07_04.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
	Person psn;
	read(cin, psn);
	print(cout, psn) << endl;
	return 0;
}