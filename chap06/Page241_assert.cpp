#include <iostream>
#include <cassert>
#include <string>
using std::cin;
using std::string;
int main()
{
	string::size_type threshold = 5;
	string word;
	while(cin >> word)
	{
		// a dreadful "Your program has stopped working" pops up if you input a
		// string shorter than 5
		assert(word.size() > threshold);
	}
	return 0;
}