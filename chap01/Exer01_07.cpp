/*
 * comment pairs /* */ cannot nest.
 * "cannot nest" is considered source code
 * as is the rest of the program
 */
int main()
{
	return 0;
}
// ******compile info of g++******
// Exer01_07.cpp:2:24: error: 'cannot' does not name a type
//   * comment pairs /* */ cannot nest.
//                         ^

// ******compile info of clang******
// Exer01_07.cpp:2:18: warning: '/*' within block comment [-Wcomment]
//  * comment pairs /* */ cannot nest.
//                  ^
// Exer01_07.cpp:2:24: error: unknown type name 'cannot'
//  * comment pairs /* */ cannot nest.
//                        ^
// Exer01_07.cpp:2:35: error: expected ';' after top level declarator
//  * comment pairs /* */ cannot nest.
//                                   ^
//                                   ;
// 1 warning and 2 errors generated.

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
// 
// Exer01_07.cpp
// Exer01_07.cpp(2) : error C2146: 语法错误: 缺少“;”(在标识符“nest”的前面)
// Exer01_07.cpp(2) : error C4430: 缺少类型说明符 - 假定为 int。注意:  C++ 不支持默
// 认 int
// Exer01_07.cpp(2) : error C2143: 语法错误 : 缺少“;”(在“.”的前面)
// Exer01_07.cpp(5) : warning C4138: 在注释外找到“*/”
// Exer01_07.cpp(7) : error C2143: 语法错误 : 缺少“;”(在“{”的前面)
// Exer01_07.cpp(7) : error C2447: “{”: 缺少函数标题(是否是老式的形式表?)