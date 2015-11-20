#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
class InRange {
public:
	InRange(string::size_type d, string::size_type u) : down(d), up(u) {}
	bool operator()(const string& s) const 
	    { return s.size() >= down && s.size() <= up; }
private:
	string::size_type down;
	string::size_type up;
};
int main(int argc, char* argv[])
{
	if(argc != 2)
		return -1;
	ifstream file(argv[1]);
	string word;
	vector<string> text;
	while(file >> word)
		text.push_back(word);
	auto cnt = count_if(text.cbegin(), text.cend(), InRange(1, 10));
	cout << "There are " << cnt << " words whose length between 1 and 10 inclusive" << endl;
	return 0;
}