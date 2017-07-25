#include <iostream>
#include <list>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;
int main()
{
    list<const char*> detectives = {"Holmes", "Watson", "Hudson", "Poirot", "Hastings", "Marple"};
    vector<string> names; // assign doesn't require identical container type
    list<const char*> names2; // swap requires identical container type
    names.assign(detectives.begin(), detectives.end());
    swap(names2, detectives);
    for(const auto &s : names)
        cout << s << " ";
    cout << endl;
    for(auto itr = names2.begin(); itr != names2.end(); ++ itr)
        cout << *itr << " ";
    cout << endl;
    return 0;
}
