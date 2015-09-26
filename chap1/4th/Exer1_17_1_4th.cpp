#include <iostream>
int main()
{
	std::cout << "Enter some integers separated by white space," << std::endl
			<< "and end inputting by pressing enter:" << std::endl;
	int total = 0;
	int val;
	while(std::cin >> val)//In this way, only when meeting end-of-line(ctrl+Z in Windows) does the loop exit
	{
		if(val < 0)
			total += 1;
	}
	std::cout << "Total number of negative is: " << total << std::endl;
	return 0;
}