#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
string& changeSubstr(string &s, const string& oldVal, const string& newVal)
{
    if(s.empty() || oldVal.empty()) // be careful, s and oldVal should be non empty strings
        return s;
    auto sizeOld = oldVal.size();
    auto sizeNew = newVal.size();
    auto iter = s.begin();
    while(iter != s.end()) // make sure don't skip any element
    {
        string subOld(iter, iter + sizeOld);
        if(subOld == oldVal)
        {
            s.erase(iter, iter + sizeOld);
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += sizeNew;
        }
        else
            ++iter;
    }
    return s;
}
int main()
{
    string s = "I came thru the way. thru thru thru";
    cout << s << endl;
    changeSubstr(s, "", "");
    cout << s << endl;
    return 0;
}
