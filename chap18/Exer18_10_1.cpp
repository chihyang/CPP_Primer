#include <iostream>
#include "Exer18_09_Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2) {
        sum = item1 + item2;
        cout << sum << endl;
    }
    return 0;
}
