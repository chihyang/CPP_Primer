#include <iostream>
#include "Exer15_15_Quote.h"
#include "Exer15_15_Bulk_quote.h"
#include "Exer15_16_Limit_quote.h"
using std::cout;
int main()
{
	Quote item1("978-7-121-20038-0", 128.0);
	Bulk_quote item2("978-7-121-20038-0", 128.0, 6, 0.05);
	Limit_quote item3("978-7-121-20038-0", 128.0, 2, 0.15);
	print_total(cout, item1, 10); // calls Quote::net_price
	print_total(cout, item2, 10); // calls Bulk_quote::net_price
	print_total(cout, item3, 1); // calls Limit_quote::net_price
	print_total(cout, item1, 5); // calls Quote::net_price
	print_total(cout, item2, 5); // calls Bulk_quote::net_price
	print_total(cout, item3, 5); // calls Limit_quote::net_price
	return 0;
}