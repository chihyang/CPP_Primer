#include <iostream>
#include <string>
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
using std::sregex_iterator;
bool valid(const smatch&);
int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone); // a regex to find our pattern
    string s;
    while(getline(cin, s)) {
        // for each matching phone the input file
        for(sregex_iterator it(s.begin(), s.end(), r), end_it;
            it != end_it; ++it) {
            // check whether the number's formatting is valid
            if(valid(*it))
                cout << "valid: " << it->str() << endl;
            else
                cout << "invalid: " << it->str() << endl;
        }
    }
    return 0;
}
bool valid(const smatch &m)
{
    // if there is an open parenthesis before the area code
    if(m[1].matched)
        // the area code must be followed by a close parenthesis
        // and followed immediately by the rest of the number or a space
        return m[3].matched &&
               (m[4].matched == 0 || m[4].str() == " ");
    else
        // then there can't be a close after the aera code
        // the delimiters between the other two components must match
        return !m[3].matched &&
               m[4].str() == m[6].str();
}
