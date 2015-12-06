#include <iostream>
#include <string>
#include <vector>
#include "Exer16_63_64_count.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 0, 0 };
	vector<double> vd = { 0.2, 3.14, 98, 3/2, 1.414, 2.738, 6/7, 2 };
	vector<string> vs = { "This", "is", "is", "a", "sentence" };
	vector<const char*> vc = { "This", "is", "is", "a", "sentence" };
	const vector<const char*> vc2 = { "This", "is", "is", "a", "sentence" };
	const char* cp = "is";
	cout << count(vi, 0) << endl;      // T1: int, T2: int
	cout << count(vd, 2) << endl;      // T1: double, T2: int
	cout << count(vs, "is") << endl;   // T1: string, T2: const char[3]&
	cout << count(vc, string("this")) << endl; // T1: const char*, T2: string, use the overloaded operator== of string to compare
	cout << count(vc, "this") << endl; // T1: const char*, T2: string
	cout << count(vc2, "this") << endl; // T1: const char*, T2: char[5]&
	cout << count(vc2, cp) << endl;     // T1: const char*, T2: const char*
	return 0;
}
// ******result******
// 4
// 1
// 2
// 0
// 0
// 0
// count(const std::vector<const char*> &v, const char* const &t)
// 2

// Note1: only the last one call specialization version because only the last one
// matches specialized version exactly. Note that template specialization is not
// overloading, so match rules for overloading don't apply here.

// Note2: it seems that when we compare two const char pointers, we are comparing 
// contents rather than address. Maybe library also overloads operator== for
// const char*, so that we can use == to compare const char pointers directly.