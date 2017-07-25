#include <iostream>
#include <vector>
#include <cassert>
using std::cout;
using std::endl;
using std::vector;
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int divi(int a, int b)
{
    assert(b != 0);
    return a / b;
}
int main()
{
    using PF = int(*)(int, int);
    vector<PF> vfun = {add, sub, mul, divi};
    for(auto f : vfun)
        cout << f(48, 6) << endl;
    return 0;
}
