// Page 105, exercise 3.16
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
    vector<string> v;
    string s;
    while(cin >> s)
        v.push_back(s);
    auto item = v.begin();
    for(; item != v.end(); ++item)
        cout << *item << " ";
    cout << endl;
    return 0;
}
