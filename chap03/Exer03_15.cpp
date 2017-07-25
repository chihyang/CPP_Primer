#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::string;
using std::vector;
int main()
{
    vector<string> svec;
    string str;
    while(cin >> str) {
        svec.push_back(str);
    }
    return 0;
}
