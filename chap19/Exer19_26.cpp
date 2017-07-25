// Warning: this is for verification. It cannot compile. See note below.
// The problem lies in 7.
#include <iostream>
using std::cout;
using std::endl;
extern "C" int compute(int *, int);
extern "C" double compute(double *, double); // error
int main()
{
    int i = 2, *p;
    cout << compute(p, i) << endl;
    return 0;
}
// ******compile info of g++******
// Exer19_26.cpp:7:43: error: conflicting declaration of C function 'double compute
// (double*, double)'
//  extern "C" double compute(double *, double); // error
//                                            ^
// Exer19_26.cpp:6:16: note: previous declaration 'int compute(int*, int)'
//  extern "C" int compute(int *, int);
//                 ^

// Note: to compile this program, follow the steps below:
// (Assume source files are under the directory F:\cpp_primer\chap19>, and chap19
// has a subdirectory called obj.)
// 1. comment line 7;
// 2. compile the C source file:
// F:\cpp_primer\chap19> g++ Exer19_26.c -c -o ./obj/Exer19_26_c.o
// 3. compile the C++ source file:
// F:\cpp_primer\chap19> g++ -std=c++11 Exer19_26.cpp -c -o ./obj/Exer19_26_cpp.o
// 4. link two object files:
// F:\cpp_primer\chap19> g++ -std=c++11 ./obj/Exer19_26_c.o  ./obj/Exer19_26_cpp.o -o ./obj/Exer19_26-gcc.exe
