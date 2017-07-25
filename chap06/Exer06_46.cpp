// Warning: This is for verification. It CANNOT be compiled successfully by both compilers.
// The problems lie in line 8, 14 and 15.
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
// The type of each parameter of a constexpr function must be a literal type,
// but string is not a literal type(see page 66), and parameter of isShorter is
// reference to string. So we can never define isShorter as a const expression.
// Error massage produced by compiler is verbose and weird hard to understand,
// so they are not listed here.
constexpr bool isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}
int main()
{
    constexpr string s1 = "Brave", s2 = "new world";
    cout << isShorter(s1, s2) << endl;
    const string &s = "const expression string s1";
    cout << s << endl;
    return 0;
}
