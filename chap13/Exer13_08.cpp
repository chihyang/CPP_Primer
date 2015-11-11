#include <iostream>
#include "HasPtr.h"
int main()
{
	HasPtr ps1("This is a string"), ps3("This is another string");
	HasPtr ps2 = ps1;
	ps2 = ps3;
	return 0;
}