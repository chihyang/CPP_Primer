#include <iostream>
#include <string>
#include "Exer09_51.h"
using std::cin;
using std::string;
int main()
{
	string d;
	while(getline(cin, d))
	{
		Date date(d);
		date.print_date();
	}
	return 0;
}