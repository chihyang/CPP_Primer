#ifndef INILINE_TEST
#define INILINE_TEST
#include <string>
using std::string;
inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
constexpr int new_sz()
{
    return 42;
}
#endif
