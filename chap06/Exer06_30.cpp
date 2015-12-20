// Warning: This is for verification. It CANNOT be compiled successfully by both compilers.
// The problems lie in line 16 and 18.
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
bool str_subrange(const string &str1, const string &str2)
{
	if(str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for(decltype(size) i = 0; i != size; ++i)
	{
		if(str1[i] != str2[i])
			return; // error #1: no return value
	}
	// error #2: no return here
}
int main()
{
	return 0;
}
// ******compile info under cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Exer06_30.cpp
// Exer06_30.cpp(16) : error C2561: “str_subrange”: 函数必须返回值
//         Exer06_30.cpp(8) : 参见“str_subrange”的声明

// ******compile info of g++******
// Exer06_30.cpp: In function 'bool str_subrange(const string&, const string&)':
// Exer06_30.cpp:16:4: error: return-statement with no value, in function returning
//  'bool' [-fpermissive]
//     return; // error #1: no return value
//     ^

// Note: neither compiler could detect error#02. Don't blame others for your own 
// fault.