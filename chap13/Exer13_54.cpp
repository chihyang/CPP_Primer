// Warning: this is for verification. It cannot compile for ambiguous call.
// The problem lies in class header.
#include <iostream>
#include "Exer13_54_HasPtr.h"
using std::cout;
using std::endl;
int main()
{
	HasPtr hp("Young and Beautiful");
	HasPtr hp1;
	hp1 = hp;
	HasPtr hp2("Take him away"); // now hp can't be used again, because it refers to null
	hp2 = std::move(hp);
	hp2.print(cout) << endl;
	hp.print(cout) << endl;
	return 0;
}
// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Exer13_54.cpp
// f:\programming\cpp\cpp_primer\chap13\Exer13_54.h(21) : error C3646: “noexcept”
// : 未知重写说明符
// f:\programming\cpp\cpp_primer\chap13\Exer13_54.h(26) : error C3646: “noexcept”
// : 未知重写说明符
// f:\programming\cpp\cpp_primer\chap13\Exer13_54.h(35) : error C3646: “noexcept”
// : 未知重写说明符
// Exer13_54.cpp(13) : error C2593: “operator =”不明确
//         f:\programming\cpp\cpp_primer\chap13\Exer13_54.h(26): 可能是“HasPtr &Ha
// sPtr::operator =(HasPtr &&)”
//         f:\programming\cpp\cpp_primer\chap13\Exer13_54.h(22): 或       “HasPtr
// &HasPtr::operator =(HasPtr)”
//         尝试匹配参数列表“(HasPtr, HasPtr)”时

// ******compile info of g++******
// Exer13_54.cpp: In function 'int main()':
// Exer13_54.cpp:13:6: error: ambiguous overload for 'operator=' (operand types are
//  'HasPtr' and 'std::remove_reference<HasPtr&>::type {aka HasPtr}')
//   hp2 = std::move(hp);
//       ^
// In file included from Exer13_54.cpp:4:0:
// Exer13_54.h:22:10: note: candidate: HasPtr& HasPtr::operator=(HasPtr)
//   HasPtr& operator=(HasPtr rhs) {
//           ^
// Exer13_54.h:34:9: note: candidate: HasPtr& HasPtr::operator=(HasPtr&&)
//  HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
//          ^

// ******compile info of clang******
// Exer13_54.cpp:13:6: error: use of overloaded operator '=' is ambiguous (with
//       operand types 'HasPtr' and
//       'typename std::remove_reference<HasPtr &>::type' (aka 'HasPtr'))
//         hp2 = std::move(hp);
//         ~~~ ^ ~~~~~~~~~~~~~
// ./Exer13_54.h:22:10: note: candidate function
//         HasPtr& operator=(HasPtr rhs) {
//                 ^
// ./Exer13_54.h:34:17: note: candidate function
// HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept
//                 ^
// 1 error generated.

// Note #1: why is this an ambiguous call? Let's see the declaration of both functions:
// 	HasPtr& operator=(HasPtr); //#1
//	HasPtr& operator=(HasPtr&&) noexcept; //#2
// #1 takes a HasPtr object as parameter, while #2 takes a rvalue reference to
// HasPtr as parameter. BUT REFERENCE CANNOT BE USED TO DIFFERENTIATE FUNCTIONS.
// There's no type conversion when we call "=" with a HasPtr variable. Thus both
// functions are exact match. As a result, this is an ambiguous call.

// Note #2: overloaded functions should guarantee all of the calls DIFFERENTIATED. 