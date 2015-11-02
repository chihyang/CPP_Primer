#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
int main()
{
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vec(in_iter, eof);
	// we cannot use sort for istream_iterator, so we have to store it at first
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), out_iter);
	cout << endl;
	return 0;
}