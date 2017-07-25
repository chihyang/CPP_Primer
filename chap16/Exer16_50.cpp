// Warning: this is for verification. Template declarations and definitions should be put into header files.
#include <iostream>
using std::cout;
using std::endl;
template <typename T> void f(T)
{
    cout << "void f(T)" << endl;
}
template <typename T> void f(const T*)
{
    cout << "void f(const T*)" << endl;
}
template <typename T> void g(T)
{
    cout << "void g(T)" << endl;
}
template <typename T> void g(T*)
{
    cout << "void g(T*)" << endl;
}
int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42); // g(T), T: int; g(T)* is not viable
    g(p);  // g(T), T: int*: g(int*); g(T*), T: int, more specialized and chosen
    g(ci); // g(T), T: int, top-level const ignored; g(T*) is not viable
    g(p2); // g(T), T: const int*; g(T*): int, more specialized and chosen
    f(42); // f(T), T: int; f(const T*) is not viable
    f(p);  // f(T), T: int*, exact match; f(const T*), T: int, p needs converting to const
    f(ci); // f(T), T: int, top-level const is ignored; f(const T*) is not viable
    f(p2); // f(T), T: const int*; f(const T*), T: int, more specialized and chosen
    return 0;
}
// ******result******
// void g(T)
// void g(T*)
// void g(T)
// void g(T*)
// void f(T)
// void f(T)
// void f(T)
// void f(const T*)
