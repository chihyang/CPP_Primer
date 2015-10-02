// Warning: This is for verifying. It cannot be compiled successfully by every compiler.
// The problem lies in line 17.
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	const string s = "Keep out!";
	// Type of c is const reference(or more precisely, reference to const).
	// If no operation in range for is to change value of s, it's okay, or it's an error.
	for(auto &c : s)
	{
		cout << c; // okay
		c = 'X'; // error, cannot compile successfully
	}
	cout << endl;
	return 0;
}
// ******compile info under cl******
// Exer03_11.cpp
// Exer03_11.cpp(17) : error C3892: “c”: 不能给常量赋值

// ******compile info under gcc******
// Exer03_11.cpp: In function 'int main()':
// Exer03_11.cpp:17:5: error: assignment of read-only reference 'c'
//    c = 'X'; // error, cannot compile successfully
//      ^