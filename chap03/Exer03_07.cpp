#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string s;
    cin >> s;
    if(!s.empty())
    {
        // If type of c is changed from 'auto &' to 'char', characters in s won't be changed.
        for(char c : s)
            c = 'X';
        cout << s << endl;
    }
    return 0;
}
