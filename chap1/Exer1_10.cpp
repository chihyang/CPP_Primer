#include <iostream>
int main()
{
	int sum1 = 0, sum2 = 0;
	for(int i = 50; i <= 100; i++)
	{
		sum1 += i;
	}
	
	int j = 50;
	while(j <= 100)
	{
		sum2 += j;
		j++;
	}
	std::cout << "The sum of 50 to 100 is:" << sum1 << "," << sum2 << std::endl;
}