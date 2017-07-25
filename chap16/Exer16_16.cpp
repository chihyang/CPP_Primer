#include <iostream>
#include "Exer16_16_Vec.h"
using std::cout;
using std::endl;
int main()
{
    Vec<char> v = {'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!'};
    for(const auto &c : v)
        cout << c;
    cout << endl;
    v.push_back(':');
    v.push_back(')');
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    for(auto iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter;
    cout << endl;
    return 0;
}
