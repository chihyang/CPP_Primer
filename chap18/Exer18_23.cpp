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
class D : public X, public C {};
int main()
{
	D *pd = new D;
	X *px = pd;
	A *pa = pd;
	B *pb = pd;
	C *pc = pd;
	delete pd;
	return 0;
}
