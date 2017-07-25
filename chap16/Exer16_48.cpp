#include <iostream>
#include <string>
#include "Exer16_48_debug_rep.h"
using std::cout;
using std::endl;
using std::string;
int main()
{
    string s("hi");
    const string *sp = &s;
    char a[] = "How are you?";
    char *p = a;
    cout << debug_rep(s) << "\n" << endl;  // call debug_rep(const string&)
    cout << debug_rep(sp) << "\n" << endl; // call debug_rep(T*), instantiated to debug_rep(const string*)
    cout << debug_rep("hi world!") << "\n" << endl; // call debug_rep(const char*)
    cout << debug_rep(p) << endl; // call debug_rep(char*)
    return 0;
}
