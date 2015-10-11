#include <iostream>
#include <cstddef>
using std::cout;
using std::cin;
using std::endl;
size_t countCalls()
{
	static size_t callCtr = 0;
	return callCtr++;
}
int main()
{
	for(int i = 0; i < 36; ++i)
		cout << countCalls() << endl;
	return 0;
}