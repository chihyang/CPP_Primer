#include <string>
#include <vector>
struct Base1 {
    void print(int) const; // public by default
protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};
struct Base2 {
    void print(double) const; // public by default
protected:
    float fval;
private:
    double dval;
};
struct Derived : public Base1 {
    void print(std::string) const; // public by default
protected:
    std::string sval;
    double dval;
};
struct MI : public Derived, public Base2 {
    void print(std::vector<double>) const; // public by default
    void foo(double);
protected:
    int *ival;
    std::vector<double> dvec;
};
int ival;
double dval;
void MI::foo(double cval)
{
    int dval;
    // assign local dval the sum of Base1::dval and Derived::dval
    dval = Base1::dval + Derived::dval;
    // assign Base2::fval the last element in dvec
    if(!dvec.empty())
        Base2::fval = dvec.back();
    // assign cval from Base1 to the first character in sval from Derived
    if(!Derived::sval.empty()) {
        Derived::sval.push_back(Base1::cval);
    } else {
        Derived::sval.front() = Base1::cval;
    }
}
int main()
{
    MI mi;
    mi.foo(0);
    return 0;
}
