// Warning: this is for test. It cannot compile.
// The problem lies in line 8.
#include <iostream>
#include "Exer15_15_Disc_quote.h"
using std::cout;
int main()
{
    Disc_quote item("978-7-121-20038-0", 128.0, 6, 0.05); // error: defines an object of abstract class
    return 0;
}
// ******compile info of g++******
// Exer15_17.cpp: In function 'int main()':
// Exer15_17.cpp:8:13: error: cannot declare variable 'item' to be of abstract type
//  'Disc_quote'
//   Disc_quote item("978-7-121-20038-0", 128.0, 6, 0.05); // error: defines an obj
// ect of abstract class
//              ^
// In file included from Exer15_17.cpp:4:0:
// Exer15_15_Disc_quote.h:6:7: note:   because the following virtual functions are
// pure within 'Disc_quote':
//  class Disc_quote : public Quote {
//        ^
// Exer15_15_Disc_quote.h:11:9: note:      virtual double Disc_quote::net_price(std
// ::size_t) const
//   double net_price(std::size_t) const = 0;
//          ^

// ******compile info of cl*******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Exer15_17.cpp
// Exer15_17.cpp(8) : error C2259: “Disc_quote”: 不能实例化抽象类
//         由于下列成员:
//         “double Disc_quote::net_price(size_t) const”: 是抽象的
//         f:\programming\cpp\cpp_primer\chap15\Exer15_15_Disc_quote.h(11) : 参见“
// Disc_quote::net_price”的声明

// ******compile info of clang++******
// Exer15_17.cpp:6:13: error: variable type 'Disc_quote' is an abstract class
//         Disc_quote item("978-7-121-20038-0", 128.0, 6, 0.05);
//                    ^
// ./Exer15_15_Disc_quote.h:11:9: note: unimplemented pure virtual method
//       'net_price' in 'Disc_quote'
//         double net_price(std::size_t) const = 0;
//                ^
// 1 error generated.
