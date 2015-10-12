#include <iostream>
using std::cout;
using std::endl;
void swap(int* &a, int* &b)
{
	int *tmp = a;
	a = b;
	b = tmp;
	tmp = 0;
}
int main()
{
	int i = 3, j = 8;
	int *pi = &i, *pj = &j;
	cout << "Before swap: ";
	cout << *pi << " " << *pj << endl;
	swap(pi, pj);
	cout << "After swap: ";
	cout << *pi << " " << *pj << endl;
	return 0;
}