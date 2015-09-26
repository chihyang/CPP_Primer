#include <iostream>
int main()
{	
	int sum1 = 0, sum2 = 0;
	// while loop
	int j = 50;
	while(j <= 100)
	{
		sum1 += j;
		j++;
	}
	std::cout << "The sum of 50 to 100 is:" << sum1 << "," << sum2 << std::endl;
	return 0;
}