#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int x[10];
    int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
    return 0;
}

// Note: on 64bit and 32 bit, result of
//  cout << sizeof(p)/sizeof(*p) << endl;
// is different. This result depends on machine.
// On 32bit machine, it's 1;
// on 64bit machine, it's 2.
