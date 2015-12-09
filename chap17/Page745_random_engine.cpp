#include <cstddef>
#include <iostream>
#include <random>
using std::size_t;
using std::cout;
using std::endl;
using std::default_random_engine;
int main()
{
	default_random_engine e; // generates random unsigned integers
	for (size_t i = 0; i < 10; ++i)
		// e() "calls" the object to produce the next random number
		cout << e() << " ";
	cout << endl;
}