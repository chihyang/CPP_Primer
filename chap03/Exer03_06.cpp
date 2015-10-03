// Make sure the string is not empty. That it doesn't matter here doesn't mean it's unnecessary.
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string s;
	cin >> s;
	if(!s.empty())
	{
		for(auto &c : s)
			c = 'X';
		cout << s << endl;
	}
	return 0;
}