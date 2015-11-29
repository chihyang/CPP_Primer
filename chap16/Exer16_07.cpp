#include <iostream>
#include "Exer16_05.h"
#include "Exer16_07.h"
using std::cout;
using std::endl;
int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const char *str[] = {"Never", "mind", "I", "will", "find", "someone", "like", "you"};
	cout << size(arr) << endl;
	print(arr);
	cout << size(str) << endl;
	print(str);
	return 0;
}