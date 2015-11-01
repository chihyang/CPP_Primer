#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::list;
using std::vector;
int main()
{
	vector<int> ivec = { 1, 2, 4, 4, 90, 2, 32, 1, 20, -20, 42};
	list<int> ilst; 
	// if not sort at first, the unique_copy doesn't work, because it only works on adjacent elements
	sort(ivec.begin(), ivec.end());
	unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));
	for(auto i : ivec)
		cout << i << " ";
	cout << endl;
	for(auto i : ilst)
		cout << i << " ";
	cout << endl;
	return 0;
}
