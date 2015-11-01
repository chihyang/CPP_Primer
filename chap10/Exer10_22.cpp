#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::size_t;
using namespace std::placeholders;
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}
bool check_size(const string &s, string::size_type sz)
{
	return s.size() > sz;
}
void biggies(const string &s, string::size_type sz, char c = ' ')
{
	if(s.size() > sz)
		cout << s << c;
}
vector<string>::size_type count_size(vector<string> &words, vector<string>::size_type sz)
{
	auto count = count_if(words.begin(), words.end(), 
	           bind(check_size, _1, sz));
	return count;
}
int main()
{
	vector<string> words = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
	string::size_type sz;
	while(cin >> sz)
	{
		auto cnt = count_size(words, sz);
		cout << cnt  << " " << make_plural(cnt, "word", "s") 
		     << " longer than " << sz << endl;
		for_each(words.begin(), words.end(), 
			bind(biggies, _1, sz, ' '));
		cout << endl;
	}
	return 0;
}