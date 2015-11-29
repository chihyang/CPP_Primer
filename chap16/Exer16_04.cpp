#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Exer16_04.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
int main()
{
	vector<int> vec{1, 2, 5, 8, 0, 12, 98, 29};
	list<string> lst{"Gone", "are", "the", "days"};
	string val = "day";
	auto v = find(vec.cbegin(), vec.cend(), 8);
	auto l = find(lst.cbegin(), lst.cend(), val);
	cout << v - vec.begin() << endl;
	if(l == lst.end())
		cout << val << " is not in lst" << endl;
	return 0;
}