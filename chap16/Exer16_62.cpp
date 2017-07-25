#include <iostream>
#include <string>
#include <unordered_set>
#include "Exer16_62_Sales_data.h"
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
int main()
{
    unordered_set<Sales_data> bookStore;
    bookStore.insert(Sales_data("978-7-121-20038-0", 20, 128.00));
    bookStore.emplace("978-7-121-20038-0", 50, 99.00);
    bookStore.insert(Sales_data("978-7-87779-855-0", 20, 42.00));
    for(const auto &item : bookStore)
        cout << item << endl;
    return 0;
}
