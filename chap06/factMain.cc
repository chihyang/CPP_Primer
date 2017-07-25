// Exer06_09, factMain.cc
#include <iostream>
#include "Chapter6.h"
using std::cout;
using std::endl;
int main()
{
    int j = fact(12);
    cout << j << endl;
    return 0;
}

// ******compile command of cl******
// ## compile and link and get an executable file in one step:
// $ >cl -EHsc fact.cc factMain.cc -Fo./obj/ -Fe./obj/factMain.exe
//
// ## compile separately and then link:
// $ >cl -EHsc fact.cc factMain.cc -c -Fo./obj/ #-c means no link
// $ >cl -EHsc ./obj/fact.obj ./obj/factMain.obj -Fe./obj/ #link

// ******compile command of g++******
// ## compile and link and get an executable file in one step:
// $ >g++ fact.cc factMain.cc -o ./obj/factMain.exe
//
// ## compile separately and then link:
// $ >g++ -c fact.cc factMain.cc -o ./obj/fact.obj
// $ >g++ -c factMain.cc factMain.cc -o ./obj/factMain.obj
// $ >g++ ./obj/fact.o ./obj/factMain.o -o ./obj/factMain.exe
