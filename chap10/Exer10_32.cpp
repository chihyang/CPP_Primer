// Note: this file uses a changed version of Sales_item.h, don't use it anywhere else.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Sales_item_Exer10_32.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
int main()
{
	istream_iterator<Sales_item> is_iter(cin), eof;
	ostream_iterator<Sales_item> os_iter(cout, "\n");
	vector<Sales_item> vec_item(is_iter, eof);
	vector<Sales_item> vec_sum;
	sort(vec_item.begin(), vec_item.end(), compareIsbn);
	auto beg = vec_item.begin();
	while(beg != vec_item.end())
	{
		auto same_item = beg, trans_item = beg;
		while(trans_item != vec_item.end())
		{
			same_item = trans_item;
			trans_item = find(++trans_item, vec_item.end(), *beg);
		}
		vec_sum.push_back(accumulate(beg, ++same_item, Sales_item(beg->isbn())));
		beg = same_item;
	}
	cout << "Sorted items: " << endl;
	for(const auto &si : vec_item)
		os_iter = si;
	cout << "Sum of each book: " << endl;
	for(const auto &si : vec_sum)
		os_iter = si;
	return 0;
}
// ******First Modification******
// compareIsbn(), see header Sales_item.h, but == is substituted with <.
// substituting == because we want to really sort by isbn.
// ******Second Modification******
// Overloading operator ==, see header Sales_item.h, line 86 and 87 are commented.
// Changing the implementation of overloading operator == because the exercise
// requires us to use find. If we use find_if rather than find, we needn't
// change the implementation.