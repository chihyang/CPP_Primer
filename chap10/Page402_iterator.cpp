#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <functional>
using std::cout;
using std::endl;
using std::list;
using namespace std::placeholders;
void print(const int &i)
{
    cout << i << " ";
}
int main()
{
    list<int> lst = { 1, 2, 3, 4 };
    list<int> lst2, lst3 , lst4{5};
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    copy(lst.cbegin(), lst.cend(), inserter(lst4, lst4.begin()));
    cout << "lst2: ";
    for(const auto &c : lst2)
        cout << c << " ";
    cout << endl;
    cout << "lst3: ";
    for_each(lst3.cbegin(), lst3.cend(), [](const int &i){cout << i << " ";});
    cout << endl;
    cout << "lst4: ";
    for_each(lst4.cbegin(), lst4.cend(), bind(print, _1));
    cout << endl;
    return 0;
}
