#include <iostream>
#include "Exer13_53_HasPtr.h"
using std::cout;
using std::endl;
int main()
{
	HasPtr hp("Young and Beautiful");
	HasPtr hp1;
	hp1 = hp;
	HasPtr hp2 = std::move(hp); // now hp can't be used again, because it refers to null
	hp2.print(cout) << endl;
	hp.print(cout);
	return 0;
}