#ifndef HASPTR_H
#define HASPTR_H
#include <iostream>
#include <string>
using std::string;
class HasPtr{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { i = ps->size(); }
	// here, we can use private members directly! Because this is a member 
	// function of class HasPtr. They can access any member of the class. Review
	// member functions, access control and class scope for more details.
	HasPtr(const HasPtr& hp) : ps(new string(*(hp.ps))), i(hp.i) { }
	// copy-assignment operator required by exercise 13.8
	HasPtr& operator=(const HasPtr&);
	// destructor required by exercise 13.11
	~HasPtr() {}
private:
	string *ps;
	int i;
};
HasPtr& HasPtr::operator=(const HasPtr& hp)
{
	ps = new string(*(hp.ps));
	i = hp.i;
	return *this;
}
#endif