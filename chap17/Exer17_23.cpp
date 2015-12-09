#include <iostream>
#include <string>
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::regex_match;
bool valid(const string& s)
{
	string zipcode = "(\\d{5})(-)?(\\d{4})?";
	regex r(zipcode);
	smatch m;
	if(regex_match(s, m, r)) {
		if(m[2].matched)
			// if there is a dash, then there must be 4 remaining digits
			return m[3].matched;
		else
			return true;
	}
	else
		return false;
}
int main()
{
	string s;
	while (cin >> s) {
		if(valid(s))
			cout << "valid: " << s << endl;
		else
			cout << "invalid: " << s << endl;
	}
	return 0;
}