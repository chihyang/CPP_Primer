// Warning: This is for verifying. It CANNOT be compiled successfully by all compilers.
// The problem lies in line 10(cl only), 14 and 17(for both cl and gcc).
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	unsigned buf_size = 1024;
	int ia1[buf_size];
	// illegal, buf_size is not a const or const expression.
	int ia2[4 * 7 - 14];
	//legal, 4 * 7 -14 is a const expression.
	int ia3[txt_size()]; 
	// if return value type of txt_size() is a const or const expression, it's 
	// legal.
	char st[11] = "fundamental"; 
	// legal, length of "fundamental" for char array is 12(plus a suffix '\0'), 
	// size of st should begin larger than 12
	return 0;
}
// ******compile info under cl when commenting line 12, 14 and 17******
// Exer03_27.cpp
// Exer03_27.cpp(10) : error C2057: 应输入常量表达式
// Exer03_27.cpp(10) : error C2466: 不能分配常量大小为 0 的数组
// Exer03_27.cpp(10) : error C2133: “ia1”: 未知的大小

// ******compile info under gcc when commenting line 12, 14 and 17******
// GCC ignores this error without any warning, but as the textbook shows(page 
// 113), it should be an error.