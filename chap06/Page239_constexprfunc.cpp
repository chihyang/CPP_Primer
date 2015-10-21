// Warning: This is for verifying. It CANNOT be compiled successfully by both compilers.
// Warning: Visual Studio 2013 compiler doesn't support constexpr function perfectly.
// The problem lies in line 18.
#include <iostream>
#include <cstddef>
constexpr int new_sz()
{
	return 42;
}
constexpr size_t scale(size_t cnt) 
{
	return new_sz() * cnt;
}
int main()
{
	int arr[scale(2)];
	int i = 2;
	int a2[scale(i)]; // error, return value is not a constexpr
	std::cout << sizeof(a2) << std::endl;
	return 0;
}
// ******NEVER USE IT IN C++******
// Note: Although there's an error in line 19, it's still compiled by g++ 
// successfully! So let's dissect the problem.
// Define another int value and an array:
// int j;
// int a3[j];
// It still compiles. If we output the value of j and sizeof(a3), we'll see 
// they're both 0. First of all, the behaviour of using a uninitialized 
// variable is undefined by C++, and such a variable has an uninitialized value. 
// Here g++ initializes it to 0, which is a little too warm-hearted. Moreover, 
// seems g++ doesn't regard it as illegal to define an array with a non constexpr 
// size. If we compile the program with cl(excluding all that about constexpr),
// the program won't compile. So defining an array with a non constexpr is a 
// machine-dependent behaviour.

// Note: it's confirmed that Visual Studio 2013 doesn't support constexpr, see 
// this page for detailed information:
// http://blogs.msdn.com/b/vcblog/archive/2014/11/17/c-11-14-17-features-in-vs-2015-preview.aspx