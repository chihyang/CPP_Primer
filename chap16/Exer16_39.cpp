#include <iostream>
#include <string>
#include "Exer16_02_compare.h"
using std::cout;
using std::endl;
using std::string;
int main()
{
    // compare<const char* &>, the parameter is a const reference to pointer to a char
    cout << compare<char*>("this", "winter") << endl;
    // compare<string>, recommended way, better than the last
    cout << compare<string>("hi", "world") << endl;
    return 0;
}
