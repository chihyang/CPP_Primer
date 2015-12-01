#include <iostream>
#include <vector>
#include "Exer16_02_compare.h"
using std::cout;
using std::endl;
using std::vector;
int main()
{
	cout << compare(1, 0) << endl;
	vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
	cout << compare(vec1, vec2) << endl;
	return 0;
}