// Warning: this is for illustration. Template declarations and definitions should be put into header files.
// Warning: this program cannot compile. The problem lies in line 12.
#include <vector>
using std::vector;
template <typename T>
void g(T&& val)
{ vector<T> v; }
int main()
{
	int i = 42;
	g(42); // ok: T is int; val is int&; define a vector of int
	g(i);  // error: T is int&; val is int&&; cannot define a vector of reference
	return 0;
}