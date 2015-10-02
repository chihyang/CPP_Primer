#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool findElement(vector<int>::iterator beg, vector<int>::iterator end, int key);
int main()
{
	vector<int> v;
	int i, key;
	cout << "Input a key:" << endl;
	cin >> key;
	cout << "Input some integers:" << endl;
	while(cin >> i)
	{
		v.push_back(i);
	}

	if(findElement(v.begin(), v.end(), key))
		cout << key << " is in vector." << endl;
	else
		cout << key << " is not in vector" << endl;
	return 0;
}

bool findElement(vector<int>::iterator beg, vector<int>::iterator end, int key)
{
	while(beg != end)
	{
		if(key == *beg)
			return true;
		++beg;
	}
	return false;
}