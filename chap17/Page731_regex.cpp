#include <iostream>
#include <string>
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::regex_search;
int main()
{
	// one or more alphanumeric characters followed by a '.' followed by "cpp" or "cxx" or "cc"
	regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase); // case independent
	smatch results;
	string filename;
	while (cin >> filename)
		if (regex_search(filename, results, r))
			cout << results.str() << endl; // print the current match
	return 0;
}
