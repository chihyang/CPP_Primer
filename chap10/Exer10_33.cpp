#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cerr;
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		cerr << "Wrong input!" << endl;
		return -1;
	}
	ifstream is(argv[1]);
	ofstream out_odd(argv[2]), out_even(argv[3]);
	istream_iterator<int> in_iter(is), eof;
	ostream_iterator<int> odd_iter(out_odd, " ");
	ostream_iterator<int> even_iter(out_even, "\n");
	vector<int> vec(in_iter, eof);
	auto even = partition(vec.begin(), vec.end(), [](const int &i){return i % 2;});
	copy(vec.begin(), even, odd_iter);
	copy(even, vec.end(), even_iter);
	return 0;
}