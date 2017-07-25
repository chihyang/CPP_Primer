#include <iostream>
#include <string>
using std::ostream;
using std::string;
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename;
        os << "\nvoid base::print(ostream&)" << std::endl; }
private:
    string basename = "base";
};
class derived : public base {
public:
    void print(ostream &os) { base::print(os); os << " " << i; // without base::, an infinite recursion would happen
        os << "\nvoid derived::print(ostream&)" << std::endl; }
private:
    int i = 0;
};
int main()
{
    base bobj;
    base *bp1 = &bobj;
    base &br1 = bobj;
    derived dobj;
    base *bp2 = &dobj;
    base &br2 = dobj;
    bobj.print(std::cout); // calls base::print
    std::cout << std::endl;
    dobj.print(std::cout); // calls derived::print
    std::cout << std::endl;
    bp1->name(); // calls base::name
    bp2->name(); // calls base::name
    br1.print(std::cout); // calls base::print
    std::cout << std::endl;
    br2.print(std::cout); // calls derived::print
    std::cout << std::endl;
    return 0;
}
