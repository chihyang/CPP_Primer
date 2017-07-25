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
        data.push_back(make_pair(str, i)); // way # 1
    }
    for(auto &p : data)
        cout << p.first << " " << p.second << endl;
    return 0;
}
// Other ways to create the pairs:
// # way 2
// pair<string, int> new_pair(str, i);
// data.push_back(new_pair);
//
// # way 3
// data.push_back({str, i});
// # way 1 is the easiest, because we needn't define a temporary local object
