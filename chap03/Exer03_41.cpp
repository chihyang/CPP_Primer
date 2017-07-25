#include <iostream>
#include <vector>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v(begin(a), end(a));
    for(auto &i : v)
        cout << i << endl;
    return 0;
}
