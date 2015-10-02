#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
	vector<int> v;
	int i, j = 0;
	while(cin >> i)
	{
		v.push_back(i);
	}
	while(j < v.size() - 1)
	{
		cout << v[j] + v[j + 1] << " ";
		++j;
	}
	cout << endl;
	j = 0;
	while(j <= v.size() - 1 - j)
	{
		if(j < v.size() -1 - j)
			cout << v[j] + v[v.size() - 1 - j] << " ";
		else
			cout << v[j];
		++j;
	}
	cout << endl;
	return 0;
}