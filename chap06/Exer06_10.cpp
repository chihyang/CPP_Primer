#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void swap(int *pa, int *pb)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << "Before swap: " << a << " " << b << endl;
	swap(&a, &b);
	cout << "After swap: " << a << " " << b << endl;
	return 0;
}