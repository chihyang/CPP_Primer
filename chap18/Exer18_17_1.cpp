// Warning: this is for verification. It cannot compile.
// The problem lie in line 9.
namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}
int ivar = 0;
using Exercise::ivar; // conficts with ::ivar
using Exercise::dvar;
using Exercise::limit;
int main()
{
    double dvar = 3.1416; // hides Exercise::dvar
    int iobj = limit + 1; // uses Exercise::limit
    ++ivar;   // conflicts above, if comment using Exercise::ivar, this uses ::ivar
    ++::ivar; // uses ::ivar
    return 0;
}
// ******compile info of g++******
// Exer18_17_1.cpp:9:17: error: 'ivar' is already declared in this scope
//  using Exercise::ivar; // conficts with ::ivar
//                  ^
