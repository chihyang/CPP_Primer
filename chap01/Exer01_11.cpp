#include <iostream>

int main()
{
	int i1, i2, upper, lower;
	std::cout << "Input two numbers separated by space:" << std::endl;
	std::cin >> i1 >> i2;
	if(i1 < i2)
	{
		lower = i1;
		upper = i2;
	}
	else
	{
		upper = i1;
		lower = i2;
	}
	//if you don't compare v1 and v2, result may be wrong.
	// while loop
	int iwhile = lower;
	while(iwhile <= upper)
	{
		std::cout << iwhile << std::endl;
		++iwhile;
	}
	return 0;
}