#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
	vector<int> iv;
	int i, val;
	// read a sequence of ints
	while(cin >> i)
	{
		iv.push_back(i);
	}
	// read a value to be counted
	cin.clear(); // if not, we can't input anything, see page 313, 8.1.2 Condition States
	cin >> val;
	// count how often val appears
	auto cnt = count(iv.begin(), iv.end(), val);
	cout << cnt << endl;
	return 0;
}