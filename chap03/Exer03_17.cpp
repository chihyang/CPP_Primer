#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int main()
{
    string word;
    vector<string> text;
    while(cin >> word)
        text.push_back(word);
    for(string &s : text)
    {
        if(!s.empty())
        {
            for(char &c : s)
            {
                if(isalpha(c) && !isupper(c))
                    c = toupper(c); // !attention: toupper() doesn't change it's parameter
            }
        }
    }
    for(auto s : text)
        cout << s << " ";
    cout << endl;
    return 0;
}
