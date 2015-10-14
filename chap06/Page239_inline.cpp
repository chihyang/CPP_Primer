// Warning: This is for verifying. It CANNOT be compiled successfully by both compilers.
// The problems lie in line 8-11.
#include <iostream>
#include <string>
#include "Page239_inline.h"
using std::cout;
using std::endl;
constexpr int new_sz();
{
	return 42;
}
int main()
{
	cout << new_sz() << endl;
	return 0;
}
// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Page239_inline.cpp
// Page239_inline.h(9) : error C2144: 语法错误:“int”的前面应有“;”
// Page239_inline.h(9) : error C4430: 缺少类型说明符 - 假定为 int。注意:  C++
// 不支持默认 int
// Page239_inline.cpp(8) : error C2144: 语法错误:“int”的前面应有“;”
// Page239_inline.cpp(8) : error C4430: 缺少类型说明符 - 假定为 int。注意:  C++ 不
// 支持默认 int
// Page239_inline.cpp(8) : error C2086: “int constexpr”: 重定义
//         Page239_inline.h(9) : 参见“constexpr”的声明
// Page239_inline.cpp(9) : error C2084: 函数“int new_sz(void)”已有主体
//         Page239_inline.h(9) : 参见“new_sz”的前一个定义
// Page239_inline.cpp(14) : error C2568: “<<”: 无法解析函数重载
//         Page239_inline.h(9): 可能是“int new_sz(void)”
// Page239_inline.cpp(14) : error C3861: “new_sz”:  找不到标识符

// ******compile info of g++******
// Page239_inline.cpp: In function 'constexpr int new_sz()':
// Page239_inline.cpp:8:15: error: redefinition of 'constexpr int new_sz()'
//  constexpr int new_sz()
               // ^
// In file included from Page239_inline.cpp:3:0:
// Page239_inline.h:9:15: note: 'constexpr int new_sz()' previously defined here
//  constexpr int new_sz()
//                ^

// Note: if line 9 to line 11 are commented, and line 8 is modified as 
// constexpr int new_sz();
// The program can be compiled successfully by g++, because it's just a 
// redeclaration of the constexpr function new_sz(). But cl doesn't compile it 
// and produce confusing error message.