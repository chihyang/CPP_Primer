#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
int main()
{
    vector<int> a(10);
    for(int i = 0; i < 10; ++i)
        a[i] = i;
    vector<int> a2 = a;
    return 0;
}
