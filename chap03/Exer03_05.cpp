#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string word, line1, line2;
    while(cin >> word)
    {
        line1 += word; // concatenated without space
        line2 = line2 + word + " "; // separated with space
    }
    if(!line1.empty())
        cout << line1 << endl;
    if(!line2.empty())
        cout << line2 << endl;
    return 0;
}
