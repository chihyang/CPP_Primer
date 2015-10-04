#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string st1 = "Like a thunderbolt he falls.";
	string st2 = "Do not go gentle into that good night.";
	if(st1 > st2)
		cout << "st1 is larger than st2." << endl;
	else if(st1 < st2)
		cout << "st1 is larger than st2." << endl;
	else
		cout << "st1 is equal to st2." << endl;
	char st3[] = {'T', 'e', 'n', 'd', 'e', 'r', '\0'};
	// If we do not add a null terminator, there'll be potential problems.
	// Keep it in mind.
	char st4[] = "Is The Night";
	if(strcmp(st3, st4) > 0)
		cout << "st3 is larger than st4." << endl;
	else if(strcmp(st3, st4) < 0)
		cout << "st3 is larger than st4." << endl;
	else
		cout << "st3 is equal to st4." << endl;
	return 0;
}