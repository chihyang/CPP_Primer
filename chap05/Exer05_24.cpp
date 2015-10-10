#include <iostream>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;
int main()
{
	int i1, i2;
	while(cin >> i1 >> i2)
	{
		if(i2 == 0)
			throw runtime_error("Divider mustn't be zero!");
		cout << i1 / i2 << endl;
	}
	return 0;
}
// If there is no catch block, program just terminates with a dreadful tip 
// saying that "Your program has stopped working."