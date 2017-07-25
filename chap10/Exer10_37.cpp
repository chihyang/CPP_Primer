#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::ostream_iterator;
int main()
{
    // iterator:        begin----------------------->end
    //                  ^                            ^
    vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //                ^                            ^
    // rev_iterator:  rend<------------------------rbegin
    list<int> lst;
    ostream_iterator<int> os_iter(cout, " ");
    copy(vec.crbegin() + 2, vec.crbegin() + 7, back_inserter(lst));
    copy(vec.cbegin(), vec.cend(), os_iter);
    cout << endl;
    copy(lst.cbegin(), lst.cend(), os_iter);
    cout << endl;
    return 0;
}
