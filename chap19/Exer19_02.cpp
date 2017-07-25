#include <iostream>
#include "Exer19_02_StrVec.h"
using std::cout;
using std::endl;
int main()
{
    StrVec v1{"This", "is", "a", "new", "day"}, v2{"This", "is", "new", "day"};
    if(v1 < v2)
        cout << "v1 < v2" << endl;
    else if(v1 == v2)
        cout << "v1 == v2" << endl;
    else
        cout << "v1 > v2" << endl;
    return 0;
}
