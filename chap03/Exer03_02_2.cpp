// Read a word a time
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string word;
    while(cin >> word)
        cout << word << endl;
    return 0;
}
