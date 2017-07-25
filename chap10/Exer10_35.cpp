#include <iostream>
#include <iterator>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    ostream_iterator<int> os_iter(cout, " ");
    copy(vec.cbegin(), vec.cend(), os_iter);
    cout << endl;
    return 0;
}
