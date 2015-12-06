#ifndef EXER16_63_COUNT_H
#define EXER16_63_COUNT_H
#include <cstring>
#include <iostream>
#include <vector>
// use two template arguments for compatible but different types
template <typename T1, typename T2>
typename std::vector<T1>::size_type count(const std::vector<T1> &v, const T2 &t)
{
	typename std::vector<T1>::size_type cnt = 0;
	for(auto b = v.begin(); b != v.end(); ++b)
	{
		if(*b == t)
			++cnt;
	}
	return cnt;
}
template <>
std::vector<const char*>::size_type count(std::vector<const char*> const& v, const char* const &t)
{
	std::cout << "count(const std::vector<const char*> &v, const char* const &t)" << std::endl;
	std::vector<const char*>::size_type cnt = 0;
	for(auto b = v.begin(); b != v.end(); ++b)
	{
		if(!strcmp(*b, t))
			++cnt;
	}
	return cnt;	
}
#endif