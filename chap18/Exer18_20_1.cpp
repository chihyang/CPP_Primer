#include <iostream>
namespace primerLib {
	void compute() { std::cout << "compute()" << std::endl; }
	void compute(const void*) { std::cout << "compute(const void*)" << std::endl; }
}
using primerLib::compute;
void compute(int) { std::cout << "compute(int)" << std::endl; }
void compute(double, double = 3.4) { std::cout << "compute(double, double)" << std::endl; }
void compute(char*, char* = 0) { std::cout << "compute(char*, char*)" << std::endl; }
int main()
{
	compute(0);
	return 0;
}