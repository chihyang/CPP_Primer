#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
bool isLongWord(const string& str)
{
	return str.size() >= 5;
}
int main()
{
	vector<string> words = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
	auto longer_words = partition(words.begin(), words.end(), isLongWord);
	for(auto iter = words.begin(); iter != longer_words; ++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}