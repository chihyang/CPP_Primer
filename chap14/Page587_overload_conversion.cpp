// Warning: this is for verification. It cannot compile.
#include <iostream>
struct C {
    C(int) { std::cout << "C(int)is called" << std::endl; }
    C(double) { std::cout << "C(double) is called" << std::endl; }
};
struct E {
    E(double) {}
};
void manip2(const C&) { std::cout << "manip2(const E&) is called" << std::endl; }
void manip2(const E&) { std::cout << "manip2(const E&) is called" << std::endl; }
void manip3(const C&) { std::cout << "manip3(const C&) is called" << std::endl; }
int main()
{
    // error ambiguous: two difference user-defined conversions could be used
    manip2(10); // manip2(C(10)) or manip2(E(double(10)))? the effect of arithmetic conversion is not considered
    manip3(10); // the same conversion function, but has two overloaded version
    manip3(2.5);// according to arithmetic match, choose C(double), from 2.5 to int requires arithmetic conversion, while double is exact match, so C(double is better match)
    return 0;
}
