#ifndef EXER13_27_H
#define EXER13_27_H
#include <string>
#include <cstddef>
using std::string;
using std::size_t;
class HasPtr {
public:
	// constructor allocates a new string and a new counter, which it sets to 1
	HasPtr(const string&s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
	// copy constructor copies all three data members and increments the counter
	HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator=(const HasPtr& p);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use; // member to keep track of how many objects share *ps
};
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use; // increments the use count of the right-hand operand
	if(--*use == 0) // then decrement this object's counter
	{
		delete ps; // if no other users
		delete use; // free this object's allocated members
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this; // return this object
}
HasPtr::~HasPtr()
{
	if(--*use == 0) // if the reference count goes to 0
	{
		delete ps; // delete the string
		delete use; // and the counter
	}
}
#endif