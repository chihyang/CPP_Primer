// Page 13, exercise 11
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int i1, i2, upper, lower;
	cout << "Input two numbers separated by space:" << endl;
	cin >> i1 >> i2;
	if(i1 < i2)
	{
		lower = i1;
		upper = i2;
	}
	else
	{
		upper = i1;
		lower = i2;
	}
	// if you don't compare v1 and v2, result may be wrong.
	// while loop
	int iwhile = lower;
	while(iwhile <= upper)
	{
		cout << iwhile << endl;
		++iwhile;
	}
	return 0;
}