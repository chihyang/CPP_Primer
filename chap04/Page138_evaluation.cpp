// Order of evaluation
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	int i = 0, j = 1;
	// The results compiled by G++ and CL are both 1 1, but this doesn't mean
	// with any compiler the result is 1 1.
	cout << i << " " << ++i << endl;
	return 0;
}