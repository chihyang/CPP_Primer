// Warning: this is for verification. It cannot compile.
// The problem lies in line 10.
#include "Page617_Bulk_quote.h"
int main()
{
	Bulk_quote bulk;
	Bulk_quote *bulkP = &bulk;	// static and dynamic types are the same
	Quote *itemP = &bulk;       // static and dynamic types differ
	bulkP->discount_policy();   // ok: bulkP has type Bulk_quote*
	itemP->discount_policy();   // error: itemP has type Quote*
	return 0;
}
// ******compile info of g++******
// Page617_scope.cpp: In function 'int main()':
// Page617_scope.cpp:10:9: error: 'class Quote' has no member named 'discount_policy'
//   itemP->discount_policy();   // error: itemP has type Quote*
//          ^

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。

// ******compile info of clang++******
// Page617_scope.cpp
// Page617_scope.cpp(10) : error C2039: “discount_policy”: 不是“Quote”的成员
//         f:\programming\cpp\cpp_primer\chap15\Exer15_15_Quote.h(6) : 参见“Quote
// ”的声明
// 	 
// Page617_scope.cpp:10:9: error: no member named 'discount_policy' in 'Quote'
//         itemP->discount_policy();   // error: itemP has type Quote*
//         ~~~~~  ^
// 1 error generated.