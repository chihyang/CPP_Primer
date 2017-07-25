#include <cstddef>
#include <iostream>
#include <random>
using std::size_t;
using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
int main()
{
    // uniformly distributed from 0 to 0 inclusive
    uniform_int_distribution<unsigned> u(0, 9);
    default_random_engine e; // generates random unsigned integers
    for (size_t i = 0; i < 10; ++i)
        // u uses e as a source of numbers
        // e() "calls" the object to produce the next random number
        cout << u(e) << " ";
    cout << endl;
    cout << "min: " << e.min() << " max: " << e.max() << endl;
}
