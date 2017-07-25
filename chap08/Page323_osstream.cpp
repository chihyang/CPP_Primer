#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::vector;
struct PersonInfo {
    string name;
    vector<string> phones;
};
bool valid(const string& s)
{
    int size = 0;
    for(auto &c : s)
    {
        if(!isdigit(c) && c != ' ' && c != '-')
            return false;
        if(isdigit(c))
            ++size;
    }
    if(size == 11 || size == 12 || size == 8)
        return true;
    else
        return false;
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
int main()
{

    string line, word; // will hold a line and word from input, respectively
    vector<PersonInfo> people; // will hold all the records from the input
    istringstream record; // move istringstream here
    ostringstream os;
    // read the input a line at a time until cin hits end-of-file(or another error)
    while(getline(cin, line))
    {
        PersonInfo info; // create an object to hold this record's data
        record.clear(); // WARNING: without this, we can only read one record, because after the first
        // iteration, fail and eofbit will be set
        record.str(line); // copy a line we just read to record
        if(record.eof())
            cout << "record eof" << endl;
        if(record.fail())
            cout << "record fail" << endl;
        record >> info.name; // read the name
        while(record >> word) // read the phone numbers
            info.phones.push_back(word); // and store them
        people.push_back(info); // append this record to people
    }
    for(const auto &entry : people)
    {
        os.clear();
        ostringstream formatted, badNums;
        for(const auto &nums : entry.phones)
        {
            if(!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if(badNums.str().empty())
        {
            os << entry.name << " " << formatted.str() << endl;
            cout << os.str();
        }
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s)" << badNums.str() << endl;
    }
    return 0;
}
