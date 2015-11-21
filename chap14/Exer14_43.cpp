#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::vector;
using std::modulus;
using namespace std::placeholders;
int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> vi;
	int val = 1000;
	auto cnt = count_if(vec.begin(), vec.end(), bind(modulus<int>(), val, _1));
	if(cnt == vec.size())
		cout << val << " can't be divided by any value in vec." << endl;
	else	
		cout << val << " can be divided by some values in vec." << endl;
	return 0;
}