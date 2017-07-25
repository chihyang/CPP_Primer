#include <iostream>
#include "Exer16_14_15_Screen.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    Screen<5, 5> scr('c');
    Screen<5, 5> scr2;
    cout << scr << endl;
    cin >> scr2;
    cout << scr2 << endl;
    return 0;
}
