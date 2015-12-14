// Note: see the link below for further discussion:
// https://stackoverflow.com/questions/34258836/ways-to-avoid-memory-leak-when-exception-thrown
#include <fstream>
#include <vector>
#include <memory>
using std::ifstream;
using std::vector;
using std::unique_ptr;
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	unique_ptr<int[]>  p(new int[v.size()]);
	ifstream in("ints");
	// exception occurs here
}
int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int *b = a, *e = a + 7;
	exercise(b, e);
	return 0;
}
// Way 2: use smart pointer and then we can solve the problem.