// Warning: not every compiler could compile this.
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
class A {
public:
	A() = default;
	virtual ~A() = default;
};
class B : public A {
public:
	B() = default;
	~B() = default;
};
class C : public B {
public:
	C() = default;
	~C() = default;
};
class D : public B, public A {
public:
	D() = default;
	~D() = default;
};
int main()
{
	// exercise 19.3
	// (a)
	A *pa1 = new C;
	if(B *pb1 = dynamic_cast<B*>(pa1)) {
		cout << "(a): cast succeeds!" << endl;
	} else {
		cout << "(a): cast fails!" << endl;
	}
	// (b)
	B *pb2 = new B;
	// fail, dynamic type of pb2 is not C or derived class of C
	if(C *pc1 = dynamic_cast<C*>(pb2)) {
		cout << "(b): cast succeeds!" << endl;
	} else {
		cout << "(b): cast fails!" << endl;
	}
	// (c)
	A *pa2 = new D;
	if(B *pb3 = dynamic_cast<B*>(pa2)) {
		cout << "(c): cast succeeds!" << endl;
	} else {
		cout << "(c): cast fails!" << endl;
	}
	
	// exercise 19.4
	try {
		C &rc1 = dynamic_cast<C&>(*pa1); // ok: dynamic type of pa1 is C
		C &rc2 = dynamic_cast<C&>(*pa2); // error: dynamic type of pa2 is not C 
		                                 // or its derived class
	} catch(std::bad_cast e) {
		cout << e.what() << endl;
	}
	return 0;
}
// ******compile info of g++******
// Exer19_03.cpp:20:7: warning: direct base 'A' inaccessible in 'D' due to ambiguity
//  class D : public B, public A {
//        ^
// Exer19_03.cpp: In function 'int main()':
// Exer19_03.cpp:43:15: error: 'A' is an ambiguous base of 'D'
//   A *pa2 = new D;
//                ^

// ******compile info of clang++******
// Exer19_03.cpp:20:21: warning: direct base 'A' is inaccessible due to ambiguity:
//     class D -> class B -> class A
//     class D -> class A [-Winaccessible-base]
// class D : public B, public A {
//                     ^~~~~~~~
// Exer19_03.cpp:43:11: error: ambiguous conversion from derived class 'D' to base
//       class 'A':
//     class D -> class B -> class A
//     class D -> class A
//         A *pa2 = new D;
//                  ^~~~~
// 1 warning and 1 error generated.

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
// 
// Exer19_03.cpp
// Exer19_03.cpp(19) : warning C4584: “D”: 基类“A”已是“B”的基类
//         Exer19_03.cpp(4) : 参见“A”的声明
//         Exer19_03.cpp(9) : 参见“B”的声明