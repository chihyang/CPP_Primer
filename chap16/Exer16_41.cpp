#include <iostream>
#include <limits>
#include "Exer16_41.h"
using std::cout;
using std::endl;
int main()
{
    int i = 2;
    // std::numeric_limits<T>::max gets the maximum value of type T, see
    // http://en.cppreference.com/w/cpp/types/numeric_limits
    long long lng = std::numeric_limits<long>::max() - 20;
    cout << "i = " << i << endl;
    cout << "lng = " << lng << endl;
    cout << "i + lng = " << sum(i, lng) << endl;
    return 0;
}
