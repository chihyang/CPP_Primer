// Note: this program uses ./data/person_info.
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::regex;
using std::smatch;
using std::regex_constants::format_first_only;
int main(int argc, char* argv[])
{
    if (argc != 2)
        return -1;
    ifstream is(argv[1]);
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone); // a regex to find our pattern
    smatch m;
    string s;
    string fmt = "$2.$5.$7"; // reformat numbers to ddd.ddd.dddd
    // read each record from the input file, write the first match only
    while (getline(is, s))
        cout << regex_replace(s, r, fmt, format_first_only) << endl;
    return 0;
}
