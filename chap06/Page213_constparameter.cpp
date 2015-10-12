// Warning: This is for verifying. It CANNOT be compiled successfully by both compilers.
// The problem lies in line 16.
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
void reset(int &i)
{
	i = 0;
}
int main()
{
	string::size_type ctr = 0;
	int i = 9;
	reset(ctr); // When initialing a reference, there's no common type conversion
	reset(i);
	return 0;
}
// ******compile info under cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Page213_constparameter.cpp
// Page213_constparameter.cpp(16) : error C2664: “void reset(int &)”: 无法将参数
// 1 从“unsigned int”转换为“int &”

// ******compile info under g++******
// Page213_constparameter.cpp: In function 'int main()':
// Page213_constparameter.cpp:16:11: error: invalid initialization of non-const ref
// erence of type 'int&' from an rvalue of type 'int'
//   reset(ctr);
//            ^
// Page213_constparameter.cpp:6:6: note:   initializing argument 1 of 'void reset(i
// nt&)'
//  void reset(int &i)
//       ^

// Note: We can assign a size_type to int in fact, even if it's out of range.
// ctr = 2147483648;
// int j = ctr; // it's okay
// But we cannot bind a reference to int to a variable of size_type, There is no
// type conversion(except some exceptions about const) when we initialize a 
// reference.