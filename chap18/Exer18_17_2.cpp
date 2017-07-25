// Warning: this is for verification. It cannot compile.
// The problem lie in line 14.
namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}
int ivar = 0;
int main()
{
    using Exercise::ivar; // hides ::ivar
    using Exercise::dvar;
    using Exercise::limit;
    double dvar = 3.1416; // conflicts with Exercise::dvar
    int iobj = limit + 1; // uses Exercise::limit
    ++ivar;   // uses Exercise::ivar
    ++::ivar; // uses ::ivar
    return 0;
}
// ******compile info of g++******
// Exer18_17_2.cpp: In function 'int main()':
// Exer18_17_2.cpp:14:9: error: redeclaration of 'double dvar'
//   double dvar = 3.1416; // conflicts with Exercise::dvar
//          ^
// Exer18_17_2.cpp:5:9: note: previous declaration 'double Exercise::dvar'
//   double dvar = 0;
//          ^
