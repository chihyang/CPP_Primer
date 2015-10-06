#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int> v = {1, 3, 2, 4, 6, 23, 11, 2, -3, -20, 0};
	for(auto p = v.begin(); p != v.end(); ++p)
		*p = (*p % 2 != 0) ? (2 * *p) : *p;
	for(const int &i : v)
		cout << i << " ";
	cout << endl;
	return 0;
}