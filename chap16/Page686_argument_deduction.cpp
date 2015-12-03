// Warning: this is for illustration. Template declarations and definitions should be put into header files.
// Warning: this program cannot compile. The problem lies in line 19.
#include <string>
using std::string;
template <typename T>
int compare(const T &v1, const T &v2)
{
	if(v1 < v2) return -1;
	if(v2 < v1) return 1;
	return 0;
}
void func(int(*)(const string&, const string&)) {}
void func(int(*)(const int&, const int&)) {}
int main()
{
	// pf1 points to the instantiation int compare(const int&, const int&)
	int (*pf1)(const int&, const int&) = compare;
	// overloaded versions of func; each takes a different function pointer type
	func(compare); // error: which instantiation of compare, both compare<int> and compare<string> are ok
	return 0;
}