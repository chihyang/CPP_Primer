// Warning: this is for verification. It cannot compile by all of the compilers.
// Don't use such machine-dependent codes.
#include <iostream>
// usually a bad idea to have mutual conversions between two class types
struct B;
struct A {
    A() = default;
    A(const B&) { std::cout << "A(const B&) is called" << std::endl; } // converts a B to an A
};
struct B {
    operator A() const {
        std::cout << "operator A() const is called" << std::endl;
        return A(); } // also converts a B to an A
};
int main()
{
    A f(const A&);
    B b;
    A a = f(b); // error ambiguous: f(B::operator A())
                //              or: f(A::A(const B&))
    A a1 = f(b.operator A()); // ok: use B's conversion operator, but bad design
    A a2 = f(A(b));           // ok: use A's constructor, but bad design
    return 0;
}
A f(const A &a)
{
    return a;
}
// ******compile info of g++******
// (NOTHING happened; the compilation is successful)
//
// ******execution result******
// A(const B&) is called

// ******compile info of clang++******
// Page584_mutual_conversions.cpp:14:10: error: reference initialization of type
//       'const A &' with initializer of type 'B' is ambiguous
//         A a = f(b);
//                 ^
// Page584_mutual_conversions.cpp:5:2: note: candidate constructor
//         A(const B&) {} // converts a B to an A
//         ^
// Page584_mutual_conversions.cpp:8:2: note: candidate function
//         operator A() const { return A(); } // also converts a B to an A
//         ^
// Page584_mutual_conversions.cpp:12:14: note: passing argument to parameter here
//         A f(const A&);
//                     ^

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Page584_mutual_conversions.cpp
// Page584_mutual_conversions.cpp(17) : error C2664: “A f(const A &)”: 无法将参数
//  1 从“B”转换为“const A &”
//         原因如下:  无法从“B”转换为“const A”
//         没有可用于执行该转换的用户定义的转换运算符，或者无法调用该运算符

// Note: as the result above shows: although it's an ambiguous call, not all of
// compilers indicated it; some even compiled it! Anyway, don't use the code
// above, or it would have machine-dependent behaviour.
