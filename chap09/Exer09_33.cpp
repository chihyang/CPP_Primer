// Warning: This is for illustration. It has runtime error.
// The problem lies in line 15.
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto begin = v.begin();
    while(begin != v.end())
    {
        ++begin;
        v.insert(begin,42); // lead to infinite loop
        ++begin;
    }
    for(auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
