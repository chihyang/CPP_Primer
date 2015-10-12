#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main(int argc, char *argv[])
{
	string argStr;
	for(int i = 0; i != argc; ++i)
		argStr = argStr + argv[i] + " "; 
	// Note: argv[0] contains program's name or is empty
	// Here we can take a glimpse of how those magnificant linux commands are
	// built.
	cout << argStr << endl;
	return 0;
}