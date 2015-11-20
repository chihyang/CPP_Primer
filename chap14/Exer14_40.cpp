#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::size_t;
class CompareSize {
public:
	bool operator()(const string &s1, const string &s2) const { return s1.size() < s2.size(); }
};
class IsLonger {
	// Note: members that define types must appear before they are used(on page 272)
	using size_type = vector<string>::size_type;
public:
	IsLonger(size_type sz) : size(sz) {}
	bool operator()(const string &s) const { return s.size() >= size; }
private:
	size_type size;
};
class OutputStr {
public:
	void operator()(const string &s) const { cout << s << " "; }
};
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}
void elimDup(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}
void biggie(vector<string> &words, vector<string>::size_type sz)
{
	// put words in alphabetical order and remove duplicate
	elimDup(words);
	// sort words by size, but maintain alphabetical order for words of the same size
	stable_sort(words.begin(), words.end(), CompareSize());
	// get an iterator to the first element whose size() is >= sz
	auto wc = find_if(words.begin(), words.end(), IsLonger(sz));
	// compute the number of elements with size >= sz
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " 
	     << sz << " or longer" << endl;
	// put words of the given size or longer, each one followed by a space
	for_each(wc, words.end(), OutputStr());
	cout << endl;
}
int main()
{
	vector<string> words = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
	biggie(words, 3);
	return 0;
}