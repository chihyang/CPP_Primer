#include <iostream>
#include <vector>
#include <numeric>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> vi = { 7, 198, 39, 429, 345, 440, 66, 432, 17, 500, 331 };
    auto sum = accumulate(vi.cbegin(), vi.cend(), 0);
    cout << sum << endl;
    return 0;
}
