#include <iostream>
#include "Exer15_27_Bulk_quote.h"
using std::cout;
int main()
{
	Bulk_quote item("978-7-121-20038-0", 128.0, 6, 0.05);
	print_total(cout, item, 10); // calls Bulk_quote::net_price
	return 0;
}