// Warning: this is for illustration and reflects bad practice. It cannot compile.
#include <iostream>
// class D;
class Base {
	friend void VirAccess(const Base&);
	friend void NonVirAccess();
	// friend class D; // bad idea, don't use it in practice
protected:
	virtual void FooProt() const { std::cout << "Base::FooProt" << std::endl;}
private:
	virtual void FooPriv() const { std::cout << "Base::FooPriv" << std::endl; }
	void FooPriv_nonvir() const { std::cout << "Base::FooPriv_nonvir" << std::endl; }
};
class D : public Base {
	void CallBase() { 
		FooProt();        // ok: call Base::FooProt
		Base::FooPriv();  // error: cannot access private number of Base
	}
	void FooPriv() const { std::cout << "D::FooPriv" << std::endl; }
};
void VirAccess(const Base &b)
{
	b.FooProt(); // ok: VirAccess is friend of Base
	b.FooPriv(); // ok: dynamic binding
}
void NonVirAccess()
{
	Base b;
	D d;
	// ok: NonVirAccess is friend of Base
	b.FooProt();        // calls Base::FooProt
	b.FooPriv();        // calls Base::FooPriv
	b.FooPriv_nonvir(); // calls Base::FooPriv_nonvir
	// ok: NonVirAccess is friend of Base; FooPriv of D is public
	d.FooProt();        // calls Base::FooProt
	d.FooPriv();        // error: attempt to call D::FooPriv; it's private
}
int main()
{
	Base b;
	D d;
	VirAccess(b);
	std::cout << std::endl;
	VirAccess(d);
	std::cout << std::endl;
	NonVirAccess();
	return 0;
}
// Note: first see the base class Base. It has a protected virtual function FooProt
// and a private virtual function FooPriv. FooPriv could only be accessed by its 
// friends and members. As a result, we cannot access this function in Derived
// class D. The call to FooPriv in line 17 is an error, EVEN IF FooPriv exists
// in D's closed scope. On the other hand, FooProt could be accessed by derived
// class, so the call to FooProt in line 16 is allowed.
//
// Then let's see friend function VirAccess. Because it is a friend of Base, it 
// could access any member of Base. It takes a reference to Base type as parameter,
// which implies we can use this function to dynamically bind to an object of 
// derived class. Now the question is: can we use the function FooPriv if an
// object of D is passed to it? After all, even in class D itself we cannot 
// access Base::FooPriv. Try to compile the program(comment line 17), we would find 
// that the it works! And dynamical binding still takes effect. Why? For the same
// reason referred to in Page626_derived_constructor.cpp, which is quoted from 
// page 619. Whether a function is virtual is only material to dynamic binding.
// But whether dynamic binding is viable depends on whether a member is accessible.
// If VirAccess wants to access both the base and the derived version of FooPriv,
// the name Base::FooPriv MUST be accessible to it. Then even if it's not a friend 
// of derived class(thus in VirAccess we cannot access FooPriv by through an object
// of D), it can dynamical bind to D::FooPriv. This is something that DISAGREES
// WITH ACCESS CONTROL.
//
// As a comparison, NonVirAccess, which is not a friend of D either, cannot access
// to D::FooPriv through an object of D.
//
// A terrible but viable way to access private members of base class from derived
// class is declare derived class as a friend of the base class. But this 
// completely corrupts the hierarchy, thus should never be used in practice.