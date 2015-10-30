#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;
int main()
{
	vector<int> ivec(10);
	fill_n(ivec.begin(), ivec.size(), 9); // use a container that has nonzero size
	list<int> ilst;
	fill_n(back_inserter(ilst), 10, 5); // use inserter iterator
	for(const auto &i : ivec)
		cout << i << " ";
	cout << endl;
	for(const auto &i : ilst)
		cout << i << " ";
	cout << endl;
	return 0;
}