// Warning: this is for verification. Don't use accumulate this way.
#include <iostream>
#include <vector>
#include <numeric>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<double> vi = { 7, 19.8, 3.9, .429, 34.5, 4.40, 6.6, 43.2, 1.7, 5.00, 3.31 };
    auto sum = accumulate(vi.cbegin(), vi.cend(), 0);
    cout << sum << endl;
    return 0;
}
