#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main()
{
	vector<int> v1 = {2, 3, 5, 7, 8};
	vector<int> v2 = {2, 3, 5, 7, 8};
	auto pv1 = v1.begin();
	auto pv2 = v2.begin();
	if(v1.end() - v1.begin() == v2.end() - v2.begin())
	{
		while(pv1 != v1.end() && pv2 != v2.end())
		{
			if(*pv1 != *pv2)
			{
				cout << "a1 and a2 are NOT equal!" << endl;
				return -1;
			}
			++pv1;
			++pv2;
		}
		cout << "a1 and a2 are equal!" << endl;
	}
	else
	{
		cout << "a1 and a2 are NOT equal!" << endl;
		return -1;
	}
	return 0;
}