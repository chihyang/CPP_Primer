#include <iostream>
#include <string>
#include "Exer07_49_Sales_data.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    Sales_data item("978-7-121-20038-0", 10, 128);
    string s = "978-7-121-20038-0";
    // for Sales_data(const string&)
    // combine #(a) and combine #(c) work, combine #(b) doesn't compile
    // for explicit Sales_data(const string&)
    // combine #(a) , combine #(b), combine #(c) won't compile
    item.combine(s);
    return 0;
}
// Note: see Exer07_49.h for combine #(a), #(b), #(c)
