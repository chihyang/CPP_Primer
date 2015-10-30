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
	// read a value to be counted
	cin >> val;
	// read a sequence of ints
	while(cin >> i)
	{
		iv.push_back(i);
	}
	// count how often val appears
	auto cnt = count(iv.begin(), iv.end(), val);
	cout << cnt << endl;
	return 0;
}