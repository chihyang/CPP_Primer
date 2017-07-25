#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
using std::type_info;
class A {
public:
    A() = default;
    virtual ~A() = default;
};
class B : public A {};
class C : public B {};
int main()
{
    A *pa = new C;
    cout << typeid(pa).name() << endl;
    C cobj;
    A &ra = cobj;
    cout << typeid(&ra).name() << endl;
    B *px = new B;
    A &ra1 = *px;
    cout << typeid(ra1).name() << endl;
}
// ******result of cl******
// class A *
// class A *
// class B
