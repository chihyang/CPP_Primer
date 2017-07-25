#include <iostream>
#include "Exer14_27_StrBlob.h"
int main()
{
    StrBlob v = {"Like", "a", "thunderbolt", "he", "falls"};
    StrBlobPtr pv(v);
    for(; pv != v.end(); ++pv)
        std::cout << pv.deref() << " ";
    std::cout << std::endl;
    return 0;
}
