#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a[10];
    for(int i = 0; i < 10; ++i)
        a[i] = v[i];
    for(int j : a)
        cout << j << endl;
    return 0;
}
