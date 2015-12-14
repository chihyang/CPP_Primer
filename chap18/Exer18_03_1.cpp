// Note: see the link below for further discussion:
// https://stackoverflow.com/questions/34258836/ways-to-avoid-memory-leak-when-exception-thrown
#include <fstream>
#include <vector>
using std::ifstream;
using std::vector;
void exercise(int *b, int *e)
{
	try {
		vector<int> v(b, e);
		int *p = new int[v.size()];
		ifstream in("ints");
		throw p;
	} catch (int *e) {
		delete[] e; // don't forget p points to an array
	}
}
int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int *b = a, *e = a + 7;
	exercise(b, e);
	return 0;
}
// Way 1: throw p and then delete it. The flaw of this solution is sometimes we 
// cannot throw every pointer that points to dynamically allocated resource. And
// what if another operation throws exception? We don't even have a chance to 
// throw p. This is not the way out.