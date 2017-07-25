#include <iostream>
#include <string>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
int main()
{
    string word;
    list<string> text;
    while(cin >> word)
        text.emplace_back(word);
    for(auto iter = text.begin(); iter != text.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}
