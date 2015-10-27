#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<char> vch = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '!', '!' };
	char* cp = &vch[0];
	// way1, don't forget sting can be initialized with common way of a container
	string str1(vch.cbegin(), vch.cend());
	string str2(cp, vch.size()); // don't know why, even if we don't provide vch.size(), the result still 
	// the same
	cout << str1 << endl;
	cout << str2 << endl;
	return 0;
}