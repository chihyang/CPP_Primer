#include <iostream>
#include <vector>
#include <memory>
#include "Exer13_13.h"
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
int main()
{
	cout << "x1: ";
	X x1; // default constructor constructs x1
	cout << "x2: ";
	X x2 = x1; // copy constructor copies x1 to x2
	cout << "x3: ";
	X &x3 = x1; // no constructor call
	cout << "x4: ";
	const X &x4 = x1; // no constructor call
	cout << "x5: ";
	X x5(x4); // copy constructor copies x4 to x5, pass a const reference
	cout << "p: ";
	X *p = &x2; // no constructor call
	cout << "x6: ";
	X x6(*p); // copy constructor copies object p points to to x6
	cout << "x7: ";
	X x7(x3); // copy constructor copies x1 to x7, pass a plain reference
	cout << "dynamically allocated pd: ";
	X *pd = new X(x2); // call copy constructor
	cout << "vec: ";
	vector<X> vec; // local vector<X> object with 0 element
	vec.push_back(x2); // copy constructor copies x2 into vec
	cout << "shared_ptr: ";
	shared_ptr<X> sp = make_shared<X>(x1); // copy constructor copies x1
	delete pd; // destructor called on pd, the object pd points is destroyed, or
	// the object won't be destroyed
	cout << endl;
	return 0;
}
// all of the objects above go out of scope, x7, x6, x5, x2, x1 is destroyed,
// the object pd points to should be destroyed with delete, 
// the object sp point to is destroyed, the object p points to isn't destroyed
// the elements in vec is destroyed, and vec itself is destroyed