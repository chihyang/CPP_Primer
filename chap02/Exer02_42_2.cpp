// Rewrite of Exer1.21
#include <iostream>
#include "Sales_data.h"
int main()
{
    Sales_data book1, book2;
    double price1 = 0, price2 = 0;
    std::cin >> book1.bookNo >> book1.units_sold >> price1;
    std::cin >> book1.bookNo >> book1.units_sold >> price2;
    book1.revenue = price1 * book1.units_sold;
    book2.revenue = price2 * book2.units_sold;
    if(book1.bookNo == book2.bookNo)
        std::cout << book1.bookNo << " "
                  <<book1.units_sold + book2.units_sold << " "
                  << book1.revenue + book2.revenue << std::endl;
    else
    {
        std::cerr << "Two items have different isbn!" << std::endl;
        return -1;
    }
    return 0;
}
