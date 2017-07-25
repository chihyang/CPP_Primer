#include <iostream>
#include "Sales_item.h"
int main()
{
	Sales_item book;
	Sales_item bookSum;
	while(std::cin >> book)
	{
		bookSum = bookSum + book;
	}

	std::cout << bookSum << std::endl;
	return 0;
}
