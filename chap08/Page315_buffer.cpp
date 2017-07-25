#include <iostream>
using std::cout;
using std::endl;
using std::flush;
using std::ends;
int main()
{
    cout << "hi!" << endl; // writes hi! and a newline, then flushes the buffer
    cout << "hi!" << flush; // writes hi!, then flushes the buffer
    cout << "hi!" << ends; // writes hi! and a null, then flushes the buffer
    return 0;
}
