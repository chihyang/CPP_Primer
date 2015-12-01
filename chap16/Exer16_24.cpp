#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "Exer16_06_begin_end.h" // for begin and end
#include "Exer16_24_Blob.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
int main()
{
	int ia[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<long> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<const char*> w = { "now", "is", "the", "time" };
	// instantiates the Blob<int> class
	// and the Blob<int> constructor that has two int* parameters
	Blob<int> a1(begin(ia), end(ia));
	// instantiates the Blob<int> constructor that has
	// has two vector<long>::iterator parameters
	Blob<int> a2(vi.begin(), vi.end());
	// instantiates the Blob<string> class and the Blob<string>
	// constructor that has two list<const char*>::iterator parameters
	Blob<string> a3(w.begin(), w.end());
	for(typename Blob<int>::size_type i = 0; i != a1.size(); ++i)
		cout << a1[i] << " ";
	cout << endl;
	for(typename Blob<int>::size_type i = 0; i != a2.size(); ++i)
		cout << a2[i] << " ";
	cout << endl;
	for(typename Blob<string>::size_type i = 0; i != a3.size(); ++i)
		cout << a3[i] << " ";
	cout << endl;
	return 0;
}