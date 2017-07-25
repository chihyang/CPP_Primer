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
class D1 : public virtual Base {
public:
    D1() { std::cout << "D1()" << std::endl; }
};
class D2 : public virtual Base {
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
    Base *pb;
    Class *pc;
    MI *pmi;
    D2 *pd2;
    pb = new Class; // error: no implicit conversion from base to derived class
    pc = new Final; // error: which subpart to point to?
    pmi = pb;       // error: no implicit conversion from base to derived class
    pd2 = pmi;      // ok: no ambiguity, conversion from derived class to base
    return 0;
}
// ******result(comment line 30 to 37)******
// Class()
// Base()
// D1()
// D2()
// MI()
// Class()
// Final()

// ******compile info of g++(uncomment 30 to 37)******
// Exer18_29_1.cpp:23:7: warning: direct base 'Class' inaccessible in 'Final' due t
// o ambiguity
//  class Final : public MI, public Class {
//        ^
// Exer18_29_1.cpp: In function 'int main()':
// Exer18_29_1.cpp:34:5: error: invalid conversion from 'Class*' to 'Base*' [-fperm
// issive]
//   pb = new Class;
//      ^
// Exer18_29_1.cpp:35:5: error: 'Class' is an ambiguous base of 'Final'
//   pc = new Final;
//      ^
// Exer18_29_1.cpp:36:6: error: invalid conversion from 'Base*' to 'MI*' [-fpermiss
// ive]
//   pmi = pb;
//       ^
// Exer18_29_1.cpp:37:6: error: cannot convert from pointer to base class 'Base' to
//  pointer to derived class 'MI' because the base is virtual

// Note #1: Final only has two Class parts. Why? Consider why Final could have more
// than one Class subparts. Because Base inherits from Class, and Final has more
// than one indirect base classes that inherit from Base. If Base is not a virtual
// class, of course Final would have as many subparts of Class as the derivation
// path. But Base is a virtual class, which would have only one copy in derived
// class. As a result, its own subparts only have one copy in derived class. Plus
// a direct base class, Final has two Class subparts in total. Compared to
// Exer18_29_2.cpp, we can understand this difference.

// Note #2: because Final has two subparts of Class, when we use a Class pointer
// to point to Final object, compiler doesn't know which subpart we intend to point
// to. As a result, line 35 is an error.
