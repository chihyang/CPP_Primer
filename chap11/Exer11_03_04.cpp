#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <cctype>
#include <map>
#include <set>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::size_t;
using std::map;
using std::set;
int main(int argc, char *argv[])
{
	if(argc != 2)
		return -1;
	ifstream is(argv[1]);
	map<string, size_t> word_count; // empty map from string to size_t
	string word;
	while(is >> word)
	{
		for(auto &c : word)
			c = tolower(c); // convert all words to upper case
		++word_count[word];
	}
	for(const auto &w : word_count)
		// print the result
		cout << w.first << " occurs " << w.second
	         << ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}