#include <iostream>
#include <forward_list>
#include <string>
using std::cout;
using std::endl;
using std::forward_list;
using std::string;
forward_list<string>::iterator insert_word(forward_list<string>& flst, const string& str1, const string& str2)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while(curr != flst.end())
	{
		if(*curr == str1)
		{
			curr = flst.insert_after(curr, str2);
			return curr;
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	curr = flst.insert_after(prev, str2);
	return curr;
}
int main()
{
	forward_list<string> flst = { "The", "wrinkled", "sea", "beneath", "him", "crawls;\n", 
	                              "He", "from", "his", "mountain", "walls,\n",
	                              "And", "like", "a", "thunderbolt", "he", "falls.\n" };
	string word1 = "He", word2 = "watches";
	insert_word(flst, word1, word2);
	for(const auto &s : flst)
		cout << s << " ";
	cout << endl;
	return 0;
}