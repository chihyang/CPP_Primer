#include <cstddef>
#include <iostream>
#include <random>
#include <ctime>
using std::size_t;
using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
int main()
{
	default_random_engine e1(time(0));   // a somewhat random seed
	for (size_t i = 0; i < 10; ++i)
		cout << e1() << " ";
	cout << endl;
	return 0;
}