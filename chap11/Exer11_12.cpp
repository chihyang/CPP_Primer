#include <iostream>
#include <string>
#include <vector>
#include <utility>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
int main()
{
    string str;
    int i;
    vector<pair<string, int>> data;
    while(cin >> str >> i)
    {
        data.push_back(make_pair(str, i));
    }
    for(auto &p : data)
        cout << p.first << " " << p.second << endl;
    return 0;
}
