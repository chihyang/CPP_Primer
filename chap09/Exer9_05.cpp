#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>::iterator findElement(vector<int>::iterator beg, vector<int>::iterator end, int key);
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
	vector<int>::iterator result = findElement(v.begin(), v.end(), key);
	if(result != v.end())
		cout << *result << endl;
	else
		cout << key << " is not in vector" << endl;
	return 0;
}

vector<int>::iterator findElement(vector<int>::iterator beg, vector<int>::iterator end, int key)
{
	while(beg != end)
	{
		if(key == *beg)
			return beg;
		++beg;
	}
	return end;
}