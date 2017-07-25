// Warning: this is for illustration. Template declarations and definitions should be put into header files.
// Warning: this program cannot compile. The problems lie in line 39 and 43.
#include <iostream>
#include <utility>
using std::cout;
using std::endl;
// flip1 neither preserves constness or rvalue/lvalue property
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}
// rvalue reference preserves constness and lvalue/rvalue property but cannot forward lvalue/rvalue property
template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
    f(t2, t1);
}
// combine rvalue reference and forward can preserve and forward constness and lvalue/rvalue property
template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}
void f(int v1, int &v2)
{
    cout << v1 << " " << ++v2 << endl;
}
void g(int &&i, int &j)
{
    cout << i << " " << j << endl;
}
int main()
{
    int i = 10;
    // T1: int, T2: int
    flip1(f, i, 42); // flip1(void(*)(int, int), int, int); changing t1 doesn't change i
    cout << i << endl;
    flip1(g, i, 42); // error: flip1(void(*)(int&&, int&), int, int); i is copied; cannot pass t1(int) to int&&
    // T1: int&, T2: int
    flip2(f, i, 42); // flip2(void(*)(int, int), int&, int&&); changing t1 changes i
    cout << i << endl;
    flip2(g, i, 42); // error: flip2(void(*)(int&&, int&&), int&, int&&); cannot pass int&& to int&&
    // T1: int&, T2: int
    flip(f, i, 42);  // pass f (int&&, int&); changing t1 changes i
    cout << i << endl;
    flip(g, i, 42);  // pass g (int&&, int&), ok
    return 0;
}
