#include <iostream>
#include "Exer14_45_Sales_data.h"
int main()
{
    Sales_data item1("9-999999-99");
    Sales_data item2("9-999999-99", 10, 28.0);
    if(item1 == string("9-999999-99")) // convert item to string
        std::cout << "True" << std::endl;
    if(item1 != item2) // call overloaded == operator of Sales_data
        std::cout << "False" << std::endl;
    return 0;
}
