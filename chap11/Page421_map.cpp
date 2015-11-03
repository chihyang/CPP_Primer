#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <map>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::size_t;
using std::map;
int main(int argc, char *argv[])
{
	if(argc != 2)
		return -1;
	ifstream is(argv[1]);
	// count the number of times each word occurs in the input
	map<string, size_t> word_count; // empty map from string to size_t
	string word;
	while(is >> word)
		++word_count[word]; // fetch and increment the counter for word
	for(const auto &w : word_count) // for each element in the map
		// print the result
		cout << w.first << " occurs " << w.second
	         << ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}