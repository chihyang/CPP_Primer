// Warning: This is for illustration. It has an potential error.
// The problem lies in line 10.
#include <string>
typedef double Money;
class Account {
public:
	// typedef std::string Money; // putting line 10 here is correct.
	Money balance() { return bal; }
private:
	typedef double Money; // error, but won't be found by some compilers.
	// typedef std::string Money; // error, a type name redefinition
	Money bal;
};
int main()
{
	Account myAcc;
	return 0;
}
// ******compile info of cl******
// cl

// ******compile info of g++******
// g++ does not find this error.

// Note: if we change typedef in line 10 from double to string(comment line 10 
// and uncomment line 11), both compilers will complain there is an error. Why? 
// according to page 284:  
// "Names used in declarations, including names used for the return type and types 
// in the parameter list, must be seen before they are used." 
// So for Money balance() { return bal; } compiler only checks the return type name
// Money declaration before it's used. Compiler finds it in line 4 and knows it's 
// an alias for double. Then it checks the type of return value bal. This time 
// it's a name used in member function body, so the compiler first checks name 
// definition in class, finding Money bal, which is a string variable. So the 
// return value and return type conflict. Compiler reports the error. If we put 
// this type definition at the beginning of the class, it's be correct.