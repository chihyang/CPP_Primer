#include <iostream>
#include <string>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;
int main()
{
    string word;
    deque<string> text;
    while(cin >> word)
        text.emplace_back(word);
    for(auto iter = text.begin(); iter != text.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}
