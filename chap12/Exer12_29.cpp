#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::set;
vector<string>::size_type query(ifstream &infile, const string &query_word)
{
	string str;
	vector<string> text;
	vector<string>::size_type occur_line = 0, cnt = 0;
	map<string, set<vector<string>::size_type>> word_line;
	while(getline(infile, str))
	{
		text.push_back(str);
		string word;
		istringstream istrm_line(str);
		while(istrm_line >> word)
			word_line[word].insert(occur_line);
		++occur_line;
	}
	auto find_rst = word_line.find(query_word);
	if(find_rst != word_line.end())
	{
		for(auto iter = find_rst->second.cbegin(); iter != find_rst->second.cend(); ++iter)
		{
			string output_line = text[*iter];
			istringstream is(output_line);
			vector<string> line_breakup;
			string out_word;
			while(is >> out_word)
				line_breakup.push_back(out_word);
			cnt += count(line_breakup.cbegin(), line_breakup.cend(), query_word);
			cout << "(line " << *iter << ") " << output_line << endl;
		}
	}
	return cnt;
}
int main(int argc, char* argv[])
{
	if(argc != 2 && argc != 3)
		return -1;
	do
	{
		ifstream in(argv[1]);
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q") 
			break;
		else
		{
			auto cnt = query(in, s);
			cout << "element occurs " << cnt << " times" << endl;
		}
	}while(true);
	return 0;
}