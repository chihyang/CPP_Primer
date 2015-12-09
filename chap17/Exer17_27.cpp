#include <cctype>
#include <iostream>
#include <string>
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
int main()
{
	string zipcode = "(\\d{5})(-)?(\\d{4})?";
	regex r(zipcode);
	smatch m;
	string s;
	string fmt = "$1-$3 ";
	while (cin >> s) {
		if (regex_match(s, m, r)) {
			if (m[3].matched)
				cout << "valid: " << m.format(fmt) << endl;
			else
				cout << "valid: " << m.str() << endl;
		}
		else
			cout << "invalid zip code: " << s << endl;
	}
	return 0;
}