// Warning: this is for verification. It can't compile.
// The problem lies in line 19.
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;
int main()
{
    string s = "Anna";
    const string &sref = s;
    map<string, int> m;
    m[sref] = 3; // here, we can use both const and non const
    map<string, int>::iterator map_iter = m.begin();
    cout << map_iter->first << " " << map_iter->second << endl;
    // because key is const string, we cannot initialize a nonconst reference with it
    string& pref_nc = &(map_iter->first);
    return 0;
}
