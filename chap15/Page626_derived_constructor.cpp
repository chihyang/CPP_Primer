// Warning: this is for illustration only and reflects bad practice. It can't compile.
#include <iostream>
#include <string>
class D;
class Base {
public:
	Base() = default;
	Base(const D&);
	Base(const Base&) = default;
	Base(Base&&) = default;
	Base& operator=(const Base&) = default;
	Base& operator=(Base&&) = default;
	virtual ~Base() = default;
protected:
	int i = 0;
};
class D : public Base {
public:
	D() = default;
	D(const D &d) : Base(d), s(d.s) {}
protected:
	std::string s;
};
// We can use the member of D until it's defined
Base::Base(const D &d)
{
	std::cout << "Base(const D&) is called" << std::endl;
	i = d.i;
	std::cout << s << std::endl; // error: s in not is scope
}
int main()
{
	D d1;
	D d2(d1); // calls Base(const D&)
	Base b(d1); // calls Base(const D&)
	return 0;
}
// Note: on page 626, it says:
// Although in principle, Base could have a constructor that has a parameter of
// type D, in practice, that is very unlikely.
// As the code above shows, if we handle the order of declaration and definition
// carefully, Base could have a constructor that has a parameter of type D, but 
// that will lead to a circle: we use the constructor of Base to initialize an
// object of type D, but the constructor itself takes a D parameter. D should be
// built on Base, thus we shouldn't use type D's object to initialize type Base's.
// See page 619.