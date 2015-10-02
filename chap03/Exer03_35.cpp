#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	constexpr size_t sz = 5;
	int a[sz] = {2, 3, 5, 7, 9};
	int *p = a;
	for(int i = 0; i < sz; ++i)
		p[i] = 0;
	for(int j = 0; j < sz; ++j)
		cout << p[j] << " ";
	cout << endl;
	return 0;
}