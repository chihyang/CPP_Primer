#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
int main()
{
	cout << "size of built-in type:" << endl;
	cout << "bool:\t" << sizeof(bool) << endl
	     << "char:\t" << sizeof(char) << endl
		 << "wchar_t:\t" << sizeof(wchar_t) << endl
		 << "char16_t:\t" << sizeof(char16_t) << endl
		 << "char32_t:\t" << sizeof(char32_t) << endl
		 << "short:\t" << sizeof(short) << endl
		 << "int:\t" << sizeof(long) << endl
         << "long:\t" << sizeof(long) << endl
		 << "long long:\t" << sizeof(long long) << endl
		 << "float:\t" << sizeof(float) << endl
		 << "double:\t" << sizeof(double) << endl
		 << "long double:\t" << sizeof(long double) << endl
		 << "int pointer:\t" << sizeof(int*) << endl;
	return 0;
}
// **********Output, compiled by G++, on a x64 machine:**********
// size of built-in type:
// bool:   1
// char:   1
// wchar_t:        2
// char16_t:       2
// char32_t:       4
// short:  2
// int:    4
// long:   4
// long long:      8
// float:  4
// double: 8
// long double:    16
// int pointer:    8

// **********Output, compiled compiled by G++, on a x64 machine, with -m32:**********
// size of built-in type:
// bool:   1
// char:   1
// wchar_t:        2
// char16_t:       2
// char32_t:       4
// short:  2
// int:    4
// long:   4
// long long:      8
// float:  4
// double: 8
// long double:    12
// int pointer:    4

// **********Output, compiled by cl x64, on a x64 machine:**********
// size of built-in type:
// bool:   1
// char:   1
// wchar_t:        2
// char16_t:       2
// char32_t:       4
// short:  2
// int:    4
// long:   4
// long long:      8
// float:  4
// double: 8
// long double:    8
// int pointer:    8

// **********Output, compiled by cl x86, on a x86 machine:**********
// size of built-in type:
// bool:   1
// char:   1
// wchar_t:        2
// char16_t:       2
// char32_t:       4
// short:  2
// int:    4
// long:   4
// long long:      8
// float:  4
// double: 8
// long double:    8
// int pointer:    4