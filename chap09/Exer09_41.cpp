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
	string str(cp, vch.size()); // don't know why, even if we don't provide vch.size(), the result still 
	// the same
	cout << str << endl;
	return 0;
}