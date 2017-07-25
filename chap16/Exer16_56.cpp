#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Exer16_56_errorMsg.h"
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::make_shared;
int main()
{
    int i = 2, *p = &i;
    string other = "other";
    // calls print(os, const char[7]&, const int&, const int*&, const string&)
    errorMsg(cerr, "fcnName", __LINE__, p, other) << endl;
    return 0;
}
