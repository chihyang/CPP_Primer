// Page 105, exercise 3.17
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
    for(auto item = text.begin(); item != text.end() && !item->empty(); ++item)
    {
        for(auto c = item->begin(); c != item->end(); ++c)
        {
            if(isalpha(*c) && !isupper(*c))
            {
                *c = toupper(*c); // !attention: toupper() doesn't change it's parameter
            }
        }
    }
    for(auto s : text)
        cout << s << " ";
    cout << endl;
    return 0;
}
