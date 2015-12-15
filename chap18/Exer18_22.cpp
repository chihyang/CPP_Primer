#include <iostream>
using std::cout;
using std::endl;
class A {
public:
	A() { cout << "A()" << endl; }
};
class B : public A {
public:
	B() : A() { cout << "B()" << endl; }
};
class C : public B {
public:
	C() : B() { cout << "C()" << endl; }
};
class X {
public:
	X() { cout << "X()" << endl; }
};
class Y {
public:
	Y() { cout << "Y()" << endl; }
};
class Z : public X, public Y {
public:
	Z() : X(), Y() { cout << "Z()" << endl; }
};
class MI : public C, public Z {};
int main()
{
	MI mi;
	return 0;
}
// Chain of call:
// MI() -> C() -> B() -> A() -> Z() -> X() -> Y()