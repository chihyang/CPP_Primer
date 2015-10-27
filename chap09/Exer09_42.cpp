#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string str;
	str.reserve(100); // at least 100 elements
	cout << str.capacity() << endl;
	char ch;
	while(cin >> ch)
		str.push_back(ch);
	return 0;
}