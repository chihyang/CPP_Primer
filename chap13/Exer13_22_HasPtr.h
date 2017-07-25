#ifndef HASPTR_H
#define HASPTR_H
#include <iostream>
#include <string>
class HasPtr{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { i = ps->size(); }
    // here, we can use private members directly! Because this is a member
    // function of class HasPtr. They can access any member of the class. Review
    // member functions, access control and class scope for more details.
    HasPtr(const HasPtr& hp) : ps(new std::string(*(hp.ps))), i(hp.i) { }
    // . has higher precedence, so the parenthesize could be ignored here
    // copy-assignment operator required by exercise 13.8
    HasPtr& operator=(const HasPtr&);
    // destructor required by exercise 13.11
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};
HasPtr& HasPtr::operator=(const HasPtr& hp)
{
    // WARNING: ensure self assignment gets the correct result!!!
    // Remember to free resources before deleting!!!
    // WRONG way to write an assignment operator!
    ps = new std::string(*hp.ps);
    i = hp.i;
    return *this; // return this object
}
#endif
// value-like copy and assign required by exercise 13.22
// Note: both copy and copy-assign member allocate new memory, so they make the
// class behave like a value.
