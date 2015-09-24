#include <iostream>
int main()
{
	int lower,upper;
	int v1, v2;
	std::cout << "Input two numbers:" << std::endl;
	std::cin >> v1 >> v2;
	if(v1 <= v2)
	{
		lower = v1;
		upper = v2;
	}
	else
	{
		lower = v2; 
		upper = v1;
	}
	for(int i = lower; i <= upper; i++)
	{   
		std::cout << i << " ";
		if((i - lower) % 10 == 9)
			std::cout << std::endl;
	}
	return 0;
}