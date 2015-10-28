#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
string& changeSubstr(string &s, const string& oldVal, const string& newVal)
{
	if(s.empty() || oldVal.empty()) // be careful, s and oldVal should be non empty strings
		return s;
	auto sizeOld = oldVal.size();
	auto sizeNew = newVal.size();
	decltype(sizeOld) index = 0;
	while(index <= s.size()) // make sure don't skip any element
	{
		string subOld = s.substr(index, sizeOld);
		if(subOld == oldVal)
		{
			s.replace(index, sizeOld, newVal);
			index += sizeNew;
		}
		else
			++index;
	}
	return s;
}
int main()
{
	string s = "I came thru the way. thru thru thru";
	cout << s << endl;
	changeSubstr(s, "t", "th");
	cout << s << endl;
	return 0;
}