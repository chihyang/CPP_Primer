#ifndef EXER16_20_H
#define EXER16_20_H
#include <iostream>
template <typename C>
void print(const C &c)
{
	for(auto iter = c.begin(); iter != c.end(); ++iter)
		std::cout << *iter << " ";
}
#endif