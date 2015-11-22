// Warning: this is for verification. It cannot compile.
#include <cstddef>
class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
	SmallInt(int = 0) {} // conversion from int
	operator int() const { return val; } // conversion to int
private:
	std::size_t val;
};
SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs)
{
	return lhs.val + rhs.val;
}
int main()
{
	SmallInt s1;
	double d = s1 + 3.14;
	// error: ambiguous call. There are two viable functions:
	// SmallInt operator+(const SmallInt&, const SmallInt&), 3.14 is converted to int and then SmallInt
	// built-in operator+(int, double), s1 is converted to int
	// To make it legal, we can write as below
	SmallInt s2;
	double d2 = s2.operator int() + 3.14;
	SmallInt s3;
	double d3 = s3 + SmallInt(3.14);
	return 0;
}