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
typedef pair<vector<Sales_data>::size_type,
             pair<vector<Sales_data>::const_iterator,
                  vector<Sales_data>::const_iterator>> matches;
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
			ret.push_back(make_pair(it - files.cbegin(),
			                        make_pair(found.first, found.second)));
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
			os << "store " <<store.first << " sales: "
			   << accumulate(store.second.first, store.second.second, Sales_data(s))
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