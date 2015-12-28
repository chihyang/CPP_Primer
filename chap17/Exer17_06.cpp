// Note: this program uses data in directory ./data/store0, ./data/store1 and ./data/store2.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include "Sales_data.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
// matches has three members: an index of a store and iterators into that store's vector
struct matches {
	// if uses size_type, the compiler would warn us, see notes below
	vector<Sales_data>::difference_type index;
	vector<Sales_data>::const_iterator begin;
	vector<Sales_data>::const_iterator end;
};
// compare ISBN from section 11.2.2, page 426
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
// files holds the transaction for every store
// findBook returns a vector with an entry for each store that sold the given book
vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret; // initially empty
	// for each store find the range of matching books, if any
	for(auto it = files.cbegin(); it != files.cend(); ++it) {
		// find the range of Sales_data that have the same ISBN
		// to use equal_range, the vector must be ordered
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if(found.first != found.second) // this store had sales
			// remember the index of this store and the matching range
			// aggregate class(section 7.7.7, page 298), could be initialized with a braced list 
			ret.push_back({it - files.cbegin(), found.first, found.second});
	}
	return ret; // empty if no matches found
}
void reportResults(istream &in, ostream &os, 
                   const vector<vector<Sales_data>> &files)
{
	string s; // book to look for
	while (in >> s) {
		auto trans = findBook(files, s); // stores that sold this book
		if (trans.empty()) {
			cout << s << " not found in any stores" << endl;
			continue; // get the next book to look for
		}
		for (const auto &store : trans) {
			os << "store " <<store.index << " sales: "
			   << accumulate(store.begin, store.end, Sales_data(s))
			   << endl;
		}
	}
}
// read from a data file and return a vector of Sales_data
vector<Sales_data> getData(ifstream &in)
{
	vector<Sales_data> ret; // initially empty
	string data;
	while (getline(in, data)) {
		istringstream is(data);
		string bookNo;
		unsigned sold;
		double price;
		is >> bookNo >> sold >> price;
		ret.push_back(Sales_data(bookNo, sold, price));
	}
	sort(ret.begin(), ret.end(), compareIsbn); // sort by ISBN
	return ret;
}
int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "no sales data offered!" << endl;
		return -1;
	}
	// read and store data
	vector<vector<Sales_data>> files;
	for (int i = 1; i != argc; ++i) {
		ifstream is(argv[i]);
		files.push_back(getData(is));
	}
	// find and display result
	reportResults(cin, cout, files);
	return 0;
}
// if we use vector<Sales_data>::size_type rather than difference_type
// ******compile info of g++******
// Exer17_06.cpp: In function 'std::vector<matches> findBook(const std::vector<std:
// :vector<Sales_data> >&, const string&)':
// Exer17_06.cpp:47:22: warning: narrowing conversion of '__gnu_cxx::operator-<cons
// t std::vector<Sales_data>*, std::vector<std::vector<Sales_data> > >(it, (& files
// )->std::vector<_Tp, _Alloc>::cbegin<std::vector<Sales_data>, std::allocator<std:
// :vector<Sales_data> > >())' from '__gnu_cxx::__normal_iterator<const std::vector
// <Sales_data>*, std::vector<std::vector<Sales_data> > >::difference_type {aka lon
// g long int}' to 'std::vector<Sales_data>::size_type {aka long long unsigned int}
// ' inside { } [-Wnarrowing]
//     ret.push_back({it - files.cbegin(), found.first, found.second});
//                       ^

// ******compiler info of clang******
// Exer17_06.cpp:47:19: error: non-constant-expression cannot be narrowed from type
// 
//       'typename __normal_iterator<const vector<Sales_data, allocator<Sales_data>
// 
//       > *, vector<vector<Sales_data, allocator<Sales_data> >,
//       allocator<vector<Sales_data, allocator<Sales_data> > > >
//       >::difference_type' (aka 'long long') to 'vector<Sales_data>::size_type'
//       (aka 'unsigned long long') in initializer list [-Wc++11-narrowing]
//                         ret.push_back({it - files.cbegin(), found.first...
//                                        ^~~~~~~~~~~~~~~~~~~
// Exer17_06.cpp:47:19: note: insert an explicit cast to silence this issue
//                         ret.push_back({it - files.cbegin(), found.first...
//                                        ^~~~~~~~~~~~~~~~~~~
//                                        static_cast<size_type>( )
// 1 error generated.

// ******compile info of cl******
// (compile passed)

// Note: it seems that gcc and clang checks more strictly on type conversion. Because
// size_type is unsigned, difference_type is signed, and compiler won't allow 
// list initialization if it leads to loss of information(section 2.2.1, page 43),
// gcc warned us, while clang refused to generate code directly.