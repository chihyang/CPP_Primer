#include <iostream>
#include <vector>
#include "Exer16_61_shared_ptr.h"
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
int main()
{
	// call move constructor of vector to construct an object
	auto sp = make_shared<vector<int>>(vector<int>{1, 2, 3, 4, 5});
	for(auto p = sp->begin(); p != sp->end(); ++p)
		cout << *p << " ";
	cout << endl;
	return 0;
}