// Warning: This is for illustration. It has runtime error.
// The problem lies in line 12-15.
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto iter = v.begin();
    while(iter != v.end()) // error: lacking curly braces
        if(*iter % 2)
            iter = v.insert(iter, *iter); // error: infinite loop, add iter by 2 after each insert
        ++iter; // error: add iter by 1 if if condition is false
    for(auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
