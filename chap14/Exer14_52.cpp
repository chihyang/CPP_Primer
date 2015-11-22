// Warning: this is for verification. It cannot compile.
// The problem lies in line 38.
#include <cstddef>
#include <iostream>
class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0) {} // conversion from int
	operator int() const { return val; } // conversion to int
private:
	std::size_t val;
};
struct LongDouble {
	LongDouble(double = 0.0) { std::cout << "LongDouble(double) is called" << std::endl; }
	operator double() { std::cout << "operator double() is called" << std::endl; return 0.0; }
	operator float() { std::cout << "operator float() is called" << std::endl; return 0; }
	// member operator+ for illustration purposes; + is usually a nonmember
	LongDouble operator+(const SmallInt&);
};
SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs)
{
	return lhs.val + rhs.val;
}
LongDouble LongDouble::operator+(const SmallInt &rhs)
{
	std::cout << "LongDouble operator+(const SmallInt&) is called" << std::endl;
	return LongDouble();
}
LongDouble operator+(LongDouble&, double)
{
	std::cout << "LongDouble operator+(LongDouble&, double) is called" << std::endl;
	return LongDouble();
}
int main()
{
	SmallInt si; 
	LongDouble ld;
	ld = si + ld; // error: ambiguous call, operator+(int, float) or operator+(int, double)? Another problem: user-defined conversion might happen more than once
	ld = ld + si; // LongDouble operator+(const SmallInt&) is called
	return 0;
}
// ******compile info of g++******
// Exer14_52.cpp: In function 'int main()':
// Exer14_52.cpp:38:10: error: ambiguous overload for 'operator+' (operand types ar
// e 'SmallInt' and 'LongDouble')
//   ld = si + ld; // error: ambiguous call,
//           ^
// Exer14_52.cpp:38:10: note: candidate: operator+(int, double) <built-in>
// Exer14_52.cpp:38:10: note: candidate: operator+(int, float) <built-in>