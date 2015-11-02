#include <iostream>
#include <iterator>
#include "Sales_item.h"
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
int main()
{
	istream_iterator<Sales_item> item_iter(cin), eof;
	ostream_iterator<Sales_item> out_iter(cout, "\n");
	Sales_item sum = *item_iter++;
	while(item_iter != eof)
	{
		if(item_iter->isbn() == sum.isbn())
			sum += *item_iter++;
		else{
			out_iter = sum;
			sum = *item_iter;
		}
	}
	out_iter = sum;
	return 0;
}