// Warning: this is for verification. It cannot compile.
// The problems lie in line 10, 11, 12.
struct B {
	virtual void f1(int) const;
	virtual void f2();
	void f3();
};
struct D1 : B {
	void f1(int) const override; // ok: f1 matches f1 in the base
	void f2(int) override; // error: B has no f2(int) function
	void f3() override; // error: f3 not virtual
	void f4() override; // error: B doesn't have a function named f4
};
// ******compile info of g++******
// Page606_override.cpp:10:7: error: 'void D1::f2(int)' marked 'override', but does n
// ot override
//   void f2(int) override; // error: B has no f2(int) function
//        ^
// Page606_override.cpp:11:7: error: 'void D1::f3()' marked 'override', but does not
// override
//   void f3() override; // error: f3 not virtual
//        ^
// Page606_override.cpp:12:7: error: 'void D1::f4()' marked 'override', but does not
//  override
//   void f4() override; // error: B doesn't have a function named f4
//        ^

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
// 
// Page606_override.cpp
// Page606_override.cpp(10) : error C3668: “D1::f2”: 包含重写说明符“override”的方
// 法没有重写任何基类方法
// Page606_override.cpp(11) : error C3668: “D1::f3”: 包含重写说明符“override”的方
// 法没有重写任何基类方法
// Page606_override.cpp(12) : error C3668: “D1::f4”: 包含重写说明符“override”的
// 方法没有重写任何基类方法

// ******compile info of clang******
// Page606_override.cpp:10:15: error: non-virtual member function marked 'override'
//       hides virtual member function
//         void f2(int) override; // error: B has no f2(int) function
//                      ^
// Page606_override.cpp:5:15: note: hidden overloaded virtual function 'B::f2'
//       declared here: different number of parameters (0 vs 1)
//         virtual void f2();
//                      ^
// Page606_override.cpp:11:12: error: only virtual member functions can be marked
//       'override'
//         void f3() override; // error: f3 not virtual
//                   ^~~~~~~~
// Page606_override.cpp:12:12: error: only virtual member functions can be marked
//       'override'
//         void f4() override; // error: B doesn't have a function named f4
//                   ^~~~~~~~
// 3 errors generated.