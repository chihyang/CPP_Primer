#include <iostream>
#include "Exer13_53_HasPtr_copy_swap.h"
using std::cout;
using std::endl;
int main()
{
	HasPtr hp("Young and Beautiful");
	HasPtr hp1;
	hp1 = hp;
	HasPtr hp2("Take him away"); // now hp can't be used again, because it refers to null
	hp2 = std::move(hp);
	hp2.print(cout) << endl;
	hp.print(cout);
	return 0;
}
// Note #1: what's the difference between copy-swap and move version? As we can 
// see, both get the same result. The difference is which constructor to call.
// When we use move-assignment, we never call constructor; when we use copy-swap
// version, copy constructor or move constructor is called depending on type of 
// argument. In the former version, function matches before argument passing, 
// while function matches after argument passing in the latter.

// Note #2 : const T& and T cannot be used to overload functions. See
// Exer13_53_overload.cpp for details.