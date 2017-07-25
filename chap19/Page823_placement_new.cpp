#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main()
{
    string* sp = new string("a value"); // allocate and initialize a string
    cout << *sp << endl;
    sp->~string();                      // destroy but not deallocate the string
    new (sp) string("another value");   // reconstruct the string
    cout << *sp << endl;
    delete sp;                          // destroy and deallocate the string
    return 0;
}
