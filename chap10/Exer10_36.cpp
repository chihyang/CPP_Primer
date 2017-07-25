#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::list;
using std::ostream_iterator;
int main()
{
    list<int> lst = { 1, 2, 3, 0, 4, 5, 6, 7, 8, 9 };
    ostream_iterator<int> os_iter(cout, " ");
    auto last_zero = find(lst.crbegin(), lst.crend(), 0);
    // the input range must be both reverse_iterators or plain iterators, don't mix them together
    copy(lst.cbegin(), last_zero.base(), os_iter);
    cout << endl;
    return 0;
}
