// Warning: this is for verification. It cannot compile.
// The problem lies in line 14
int a, val;
void foo(int val)
{
    static int si;
    enum Loc { a = 1024, b };
    // Bar is local to foo
    struct Bar {
        Loc locVal; // ok: uses a local type name
        int barVal;
        void fooBar(Loc l = a)
        {
            barVal = val;   // error: val is local to foo
            barVal = ::val; // ok: uses a global object
            barVal = si;    // ok: uses a static locVal object
            locVal = b;     // ok: uses an  enumerator
        }
    };
}
int main()
{
    return 0;
}
// ******compile info of g++******
// Page853_local_class.cpp: In member function 'void foo(int)::Bar::fooBar(foo(int)
// ::Loc)':
// Page853_local_class.cpp:14:13: error: use of parameter from containing function
//     barVal = val;   // error: val is local to foo
//              ^
// Page853_local_class.cpp:4:14: note: 'int val' declared here
//  void foo(int val)
//               ^

// ******compile info of clang++******
// Page853_local_class.cpp:14:13: error: reference to local variable 'val' declared
//
//       in enclosing function 'foo'
//                         barVal = val;   // error: val is local to foo
//                                  ^
// Page853_local_class.cpp:4:14: note: 'val' declared here
// void foo(int val)
//              ^
// 1 error generated.

// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Page853_local_class.cpp
// Page853_local_class.cpp(14) : error C2326: “void foo::Bar::fooBar(foo::Loc)”:
// 函数无法访问“val”
