// Warning: this is for verification. It has runtime error.
#include <iostream>
int main()
{
	int *p;
	try {
		int i = 12;
		int *p = new int(12);
		throw i; // ok: we can throw i just as we can return a local object
	} catch (int e) {
		if(e == 12) {
			std::cerr << "throw can raise expression of any type" << std::endl;
			// although the memory p points to is not freed, we can not 
			// access to it any more, because it's out of scope, not because it's
			// freed, see section 12.1.4, page 467.
			std::cout << *p << std::endl;
			// cannot delete p again, because the resource it points to has been
			// freed
			delete p;
		}
	}
	return 0;
}
