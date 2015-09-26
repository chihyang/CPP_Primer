#include <iostream>

int main()
{
	int i1, i2, upper, lower;
	std::cout << "Input two numbers separated by space:" << std::endl;
	std::cin >> i1 >> i2;
	//if you don't compare v1 and v2, result may be wrong.
	// for loop
	for(int i = lower; i <= upper; ++i)
		std::cout << i << std::endl;
	return 0;
}