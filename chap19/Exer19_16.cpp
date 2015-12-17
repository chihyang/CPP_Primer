#include <iostream>
#include "Sales_data.h"
using std::cout;
using std::endl;
void debug_test(const Sales_data &item)
{
	Sales_data::Avg price = &Sales_data::avg_price;
	cout << (item.*price)() << endl;
}
int main()
{
	Sales_data item1("978-7-121-20038-0", 12, 128.0), item2("978-7-121-20038-0", 10, 98.0);
	debug_test(item1 + item2);
	return 0;
}