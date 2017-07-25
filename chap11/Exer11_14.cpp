#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;
using std::ostream_iterator;
int main()
{
    map<string, vector<pair<string, string>>> family;
    string patronymic;
    string child_name, child_birthday;
    ostream_iterator<string> os(cout, " ");
    while(cin >> patronymic)
    {
        while(cin >> child_name >> child_birthday)
        {
            family[patronymic].push_back(make_pair(child_name, child_birthday));
        }
        cin.clear(); // clear for next input
    }
    for(const auto &w : family)
    {
        cout << w.first << ":\n";
        for(const auto &c : w.second)
            cout << c.first << " " << c.second << endl;
    }
    return 0;
}
