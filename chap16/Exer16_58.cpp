#include <iostream>
#include <string>
#include "Sales_data.h"
#include "Exer16_58_Vec.h"
#include "Exer16_58_StrVec.h"
using std::cout;
using std::endl;
using std::string;
int main()
{
    Vec<Sales_data> v;
    // here, emplace_back uses move constructor of Sales_data to construct object
    v.emplace_back("978-7-121-20038", 20, 122);
    v.emplace_back("978-7-121-20038", 50, 120);
    for(const auto &item : v)
        cout << item << endl;
    StrVec str;
    string s = "world";
    str.emplace_back("hi");
    str.emplace_back(s);
    for(const auto &item : str)
        cout << item << " ";
    cout << endl;
    return 0;
}
