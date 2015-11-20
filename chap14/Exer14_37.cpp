#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
class Equality {
public:
	Equality(int i = 0) : val(i) {}
	bool operator()(int iv) const { return iv == val; }
private:
	int val;
};
int main(int argc, char* argv[])
{
	if(argc != 2)
		return -1;
	Equality equ(10);
	ifstream file(argv[1]);
	istream_iterator<int> in(file), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> v;
	copy(in, eof, back_inserter(v)); // review of iterator
	copy(v.cbegin(), v.cend(), out);
	cout << endl;
	replace_if(v.begin(), v.end(), equ, 42);
	copy(v.cbegin(), v.cend(), out);
	cout << endl;
	return 0;
}