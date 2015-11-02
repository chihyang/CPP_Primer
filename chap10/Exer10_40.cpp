// Warning: this is for verification. It compiles and has no error but can't perform what's intended.
// The problem is that flst is not sorted.
#include <iostream>
#include <forward_list>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::forward_list;
using std::ostream_iterator;
int main()
{
	forward_list<int> flst = { 0, 1, 2, 2, 7, 5, 6, 2, 7, 9 };
	// warning: unique only requires forward iterator because it only applies to 
	// SORTED sequences. If a forward_list is not sorted, unique cannot correctly
	// perform what we intend(see results below). Because we cannot use sort on a 
	// forward list, we can't use unique on an unsorted forward list.
	unique(flst.begin(), flst.end());
	ostream_iterator<int> os(cout, " ");
	copy(flst.cbegin(), flst.cend(), os);
	cout << endl;
	return 0;
}
// ******Result compiled by cl******
// 0 1 2 7 5 6 2 7 9 9

// ******Result compiled by G++******
// 0 1 2 7 5 6 2 7 9 9