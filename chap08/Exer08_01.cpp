#include <iostream>
#include <string>
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
istream& read(istream& is)
{
	string word;
	while(!is.eof())
	{
		is >> word;
		cout << word << endl;
	}
	is.clear();
	return is;
}
int main()
{
	read(cin);
	return 0;
}