#include <iostream>
#include <string>
#include <utility>
#include "Exer19_21_25_Token.h"
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::string;
int main()
{
    string s = "this is a string";
    Sales_data item("978-7-121-20038-0", 12, 128.0);
    int i = 12;
    char c = 'c';
    double d = 1.28;
    Token tkn;
    tkn = i;
    cout << tkn << endl;
    tkn = c;
    cout << tkn << endl;
    tkn = d;
    cout << tkn << endl;
    tkn = s;
    cout << tkn << endl;
    tkn = item;
    cout << tkn << endl;
    Token tkn2 = tkn;
    cout << tkn2 << endl;
    tkn2 = s;
    cout << tkn2 << endl;
    tkn2 = tkn;
    cout << tkn2 << endl;
    tkn2 = c;
    cout << tkn2 << endl;
    tkn = s;
    tkn2 = std::move(tkn);
    cout << tkn2 << endl;
    Token tkn3 = std::move(tkn2);
    cout << tkn3 << endl;
    tkn3 = tkn3;
    cout << tkn3 << endl;
    tkn3 = item;
    cout << tkn3 << endl;
    tkn2 = std::move(tkn3);
    cout << tkn2 << endl;
    return 0;
}
