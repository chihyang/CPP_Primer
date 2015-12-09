#include <iostream>
#include <string>
#include <regex>
using std::cout;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::regex_error;
int main()
{
	// [] mismatch
	try {
		regex r("[[:alnum]+\\.(cpp|cxx|cc)$", regex::icase);
	} catch (regex_error e)
	{ cout << e.what() << "\ncode: " << e.code() << endl; }
	// () mismatch
	try {
		regex r("[[:alnum]]+\\.cpp|cxx|cc)$", regex::icase);
	} catch (regex_error e)
	{ cout << e.what() << "\ncode: " << e.code() << endl; }
	// {} mismatch
	try {
		regex r("[[:alnum]]{1-2\\.(cpp|cxx|cc)$", regex::icase);
	} catch (regex_error e)
	{ cout << e.what() << "\ncode: " << e.code() << endl; }
	// repetition character not preceded by a valid RE
	try {
		regex r("+\\.(cpp|cxx|cc)$", regex::icase);
	} catch (regex_error e)
	{ cout << e.what() << "\ncode: " << e.code() << endl; }
	// invalid range in {}
	try {
		regex r("[[:alnum]]{a-x}+\\.(cpp|cxx|cc)$", regex::icase);
	} catch (regex_error e)
	{ cout << e.what() << "\ncode: " << e.code() << endl; }
	// invalid character range
	try {
		regex r("[z-a]+\\.(cpp|cxx|cc)$", regex::icase);
	} catch (regex_error e)
	{ cout << e.what() << "\ncode: " << e.code() << endl; }
	return 0;
}
// ******result of clang++ and g++******
// regex_error
// code: 1
// regex_error
// code: 1
// regex_error
// code: 1
// regex_error
// code: 5
// regex_error
// code: 1
// regex_error
// code: 8

// ******result of cl******
// regex_error(error_ctype): The expression contained an invalid character class 
// name.
// code: 1
// regex_error(error_ctype): The expression contained an invalid character class
// name.
// code: 1
// regex_error(error_ctype): The expression contained an invalid character class 
// name.
// code: 1
// regex_error(error_badrepeat): One of *?+{ was not preceded by a valid regular 
// expression.
// code: 10
// regex_error(error_ctype): The expression contained an invalid character class 
// name.
// code: 1
// regex_error(error_range): The expression contained an invalid character range, 
// such as [b-a] in most encodings.
// code: 8