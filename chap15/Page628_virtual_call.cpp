// Warning: this is for illustration only and reflects bad practice.
// Note: VS 2013 doesn't support synthesized move constructor even if we use =default.
#include <iostream>
#include <string>
class D;
class Base {
public:
	Base() = default;
	Base(const Base &b) : i(debug()) { b.debug(); }
	Base(Base&&) = default;
	Base& operator=(const Base&) = default;
	Base& operator=(Base&&) = default;
	virtual ~Base() = default;
	virtual int debug() const { std::cout << "Base::debug() is called" << std::endl; return 1;}
protected:
	int i = 0;
};
class D : public Base {
public:
	D() = default;
	D(const D &d) : Base(d), s(d.s) { }
	int debug() const override { std::cout << "D::debug() is called" << std::endl; return 2; }
protected:
	std::string s;
};
int main()
{
	Base b; D d;
	D d1(d);    // calls Base::debug in i(debug()), and D::debug() in function body
	std::cout << std::endl;
	Base b1(b); // calls Base::debug in i(debug()), and Base::debug() in function body
	std::cout << std::endl;
	Base b2(d); // calls Base::debug in i(debug()), and D::debug() in function body
	return 0;
}
// ******result******
// Base::debug() is called
// D::debug() is called
// 
// Base::debug() is called
// Base::debug() is called
// 
// Base::debug() is called
// D::debug() is called

// Note: on page 628, it says:
// If a constructor or destructor calls a virtual, the version that is run is 
// the one corresponding to the type of the constructor or destructor itself.
//
// But the word has a presumption: we don't explicitly call a virtual through a 
// reference or pointer of the base class. As the code above shows, in Base's
// constructor, we call debug in initialization list, and b.debug() in function 
// body. Because b is a reference to Base type, and debug is a virtual function,
// the second call to debug in Base constructor is dynamic binding. According to
// the contents on page 628, however, this should be a call to Base::debug
// whatever b refers to. But the result declares against it. Still, the call is
// still to D::debug if b is bound to an object of D type. What agrees with the
// contents on page 628 is the first call to debug in Base constructor. It always
// calls to Base::debug().

// According to this discussion:
// https://stackoverflow.com/questions/962132/calling-virtual-functions-inside-constructors
// calls to a virtual in constructor is NEVER recommended. So in practice we had
// better avoid such usage.