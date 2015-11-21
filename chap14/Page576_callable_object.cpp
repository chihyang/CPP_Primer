// Warning: this is for illustration. It cannot link.
// Note: this is an illustration of protracted problems. It covers contents of
// chapter 2, chapter 6 and chapter 14.
#include <iostream>
int foo(int i, int j = 0);
int main()
{
	int foo(int i, int j = 5);
	extern const int ic;
	std::cout << ic << std::endl;
	int(*p)(int, int);
	p = foo;
	return 0;
}
extern const int ic = 4;
// ******do not uncomment this function******
// int foo(int i, int j)
// {
	// return 0;
// }
// ******compile info of g++(without -c parameter)******
// D:\Temp\AppData\Local\Temp\ccxKsSNs.o:Page576_callable_object.cpp:(.rdata$.refpt
// r._Z3fooii[.refptr._Z3fooii]+0x0): undefined reference to `foo(int, int)'
// collect2.exe: error: ld returned 1 exit status
//
// ******compile info of g++(with -c parameter)******
// (NOTHING happened)

// ******compile info of clang++(without -c parameter)******
// D:\Temp\AppData\Local\Temp\Page576_callable_object-c4bb54.o:(.text+0x8a): undefi
// ned reference to `foo(int, int)'
// clang++.exe: error: linker command failed with exit code 1 (use -v to see invoca
// tion)
//
// ******compile info of clang++ (with -c parameter)******
// (NOTHING happened)

// ******compile info of cl(without -c parameter)******
// 用于 x86 的 Microsoft (R) C/C++ 优化编译器 18.00.40629 版版权所有(C) Microsoft C
// orporation。  保留所有权利。
//
// Page576_callable_object.cpp
// Microsoft (R) Incremental Linker Version 12.00.40629.0
// Copyright (C) Microsoft Corporation.  All rights reserved.
//
// /out:./obj/Page576_callable_object.exe
// ./obj/Page576_callable_object.obj
// Page576_callable_object.obj : error LNK2019: 无法解析的外部符号 "int __cdecl foo
// (int,int)" (?foo@@YAHHH@Z)，该符号在函数 _main 中被引用
// ./obj/Page576_callable_object.exe : fatal error LNK1120: 1 个无法解析的外部命令
//
// ******compile info of cl(with -c parameter)******
// (NOTHING happened)

// Note #1: from the compilation info above, we know that this file has link error.
// Why? Because the function foo has only declaration but no definition. The
// program has no grammar error, it compiles. But linker cannot find concrete
// definition of foo. Thus it cannot generate a executable file for us. If we
// uncomment line 15 to 19, everything will work fine.

// Note #2: the declaration of foo is inside main function, why is it okay? 
// Because this is a function declaration(page 206, chapter 6), and a declaration 
// makes a name known to the program(page 45, chapter 2). A definition just 
// represents a name, so it could be placed at any place, even inside a scope 
// and repeated multiple times, with constraints in Note #3.

// Note #3: foo has two declarations: on in main and the other in global scope. 
// And they offer different default arguments for the second parameter of foo. 
// This is okay because each parameter can have its default specified only once
// in A GIVEN SCOPE(page 237, chapter 6). So it's okay. However, we cannot write
// another declaration in main or global scope that provides default argument for
// j, EVEN IF the value of the argument is the same as the declared one.

// Note #4: as the Note #1 shows, because foo has no definition, it's useless to
// use a function pointer to point to it.

// Note #5: As for variable, things are different. Once we write type and name,
// a variable is defined. Sometimes we may not want to write a variable 
// definition, then we have use keyword extern. If we use extern, we MUST use it
// both in definition -- a variable with both extern and initializer and OUTSIDE
// any function(page 45, chapter 2) -- and in declaration(inside or outside a
// function, without initializer).