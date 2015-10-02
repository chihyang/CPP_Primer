#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
	vector<int> v;
	int i;
	while(cin >> i)
		v.push_back(i);
	return 0;
}