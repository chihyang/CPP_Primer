#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void reset(int &i)
{
    i = 0;
}
int main()
{
    int ival = 9;
    cout << "ival: " <<ival << endl;
    reset(ival);
    cout << "reset ival: " << ival << endl;
    return 0;
}
