// Warning: This is for illustration. It has an potential error.
// The problems lie in line 21, 22.
#include <deque>
#include <forward_list>
#include <list>
#include <string>
#include <vector>
using std::string;
using std::deque;
using std::forward_list;
using std::list;
using std::string;
using std::vector;
int main()
{
	list<string> authors = {"Milton", "Shakespeare", "Austen"};
	vector<const char*> articles = {"a", "an", "the"};
	// with one container to initialize another it is okay
	list<string> list2(authors);
	// container type and element type must match
	deque<string> authList(authors); // error: container type doesn't match
	vector<string> words(articles); // error: element type doesn't match
	// element type conversion is okay
	forward_list<string> words(articles.begin(), articles.end());
	return 0;
}