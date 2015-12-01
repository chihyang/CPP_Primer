#include <iostream>
#include <iterator>
#include "Exer16_06_begin_end.h"
using std::cout;
using std::endl;
int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const int(&arr_r)[11] = arr;
	for(auto p = begin(arr_r); p != end(arr_r); ++p)
	{
		cout << *p << " ";
	}
	cout << endl;
	return 0;
}