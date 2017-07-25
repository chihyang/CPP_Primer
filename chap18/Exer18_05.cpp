#include <cstdlib>
#include <iostream>
#include <stdexcept>
using std::cerr;
using std::endl;
using std::exception;
using std::runtime_error;
int main()
{
    try {
        throw runtime_error("runtime error!");
    } catch(const exception &e) {
        cerr << e.what() << endl;
        abort();
    }
    return 0;
}
