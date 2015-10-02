#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int a1[0];
	int a2[0]; // Be sure the program doesn't crash under any circumstance.
	int a1len = sizeof(a1) / sizeof(int);
	int a2len = sizeof(a2) / sizeof(int);
	cout << a1len << " " << a2len << endl;
	if(a1len == a2len)
	{
		for(int i = 0; i < a1len; ++i)
		{
			cout << a1[i] << " " << a2[i] << endl;
			if(a1[i] != a2[i])
			{
				cout << "a1 and a2 are NOT equal!" << endl;
				return -1;
			}
		}
		cout << "a1 and a2 are equal!" << endl;
	}
	else 
	{
		cout << "a1 and a2 are NOT equal!" << endl;
		return -1;
	}
	return 0;
}