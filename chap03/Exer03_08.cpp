#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string s1, s2;
	int i = 0;
	cin >> s1 >> s2;
	if(!s1.empty()){
		// Compared to ways below, range for is the most simplest.
		while(i != s1.size())
		{
			s1[i] = 'X';
			++i;
		}
		cout << s1 << endl;
	}
	if(!s2.empty())
	{
		for(i = 0; i < s2.size(); ++i)
			s2[i] = 'X';
		cout << s2 << endl;
	}
	return 0;
}