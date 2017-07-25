#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::istringstream;
using std::string;
using std::vector;
struct PersonInfo {
    string name;
    vector<string> phones;
};
int main()
{
    string line, word; // will hold a line and word from input, respectively
    vector<PersonInfo> people; // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-file(or another error)
    while(getline(cin, line))
    {
        PersonInfo info; // create an object to hold this record's data
        istringstream record(line); // bind record to the line we just read
        record >> info.name; // read the name
        while(record >> word) // read the phone numbers
            info.phones.push_back(word); // and store them
        people.push_back(info); // append this record to people
    }
    return 0;
}
