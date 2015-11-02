#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
int main()
{
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ostream_iterator<int> out_iter(cout, " ");
	for(auto e : ivec)
		*out_iter++ = e; // equivalent to out_iter = e, but more readable and general
	cout << endl;
	copy(ivec.begin(), ivec.end(), out_iter);
	cout << endl;
	return 0;
}