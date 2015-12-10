#include <cstddef>
#include <iostream>
#include <random>
using std::size_t;
using std::cout;
using std::cin;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
unsigned getNum(unsigned seed = 0, unsigned min = 0, unsigned max = 32767)
{
	static default_random_engine e(seed);
	static uniform_int_distribution<unsigned> u(min, max);
	return u(e);
}
int main()
{
	unsigned seed, min, max;
	cin >> seed >> min >> max;
	for(size_t i = 0; i < 10; ++i)
		cout << getNum(seed, min, max) << endl;
	return 0;
}