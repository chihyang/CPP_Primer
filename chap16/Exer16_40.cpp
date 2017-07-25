// Warning: this is for verification. It cannot compile.
// The problem lies in line 29 to 32.
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;
}
int main()
{
    vector<int> vi = { 0, 1, 2, 3, 4, 5 };
    vector<double> vd = { 3.14, 1.414, 2.2, 1.7171, 4, 5 };
    vector<string> vs = { "old", "man", "and", "the", "sea" };
    // ok: int could be added
    for(auto b = vi.begin(); b != vi.end(); ++b)
        cout << fcn3(b, vi.end()) << " ";
    cout << endl;
    // ok: double could be added with int
    for(auto b = vd.begin(); b != vd.end(); ++b)
        cout << fcn3(b, vd.end()) << " ";
    cout << endl;
    // error: string can not be added with an int
    for(auto b = vs.begin(); b != vs.end(); ++b)
        cout << fcn3(b, vs.end()) << " ";
    cout << endl;
    return 0;
}
