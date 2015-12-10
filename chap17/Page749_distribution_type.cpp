#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
using std::size_t;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::default_random_engine;
using std::normal_distribution;
int main()
{
	default_random_engine e;           // generates random integers
	normal_distribution<> n(4, 1.5); // mean 4, standard deviation 1.5
	vector<unsigned> vals(9);        // nine elements each 0
	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n(e));   // round to the nearest integer
		if (v < vals.size())         // if this result is in range
			++vals[v];               // count how often each number appears
	}
	for (size_t j = 0; j != vals.size(); ++j)
		cout << j << ": " << string(vals[j], '*') << endl;
	return 0;
}
