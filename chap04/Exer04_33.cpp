#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int someValue = 0;
    int x = 2, y = 5;
    int val = (someValue ? ++x, --y : --x, --y);
    cout << val << endl;
    return 0;
}
