#ifndef EXER13_14_H
#define EXER13_14_H
#include <iostream>
#include <cstdlib>
struct numbered {
    numbered() : mysn(rand()) {}
    numbered(const numbered&) : mysn(rand()) {}
    int mysn = 0;
};
void f(numbered s) { std::cout << s.mysn << std::endl; } // copy constructor always generates a new value
#endif
