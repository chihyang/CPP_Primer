// Warning: this is for verification. It cannot compile.
// The problems lie in 31, 34, 36, 40 and 43.
#include <iostream>
#include <string>
class Base {
public:
	// overloaded virtual functions
	virtual void fcn_v() { std::cout << "void Base::fcn_v()" << std::endl; }
	virtual void fcn_v(int) { std::cout << "void Base::fcn_v(int)" << std::endl; }
	// overloaded nonvirtual functions
	void fcn() { std::cout << "void Base::fcn()" << std::endl; }
	void fcn(int) { std::cout << "void Base::fcn(int)" << std::endl; }
};
class D : public Base {
public:
	// if we don't use using declaration, all of the overloaded functions that are not overridden would be hidden
	using Base::fcn;
	void fcn(const std::string&) { std::cout << "void D::fcn(string)" << std::endl; }
	// not use using, so fcn_v(int) is hidden in D
	void fcn_v(const std::string&) { std::cout << "void D::fcn_v(string)" << std::endl; } // this is a nonvirtual function, not an overridden function of Base::fcn_v(int) or Base::fcn_v()
	void fcn_v() { std::cout << "void D::fcn_v()" << std::endl; } // this is overridden virtual function
	// Base::fcn_v(int) is hidden
};
int main()
{
	Base bobj; D d1obj;
	Base *bp1 = &bobj, *bp2 = &d1obj;
	D *dp = &d1obj;
	bp1->fcn_v();       // virtual call, will call Base::fcn_v() at run time
	bp1->fcn_v(3);      // virtual call, will call Base::fcn_v(int) at run time
	bp1->fcn_v("B");    // error: Base has no member that takes a string argument
	bp2->fcn_v();       // virtual call, will call D::fcn_v() at run time
	bp2->fcn_v(5);      // virtual call, but call Base::fcn_v(int) at run time
	bp2->fcn_v("D");    // error: Base has no member that takes a string argument
	dp->fcn_v();        // virtual call, will call D::fcn_v() at compile time
	dp->fcn_v(7);       // error: Base::fcn(int) is hidden in D
	dp->fcn_v("D");     // nonvirtual call, because D::fcn_v(string) is not a virtual function, will call D:fcn_v(string)
	bp1->fcn();         // nonvirtual call, will call Base::fcn()
	bp1->fcn(9);        // nonvirtual call, will call Base::fcn(int)
	bp1->fcn("B");      // error: Base has no member that takes a string argument
	bp2->fcn();         // nonvirtual call, will call Base::fcn()
	bp2->fcn(9);        // nonvirtual call, will call Base::fcn(int)
	bp2->fcn("B");      // error: Base has no member that takes a string argument
	dp->fcn();          // nonvirtual call, will call D::fcn() at compile time because of using declaration
	dp->fcn(7);         // nonvirtual call, will call Base::fcn() at compile time because of using declaration
	dp->fcn("D");       // nonvirtual call, will call D:fcn(string) at compile time
	return 0;
}
// Note: scope, name lookup and dynamic binding are perplexing, but once you know
// when they happen, things will be easier. Name lookup happens before the compiler 
// generates code; static binding happens at compile time; dynamic binding happens
// at run time. One thumb of rule is that once the name is found, the compiler looks
// no further(page 620), and name lookup ONLY relies on static type. Keeping these
// things in mind, we don't need to remember every case, but are able to analyse 
// specific cases.