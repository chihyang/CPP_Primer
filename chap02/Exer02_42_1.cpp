// Rewrite of Exer1.20
#include <iostream>
#include "Sales_data.h"
int main()
{
	Sales_data book;
	double price = 0;
	while(std::cin >> book.bookNo >> book.units_sold >> price)
	{
		book.revenue = price * book.units_sold;
		std::cout << book.bookNo << " "
		          << book.units_sold << " " 
		          << book.revenue << std::endl;
	}
	
	return 0;
}