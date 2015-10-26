// Warning: This is for verification. It can be compiled successfully but doesn't work.
// The problems lie in line 11 to 14.
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int> iv;
	cout << iv.at(0) << endl;
	cout << iv[0] << endl;
	cout << iv.front() << endl;
	cout << iv.back() << endl;
	return 0;
}
// Note: if we don't judge if a vector is empty, the access operation above just
// make the program crash. But at operation will throw an exception, reminding 
// us of the stupid error.
// WARNING: JUDGE if a container is empty before accessing its elements.