#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Exer15_41_42_TextQuery.h"
#include "Exer15_41_42_Query.h"
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::out_of_range;
// check if the input is a word or a number representing an entry in query his
inline bool is_cmd(const string&);
Query get_query(vector<Query>::const_reverse_iterator, vector<Query>::const_reverse_iterator, const string&);
int main(int argc, char* argv[])
{
	if(argc != 2)
		return -1;
	ifstream is(argv[1]);
	TextQuery tq(is);
	cout << "Input 3 words or input q to quit:" << endl;
	string opt;
	vector<Query> his;
	while(getline(cin, opt) && opt != "q")
	{
		string sought1, sought2, sought3;
		istringstream istr(opt);
		istr >> sought1 >> sought2 >> sought3;
		try{
			Query q = get_query(his.crbegin(), his.crend(), sought1) &
					  get_query(his.crbegin(), his.crend(), sought2) | 
					  get_query(his.crbegin(), his.crend(), sought3);
			his.push_back(q);
			QueryResult qr = q.eval(tq);
			TextQuery::line_no min, max;
			cout << "Input two numbers of range between 1 and " << qr.get_file()->size() << "\n";
			while(cin >> min >> max)
			{
				cout << "Executing Query for: " << q << "\n";
				print(cout, qr, min, max);
			}
		} catch(out_of_range err) {
			err.what();
		}
		cin.clear();
		cout << "Input 3 words or $ followed by a number representing the query history, or input q to quit:\n";
	}
	return 0;
}
inline bool is_cmd(const string &s)
{
	bool cmd = false;
	if(s.size() > 1 && s[0] == '$') {
		auto illegal_pos = s.substr(1).find_first_not_of("0123456789");
		cmd = (illegal_pos == string::npos);
	}
	return cmd;
}
Query get_query(vector<Query>::const_reverse_iterator beg, vector<Query>::const_reverse_iterator end, const string &s)
{
	if(is_cmd(s)) {
		auto index = stoul(s.substr(1)) - 1;
		if(index < (end - beg))
			return *(beg + index);
		else
			throw out_of_range("index out of range!");
	}
	else
		return Query(s);
}