// Warning: This is for verification. It cannot be compiled successfully by every compiler.
// The problem lies in line 5.
#include<iostream>
struct Foo {} //no semicolon
int main()
{
	return 0;
}
// ******compile info under gcc******
// Exer2_39.cpp:3:13: error: expected ';' after struct definition
// struct Foo {} //no semicolon
//              ^

// ******compile info under cl******
// Exer2_39.cpp
// Exer2_39.cpp(4) : error C2628: “Foo”后面接“int”是非法的(是否忘记了“;”?)
// Exer2_39.cpp(5) : error C3874: “main”的返回类型应为“int”而非“Foo”
// Exer2_39.cpp(6) : error C2440: “return”: 无法从“int”转换为“Foo”
//         无构造函数可以接受源类型，或构造函数重载决策不明确
