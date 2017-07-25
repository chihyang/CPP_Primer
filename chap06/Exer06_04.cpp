#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void fact()
{
    int val;
    cin >> val;
    int ret = 1;
    while(val > 1)
        ret *= val--;
    cout << ret << endl;
}
int main()
{
    fact();
    return 0;
}
