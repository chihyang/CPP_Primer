#include <iostream>
#include <string>
#include <forward_list>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::forward_list;
using std::list;
void elimDups(forward_list<string> &words)
{
	words.sort();
	words.unique();
}
void elimDups(list<string> &words)
{
	words.sort();
	words.unique();
}
int main()
{
	forward_list<string> flst = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
	list<string> lst = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
	elimDups(flst);
	elimDups(lst);
	for_each(flst.cbegin(), flst.cend(), [](const string &str){cout << str << " ";});
	cout << endl;
	for_each(lst.cbegin(), lst.cend(), [](const string &str){cout << str << " ";});
	cout << endl;
	return 0;
}