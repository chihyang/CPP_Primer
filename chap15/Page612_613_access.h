#ifndef PAGE612_613_ACCESS_H
#define PAGE612_613_ACCESS_H
class Base {
public:
    void pub_mem(); // public member
protected:
    int prot_mem = 0;   // protected member
private:
    char priv_mem = 0;  //private member
};
struct Pub_Derv : public Base {
    // ok: derived classes can access protected members
    int f() { return prot_mem; }
    // error: private members are inaccessible to derived classes
    // char g() { return priv_mem; }
};
struct Priv_Derv : private Base {
    // private derivation doesn't affect access in the derived class
    int f1() { return prot_mem; }
};
struct Prot_Derv : protected Base {
    // protected derivation doesn't affect access in the derived class
    int f2() { return prot_mem; }
};
struct Derived_from_Public : public Pub_Derv {
    // ok: Base::prot_mem remains protected in Pub_Derv
    int use_base() { return prot_mem; }
};
struct Derived_from_Private: public Priv_Derv {
    // error: Base::prot_mem is private in Priv_Derv
    // int use_base() { return prot_mem; }
};
struct Derived_from_Protected: public Prot_Derv {
    // ok: Base::prot_mem is protected in Prot_Derv
    int use_base() { return prot_mem; }
};
#endif
