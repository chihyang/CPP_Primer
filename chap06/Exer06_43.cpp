// Warning: This is for verifying. It CANNOT be compiled successfully by both compilers.
// The problem lies in line 9.
#include <iostream>
#include <string>
#include "Page239_inline.h"
using std::cout;
using std::endl;
// This is just for verifying that ellipsis cannot be used this way.
inline bool eq(const int&, const int&){...}; 
int main()
{
	return 0;
}