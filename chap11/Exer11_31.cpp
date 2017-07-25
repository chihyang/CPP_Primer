#include <iostream>
#include <string>
#include <map>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::multimap;
int main()
{
    multimap<string, string> authors;
    string aut, works;
    while(getline(cin, aut))
    {
        getline(cin, works);
        authors.insert({aut, works});
    }
    cin.clear(); // clear for subsequent input
    cout << "find an author and remove it:" << endl;
    while(cin >> aut)
    {
        if(authors.empty())
        {
            cout << "The container has been empty! Search terminated.";
            break;
        }
        if(authors.erase(aut))
            cout << "ok: " << aut << " removed\n";
        else
            cout << "oops: " << aut << " not found!\n";
    }
    cout << endl;
    return 0;
}
