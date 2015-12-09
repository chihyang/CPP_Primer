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
	string phone = "(\\()?(\\d{3})(\\))?(-|.| +)?(\\d{3})(-|.| +)?(\\d{4})";
	string space = " +";
	regex r(phone);
	regex rs(space);
	smatch m;
	if(regex_match(s, m, r))
	{
		// if there is an open parenthesis before the area code
		if(m[1].matched)
			// the area code must be followed by a close parenthesis
			// and followed immediately by the rest of the number or a space
			return m[3].matched &&
				   (m[4].matched == 0 || regex_match(m[4].str(), rs));
		else
			// then there can't be a close after the aera code
			// the delimiters between the other two components must match
			return !m[3].matched &&
			       regex_match(m[4].str(), rs) &&
			       regex_match(m[6].str(), rs);
	}
	else
		return false;
}
int main()
{
	string s;
	while(getline(cin, s))
	{
		if(valid(s))
			cout << "valid: " << s << endl;
		else
			cout << "invalid: " << s << endl;
	}
	return 0;
}