#include <iostream>
#include <vector>
#include <algorithm>
#include "Sales_Data.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2)
{
	return sd1.isbn() < sd2.isbn();
}
int main()
{
	vector<Sales_data> sales_item;
	Sales_data item;
	while(read(cin, item))
	{
		sales_item.push_back(item);
	}
	sort(sales_item.begin(), sales_item.end(), compareIsbn);
	for(const auto &s : sales_item)
	{
		print(cout, s) << endl;
	}
	return 0;
}