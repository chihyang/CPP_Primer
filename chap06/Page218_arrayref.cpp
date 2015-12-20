// Warning: This is for verification. It CANNOT be compiled successfully by both compilers.
// The problems lie in line 16, 17 and 19.
#include <iostream>
using std::cout;
using std::endl;
void print(int (&arr)[10])
{
	for(auto elem : arr)
		cout << elem << endl;
}
int main()
{
	int i = 0, j[2] = {0, 1};
	int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p = k;
	print(&i); // error: &i is not an array of ten 10 ints
	print(j); // error: j is an array of 2 ints
	print(k); // ok
	print(p); // error: this is equivalent of line 16
	return 0;
}