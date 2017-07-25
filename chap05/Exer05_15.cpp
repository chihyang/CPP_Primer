#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int sz = 9;
    // The space between ++ and sz is immaterial.
    for(int ix = 0; ix != sz; ++ix, ++ sz)
    {
        cout << ix << " " << sz << endl;
    }
    return 0;
}
