#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int i = 10;
    auto f = [&]() { return (--i <= 0) ? true : false; };
    while(!f())
        cout << i << " ";
    cout << endl;
    return 0;
}
