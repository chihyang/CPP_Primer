#include <iostream>
int main()
{
	std::cout << "Enter some integers separated by white " << std::endl
			<< "space, and end inputting by pressing enter:" << std::endl;
	int total = 0;
	int val;
	do{
		std::cin >> val;
		if(val < 0)
			total += 1;
	}while(std::cin.get() != '\n');
	std::cout << "Total number of negative is: " << total << std::endl;
	return 0;
}