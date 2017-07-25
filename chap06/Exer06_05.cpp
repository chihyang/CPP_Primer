#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int abs(int n)
{
    return (n >= 0) ? n : -n;
}
int main()
{
    int n;
    while(cin >> n)
        cout << abs(n) << endl;
    return 0;
}
