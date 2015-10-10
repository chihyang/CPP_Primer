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
		try{
			if(i2 == 0)
				throw runtime_error("Divider mustn't be zero!");
			cout << i1 / i2 << endl;
		}
		// with a catch, the program could move on peacefully.
		catch(runtime_error err){
			cout << err.what() << "\nEnter another divider:" << endl;
			cin >> i2;
			cout << i1 / i2 << endl;
		}
	}
	return 0;
}