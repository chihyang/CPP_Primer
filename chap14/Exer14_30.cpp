#include <cstddef>
#include <iostream>
#include "Exer14_30_StrBlob.h"
using std::size_t;
int main()
{
	StrBlob v = {"Like", "a", "thunderbolt", "he", "falls"};
	StrBlobPtr p1(v), p2 = p1, p3 = p1;
	ConstStrBlobPtr pc(v);
	for(size_t i = 0; i != v.size(); ++i)
		std::cout << *(p1 + i) << " ";
	std::cout << std::endl;
	p2 += 2;
	std::cout << *pc << std::endl;
	std::cout << pc->size() << std::endl;
	return 0;
}