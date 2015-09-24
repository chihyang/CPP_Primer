// Warning: This is for verifying. It cannot be compiled successfully by every compiler.
// The problem lies in line 12, 13.
#include<iostream>

int main()
{
	int i = 3;
	// (f), the primary problem is that r2 isn't initialized. Whether it's compiled
	// successfully depends on compiler if initialization is completed. The const after
	// & is redundant.
	const int &const r2;
	const int &const r3 = i;
	return 0;
}
// ******compile info under cl******
// Exer2_27.cpp
// Exer2_27.cpp(6) : warning C4227: 使用了记时错误: 忽略引用上的限定符
// Microsoft (R) Incremental Linker Version 12.00.40629.0
// Copyright (C) Microsoft Corporation.  All rights reserved.

// /out:./obj/Exer2_27.exe 
// ./obj/Exer2_27.obj 

// ******compile info under gcc******
// Exer2_27.cpp: In function 'int main()':
// Exer2_27.cpp:6:19: error: 'const' qualifiers cannot be applied to 'const int&'
// const int &const r2 = i;