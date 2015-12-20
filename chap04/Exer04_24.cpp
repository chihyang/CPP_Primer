// Warning: This is for verification. It CANNOT be compiled successfully by every compiler.
// The problem lies in line 15.
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
	int grade = 80;
	// if ? : is left associative, result is something like below. 
	// It's a wrong expression for type of two expressions of the first 
	// conditional operator is neither the same type nor able to be converted to
	// the same type.
	string finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) 
	                                  ? "fail" : "pass";
	cout << finalgrade << endl;
	return 0;
}