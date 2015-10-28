#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
	string numbers("0123456789"), name("r2d2 C-3PO");
	string::size_type pos = 0;
	while((pos = name.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "found number at index: " << pos
		     << " element is " << name[pos] << endl;
			 ++pos;
	}
	return 0;
}