// Warning: This is for verification. It CANNOT be compiled successfully by both compilers.
// The problem lies in line 24.
#include <iostream>
using std::cout;
using std::endl;
void f()
{
    cout << "This function takes no parameters." << endl;
}
void f(int)
{
    cout << "This function takes an int parameter." << endl;
}
void f(int, int)
{
    cout << "This function takes two int parameters." << endl;
}
void f(double, double = 3.14)
{
    cout << "This function takes two double parameters." << endl;
}
int main()
{
    f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Exer06_51.cpp
// Exer06_51.cpp(24) : error C2666: “f”: 2 个重载有相似的转换
//         Exer06_51.cpp(18): 可能是“void f(double,double)”
//         Exer06_51.cpp(14): 或       “void f(int,int)”
//         尝试匹配参数列表“(double, int)”时

// ******compile info of g++******
// Exer06_51.cpp: In function 'int main()':
// Exer06_51.cpp:24:12: error: call of overloaded 'f(double, int)' is ambiguous
//   f(2.56, 42);
//             ^
// Exer06_51.cpp:14:6: note: candidate: void f(int, int)
//  void f(int, int)
//       ^
// Exer06_51.cpp:18:6: note: candidate: void f(double, double)
//  void f(double, double = 3.14)
//       ^
