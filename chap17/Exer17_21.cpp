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
using std::regex_match;
struct PersonInfo {
	string name;
	vector<string> phones;
};
bool valid(const string& s)
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	smatch m;
	if(regex_match(s, m, r))
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
	istringstream record; // move istringstream here
	ostringstream os;
	// read the input a line at a time until cin hits end-of-file(or another error)
	while(getline(input, line))
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
		}
		else
			cerr << "input error: " << entry.name 
		         << " invalid number(s)" << badNums.str() << endl;
	}
	cout << os.str();
	return 0;
}