// Warning: this is for verification. It cannot compile.
#include <iostream>
#include <vector>
#include "Exer16_02.h"
#include "Sales_data.h"
using std::cout;
using std::endl;
using std::vector;
int main()
{
	Sales_data item1("978-7-121-20038-0", 10, 128.0);
	Sales_data item2("978-0-87779-855-2", 10, 6.99);
	cout << compare(item1, item2) << endl;
	return 0;
}
// ******compile info of g++******
// In file included from Exer16_03.cpp:4:0:
// Exer16_02.h: In instantiation of 'int compare(const T&, const T&) [with T = Sale
// s_data]':
// Exer16_03.cpp:13:30:   required from here
// Exer16_02.h:6:8: error: no match for 'operator<' (operand types are 'const Sales
// _data' and 'const Sales_data')
//   if(v1 < v2) return -1;
//         ^
// Exer16_02.h:7:8: error: no match for 'operator<' (operand types are 'const Sales
// _data' and 'const Sales_data')
//   if(v2 < v1) return 1;
//         ^

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
// 
// Exer16_03.cpp
// f:\programming\cpp\cpp_primer\chap16\Exer16_02.h(6) : error C2676: 二进制“<”:
// “const Sales_data”不定义该运算符或到预定义运算符可接收的类型的转换
//         Exer16_03.cpp(13): 参见对正在编译的函数 模板 实例化“int compare<Sales_d
// ata>(const T &,const T &)”的引用
//         with
//         [
//             T=Sales_data
//         ]
// f:\programming\cpp\cpp_primer\chap16\Exer16_02.h(7) : error C2676: 二进制“<”:
// “const Sales_data”不定义该运算符或到预定义运算符可接收的类型的转换

// *******compile info of clang++******
// In file included from Exer16_03.cpp:4:
// ./Exer16_02.h:6:8: error: invalid operands to binary expression
//       ('const Sales_data' and 'const Sales_data')
//         if(v1 < v2) return -1;
//            ~~ ^ ~~
// Exer16_03.cpp:13:10: note: in instantiation of function template specialization
//       'compare<Sales_data>' requested here
//         cout << compare(item1, item2) << endl;
//                 ^
// In file included from Exer16_03.cpp:4:
// ./Exer16_02.h:7:8: error: invalid operands to binary expression
//       ('const Sales_data' and 'const Sales_data')
//         if(v2 < v1) return 1;
//            ~~ ^ ~~
// 2 errors generated.