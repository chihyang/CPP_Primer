#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> v;
    string s;
    while(cin >> s)
        v.push_back(s);
    return 0;
}
