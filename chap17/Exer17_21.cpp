// Note: this program uses ./data/person_info.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;
using std::regex;
using std::smatch;
using std::sregex_iterator;
struct PersonInfo {
    string name;
    vector<string> phones;
};
bool valid(const smatch& m)
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
string format(const string& s)
{
    string num;
    for(auto ch : s)
    {
        if(isdigit(ch))
            num += ch;
    }
    return num;
}
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cerr << "Wrong Input!" << endl;
        return -1;
    }
    ifstream input(argv[1]);
    string line, word; // will hold a line and word from input, respectively
    vector<PersonInfo> people; // will hold all the records from the input
    ostringstream os;
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    regex r(phone);
    // read the input a line at a time until cin hits end-of-file(or another error)
    while(getline(input, line))
    {
        istringstream record; // move istringstream here
        PersonInfo info; // create an object to hold this record's data
        record.str(line); // copy a line we just read to record
        record >> info.name; // read the name
        ostringstream formatted, badNums;
        while(getline(record, word)) { // read the phone numbers
            for(sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it;
                ++it) {
                if(!valid(*it)){
                    badNums << " " << it->str();
                } else {
                    formatted << " " << format(it->str());
                    info.phones.push_back(it->str()); // and store them
                }
            }
            if(!badNums.str().empty())
                cerr << "input error: " << info.name << " "
                     << " invalid number(s)" << badNums.str() << endl;
        }
        cout << info.name << ": " << formatted.str() << endl;
        people.push_back(info); // append this record to people
    }
    return 0;
}
