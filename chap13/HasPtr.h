#ifndef HASPTR_H
#define HASPTR_H
#include <iostream>
#include <string>
#include <algorithm>
using std::ostream;
using std::string;
class HasPtr{
	// swap on page 517
	friend void swap(HasPtr&, HasPtr&);
	// relational operator required by exercise 13.31
	friend bool operator<(const HasPtr&, const HasPtr&);
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { i = ps->size(); }
	// here, we can use private members directly! Because this is a member 
	// function of class HasPtr. They can access any member of the class. Review
	// member functions, access control and class scope for more details.
	HasPtr(const HasPtr &hp) : ps(new string(*(hp.ps))), i(hp.i) { } 
	// . has higher precedence, so the parenthesize could be ignored here
	// copy-assignment operator required by exercise 13.8
	HasPtr& operator=(const HasPtr&);
	ostream& print(ostream&) const;
	// destructor required by exercise 13.11
	~HasPtr() { delete ps; } 
private:
	string *ps;
	int i;
};
HasPtr& HasPtr::operator=(const HasPtr &hp)
{
	// WARNING: ensure self assignment gets the correct result!!!
	// Remember to free resources before deleting!!!
	auto newp = new string(*hp.ps);
	delete ps;
	ps = newp;
	i = hp.i;
	return *this; // return this object
}
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}
ostream& HasPtr::print(ostream &os) const
{
	os << *ps;
	return os;
}
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "two HasPtr objects are swapped" << std::endl; // required by exercise 13.30
}
#endif
// value-like copy and assign required by exercise 13.22
// Note: both copy and copy-assign member allocate new memory, so they make the 
// class behave like a value. 