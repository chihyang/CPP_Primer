#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;
using std::string;
using std::vector;
using std::multimap;
int main()
{
    multimap<string, vector<string>> family;
    string surname, child;
    ostream_iterator<string> os(cout, " ");
    while(cin >> surname)
    {
        vector<string> children;
        while(cin >> child)
            children.push_back(child);
        family.insert({surname, children});
        cin.clear();
    }
    for(const auto &w : family)
    {
        cout << w.first << ":\n";
        copy(w.second.cbegin(), w.second.cend(), os);
        cout << endl;
    }
    return 0;
}
