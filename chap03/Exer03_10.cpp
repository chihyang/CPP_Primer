#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string text;
	getline(cin, text);
	for(auto c : text)
		if(!ispunct(c))
			cout << c;
	cout << endl;
	return 0;
}