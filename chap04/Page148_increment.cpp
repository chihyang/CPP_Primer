// Warning: This is for verification. It CANNOT be compiled successfully by every compiler.
// The problem lies in line 10.
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int i = 0;
    ++i = 5; // legal, prefix ++ returns i itself as a lvalue
    i++ = 5; // illegal, postfix ++ returns copy of origin i as an rvalue
    cout << i << endl;
    return 0;
}
