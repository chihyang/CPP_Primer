#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
	// size zero, capacity implementation defined
	vector<int> ivec;
	cout << "ivec: size: " << ivec.size() 
	     << " capacity: " << ivec.capacity() << endl;
	// give ivec 24 elements
	for(vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;
	// sets capacity to at least 50, might be more
	ivec.reserve(50); // reserve should take affect immediately, but the effect depends on the 
	// relationship between the argument and current capacity
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;
	// add elements to use up the excess capacity
	while(ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;
	// add another element,, capacity will be >= 51 and defined by implementation
	ivec.push_back(42);
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;
	// request to shrink, but might be ignored	
	ivec.shrink_to_fit();
	cout << "ivec: size: " << ivec.size()
	     << " capacity: " << ivec.capacity() << endl;
	return 0;
}
// ******output compiled by cl******
// ivec: size: 0 capacity: 0
// ivec: size: 24 capacity: 28
// ivec: size: 24 capacity: 50
// ivec: size: 50 capacity: 50
// ivec: size: 51 capacity: 75
// ivec: size: 51 capacity: 51

// ******output compiled by g++******
// ivec: size: 0 capacity: 0
// ivec: size: 24 capacity: 32
// ivec: size: 24 capacity: 50
// ivec: size: 50 capacity: 50
// ivec: size: 51 capacity: 100
// ivec: size: 51 capacity: 51

