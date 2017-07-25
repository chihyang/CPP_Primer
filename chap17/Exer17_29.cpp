#include <cstddef>
#include <iostream>
#include <random>
using std::size_t;
using std::cout;
using std::cin;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
unsigned getNum(unsigned seed = 0)
{
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u(0, 100);
    return u(e);
}
int main()
{
    unsigned seed;
    cin >> seed;
    for(size_t i = 0; i < 10; ++i)
        cout << getNum(seed) << endl;
    return 0;
}
