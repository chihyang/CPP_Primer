#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
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
	// count the number of times each word occurs in the input
	map<string, size_t> word_count; // empty map from string to size_t
	set<string> exclude = { "The", "But", "And", "Or", "An", "A",
	                        "the", "but", "and", "or", "an", "a" };
	string word;
	while(is >> word)
	{
		// count only words that are not in exclude
		if(exclude.find(word) == exclude.end())
			++word_count[word]; // fetch and increment the counter for word
	}
	for(const auto &w : word_count) // for each element in the map
		// print the result
		cout << w.first << " occurs " << w.second
	         << ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}