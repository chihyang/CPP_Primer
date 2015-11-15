#include <iostream>
#include <string>
#include "Exer13_43.h"
using std::cout;
using std::endl;
using std::string;
int main()
{
	StrVec v = {"Gone", "with", "the"};
	v.push_back("winds");
	for_each(v.begin(), v.end(), [](const string &s) {cout << s << " ";});
	cout << endl;
	return 0;
}
