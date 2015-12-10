#include <cstddef>
#include <iostream>
#include <random>
using std::size_t;
using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
unsigned getNum()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 100);
	return u(e);
}
int main()
{
	for(size_t i = 0; i < 10; ++i)
		cout << getNum() << endl;
	return 0;
}
