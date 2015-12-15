// Warning: this is for verification and illustration.
#include <iostream>
class Class {
public:
	Class() { std::cout << "Class()" << std::endl; }
};
class Base : public Class {
public:
	Base() : Class(), ival(0) { std::cout << "Base()" << std::endl; }
	Base(const Base&) = default;
	Base(int i) : Class(), ival(i) {}
protected:
	int ival;
};
class D1 : public virtual Base {
public:
	D1() { std::cout << "D1()" << std::endl; }
	D1(const D1 &d) : Base(d) { }
	D1(int i) : Base(i) {}
};
class D2 : public virtual Base {
public:
	D2() { std::cout << "D2()" << std::endl; }
	D2(const D2 &d) : Base(d) { }
	D2(int i) : Base(i) {}	
};
class MI : public D1, public D2 {
public:
	MI() { std::cout << "MI()" << std::endl; }
	MI(const MI &mi) : Base(mi), D1(mi), D2(mi) {}
	MI(int i) : Base(i), D1(i), D2(i) {}
};
class Final : public MI, public Class {
public:
	Final() { std::cout << "Final()" << std::endl; }
	Final(const Final &fi) : Base(fi), MI(fi), Class() {}
	Final(int i) : Base(i), Class() {}
};
int main()
{
	Final fi;
	std::cout << std::endl;
	Final fi2 = fi;
	return 0;
}