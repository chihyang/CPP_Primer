#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int i = 0;
	// Compared to ways below, range for is the most simplest.
	while(i != s1.size())
	{
		s1[i] = 'X';
		++i;
	}
	for(i = 0; i < s2.size(); ++i)
		s2[i] = 'X';
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}