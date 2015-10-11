#include <iostream>
using std::cout;
using std::endl;
int fact(int val)
{
	int ret = 1;
	while(val > 1)
		ret *= val--;
	return ret;
}
int main()
{
	int j = fact(12);
	cout << j << endl;
	return 0;
}