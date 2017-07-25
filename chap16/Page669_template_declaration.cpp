// Warning: this is for illustration. Template declarations and definitions should be put into header files.
#include <iostream>
using std::cout;
using std::endl;
// we can omit a type name, if the name is not used as function parameter or return type
template <typename, typename M> void compare(const M&);
// template name can be different across definitions and declarations
// but the number and kind(i.e., type and nontype) of type name should keep the same
template <typename T, typename U> void compare(const U &u)
{
    T t;
    cout << t << " " << u << endl;
}
int main()
{
    compare<int, double>(2.0);
    return 0;
}
