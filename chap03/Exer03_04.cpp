#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == s2)
        cout << "Two strings are equal." << endl;
    else if(s1 > s2)
        cout << "The first string is larger." << endl;
    else
        cout << "The second string is larger." << endl;

    if(s1.size() == s2.size())
        cout << "Two strings have the same length." << endl;
    else if(s1.size() > s2.size())
        cout << "The first string is longer." << endl;
    else
        cout << "The second string is longer." << endl;
    return 0;
}
