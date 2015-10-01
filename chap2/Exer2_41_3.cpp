// Rewrite of Exer1.22
#include <iostream>
struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
int main()
{
	Sales_data book, total;
	double price = 0;
	if(std::cin >> total.bookNo >> total.units_sold >> price)
	{
		total.revenue = price * total.units_sold;
		while(std::cin >> book.bookNo >> book.units_sold >> price){
			book.revenue = price * book.units_sold;
			if(book.bookNo == total.bookNo)
			{
				total.units_sold += book.units_sold;
				total.revenue += book.revenue; 
			}
			else{
				std::cerr << "Not the same book!" << std::endl;
				break;
			}
		}
	}
	std::cout << total.bookNo << " "
              << total.units_sold << " "
			  << total.revenue << std::endl;
	return 0;
}