#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};
    for(auto i: v)
        cout << i << " ";
    cout << endl;
    for(auto item = v.begin(); item != v.end(); ++item)
        *item = *item << 1;
    for(auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
