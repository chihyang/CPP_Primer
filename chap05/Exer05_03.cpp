#include <iostream>
int main()
{
	int sum = 0, val = 1;
	while(val <= 10)
		sum += val, ++val;
	std::cout << "sum of 1 to 10 inclusive is "
	          << sum << std::endl;
	return 0;
}
// Note: Substituting a comma expression for a block is okay. But if there are many 
// statements, a chain of comma expressions will make the program drastically
// unreadable. It'll perplex others and the programmer himself. If there's any 
// bug in one gigantic and long-winded expression, the programmer cannot locate
// the problem easily even if he uses a sophisticated debugger.