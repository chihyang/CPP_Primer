#include <iostream>
#include <string>
#include <vector>
#include "Exer14_35_ReadString.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    ReadString reader;
    string s;
    vector<string> vs;
    while((s = reader()) != ""){
        vs.push_back(s);
    }
    for(const auto &s : vs)
        cout << s << endl;
    return 0;
}
