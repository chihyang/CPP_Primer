#ifndef X_H
#define X_H
#include <iostream>
struct X {
	X() {std::cout << "X()" << std::endl;}
	X(const X&) {std::cout << "X(const X&)" << std::endl;}
	X& operator=(const X&) {
		std::cout << "X(const X&)" << std::endl;
		return *this;}
	~X() {std::cout << "~X()" << std::endl;}
};
#endif