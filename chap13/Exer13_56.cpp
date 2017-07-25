// Warning: this is for verification. It has run time error.
// The problem lies in line 28.
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
class Foo {
public:
    Foo() = default;
    Foo(const vector<int> &v) : data(v) {}
    Foo(const Foo &f) : data(f.data) {}
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;
};
Foo Foo::sorted() &&
{
    sort(data.begin(),data.end());
    return *this;
}
Foo Foo::sorted() const &
{
    Foo ret(*this);
    cout << "Foo sorted() const & is called." << endl;
    return ret.sorted(); // recursive call, infinite loop
}
int main()
{
    Foo f = Foo({1,2,3,4}); // f is an lvalue
    f.sorted();
    return 0;
}
