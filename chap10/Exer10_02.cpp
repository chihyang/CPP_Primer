#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
int main()
{
	list<string> lst;
	string str, str_val;
	// read a sequence of strings
	while(cin >> str)
	{
		lst.push_back(str);
	}
	// read a value to be counted
	cin.clear(); // if not, we can't input anything, see page 313, 8.1.2 Condition States
	cin >> str_val;
	// count how often val appears
	auto cnt = count(lst.begin(), lst.end(), str_val);
	cout << cnt << endl;
	return 0;
}