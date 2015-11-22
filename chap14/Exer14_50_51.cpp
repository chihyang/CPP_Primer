#include <iostream>
struct LongDouble {
	LongDouble(double = 0.0) { std::cout << "LongDouble(double) is called" << std::endl; }
	operator double() { std::cout << "operator double() is called" << std::endl; return 0.0; }
	operator float() { std::cout << "operator float() is called" << std::endl; return 0; }
};
int main()
{
	// exercise 14.50
	LongDouble ldObj;
	int ex1 = ldObj; // ambiguous call, both operator int() and operator double() requires arithmetic conversion
	float ex2 =ldObj; // calls operator float()
	// exercise 14.51
	void calc(int);
	void calc(LongDouble);
	double dval;
	calc(dval); // call calc(int), because arithmetic conversion from double to int is ranked higher than class-type conversion from double to LongDouble
	return 0;
}
void calc(int)
{
	std::cout << "void calc(int) is called" << std::endl;
}
void calc(LongDouble)
{
	std::cout << "void calc(LongDouble) is called" << std::endl;
}