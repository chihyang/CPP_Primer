#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	using int_array = int[4];
	typedef int int_array[4];
	int_array ia[3] = {0};
	// ia is an array of 3 elements, every of which is an array 4 ints.           
	for(int_array *p = ia; p != ia + 3; ++p)
	{
		for(int *q = *p; q != *p + 4; ++q)
			cout << *q << ' ';
		cout << endl;
	}
	return 0;
}