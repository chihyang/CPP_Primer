// Warning: this is for verification. It cannot compile.
// The problem lies in line 14.
struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};
struct D2 : B {
    // inherits f2() and f3() from B and overrides f1(int)
    virtual void f1(int) const final; // subsequent classes can't override f1(int)
};
struct D3 : D2 {
    void f2(); // ok: overrides f2 inherited from the indirect base, B
    void f1(int) const; // error: D2 declares f2 as final
};
// ******compile info of g++******
// Page607_final.cpp:14:7: error: virtual function 'virtual void D3::f1(int) const'
//   void f1(int) const; // error: D2 declares f2 as final
//        ^
// Page607_final.cpp:10:15: error: overriding final function 'virtual void D2::f1(i
// nt) const'
//   virtual void f1(int) const final; // subsequent classes can't override f1(int)
//                ^

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Page607_final.cpp
// Page607_final.cpp : warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。
// 请将该文件保存为 Unicode 格式以防止数据丢失
// Page607_final.cpp(14) : error C3248: “D2::f1”:  声明为“final”的函数无法被“D
// 3::f1”重写
//         Page607_final.cpp(10) : 参见“D2::f1”的声明

// ******compile info of clang******
// Page607_final.cpp:14:7: error: declaration of 'f1' overrides a 'final' function
//         void f1(int) const; // error: D2 declares f2 as final
//              ^
// Page607_final.cpp:10:15: note: overridden virtual function is here
//         virtual void f1(int) const final; // subsequent classes can't ov...
//                      ^
// 1 error generated.
