#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::multimap;
using std::pair;
int main(int argc, char *argv[])
{
	if(argc != 2 && argc != 1)
		return -1;
	ifstream is(argv[1]);
	multimap<string, string> authors;
	string aut, works;
	while(getline(is, aut))
	{
		getline(is, works);
		authors.insert({aut, works});
	}
	auto beg = authors.begin();
	while(beg != authors.end())
	{
		// to sort works by alphabetically, we have to find out a way to sort works
		auto author_works = authors.equal_range(beg->first);
		vector<pair<string, string>> vec(author_works.first, author_works.second);
		sort(vec.begin(), vec.end(), 
		[](const pair<string, string> &a1, const pair<string, string> &a2) { return a1.second < a2.second; });
		for(const auto &p : vec)
			cout << p.first << " " << p.second << "\n";
		beg = author_works.second;
	}
	cout << endl;
	return 0;
}