#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	for(const auto &s : words)
		cout << s << " ";
	cout << endl;
	words.erase(end_unique, words.end());
}
vector<string>::iterator elimDups(vector<string>::iterator beg, vector<string>::iterator end)
{
	sort(beg, end);
	auto end_unique = unique(beg, end);
	return end_unique;
}
int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cerr << "Wrong input argument." << endl;
		return -1;
	}
	ifstream is(argv[1]);
	string word;
	vector<string> text;
	while(is >> word)
	{
		text.push_back(word);
	}
	vector<string>::size_type part= text.size() > 50 ? 50 : text.size();
	for(auto iter = text.begin(); iter != text.begin() + part; ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;
	auto end_unique = elimDups(text.begin(), text.begin() + part);
	text.erase(end_unique, text.end());
	for(auto iter = text.begin(); iter != end_unique; ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;
	stable_sort(text.begin(), text.end(), isShorter);
	for(auto iter = text.begin(); iter != end_unique; ++iter)
		cout << *iter << " ";
	cout << "\n" << endl;
	return 0;
}