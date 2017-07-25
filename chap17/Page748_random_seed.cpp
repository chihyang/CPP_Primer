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
    default_random_engine e1;            // uses the default seed
    default_random_engine e2(214783646); // uses the given seed value
    // e3 and e4 will generate the same sequence because they use the same seed
    default_random_engine e3;          // uses the default seed value
    e3.seed(32767);                    // calls seed to set a new seed value
    default_random_engine e4(32767);   // set the seed value to 32767
    for (size_t i = 0; i < 10; ++i) {
        if(e1() == e2())
            cout << "unseeded match at iteration: " << i << endl;
        if(e3() != e4())
            cout << "seeded differs at iteration: " << i << endl;
    }
    return 0;
}
