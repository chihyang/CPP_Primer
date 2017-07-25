#ifndef READ_STRING_H
#define READ_STRING_H
#include <iostream>
#include <string>
using std::cin;
using std::istream;
using std::string;
class ReadString {
public:
    ReadString(istream &i = cin) : is(i) {}
    string operator()() const;
private:
    istream &is;
};
string ReadString::operator()() const
{
    string s;
    if(getline(is, s))
        return s;
    else {
        s = "";
    }
}
#endif
