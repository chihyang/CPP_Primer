// Warning: this is for verification. It cannot compile.
// The problems lie between line 11 and 18.
#include <string>
#include <memory>
using std::string;
using std::unique_ptr;
int main()
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	IntP p0(ix); // error: no constructor takes an int or compatible type
	IntP p1(pi); // error: must be a dynamically allocated pointer
	{
		// error: the object pi2 points to will be destroyed at the end of this scope, pi2 will be dangling
		IntP p2(pi2); 
		IntP p5(p2.get()); // error: no copy for unique_ptr
	}
	IntP p3(&ix); // error, ix is not a dynamically allocated object
	IntP p4(new int(2048)); // legal
	return 0;
}