#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const char* test =  "test it";
    void *p = &test;
    const auto &refer = test;
    int i = 2;
    int *pi = &i;

    cout << test << "===" << refer << endl;
    cout << static_cast<const void*>(test) << "\t" << &test << '\t' << p << endl;
    cout << static_cast<const void*>(refer) << "\t" << &refer << endl;
    cout << i << "\t" << &i << endl;
    cout << *pi << "\t" << pi << "\t" << &pi << endl;
    return 0;
}
