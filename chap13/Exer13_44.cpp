#include <iostream>
#include "Exer13_44_String.h"
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
	String s1("And like a thunderbolt he falls.");
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.push_back('M');
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.push_back('S');
	cout << s1.size() << " " << s1.capacity() << endl;
	String s2 = "1";
	cout << s2.size() << " " << s2.capacity() << endl;
	return 0;
}