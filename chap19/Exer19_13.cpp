#include <iostream>
#include <string>
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::string;
int main()
{
    Sales_data item("978-7-121-20038-0", 120, 128.0), *pitem = &item;
    const string Sales_data::*pdata = Sales_data::data();
    cout << item.*pdata << endl;
    cout << pitem->*pdata << endl;
    return 0;
}
