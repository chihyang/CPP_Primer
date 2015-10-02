#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<string> v;
	string s;
	while(cin >> s)
		v.push_back(s);
	for(auto s : v) // auto can decuce string also
		cout << s << " ";
	cout << endl;
	return 0;
}