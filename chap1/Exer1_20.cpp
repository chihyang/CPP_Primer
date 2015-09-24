#include <iostream>
int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1, v2;
	int sum = 0;
	std::cin >> v1 >> v2;
	//if you don't compare v1 and v2, result may be wrong.
	for(int i = v1; i <= v2; i++)
	{
		sum += i;
	}
	std::cout << sum << std::endl;
	
	return 0;
}