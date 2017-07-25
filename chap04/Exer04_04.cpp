#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int i1 = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    int i2 = ((12 /3) * 4) + (5 * 15) + ((24 % 4) / 2);
    cout << i1 << " " << i2 << endl;
    return 0;
}
