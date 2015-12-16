#ifndef EXER19_01_MEMORY_H
#define EXER19_01_MEMORY_H
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <new>
inline void *operator new(std::size_t size)
{
	std::cout << "You are using self-defined version of new!" << std::endl;
	if(void* mem = std::malloc(size))
		return mem;
	else
		throw std::bad_alloc();
}
inline void operator delete(void* mem) noexcept
{
	std::cout << "You are using self-defined version of delete!" << std::endl;
	free(mem);
}
#endif