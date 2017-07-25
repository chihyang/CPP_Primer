#ifndef EXER13_14_H
#define EXER13_14_H
#include <iostream>
#include <cstdlib>
struct numbered {
    numbered() : mysn(rand()) {}
    int mysn = 0;
};
void f(numbered s) { std::cout << s.mysn << std::endl; } // no copy constructor that generates new value
#endif
