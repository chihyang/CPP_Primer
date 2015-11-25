// Warning: this is for verification. It cannot compile.
// The problems lie in line 28 and 32.
class Base {
public:
	virtual int fcn() { return 0; }
};
class D1 : public Base {
public:
	// hide fcn in Base; this fcn is not virtual
	// D1 inherits the definition of Base::fcn
	int fcn(int i) { return i; } // parameter list differs from fcn in Base
	virtual void f2() {} // new virtual function that does not exist in Base
};
class D2 : public D1 {
public:
	int fcn(int i) { return i; } // nonvirtual function hides D1::fcn(int)
	int fcn() { return 2; } // overrides virtual fcn from Base
	void f2() {}; // overrides virtual f2 from D1
};
int main()
{
	Base bobj; D1 d1obj; D2 d2obj;
	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
	bp1->fcn(); // virtual call, will call Base::fcn at run time
	bp2->fcn(); // virtual call, will call Base::fcn at run time
	bp3->fcn(); // virtual call, will call D2::fnc at run time
	D1 *d1p = &d1obj; D2 *d2p = &d2obj;
	bp2->f2(); // error: Base has no member named f2
	d1p->f2(); // virtual call, will call D1::f2() at run time
	d2p->f2(); // virtual call, will call D2::f2() at run time
	Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
	p1->fcn(42); // error: Base has no version of fcn that takes an int
	p2->fcn(42); // statically bound, calls D1::fcn(int)
	p3->fcn(42); // statically bound, calls D2::fnc(int)
	return 0;
}