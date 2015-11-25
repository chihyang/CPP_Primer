// Warning: this is for verification. It cannot compile.
// The problem lies in line 16.
struct Base {
	int memfcn() { return mem;}
protected:
	int mem = 0;
};
struct Derived : Base {
	int memfcn(int i) { return i; } // hides memfcn in the base
};
int main()
{
	Derived d; Base b;
	b.memfcn();         // calls Base::memfcn
	d.memfcn(10);       // calls Derived::memfcn
	d.memfcn();         // error: memfcn with no argument
	d.Base::memfcn();   // ok: calls Base::memfcn
	return 0;
}
// ******compile info of g++******
// Page619_name_lookup.cpp: In function 'int main()':
// Page619_name_lookup.cpp:16:11: error: no matching function for call to 'Derived:
// :memfcn()'
//   d.memfcn();         // error: memfcn with no argument
//            ^
// Page619_name_lookup.cpp:9:6: note: candidate: int Derived::memfcn(int)
//   int memfcn(int i) { return i; } // hides memfcn in the base
//       ^
// Page619_name_lookup.cpp:9:6: note:   candidate expects 1 argument, 0 provided

// ******compile info of cl******
// Page619_name_lookup.cpp
// Page619_name_lookup.cpp(16) : error C2660: “Derived::memfcn”: 函数不接受 0 个
// 参数

// ******compile info of clang++******
// Page619_name_lookup.cpp:16:4: error: too few arguments to function call,
//       expected 1, have 0; did you mean 'Base::memfcn'?
//         d.memfcn();         // error: memfcn with no argument
//           ^~~~~~
//           Base::memfcn
// Page619_name_lookup.cpp:4:6: note: 'Base::memfcn' declared here
//         int memfcn() { return mem;}
//             ^
// 1 error generated.
// 
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。