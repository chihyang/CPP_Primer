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
    vector<string> text;
    string word;
    while(getline(cin, word))
        text.push_back(word);
    for(auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for(auto ct = it->begin(); ct != it->end(); ++ct)
        {
            if(islower(*ct))
                *ct = toupper(*ct);
        }
        cout << *it << " ";
    }
    return 0;
}
