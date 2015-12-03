// Warning: this is for illustration. Template declarations and definitions should be put into header files.
#include <iostream>
using std::cout;
using std::endl;
template <typename T>
void g(T val) { val = 2; }
int main()
{
	int i = 0;
	const int ci = i;
	g(i);      // ok: T is int; val is int
	cout << i << endl;  // assignment to val doesn't affect i
	g(ci);     // ok: T is int(top level const is discarde); val is int;
	cout << ci << endl; // assignment to val doesn't affect i
	g(i * ci); // ok: T is int; val is T
	cout << i << endl;  // assignment to val affect change i
	return 0;
}