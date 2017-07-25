// Warning: this is for verification. Template declarations and definitions should be put into header files.
// Warning: this program cannot compile. The problem lies in line 14.
#include <iostream>
using std::cout;
using std::endl;
template <typename T>
void g(T&& val) { val = 2; }
int main()
{
    int i = 0;
    const int ci = i;
    g(i);      // ok: T is int&(pass an lvalue); val is int&(int& && collapses to int&)
    cout << i << endl;  // assignment to val changes i
    g(ci);     // error: T is const int&(pass an lvalue; low level const won't be ignored); val is const int&(const int& && collapses to const int&); can not assign to a const int&
    cout << ci << endl; // assignment to val is illegal
    g(i * ci); // ok: T is int(pass an rvalue); val is T&&
    cout << i << endl;  // assignment to val doesn't change i
    return 0;
}
