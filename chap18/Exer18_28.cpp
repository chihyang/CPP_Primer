#include <iostream>
struct Base {
    void bar(int) // public by default
        { std::cout << "Base::bar(int)" << std::endl; }
protected:
    int ival;
};
struct Derived1 : virtual public Base {
    void bar(char) // public by default
        { std::cout << "Derived1::bar(char)" << std::endl; }
    void foo(char)
        { std::cout << "Derived1::foo(char)" << std::endl; }
protected:
    char cval;
};
struct Derived2 : virtual public Base {
    void foo(int) // public by default
        { std::cout << "Derived2::foo(int)" << std::endl; }
protected:
    int ival;
    char cval;
};
class VMI : public Derived1, public Derived2 {
public:
    void print();
};
void VMI::print()
{
    // direct access from VMI
    bar(0);           // Derived1::bar
    ival = 0;         // Derived2::ival
    Base::ival = 2;   // Base::ival
    // require qualification
    Derived1::foo(0); // Derived1::foo
    Derived2::foo(0); // Derived2::foo
    // foo(0);        // ambiguous
    Derived1::cval = '\0'; // Derived1::cval
    Derived2::cval = '\0'; // Derived2::cval
}
int main()
{
    VMI vmi;
    vmi.print();
    return 0;
}
