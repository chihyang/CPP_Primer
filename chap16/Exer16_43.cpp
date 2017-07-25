// Warning: this is for verification. Template declarations and definitions should be put into header files.
#include <iostream>
using std::cout;
using std::endl;
template <typename T>
void g(T&& val) { val = 2; }
int main()
{
    int i = 0;
    const int ci = i;
    g(i = ci);
    // ok: T is int&(assignment returns reference to its left-hand operand, an lvalue;
    // pass an lvalue; T is reference to lvalue, int& &; collapses to int&);
    // val is int&(int& && collapses to int&)
    cout << i << endl; // i = 2(pass reference; any change on val will change i)
    return 0;
}
