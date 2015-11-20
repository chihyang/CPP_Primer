#include <cstddef>
#include <iostream>
#include "Exer14_28_StrBlob.h"
using std::size_t;
int main()
{
	StrBlob v = {"Like", "a", "thunderbolt", "he", "falls"};
	StrBlobPtr p1(v), p2 = p1, p3 = p1;
	ConstStrBlobPtr pc(v);
	for(size_t i = 0; i != v.size(); ++i)
		std::cout << (p1 + i).deref() << " ";
	std::cout << std::endl;
	p2 += 2;
	std::cout << p2.deref() << std::endl;
	p3[4] = "falls.";
	// pc[4] = "fall";
	// p2 = 5 + p2; // throw exception
	// std::cout << p2.deref() << std::endl;
	return 0;
}