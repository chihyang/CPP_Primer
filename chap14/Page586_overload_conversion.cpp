// Warning: this is for verification. It cannot compile.
struct C {
    C(int) {}
};
struct D {
    D(int) {}
};
void manip(const C&);
void manip(const D&);
int main()
{
    manip(10); // error ambiguous: manip(C(10)) or manip(D(10))?
    return 0;
}
