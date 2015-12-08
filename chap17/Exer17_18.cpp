// Note: this program uses dictionary file ./data/wordsEn.txt.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::regex;
using std::smatch;
using std::regex_search;
using std::sregex_iterator;
int main(int argc, char* argv[])
{
	if(argc != 2) {
		cerr << "no dictionary is offered!" << endl;
		return -1;
	}
	ifstream is(argv[1]);
	vector<string> dict;
	string word;
	while(is >> word)
		dict.push_back(word);
	string file("receipt freind theif receive neighbor albeit");
	// find the characters ei that follow a character other than c
	string pattern("[^c]ei");
	// we want the whole word in which our pattern appears
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase); // we'll ignore case in doing the match
	// it will repeatedly call regex_search to find all matches in filebuf
	for (sregex_iterator it(file.begin(), file.end(), r), end_it;
	    it != end_it; ++it) {
		if (!binary_search(dict.begin(), dict.end(), it->str())) {
			auto pos = it->prefix().length(); // size of prefix
			pos = (pos > 40) ? (pos - 40) : 0; // we want up to 40 characters
			cout << it->prefix().str().substr(pos) // last part of the prefix
		         << "\n\t\t>>> " << it->str() << " <<<\n" // matched word
			     << it->suffix().str().substr(0, 40) // first part of the suffix
			     << endl;
		}
	}
	return 0;
}
