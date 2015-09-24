#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item bookSum;
	//detects: if two books with identical isbn aren't input continuously,
	//this program cannot find it.
	
	if(std::cin >> bookSum)
	{
		Sales_item book;
		while(std::cin >> book)
		{
			if(bookSum.isbn() == book.isbn())
				bookSum = bookSum + book;
			else
			{
				std::cout << bookSum << std::endl;
				bookSum = book;
			}
		}
		std::cout << bookSum << std::endl;
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
		// if(bookSum.ibsn() == book.ibsn())
			// bookSum = bookSum + book;
		// else
		// {
			// std::cout << bookSum << std::endl;
			// bookSum = book;
		// }
	}

	return 0;
}