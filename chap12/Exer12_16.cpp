// Warning: this is for verification. It cannot compile.
// The problems lie in line 12 and 14.
#include <string>
#include <memory>
using std::string;
using std::unique_ptr;
int main()
{
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));
    unique_ptr<string> p3(new string("Stegosaurus"));
    unique_ptr<string> p4(p3); // error: no copy for unique_ptr
    unique_ptr<string> p5;
    p5 = p3; // error: no assign for unique_ptr
    return 0;
}
// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Exer12_16.cpp
// Exer12_16.cpp(12) : error C2280: “std::unique_ptr<std::string,std::default_dele
// te<_Ty>>::unique_ptr(const std::unique_ptr<_Ty,std::default_delete<_Ty>> &)”:
// 尝试引用已删除的函数
//         with
//         [
//             _Ty=std::string
//         ]
//         D:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\INCLUDE\memory(14
// 86) : 参见“std::unique_ptr<std::string,std::default_delete<_Ty>>::unique_ptr”
// 的声明
//         with
//         [
//             _Ty=std::string
//         ]

// ******compile info of g++******
// Exer12_16.cpp: In function 'int main()':
// Exer12_16.cpp:12:26: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::
// unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_str
// ing<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]'
//   unique_ptr<string> p4(p3); // error: no copy for unique_ptr
//                           ^
// In file included from D:/ProgramDevelop/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.
// 1.0/include/c++/memory:81:0,
//                  from Exer12_16.cpp:4:
// D:/ProgramDevelop/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.1.0/include/c++/bits/u
// nique_ptr.h:356:7: note: declared here
//        unique_ptr(const unique_ptr&) = delete;
//        ^
// Exer12_16.cpp:14:5: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& s
// td::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp
// = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basi
// c_string<char> >]'
//   p5 = p4; // error: no assign for unique_ptr
//      ^
// In file included from D:/ProgramDevelop/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.
// 1.0/include/c++/memory:81:0,
//                  from Exer12_16.cpp:4:
// D:/ProgramDevelop/TDM-GCC-64/lib/gcc/x86_64-w64-mingw32/5.1.0/include/c++/bits/u
// nique_ptr.h:357:19: note: declared here
//        unique_ptr& operator=(const unique_ptr&) = delete;
//                    ^

// ******compile info of clang++******
// Exer12_16.cpp:12:21: error: call to deleted constructor of 'unique_ptr<string>'
//         unique_ptr<string> p4(p3); // error: no copy for unique_ptr
//                            ^  ~~
// D:\ProgramDevelop\TDM-GCC-64\lib\gcc\x86_64-w64-mingw32\5.1.0\include\c++\bits/u
// nique_ptr.h:356:7: note:
//       'unique_ptr' has been explicitly marked deleted here
//       unique_ptr(const unique_ptr&) = delete;
//       ^
// 1 error generated.
