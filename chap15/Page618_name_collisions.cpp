#include <iostream>
struct Base {
    Base() : mem(0) {}
protected:
    int mem;
};
struct Derived : Base {
    Derived(int i) : mem(i) {} // initializes Derived::mem to id
                               // Base::mem is default initialized
    int get_mem() { return mem; } //returns Derived::mem
protected:
    int mem; // hides mem in Base
};
int main()
{
    Derived d(42);
    std::cout << d.get_mem() << std::endl; // prints 42 rather than 0
    return 0;
}
