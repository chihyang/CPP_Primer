#ifndef PAGE612_613_ACCESS_H
#define PAGE612_613_ACCESS_H
class Base {
public:
	void pub_mem(); // public member
protected:
	int prot_mem = 0;   // protected member
private:
	char priv_mem = 0;  //private member
};
struct Pub_Derv : public Base {
	// ok: derived classes can access protected members
	int f() { return prot_mem; }
	// error: private members are inaccessible to derived classes
	// char g() { return priv_mem; }
	void memfcn(Base &b) { b = *this; } // legal
};
struct Priv_Derv : private Base {
	// private derivation doesn't affect access in the derived class
	int f1() { return prot_mem; }
	void memfcn(Base &b) { b = *this; } // legal
};
struct Prot_Derv : protected Base {
	// protected derivation doesn't affect access in the derived class
	int f2() { return prot_mem; }
	void memfcn(Base &b) { b = *this; } // legal
};
struct Derived_from_Public : public Pub_Derv {
	// ok: Base::prot_mem remains protected in Pub_Derv
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; } // legal
};
struct Derived_from_Private: public Priv_Derv {
	// error: Base::prot_mem is private in Priv_Derv
	// int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; } // illegal, Priv_Derv inherits from Base privatele
};
struct Derived_from_Protected: public Prot_Derv {
	// ok: Base::prot_mem is protected in Prot_Derv
	int use_base() { return prot_mem; }
	void memfcn(Base &b) { b = *this; } // legal
};
#endif
// ******compile info of g++******
// Exer15_19.h:3:12: error: 'class Base Base::Base' is inaccessible
//  class Base {
//             ^
// Exer15_19.h:36:14: error: within this context
//   void memfcn(Base &b) { b = *this; } // illegal, Priv_Derv inherits from Base privatele
//               ^
// Exer15_19.h: In member function 'void Derived_from_Private::memfcn(Base&)':
// Exer15_19.h:36:27: error: 'Base' is an inaccessible base of 'Derived_from_Private'
//   void memfcn(Base &b) { b = *this; } // illegal, Priv_Derv inherits from Base privatele
//                            ^

// ******compile info of clang++******
// Exer15_19.h:36:14: error: 'Base' is a private member of 'Base'
//         void memfcn(Base &b) { b = *this; } // illegal, Priv_Derv inheri...
//                     ^
// Exer15_19.h:18:20: note: constrained by private inheritance here
// struct Priv_Derv : private Base {
//                    ^~~~~~~~~~~~
// Exer15_19.h:3:7: note: member is declared here
// class Base {
//       ^
// Exer15_19.h:36:29: error: cannot cast 'Derived_from_Private' to its private base
// 
//       class 'Base'
//         void memfcn(Base &b) { b = *this; } // illegal, Priv_Derv inheri...
//                                    ^
// Exer15_19.h:18:20: note: declared private here
// struct Priv_Derv : private Base {
//                    ^~~~~~~~~~~~
// 2 errors generated.

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
// 
// Exer15_19.h
// Exer15_19.h(36) : error C2247: “Base”不可访问，因为“Priv_Derv”使用“private
// ”从“Base”继承
//         Exer15_19.h(3) : 参见“Base”的声明
//         Exer15_19.h(18) : 参见“Priv_Derv”的声明
//         Exer15_19.h(3) : 参见“Base”的声明
// Exer15_19.h(36) : error C2243: “类型转换”: 从“Derived_from_Private *”到“con
// st Base &”的转换存在，但无法访问