#include <iostream>
#include <vector>
#include <bitset>
using std::cout;
using std::endl;
using std::vector;
using std::bitset;
int main()
{
    vector<int> vec = { 1, 2, 3, 5, 8, 13, 21 };
    unsigned u = 0U;
    for(auto i : vec)
        u |= (1U << i);
    bitset<22> bitvec1(u);
    bitset<22> bitvec2;
    for(auto i : vec)
        bitvec2[i] = 1;
    cout << bitvec1 << endl;
    cout << bitvec2 << endl;
    return 0;
}
