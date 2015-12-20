// Warning: this program uses machine-dependent operations. Don't use it in practice.
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
int main()
{
	// just for explanation, don't use this way, see note1 and note2.
	vector<char*> roster1 = { "C++", "Primer", "Plus" };
	vector<char*> roster2 = { "C++", "Primer", "Plus" };
	cout << "Two const char arrays are " 
	     << (equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) ? "equal" : "not equal") << endl;
	cout << "Address of roster1: ";
	for(const auto &cs : roster1)
		cout << static_cast<void*>(cs) << " ";
	cout << endl;
	cout << "Address of roster2: ";
	for(const auto &cs : roster2)
		cout << static_cast<void*>(cs) << " ";
	cout << endl;
	return 0;
}
// ******Result compiled by cl******
// Two const char arrays are not equal
// Address of roster1: 00A4F190 00A4F194 00A4F19C
// Address of roster2: 00A4F1A4 00A4F1A8 00A4F1B0

// ******Result compiled by G++******
// Two const char arrays are equal
// Address of roster1: 0x4ab07e 0x4ab082 0x4ab089
// Address of roster2: 0x4ab07e 0x4ab082 0x4ab089

// Note #1: type of string literals is const char*, but we can assign one string
// literal to a nonconst char pointer. This is an exception allowed by compiler.
// If we compile the program with G++, it will warn us about it:
// warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
// It is well enough that further standards will completely forbid it so that
// newer compilers will no longer support such operations.

// Note #2: as you can see, if both rosters held C-style strings, rather than 
// library strings, the result depends. Even on the same machine, if we compile
// with different compilers, the results are different. Because for C-style strings,
// we are in fact comparing addresses. Whether addresses of two vectors with the
// same contents are identical denpends on compilers. So using C-style strings
// here is never recommended.

// Note #3: in line 19 and 23, we output the result with a named casts. Because if
// we didn't convert the cs into a void pointer, the output would be the whole 
// string! Another exception about C-style strings. On page 124 of C++ Primer, 
// it says:
// "we can use a null-terminated character array anywhere that we can use a string
// literal."
// That also implies that we cannot use a null-terminated character array as a
// pointer. So we cannot output the real value of a pointer to a null-terminated
// character array directly. Use static_cast<void*> instead.

// Note #4: last but not least, can we use array rather than pointer as elements 
// of a vector? If so, how do we initialize such a vector? This is a weird and 
// stupid question. After all, C++ library provides vector and other containers 
// in order to substitute for clumsy built-in arrays. Who would use a vector to
// contain an array? But here, it seems inviting to use const char array instead
// of pointer. Then think what we can do. If the element type is an int array,
// since an array must have a fixed size, we may have to write int [2] or 
// something like this. Thus the type is vector<int[2]>. Then it turns on 
// initialization and assignment. In fact, we cannot assign or copy an array. So
// we cannot assign an array element. As for initialization, I've tried several
// ways which all lead to compilation error. So it seems we cannot initialize an
// array in common way either. As a result, the program above uses char pointer 
// as roster's element. If you really want to use array as vector's element, use
// array container instead.