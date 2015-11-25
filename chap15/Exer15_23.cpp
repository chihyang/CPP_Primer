#include <iostream>
class Base {
public:
	virtual int fcn() { std::cout << "int Base::fcn()" << std::endl; return 0; }
};
class D1 : public Base {
public:
	int fcn() override  // override Base::fcn
	    { std::cout << "int D1::fcn()" << std::endl; return 1; }
	// hide fcn in Base; this fcn is not virtual
	// D1 inherits the definition of Base::fcn
	int fcn(int i)      // parameter list differs from fcn in Base
	    { std::cout << "int D1::fcn(int)" << std::endl; return i; }
	virtual void f2()   // new virtual function that does not exist in Base
	    {}
};
class D2 : public D1 {
public:
	int fcn(int i)  // nonvirtual function hides D1::fcn(int)
	    { std::cout << "int D2::fcn(int)" << std::endl; return i; } 
	int fcn()       // overrides virtual fcn from Base
	    { std::cout << "int D2::fcn()" << std::endl; return 2; } 
	void f2()       // overrides virtual f2 from D1
	    {}
};
int main()
{
	Base bobj; D1 d1obj; D2 d2obj;
	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn(); // virtual call, will call Base::fcn at run time
	bp2->fcn(); // virtual call, will call D1::fcn at run time
	bp3->fcn(); // virtual call, will call D2::fnc at run time
	return 0;
}