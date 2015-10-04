#include <iostream>
using std::cout;
using std::endl;
int main()
{	
	int ia[3][4] = {{0, 1, 2, 3},
		            {4, 5, 6, 7},
			        {8, 9, 10, 11}};
	// range for
	for(auto &p : ia)
	{
		for(auto &q : p)
			cout << q << ' ';
		cout << endl;
	}
	cout << endl;
	// for with pointer
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 4; ++j)
			cout << ia[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	// for with pointer
	for(auto p = ia; p != ia + 3; ++p)
	{
		for(auto q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	return 0;
}