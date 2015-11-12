// Warning: This is for verifying. It CANNOT be compiled successfully by both compilers.
// The problems lie in line 7.
class Screen {
public:
	Screen& clear(char = bkground);
private:
	const char bkground;
};
int main()
{
	return 0;
}
// ******compile info of cl******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Page304_static.cpp
// Page304_static.cpp(5) : error C2648: “Screen::bkground”: 将成员作为默认参数使
// 用要求静态成员
//         Page304_static.cpp(7) : 参见“Screen::bkground”的声明

// ******compile info of g++******
// Page304_static.cpp:5:23: error: invalid use of non-static data member 'Screen::b
// kground'
//   Screen& clear(char = bkground);
//                        ^
// Page304_static.cpp:7:13: note: declared here
//   const char bkground;
//              ^

// Note: why cannot nonstatic member be used as default argument?
// On page 284, C++ Primer 5th edition, it says:
// Class definitions are processed in two phases:
// #1 First, the member declarations are compiled.
// #2 Function bodies are compiled only after the entire class has been seen.
// This implies that class definition is processed even there is no object of 
// that class is defined. This is trivial but not immaterial. If a member 
// function is nonstatic and take a member data as default argument, then it 
// will be transformed into something like this:
// void fun(int = this -> data)
// However, till then this is not initialized, so that it doesn't point to any 
// legal object. How can we use a member of a non-existed data? This is an 
// error.