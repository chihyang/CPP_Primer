#include <iostream>
#include "Exer14_30_StrBlob.h"
class HasStrBlobPtr {
public:
	HasStrBlobPtr() : p(nullptr) {}
	HasStrBlobPtr(StrBlobPtr &a) : p(&a) {} // can only point to nonconst StrBlobPtr
	StrBlobPtr& operator*() const {
		return *p;
	}
	StrBlobPtr* operator->() const {
		return &this->operator*(); // return a pointer
	}
private:
	StrBlobPtr *p;
};
int main()
{
	StrBlob v = {"Like", "a", "thunderbolt", "he", "falls"};
	StrBlobPtr p1(v);
	HasStrBlobPtr hp(p1);
	std::cout << hp->deref() << std::endl;
	std::cout << hp->operator[](2) << std::endl;
	return 0;
}