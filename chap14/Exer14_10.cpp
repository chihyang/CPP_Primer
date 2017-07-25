#include <iostream>
#include "Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    Sales_data item(cin);
    cout << item << endl;
    return 0;
}
// ******result******
// 0-201-99999-9 10 24.95
// 0-201-99999-9 10 249.5 24.95
//
// 10 24.95 0-201-99999-9
// 10 24 22.8 0.95

// Note: as the result above shows, the second input is illegal but still yield
// an unexpected result. Because istream interpret 0-201-99999-9 as a double.
// This implies just checking if istream fails is not enough.
