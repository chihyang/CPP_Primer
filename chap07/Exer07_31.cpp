#include <iostream>
class Y; // class declaration, incomplete class type
class X {
public:
	const X& print() const;
private:
	Y* y = nullptr; // define a pointer to an incomplete class type
};
class Y {
public:
	const Y& print() const;
private:
	X x; // already defined class, complete, use its object.
};
const X& X::print() const
{
	std::cout << "This is class X" << std::endl;
	return *this;
} 
const Y& Y::print() const
{
	std::cout << "This is class Y" << std::endl;
	return *this;
}
int main()
{
	X xP;
	xP.print();
	Y yP;
	yP.print();
	return 0;
}