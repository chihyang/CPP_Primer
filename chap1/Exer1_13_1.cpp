#include <iostream>
int main()
{	
	int sum1 = 0, sum2 = 0;
	// for loop
	for(int i = 50; i <= 100; i++)
	{
		sum2 += i;
	}
	std::cout << "The sum of 50 to 100 is:" << sum1 << "," << sum2 << std::endl;
	return 0;
}