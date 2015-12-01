#ifndef EXER16_19_H
#define EXER16_19_H
#include <iostream>
template <typename C>
void print(const C &c)
{
	for(typename C::size_type i = 0; i != c.size(); ++i)
		std::cout << c[i] << " ";
}
#endif