// Warning: this is for test. It cannot compile.
// The problems lie in line 13, 14, 16 and 17.
#include "Page612_613_access.h"
int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;
	Base *p = &d1;  // d1 has type Pub_Derv
	p = &d2;        // error: d2 has type Priv_Derv
	p = &d3;        // error: d3 has type Prot_Derv
	p = &dd1;       // dd1 has type Derived_from_Public
	p = &dd2;       // error: dd2 has type Derived_from_Private
	p = &dd3;       // error: dd3 has type Derived_from_Protected
	return 0;
}
// ******compile info of g++******
// Exer15_18.cpp: In function 'int main()':
// Exer15_18.cpp:13:4: error: 'Base' is an inaccessible base of 'Priv_Derv'
//   p = &d2;        // error: d2 has type Priv_Derv
//     ^
// Exer15_18.cpp:14:4: error: 'Base' is an inaccessible base of 'Prot_Derv'
//   p = &d3;        // error: d3 has type Prot_Derv
//     ^
// Exer15_18.cpp:16:4: error: 'Base' is an inaccessible base of 'Derived_from_Priva
// te'
//   p = &dd2;       // error: dd2 has type Derived_from_Private
//     ^
// Exer15_18.cpp:17:4: error: 'Base' is an inaccessible base of 'Derived_from_Prote
// cted'
//   p = &dd3;       // error: dd3 has type Derived_from_Protected
//     ^

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
// 
// Exer15_18.cpp
// Exer15_18.cpp(13) : error C2243: “类型转换”: 从“Priv_Derv *”到“Base *”的转
// 换存在，但无法访问
// Exer15_18.cpp(14) : error C2243: “类型转换”: 从“Prot_Derv *”到“Base *”的转
// 换存在，但无法访问
// Exer15_18.cpp(16) : error C2243: “类型转换”: 从“Derived_from_Private *”到“B
// ase *”的转换存在，但无法访问
// Exer15_18.cpp(17) : error C2243: “类型转换”: 从“Derived_from_Protected *”到
// “Base *”的转换存在，但无法访问

// ******compile info of clang++******
// Exer15_18.cpp:13:6: error: cannot cast 'Priv_Derv' to its private base class
//       'Base'
//         p = &d2;        // error: d2 has type Priv_Derv
//             ^
// ./Page612_613_access.h:17:20: note: declared private here
// struct Priv_Derv : private Base {
//                    ^~~~~~~~~~~~
// Exer15_18.cpp:13:4: error: assigning to 'Base *' from incompatible type
//       'Priv_Derv *'
//         p = &d2;        // error: d2 has type Priv_Derv
//           ^ ~~~
// Exer15_18.cpp:14:6: error: cannot cast 'Prot_Derv' to its protected base class
//       'Base'
//         p = &d3;        // error: d3 has type Prot_Derv
//             ^
// ./Page612_613_access.h:21:20: note: declared protected here
// struct Prot_Derv : protected Base {
//                    ^~~~~~~~~~~~~~
// Exer15_18.cpp:14:4: error: assigning to 'Base *' from incompatible type
//       'Prot_Derv *'
//         p = &d3;        // error: d3 has type Prot_Derv
//           ^ ~~~
// Exer15_18.cpp:16:6: error: cannot cast 'Derived_from_Private' to its private
//       base class 'Base'
//         p = &dd2;       // error: dd2 has type Derived_from_Private
//             ^
// ./Page612_613_access.h:17:20: note: declared private here
// struct Priv_Derv : private Base {
//                    ^~~~~~~~~~~~
// Exer15_18.cpp:16:4: error: assigning to 'Base *' from incompatible type
//       'Derived_from_Private *'
//         p = &dd2;       // error: dd2 has type Derived_from_Private
//           ^ ~~~~
// Exer15_18.cpp:17:6: error: cannot cast 'Derived_from_Protected' to its protected
// 
//       base class 'Base'
//         p = &dd3;       // error: dd3 has type Derived_from_Protected
//             ^
// ./Page612_613_access.h:21:20: note: declared protected here
// struct Prot_Derv : protected Base {
//                    ^~~~~~~~~~~~~~
// Exer15_18.cpp:17:4: error: assigning to 'Base *' from incompatible type
//       'Derived_from_Protected *'
//         p = &dd3;       // error: dd3 has type Derived_from_Protected
//           ^ ~~~~
// 8 errors generated.