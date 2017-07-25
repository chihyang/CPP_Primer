// Note: there are two ways to define C's default constructor, see Exer07_43_1.cpp and Exer07_43_2.cpp
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
struct NoDefault {
    NoDefault(int i) : nodef_mem(i) { cout << "NoDefault(int i)" << endl; }
private:
    int nodef_mem;
};
struct C {
    C() { cout << "C()" << endl; };
    C(int ival) : c_member(ival) { cout << "C(int ival)" << endl; }
private:
    // way 2: use in-class initializer. =, {} and = {} are all okay, but () is
    // not. Because if we use (), compiler will think we define a function
    // rather than initialize a member.
    NoDefault c_member = {0};
};
int main()
{
    C cobj;
    // vector<NoDefault> vec(10); // error, no default constructor
    vector<C> vec_C(10); // okay
    return 0;
}
