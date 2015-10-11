// Exer06_09, fact.cc, see factMain.cc for compile and link info
#include <iostream>
#include "Chapter6.h"
int fact(int val)
{
	int ret = 1;
	while(val > 1)
		ret *= val--;
	return ret;
}