#include <iostream>
#include <string>
#include <bitset>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::bitset;
int main()
{
    bitset<64> bitvec(32);
    bitset<32> bv(1010101);
    string bstr;
    cin >> bstr;
    bitset<8> bvs(bstr);
    cout << bitvec << endl;
    cout << bv << endl;
    cout << bvs << endl;
    return 0;
}
