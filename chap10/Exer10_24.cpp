#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}
int main()
{
	// Note: because string::size_type is a large enough unsigned integer, when
	// we compare one of that type with an int, and int is a minus, the int
	// is probably converted to unsigned, which is not intended.
	vector<int> sz = { 2, 23, 45, 98, 72, 36 };
	string str = "A long river meanders through the village.";
	auto iter = find_if(sz.begin(), sz.end(), bind(check_size, str, _1));
	cout << "The first int in sz that has a greater value than the lenght of str"
	     << " is " << *iter << endl;
	return 0;
}