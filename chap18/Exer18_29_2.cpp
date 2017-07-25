// Warning: this is for verification and illustration.
#include <iostream>
class Class {
public:
    Class() { std::cout << "Class()" << std::endl; }
};
class Base : public Class {
public:
    Base() { std::cout << "Base()" << std::endl; }
};
class D1 : public Base {
public:
    D1() { std::cout << "D1()" << std::endl; }
};
class D2 : public Base {
public:
    D2() { std::cout << "D2()" << std::endl; }
};
class MI : public D1, public D2 {
public:
    MI() { std::cout << "MI()" << std::endl; }
};
class Final : public MI, public Class {
public:
    Final() { std::cout << "Final()" << std::endl; }
};
int main()
{
    Final fi;
    return 0;
}
// ******result******
// Class()
// Base()
// D1()
// Class()
// Base()
// D2()
// MI()
// Class()
// Final()

// Note: compared to Exer18_29_1.cpp, we can see the difference between virtual
// base and normal base.
