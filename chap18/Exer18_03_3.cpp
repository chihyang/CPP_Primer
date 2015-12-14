// Note: see the link below for further discussion:
// https://stackoverflow.com/questions/34258836/ways-to-avoid-memory-leak-when-exception-thrown
#include <fstream>
#include <vector>
#include <stdexcept>
using std::ifstream;
using std::vector;
using std::exception;
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	try {
		ifstream in("ints");
		throw exception();    // throw exception
	} catch (...) {
		delete[] p; // don't forget p points to an array
		throw;      // rethrow for further exception handling
	}
	delete[] p;
}
int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int *b = a, *e = a + 7;
	exercise(b, e);
	return 0;
}
// Way 3: catch-all and rethrow is a better way than that in Exer18_03_1.cpp,
// although this way we have to use two delete for one resource, and we have to
// carefully handle every dynamic allocated resource. If we cannot use smart 
// pointer, this is a somewhat available way.