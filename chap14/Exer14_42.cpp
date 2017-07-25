#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::greater;
using std::not_equal_to;
using std::multiplies;
using namespace std::placeholders;
int main()
{
    // problem (a)
    vector<int> va = { 1232, 8729, 8, 291, 732, 5821, 1, 0, 23 };
    auto cnt_a = count_if(va.cbegin(), va.cend(), bind(greater<int>(), _1, 1024));
    cout << cnt_a << endl;
    // problem (b)
    vector<string> vb = { "pooh", "pooh", "pooh", "pooh", "jump", "over", "the", "slow", "red", "turtle" };
    auto iter = find_if(vb.cbegin(), vb.cend(), bind(not_equal_to<string>(), _1, "pooh"));
    cout << iter - vb.begin() << endl;
    // problem (c)
    vector<int> vc = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(auto i : vc)
        cout << i << " ";
    cout << endl;
    transform(vc.begin(), vc.end(), vc.begin(), bind(multiplies<int>(), _1, 2));
    for(auto i : vc)
        cout << i << " ";
    cout << endl;
    return 0;
}
// Note: this exercise uses generic algorithms and bind. Please review contents
// in section 10.3.4(on page 397) if you forget.
